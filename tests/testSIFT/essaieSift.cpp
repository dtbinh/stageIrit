#include <opencv2/opencv.hpp>
#include <stdlib.h>
#include <stdio.h>

using namespace cv;
using namespace std;

Mat src, src_gray;
Mat dst;
const char* source_window = "Source image";

int main(int argc,char** argv){
 /// Load an image
  src = imread( argv[1] );

  if( !src.data )
    { return -1; }

 /// Create a matrix of the same type and size as src (for dst)
  dst.create( src.size(), src.type() );

  /// Convert the image to grayscale
  cvtColor( src, src_gray, COLOR_BGR2GRAY );

  /// Create a window
  namedWindow( source_window, WINDOW_AUTOSIZE );

  sift = SIFT();


}
