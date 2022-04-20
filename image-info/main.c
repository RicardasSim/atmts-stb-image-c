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
    int result;

    result = stbi_info( "swan-6752519_640.jpg", &width, &height, &channels );

    if ( result == 0 )
    {
        printf("Error: cannot read image file.\n");
        return 0;
    }

    printf(" width: %dpx\nheight: %dpx\nchannels: %d\n\n", width, height, channels );


    return 0;
}
