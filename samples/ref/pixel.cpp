#include <Magick++.h> 
#include <iostream> 

using namespace std; 
using namespace Magick; 
int main(int argc,char **argv) 
{ 
  InitializeMagick(*argv);

  // Create base image 
  Image image(Geometry(254,218), "white");


  // Set the image type to TrueColor DirectClass representation.
  image.type(TrueColorType);
  // Ensure that there is only one reference to underlying image 
  // If this is not done, then image pixels will not be modified.
  image.modifyImage();

  // Allocate pixel view 
  Pixels view(image);

  // Set all pixels in region anchored at 38x36, with size 160x230 to green. 
  size_t columns = 196; size_t rows = 162; 
  Color green("green"); 
  Quantum *pixels = view.get(38,36,columns,rows); 
  for ( ssize_t row = 0; row < rows ; ++row ) 
    for ( ssize_t column = 0; column < columns ; ++column ) 
    {
      *pixels++=QuantumRange*green.quantumRed();
      *pixels++=QuantumRange*green.quantumGreen();
      *pixels++=QuantumRange*green.quantumBlue();
    }

  // Save changes to image.
  view.sync();

  // Set all pixels in region anchored at 86x72, with size 108x67 to yellow. 
  columns = 108; rows = 67; 
  Color yellow("yellow"); 
  pixels = view.get(86,72,columns,rows); 
  for ( ssize_t row = 0; row < rows ; ++row ) 
    for ( ssize_t column = 0; column < columns ; ++column ) 
    {
      *pixels++=QuantumRange*yellow.quantumRed();
      *pixels++=QuantumRange*yellow.quantumGreen();
      *pixels++=QuantumRange*yellow.quantumBlue();
    }
   view.sync();

  // Set pixel at position 108,94 to red 
  Color red("red");
  pixels = view.get(108,94,1,1);
  *pixels++=QuantumRange*red.quantumRed();
  *pixels++=QuantumRange*red.quantumGreen();
  *pixels++=QuantumRange*red.quantumBlue();

  // Save changes to image.
  view.sync();
  image.write( "logo.png" );
}