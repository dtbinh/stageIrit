#include <opencv2/opencv.hpp>
#include <stdlib.h>
#include <stdio.h>

using namespace cv;
using namespace std;


int main(int argc,char** argv){


Mat src, src_gray;
Mat dst;
const char* source_window = "Source image";

 /// Load an image
  src = imread( argv[1],1 );

  if( !src.data )
    { return -1; }

   
 /// Create a matrix of the same type and size as src (for dst)
  ///dst.create( src.size(), src.type() );

  /// Convert the image to grayscale
 /// cvtColor( src, src_gray, COLOR_BGR2GRAY );

  /// Create a window
  ///namedWindow( source_window, WINDOW_AUTOSIZE );
  
  std::vector<cv::KeyPoint> keypoints1;

  SiftFeatureDetector sift;
  //threshold and edgethreshold
  sift.detect(src,keypoints1);

  //namedWindow( "Image 1", CV_WINDOW_AUTOSIZE );
  //imshow( "Image 1", src );

  SiftDescriptorExtractor siftDesc;
  
  Mat descriptors1;
  siftDesc.compute(src,keypoints1,descriptors1);

  

  

  
  drawKeypoints(src,keypoints1,dst,cv::Scalar(255,255,255));
  cout << '\n' << keypoints1.size() << '\n';
  imshow( "Image 1", dst );
  
  imwrite("resultat.png", dst);
  


  waitKey(0);
  
  return 0;








}
