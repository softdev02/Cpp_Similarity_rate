#include "define.h"
#include <Magick++.h>
#include <iostream>
using namespace std;
using namespace Magick;

int main(int argc, char **argv)
{
    InitializeMagick(*argv);
    Image image1,image2,differenceImage;
    try
    {
        image1.read("tga/dwsample-tga-640.tga");
        image2.read("tga/dwsample-tga-1280.tga");
        cout << GREEN_TEXT<< "Image1 Size: " <<RESET_TEXT << image1.columns() << "x" << image1.rows() << endl;
        cout << GREEN_TEXT<<"Image2 Size: " <<RESET_TEXT << image2.columns() << "x" << image2.rows() << endl;
        differenceImage = image1;
        bool areSimilar= differenceImage.compare(image2);
        cout<< "Are images similar?:" << (areSimilar ? "Yes" : "No")<< endl; 
        double metricDistortion = differenceImage.compare(image2,Magick::MeanAbsoluteErrorMetric);
        cout << RED_TEXT <<"###### MAE(Mean Absolute Error Metric) ######"<<RESET_TEXT<< endl;
        cout << "Image similarity rate: " <<(1.0 - metricDistortion) * 100 << "%"<< endl;
        cout << "Image Difference rate: " << metricDistortion * 100 << "%"<< endl;

       /* int dotSize = 5;
        Color red("red");
        for (int y = 0; y < differenceImage.rows(); y += dotSize) {
            for (int x = 0; x < differenceImage.columns(); x += dotSize) {
                differenceImage.pixelColor(x, y, red);
            }
        }*/
       // differenceImage.compose(Magick::CompositeOperator::SrcCompositeOp);
        differenceImage.write("tga/difference.png");
        cout<< "Images compared and difference image created successfully." << endl;

    }
    catch (Exception err)
    {
        cout << "Caught exception:" << err.what() << endl;
        return 1;
    }
    return 0;
}