#include "image.h"
#include <stdio.h>

static void u16(FILE *f, unsigned v){fputc(v&255,f);fputc((v>>8)&255,f);}
static void u32(FILE *f, unsigned v){u16(f,v&65535);u16(f,v>>16);}
int main(void){
 const char *p="tests/image_fixture.bmp"; FILE *f=fopen(p,"wb"); Image im={0,0,NULL};
 const unsigned char px[8]={0,0,255,0,255,0,0,0}; int ok=0;
 if(!f)return 1; fputc('B',f);fputc('M',f);u32(f,62);u16(f,0);u16(f,0);u32(f,54);u32(f,40);u32(f,1);u32(f,2);u16(f,1);u16(f,24);u32(f,0);u32(f,8);u32(f,2835);u32(f,2835);u32(f,0);u32(f,0);
 if(fwrite(px,1,8,f)!=8||fclose(f)!=0){remove(p);return 1;}
 if(!ImageLoad(p,&im)){remove(p);return 1;}
 ok=im.sizeX==1&&im.sizeY==2&&(unsigned char)im.data[0]==255&&(unsigned char)im.data[1]==0&&(unsigned char)im.data[2]==0&&(unsigned char)im.data[3]==0&&(unsigned char)im.data[4]==0&&(unsigned char)im.data[5]==255;
 ImageFree(&im); ok=ok&&im.data==NULL&&im.sizeX==0&&im.sizeY==0; remove(p);
 if(!ok){fprintf(stderr,"BMP loader test failed\n");return 1;} puts("Image loader tests passed.");return 0;
}
