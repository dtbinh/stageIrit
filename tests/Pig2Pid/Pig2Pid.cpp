#include <opencv2/opencv.hpp>

#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/legacy/legacy.hpp>
#include "opencv2/core/mat.hpp"

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

/// Global variables
Mat image1, image2;
int rows;
int cols;

string transparency_window;
string matches_window;

int thresh = 0;
int max_thresh = 100;

int seuil=100;

vector < KeyPoint > keypoints1, keypoints2;
//vector<DMatch>  matches;
vector < DMatch > matches;



/****************************/
/*                          */
/*      LES DETECTEURS      */
/*                          */
/****************************/

//utilisation de MSER
/*
 * cv::MserFeatureDetector::MserFeatureDetector (
 *            int     delta, //in the code, it compares (size_{i}-size_{i-delta})/size_{i-delta}
 *            int     minArea, //prune the area which smaller than minArea
 *            int     maxArea, //prune the area which bigger than maxArea
 *            double  maxVariation, //prune the area have simliar size to its children
 *            double  minDiversity, //trace back to cut off mser with diversity < min_diversity
 *            int     maxEvolution, //for color image, the evolution steps
 *            double  areaThreshold, //the area threshold to cause re-initialize
 *            double  minMargin,  //ignore too small margin
 *            int     edgeBlurSize //the aperture size for edge blur
 *    )
 */

//utilisation de FAST

/* cv::FastFeatureDetector::FastFeatureDetector (
  *	int threshold = 10,
  *	bool nonmaxSuppression = true
  *	)
  */

//utilisation de STAR

/*
*cv::StarFeatureDetector::StarFeatureDetector (
	int maxSize,
	int responseThreshold = 30,
	int lineThresholdProjected = 10,
	int lineThresholdBinarized = 8,
	int suppressNonmaxSize = 5
   )
   */

//utilisation de SIFT
/*
cv::SiftFeatureDetector::SiftFeatureDetector (
	double  threshold,
	double  edgeThreshold,
	int nOctaves = SIFT::CommonParams::DEFAULT_NOCTAVES,
	int nOctaveLayers = SIFT::CommonParams::DEFAULT_NOCTAVE_LAYERS,
	int firstOctave = SIFT::CommonParams::DEFAULT_FIRST_OCTAVE,
	int angleMode = SIFT::CommonParams::FIRST_ANGLE
  )
*/

//utilisation de SURF
/*
cv::SurfFeatureDetector::SurfFeatureDetector (
        double hessianThreshold = 400.,
	int octaves = 3,
	int octaveLayers = 4
	)
*/

//utilisation de ORB
/*
ORB::ORB(
int nfeatures=500,
float scaleFactor=1.2f,
int nlevels=8,
int edgeThreshold=31,
int firstLevel=0,
int WTA_K=2,
int scoreType=ORB::HARRIS_SCORE,
int patchSize=31)
*/

//utilisation de HARRIS avec GoodFeaturesToTrackDetector
/*
 	GoodFeaturesToTrackDetector (
         int maxCorners,
         double qualityLevel,
         double minDistance,
         int blockSize=3,
         true,
         double k=0.04)
*/

//utilisation de GFTT i.e cornerMinEigenVal, les minimum des valeurs propres des vecteurs.
/*
 	GoodFeaturesToTrackDetector (
         int maxCorners,
         double qualityLevel,
         double minDistance,
         int blockSize=3,
         bool useHarrisDetector=false,
         double k=0.04)
*/

//utilisation de DENSE

/*

cv::DenseFeatureDetector::Params::Params (
float  	initFeatureScale = 1.f,
int  	featureScaleLevels = 1,
float  	featureScaleMul = 0.1f,
int  	initXyStep = 6,
int  	initImgBound = 0,
bool  	varyXyStepWithScale = true,
bool  	varyImgBoundWithScale = false
)

*/

//utilisation de SIMPLE BLOB

