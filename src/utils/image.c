#include "image.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

static uint16_t read_u16(const unsigned char *bytes)
{
    return (uint16_t)((uint16_t)bytes[0] | ((uint16_t)bytes[1] << 8));
}

static uint32_t read_u32(const unsigned char *bytes)
{
    return (uint32_t)bytes[0]
        | ((uint32_t)bytes[1] << 8)
        | ((uint32_t)bytes[2] << 16)
        | ((uint32_t)bytes[3] << 24);
}

static int read_exact(FILE *file, void *buffer, size_t length)
{
    return fread(buffer, 1, length, file) == length;
}

void ImageFree(Image *image)
{
    if (image == NULL) {
        return;
    }

    free(image->data);
    image->data = NULL;
    image->sizeX = 0;
    image->sizeY = 0;
}

int ImageLoad(const char *filename, Image *image)
{
    FILE *file = NULL;
    unsigned char file_header[14];
    unsigned char dib_header[40];
    unsigned char *row_buffer = NULL;
    size_t row_bytes;
    size_t row_stride;
    size_t image_bytes;
    uint32_t pixel_offset;
    uint32_t dib_size;
    int32_t width;
    int32_t signed_height;
    size_t height;
    int top_down;
    size_t row;
    int success = 0;

    if (filename == NULL || image == NULL) {
        return 0;
    }

    image->sizeX = 0;
    image->sizeY = 0;
    image->data = NULL;

    file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Unable to open bitmap: %s\n", filename);
        goto cleanup;
    }

    if (!read_exact(file, file_header, sizeof(file_header))
            || file_header[0] != 'B' || file_header[1] != 'M') {
        fprintf(stderr, "Invalid BMP file: %s\n", filename);
        goto cleanup;
    }

    pixel_offset = read_u32(&file_header[10]);

    {
        unsigned char dib_size_bytes[4];
        if (!read_exact(file, dib_size_bytes, sizeof(dib_size_bytes))) {
            fprintf(stderr, "Truncated BMP header: %s\n", filename);
            goto cleanup;
        }
        dib_size = read_u32(dib_size_bytes);
    }

    if (dib_size < 40 || !read_exact(file, dib_header, sizeof(dib_header))) {
        fprintf(stderr, "Unsupported or truncated BMP header: %s\n", filename);
        goto cleanup;
    }

    width = (int32_t)read_u32(&dib_header[0]);
    signed_height = (int32_t)read_u32(&dib_header[4]);

    if (width <= 0 || signed_height == 0 || signed_height == INT32_MIN
            || read_u16(&dib_header[8]) != 1
            || read_u16(&dib_header[10]) != 24
            || read_u32(&dib_header[12]) != 0) {
        fprintf(stderr,
                "BMP must be a positive-width, uncompressed 24-bit image: %s\n",
                filename);
        goto cleanup;
    }

    height = (size_t)(signed_height < 0 ? -signed_height : signed_height);
    top_down = signed_height < 0;

    if ((size_t)width > (SIZE_MAX - 3U) / 3U) {
        fprintf(stderr, "BMP dimensions are too large: %s\n", filename);
        goto cleanup;
    }

    row_bytes = (size_t)width * 3U;
    row_stride = (row_bytes + 3U) & ~(size_t)3U;

    if (height > SIZE_MAX / row_bytes || height > SIZE_MAX / row_stride) {
        fprintf(stderr, "BMP dimensions are too large: %s\n", filename);
        goto cleanup;
    }

    image_bytes = row_bytes * height;
    row_buffer = (unsigned char *)malloc(row_stride);
    image->data = (char *)malloc(image_bytes);
    if (row_buffer == NULL || image->data == NULL) {
        fprintf(stderr, "Out of memory loading bitmap: %s\n", filename);
        goto cleanup;
    }

    if (dib_size > 40
            && fseek(file, (long)(dib_size - 40), SEEK_CUR) != 0) {
        fprintf(stderr, "Invalid BMP header size: %s\n", filename);
        goto cleanup;
    }

    if (pixel_offset < 14U + dib_size
            || fseek(file, (long)pixel_offset, SEEK_SET) != 0) {
        fprintf(stderr, "Invalid BMP pixel offset: %s\n", filename);
        goto cleanup;
    }

    for (row = 0; row < height; ++row) {
        size_t destination_row = top_down ? height - 1U - row : row;
        size_t column;

        if (!read_exact(file, row_buffer, row_stride)) {
            fprintf(stderr, "Truncated BMP pixel data: %s\n", filename);
            goto cleanup;
        }

        for (column = 0; column < (size_t)width; ++column) {
            size_t source = column * 3U;
            size_t destination = destination_row * row_bytes + source;

            /* BMP stores pixels as BGR; OpenGL expects RGB. */
            image->data[destination] = (char)row_buffer[source + 2U];
            image->data[destination + 1U] = (char)row_buffer[source + 1U];
            image->data[destination + 2U] = (char)row_buffer[source];
        }
    }

    image->sizeX = (unsigned long)width;
    image->sizeY = (unsigned long)height;
    success = 1;

cleanup:
    free(row_buffer);
    if (file != NULL) {
        fclose(file);
    }
    if (!success) {
        ImageFree(image);
    }
    return success;
}
