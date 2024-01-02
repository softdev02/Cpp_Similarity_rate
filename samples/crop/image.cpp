
#define FMT_HEADER_ONLY
#define MAGICKCORE_HDRI_ENABLE 1
#define MAGICKCORE_QUANTUM_DEPTH 16
#include <Magick++.h>
#include <iostream>
using namespace std;
using namespace Magick;
int main(int argc, char **argv)
{
    InitializeMagick(*argv);
    Image image;
    try
    {
        image.read("horse.png");
        // Crop the image to specified size (width, height, xOffset, yOffset)
        image.crop(Geometry(100,100, 100, 100));
        image.write( "logo.png" );
    }
    catch (Exception err)
    {
        cout << "Caught exception: " << err.what() << endl;
        return 1;
    }
    return 0;
}