/*

class SimpleBlobDetector : public FeatureDetector
{
public:
struct Params
{
    Params();
    float thresholdStep;
    float minThreshold;
    float maxThreshold;
    size_t minRepeatability;
    float minDistBetweenBlobs;

    bool filterByColor;
    uchar blobColor;

    bool filterByArea;
    float minArea, maxArea;

    bool filterByCircularity;
    float minCircularity, maxCircularity;

    bool filterByInertia;
    float minInertiaRatio, maxInertiaRatio;

    bool filterByConvexity;
    float minConvexity, maxConvexity;
};

SimpleBlobDetector(const SimpleBlobDetector::Params &parameters = SimpleBlobDetector::Params());

*/















 /**************************************/
 /*                                    */
 /*          LES DESCRIPTEURS          */  
 /*                                    */
 /**************************************/



//SIFT

//SURF

//BRIEF

//ORB



 /**************************************/
 /*                                    */
 /*           LES APPARIEURS           */
 /*                                    */
 /**************************************/

/*apparieurs fonctionnant avec les descripteurs SIFT et SURF*/

//BruteForce

//BruteForce-L1


/*apparieurs fonctionnant avec les descripteurs BRIEF et ORB */

//BruteForce-Hamming

//FlannBased



/// Function header
void interface(int argc, void *);

/**
 * @function main
 */



