#include <iostream>
#include <fstream>

//Load Images
#define STB_IMAGE_IMPLEMENTATION
// Write Images
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "include/stb_image.h"
//#include "stb/stb_image_resize.h"
#include "include/stb_image_write.h"


using namespace std;

int main()
{
    int width, height, channels;
    //loading jpeg file
    unsigned char* img = stbi_load("images/apple.jpg", &width, &height, &channels, 4);

    // Img structure
    struct MyImg {
        unsigned char* data;
        int width;
        int height;
        int channels;
        string filename;
    };
    MyImg Picture_01;

    //Pixel scructure
    struct Pixel {
        unsigned char red, green, blue, alpha;
    };

    //Color to grayscale
    void CorvertImageToGrayCPU(unsigned char* imageRGBA, int width, int height);
    {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                Pixel* ptrPixel = (imageRGBA[y * width * 4 * +4 * x]);
                unsigned char pixelValue = (unsigned char)(ptrPixel->red * 0.2126 + ptrPixel->green * 0.7152 + ptrPixel->blue * 0.0722);
                ptrPixel->red = pixelValue;
                ptrPixel->green = pixelValue;
                ptrPixel->blue = pixelValue;
                ptrPixel->alpha = 255;


            }
        }

    }

    // Check If image was loads correct!!
    if (img == 0) {
        cout << "Error loading image file" << endl;
        return -1;
    }

    cout << "Loading images\n";
    cout << "\twidth = " << width << "\n";
    cout << "\theight = " << height << "\n";
    cout << "\tchannels = " << channels << "\n";

    //writing jpeg images

    stbi_write_jpg("images/apple_gray.jpg", width, height, channels, img, 100);
    stbi_image_free(img);
    return 0;
}