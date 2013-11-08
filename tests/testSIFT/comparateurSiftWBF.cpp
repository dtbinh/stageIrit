#include <opencv2/opencv.hpp>
#include <stdlib.h>
#include <stdio.h>

#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/nonfree/features2d.hpp"
#include <opencv2/legacy/legacy.hpp>
#include "opencv2/core/mat.hpp"

using namespace cv;
using namespace std;


int main(int argc,char** argv){

Mat image1,image2;

const char* source_window = "Source image";

 /// Load images
 image1 = imread( argv[1], 1 );
 image2 = imread( argv[2], 1 );

  if( argc != 3 || !image1.data || !image2.data)
    {
      printf( "No image data \n" );
      return 1;
    }

    cout<<"\ntype de la matrice: \n" << image1.type();
    cout<<"\nflags" << image1.flags;
    cout<<"\ndims" << image1.dims;
    cout<<"\nrows" << image1.rows;
    cout<<"\ncols" << image1.cols;
    Point pt = Point(1,2);
    
    cout<< "\npoints 1 1 " << image1.at<uchar>(0,0);
    cout<< "\nmais que se passe-t'il?";

 // cout<<"\nimage1" <<  image1; 

 /// vector of keypoints 
  vector<KeyPoint> keypoints1,keypoints2;

///Construct the SURF feature detector object
  SiftFeatureDetector sift;

  sift.detect(image1,keypoints1);
  sift.detect(image2,keypoints2);

  namedWindow( "Image 1", CV_WINDOW_AUTOSIZE );
  imshow( "Image 1", image1 );
  namedWindow( "Image 2", CV_WINDOW_AUTOSIZE );
  imshow( "Image 2", image2 );
  /*afficher les coordonées des points des keypoints
	for(int i=0;i<keypoints1.size();i++){
	cout<<"\nkeypoints1" <<  keypoints1[i].pt; 
	}
  */
  SiftDescriptorExtractor siftDesc;
  
  Mat descriptors1,descriptors2;
  siftDesc.compute(image1,keypoints1,descriptors1);
  siftDesc.compute(image2,keypoints2,descriptors2);
  
   // Construction of the matcher
BruteForceMatcher<L2<float> > matcher;

// Match the two image descriptors
vector<DMatch> matches;
matcher.match(descriptors1,descriptors2, matches);

nth_element(matches.begin(),    // initial position
          matches.begin()+24, // position of the sorted element
          matches.end());     // end position
      // remove all elements after the 25th
	//display the element attributs
	//cout<< "\nmatches  " <<  matches;
	
	/*afficher les matches
	for(int i=0;i<matches.size();i++){
		cout<< "\n\npoint num " <<  i;

		
		cout<< "\nimgIdx  " <<  matches[i].imgIdx ;	
		cout<< "\nqueryIdx   " <<  matches[i].queryIdx;
		cout<< "\ntrainIdx   " <<  matches[i].trainIdx;
		



	}	
	*/



      cout << '\n' << "nombre de correspondances:" << matches.size() << '\n';  

      //matches.erase(matches.begin(), matches.end());
      //keypoints1.erase(keypoints1.begin(), keypoints1.end());
      //keypoints2.erase(keypoints2.begin(), keypoints2.end());
      //matches.erase(matches.begin(), matches.begin()+1600);



Mat imageMatches;
Mat matchesMask;
drawMatches(
  image1,keypoints1, // 1st image and its keypoints
  image2,keypoints2, // 2nd image and its keypoints
  matches,            // the matches
  imageMatches,      // the image produced
  Scalar::all(-1),   // color of the lines
  Scalar(255,255,255) //color of the keypoints
  );
  namedWindow( "Matches SIFT", CV_WINDOW_AUTOSIZE );
  imshow( "Matches SIFT", imageMatches );
  imwrite("resultat.png", imageMatches);

  /*
  drawKeypoints(src,keypoints1,dst,cv::Scalar(255,255,255));
  cout << '\n' << keypoints1.size() << '\n';
  imshow( "Image 1", dst );
  
  imwrite("resultat.png", dst);
  */


  waitKey(0);
  
  return 0;








}