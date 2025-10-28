#include <stdio.h>

int main()
{
    unsigned char original_pixels[8][8] = {
        {102, 220, 225, 95, 179, 61, 234, 203},
        {92, 3, 98, 243, 14, 149, 245, 46},
        {106, 244, 99, 187, 71, 212, 153, 199},
        {188, 174, 65, 153, 20, 44, 203, 152},
        {102, 214, 240, 39, 121, 24, 34, 114},
        {210, 65, 239, 39, 214, 244, 151, 25},
        {74, 145, 222, 14, 202, 85, 145, 117},
        {87, 184, 189, 221, 116, 237, 109, 85}};

    unsigned char brightened_pixels[8][8];
    int brightness_increase = 20;

    printf("Original Pixel Values:\n");
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%3d ", original_pixels[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int new = original_pixels[i][j] + brightness_increase;

            if (new > 255)
            {
                brightened_pixels[i][j] = 255;
            }
            else
            {
                brightened_pixels[i][j] = new;
            }
        }
    }

    printf("Original pixels after increase in brightness");
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%3d ", brightened_pixels[i][j]);
        }
        printf("\n");
    }
}