int main(int argc, char **argv)
{

  
   Ptr<DescriptorExtractor> descriptor;  
   Ptr<DescriptorMatcher> matcher;
   
   
   
    if(argc!=6)
    {
        cout << "\nusage incorrect!\n\n";
        cout << "pathimage1 pathimage2 detectorName descriptorName matcherName\n" <<endl;

        cout << "\n detectorName List:";
        cout << "\n MSER";
        cout << "\n FAST";
        cout << "\n STAR";
        cout << "\n SIFT";
        cout << "\n SURF";
        cout << "\n ORB";
        cout << "\n HARRIS";
        cout << "\n GFTT";
        cout << "\n DENSE";
        cout << "\n SIMPLE BLOB\n";
        cout << endl;

        cout << "\n descriptorName List:";
        cout << "\n SIFT";
        cout << "\n SURF";
        cout << "\n BRIEF";
        cout << "\n ORB";
        cout << endl;

        cout << "\n matcherName List:";

        cout << "\n\n pour les descripteurs SIFT et SURF\n";
        cout << "\n BruteForce";
        cout << "\n BruteForce-L1";

         cout << "\n\n pour les descripteurs BRIEF et ORB\n";
        cout << "\n BruteForce-Hamming";
        cout << "\n FlannBased";
        cout <<"\n";
        cout <<endl;
        

        exit(0);
    }



    image1 = imread(argv[1], 1);
    image2 = imread(argv[2], 1);
    


    //cout << "\n nom du détecteur: "<<argv[3];

    if(strcmp(argv[3],"MSER")==0)
    {
        MserFeatureDetector detector;
        detector.detect(image1, keypoints1);
        detector.detect(image2, keypoints2);


    }


    else if(strcmp(argv[3],"FAST")==0)
    {
        FastFeatureDetector detector(50,true);
        detector.detect(image1, keypoints1);
        detector.detect(image2, keypoints2);
    }


    else if(strcmp(argv[3],"STAR")==0)
    {
        StarFeatureDetector detector;
        detector.detect(image1, keypoints1);
        detector.detect(image2, keypoints2);


    }


    else if(strcmp(argv[3],"SIFT")==0)
    {
        SiftFeatureDetector detector;
        detector.detect(image1, keypoints1);
        detector.detect(image2, keypoints2);


    }

    else if(strcmp(argv[3],"SURF")==0)
    {
        SurfFeatureDetector detector(2000);
        detector.detect(image1, keypoints1);
        detector.detect(image2, keypoints2);


    }

    //different
    else if(strcmp(argv[3],"ORB")==0)
    {
        ORB detector(200);
        detector(image1,Mat(),keypoints1);
        detector(image2,Mat(),keypoints2);


    }
    /*
    else if(strcmp(argv[3],"BRISK")==0){
        BRISK detector;
        detector(image1,Mat(),keypoints1);
        detector(image2,Mat(),keypoints2);


    }
    */
    else if(strcmp(argv[3],"HARRIS")==0)
    {
        GoodFeaturesToTrackDetector detector( 1000,0.01,1., 3,true, 0.04);
        detector.detect(image1, keypoints1);
        detector.detect(image2, keypoints2);



    }
    else if(strcmp(argv[3],"GFTT")==0)
    {
        GoodFeaturesToTrackDetector detector;
        detector.detect(image1, keypoints1);
        detector.detect(image2, keypoints2);

    }

    else if(strcmp(argv[3],"DENSE")==0)
    {
        Ptr<FeatureDetector> detector;
        detector = FeatureDetector::create("Dense");
        
        //DenseFeatureDetector detector(0.5);
        detector->detect(image1, keypoints1);
        detector->detect(image2, keypoints2);

    }
    else if(strcmp(argv[3],"SIMPLE BLOB")==0)
    {
        cv::SimpleBlobDetector::Params params;
        params.minDistBetweenBlobs = 10.0;  // minimum 10 pixels between blobs
        params.filterByArea = true;         // filter my blobs by area of blob
        params.minArea = 10.0;              // min 20 pixels squared
        params.maxArea = 500.0;             // max 500 pixels squared
        SimpleBlobDetector detector(params);



        detector.detect(image1,keypoints1);
        detector.detect(image2,keypoints2);

    }
    else
    {

        cout << "\n detecteur inconnu"<<endl;
        cout << "\n liste des détecteurs possible:";
        cout << "\n MSER";
        cout << "\n FAST";
        cout << "\n STAR";
        cout << "\n SIFT";
        cout << "\n SURF";
        cout << "\n ORB";
        cout << "\n HARRIS";
        cout << "\n GFTT";
        cout << "\n DENSE";
        cout << "\n SIMPLE BLOB";
        cout <<"\n";
        exit(0);
    }


    //selection du descripteur

  

    if(strcmp(argv[4],"BRIEF")==0)
    {
       
        descriptor = cv::DescriptorExtractor::create("BRIEF");

    }
    else if(strcmp(argv[4],"ORB")==0)
    {
       descriptor = cv::DescriptorExtractor::create("ORB");

    }
     else if(strcmp(argv[4],"SIFT")==0)
    {
      
      descriptor = cv::DescriptorExtractor::create("SIFT");

    }
    else if(strcmp(argv[4],"SURF")==0){

       descriptor = cv::DescriptorExtractor::create("SURF");
      
    }

    else
    {

        cout << "\n descripteur inconnu"<<endl;
        cout << "\n liste des descripteurs possible:";
        cout << "\n SIFT";
        cout << "\n SURF";
        cout << "\n BRIEF";
        cout << "\n ORB";
        cout <<"\n";
 
        exit(0);
    }
    
    
        //BruteForce

   //BruteForce-L1


    /*apparieurs fonctionnant avec les descripteurs BRIEF et ORB */

    //BruteForce-Hamming

   //FlannBased

    if(strcmp(argv[5],"BruteForce")==0 || strcmp(argv[5],"BruteForce-L1")==0){

       matcher = cv::DescriptorMatcher::create(argv[5]);
     
    }

   else if(strcmp(argv[5],"BruteForce-Hamming")==0 || strcmp(argv[5],"FlannBased")==0){


       matcher = cv::DescriptorMatcher::create(argv[5]);
      
    }


    else{
        cout << "\n apparieur inconnu"<<endl;
        cout << "\n liste des apparieurs possible:";
        cout << "\n BruteForce";
        cout << "\n BruteForce-L1";
        cout << "\n BruteForce-Hamming";
        cout << "\n FlannBased";
        cout <<"\n";
 
        exit(0);
     

    }
 


    string st1= argv[3] + (string)" + " +argv[4] +  (string)" + " + argv[5];
    string st2="transparence " + st1;

    transparency_window = st2;
    matches_window= st1;



    rows = image1.rows;
    cols = image1.cols;


    namedWindow("image1", WINDOW_AUTOSIZE);
    imshow("image1", image1);
    namedWindow("image2", WINDOW_AUTOSIZE);
    imshow("image2", image2);





    Mat descriptors1, descriptors2;
    
    (*descriptor).compute(image1, keypoints1, descriptors1);
    (*descriptor).compute(image2, keypoints2, descriptors2);

    
     
    matcher->match(descriptors1, descriptors2, matches);
       
             
            


//ici on trie les matchesWithDist par distance des valeurs des descripteurs et non par distance euclidienne
    nth_element(matches.begin(), matches.begin() + 24, matches.end());
    // initial position
    // position of the sorted element
    // end position

    for(int i=0;i<matches.size();i++){
 	if(matches[i].distance>seuil){
		matches.erase(matches.begin() + i,matches.end());
        }
    }


    //si on veut garder les meilleurs correspondances
     
    /* if(matches.size()>500){
       matchesWithDist.erase(matchesWithDist.begin() + 500,matchesWithDist.end());
     }*/

    Mat imageMatches;
    
    drawMatches(image1, keypoints1,	// 1st image and its keypoints
                image2, keypoints2,	// 2nd image and its keypoints
                matches,	// the matches
                imageMatches,	// the image produced
                Scalar::all(-1),	// color of the lines
                Scalar(255, 255, 255)	//color of the keypoints
               );


    namedWindow(matches_window, CV_WINDOW_AUTOSIZE);
    imshow(matches_window, imageMatches);
    imwrite("resultat.png", imageMatches);

   

    /// Create a window and a trackbar
    namedWindow(transparency_window, WINDOW_AUTOSIZE);
    createTrackbar("Threshold: ", transparency_window, &thresh, max_thresh, interface);
    //imshow(transparency_window,image1 );

    interface(0, 0);

    waitKey(0);
    return (0);
}

