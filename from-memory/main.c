#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{

    // loading image into memory

    FILE *fp;

    fp = fopen( "love-5192377_640.jpg", "r" );

    if ( !fp )
    {
        printf( "Error: cannot open file.\n" );
        return 1;
    }

    fseek( fp, 0L, SEEK_END );

    long int file_size = ftell( fp );

    printf( "Info: file size in bytes: %ld\n", file_size );

    unsigned char *buffer = malloc( file_size );

    if ( !buffer )
    {
        printf( "Error: cannot allocate memory.\n" );
        fclose(fp);
        return 1;
    }

    fseek( fp, 0, SEEK_SET );

    size_t count = 1;

    size_t num_of_elements;

    num_of_elements = fread( buffer, file_size, count, fp );

    fclose( fp );

    if ( num_of_elements != count )
    {
        printf( "Error: file read error.\n" );
        free( buffer );
        return 1;
    }

    // loading image from memory

    int width;
    int height;
    int channels;
    unsigned char *p_image;

    p_image = stbi_load_from_memory( buffer, file_size, &width, &height, &channels, 0 );

    free( buffer );

    if( p_image == NULL )
    {
        printf("Error: cannot load image.\n");
        return 1;
    }

    printf( "width: %dpx\nheight: %dpx\nchannels: %d\n", width, height, channels );

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
