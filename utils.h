#ifndef STADIUM_UTILS_H
#define STADIUM_UTILS_H

#include <stddef.h>

/* 24-bit RGB image data, stored bottom row first for OpenGL. */
typedef struct Image {
    unsigned long sizeX;
    unsigned long sizeY;
    char *data;
} Image;

/*
 * Load an uncompressed 24-bit BMP image.
 * Returns 1 on success and 0 on failure.
 */
int ImageLoad(const char *filename, Image *image);

/* Release pixel data and reset the image structure. */
void ImageFree(Image *image);

#endif /* STADIUM_UTILS_H */