/**
 * @function cornerHarris_demo
 * @brief Executes the corner detection and draw a circle around the possible corners
 */
void interface(int, void *)
{

    Mat dst;
    image1.copyTo(dst);

    ///on adapte l'importance des pixels de chaque image selon la valeur du trackbar
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            dst.at < cv::Vec3b > (i, j)[0] = (float) (image2.at < cv::Vec3b > (i, j)[0]) * (float) (thresh / 100.) + (float) (image1.at < cv::Vec3b > (i, j)[0]) * (float) ((100. - thresh) / 100.);
            dst.at < cv::Vec3b > (i, j)[1] = (float) (image2.at < cv::Vec3b > (i, j)[1]) * (float) (thresh / 100.) + (float) (image1.at < cv::Vec3b > (i, j)[1]) * (float) ((100. - thresh) / 100.);
            dst.at < cv::Vec3b > (i, j)[2] = (float) (image2.at < cv::Vec3b > (i, j)[2]) * (float) (thresh / 100.) + (float) (image1.at < cv::Vec3b > (i, j)[2]) * (float) ((100. - thresh) / 100.);


        }
    }

    float kp1x;
    float kp1y;
    float kp2x;
    float kp2y;

    float kptx;
    float kpty;

   


    for (int i = 0; i < matches.size(); i++)
    {


        kp1x = keypoints1[matches[i].queryIdx].pt.x;
        kp1y = keypoints1[matches[i].queryIdx].pt.y;
        kp2x = keypoints2[matches[i].trainIdx].pt.x;
        kp2y = keypoints2[matches[i].trainIdx].pt.y;

        kptx = kp1x * (100. - thresh) / 100. + kp2x * (thresh / 100.);
        kpty = kp1y * (100. - thresh) / 100. + kp2y * (thresh / 100.);

        Point ptkp1 = Point(kptx, kpty);

        int nbColor = 256 * 256 * 256;

        int pascoul = nbColor / matches.size();
        int coulActu = pascoul * i;

        int bleu = coulActu % 256;

        int qb = coulActu / 256;
        int vert = qb % 256;

        int rouge = qb / 256;



        circle(dst, ptkp1, 5, Scalar(rouge, vert, bleu), 2, 8, 0);
    }

    namedWindow(transparency_window, WINDOW_AUTOSIZE);
    imshow(transparency_window, dst);
}

