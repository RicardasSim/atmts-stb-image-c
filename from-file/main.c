#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{

    int width;
    int height;
    int channels;
    unsigned char *p_image;

    p_image = stbi_load( "swan-4013225_640.jpg", &width, &height, &channels, 0 );

    if( p_image == NULL )
    {
        printf("Error: cannot load image.\n");
        return 1;
    }

    printf("width: %dpx\nheight: %dpx\nchannels: %d\n", width, height, channels );

    size_t image_size = width * height * channels;

    printf( "image size in bytes: %zu\n", image_size );

    // image data
/*
    unsigned char *p = NULL;
    uint8_t v1 = 0, v2 = 0, v3 = 0, a = 0;

    for( p = p_image; p != p_image + image_size; p += channels )
    {
        if( channels == 3 )
        {
            v1 = (uint8_t) *p;
            v2 = (uint8_t) *p + 1;
            v3 = (uint8_t) *p + 2;
        }
        else if( channels == 4 )
        {
            a = (uint8_t) *p + 3;
        }
    }
*/

    stbi_image_free( p_image );

    return 0;
}
