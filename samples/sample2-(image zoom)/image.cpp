
#define FMT_HEADER_ONLY
#define MAGICKCORE_HDRI_ENABLE 1
#define MAGICKCORE_QUANTUM_DEPTH 16
#include <Magick++.h>
#include <iostream>
using namespace std;
using namespace Magick;
int main(int argc,char **argv)
{
    InitializeMagick(*argv);
    Image master("horse.png");
    Image second = master;
    second.zoom("640x480");
    Image third = master;
    third.zoom("100x100");
    second.write("horse640x480.png");
    third.write("horse100x100.png");
    return 0;
}