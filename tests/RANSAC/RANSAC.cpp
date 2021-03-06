#include <opencv2/opencv.hpp>

#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/nonfree/features2d.hpp"
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



string transparency_window;
string matches_window;

     static vector<Point2f> obj;
     static vector<Point2f> scene;
     static vector<Point2f> scene_corners;


int thresh = 0;
int max_thresh = 100;


//seuil pour la comparaison des descripteurs
float seuil=0.5;

//rayon autour duquel on cherche les pixels autours d'un kp1
//int rayonDist = 100;

//dans keypoints1 on a les kp de l'image de gauche auxquels 
//on a apparié le meilleur pixel du voisinage correspondant

//on a appariés les pointsx de l'image gauche avec les pointsy de l'image de droite

vector < KeyPoint > keypoints1, keypoints2, pointsx, pointsy;

//puis on a vérifies qu'en appariant les pointsy avec l'image gauche, on retombait sur 
//nos pas, ce qui a formé pointsy2 et pointsx2

vector < KeyPoint > pointsy2,pointsx2; 

//les matches effectués (variable auxiliaire)
vector < DMatch > matches;

//matches en prenant en compte la distance
vector < DMatch > matchesWithDist,matchesWithDist2;

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

SimpleBlobDetector(const SimpleBlobDetector::Params ¶meters = SimpleBlobDetector::Params());

*/















 /**************************************/
 /*                                    */
 /*          LES DESCRIPTEURS          */
 /*                                    */
 /**************************************/



//SIFT

/*
 * SiftDescriptorExtractor (
     double magnification, 
     bool isNormalize = true, 
     bool recalculateAngles = true,
     int nOctaves=SIFT::CommonParams::DEFAULT_NOCTAVES, 
     int nOctaveLayers=SIFT::CommonParams::DEFAULT_NOCTAVE_LAYERS, 
     int firstOctave=SIFT::CommonParams::DEFAULT_FIRST_OCTAVE, 
     int angleMode=SIFT::CommonParams::FIRST_ANGLE
)
 *
 *mais on a:
 *SIFT(int nfeatures=0,
       int nOctaveLayers=3,
       double contrastThreshold=0.04,
       double edgeThreshold=10, 
       double sigma=1.6) 
 */

//SURF

/*
 * SurfDescriptorExtractor (int nOctaves=4, int nOctaveLayers=2, bool extended=false)
 * 
 * mais on a:
 *
 *SURF(double hessianThreshold, int nOctaves=4, int nOctaveLayers=2, bool extended=false, bool upright=false)
 */


//BRIEF
/*
 *
 *cv::BriefDescriptorExtractor::BriefDescriptorExtractor ( int bytes = 32 ) 
 *
 * // bytes is a length of descriptor in bytes. It can be equal 16, 32 or 64 bytes. 
 */
//ORB
/*
 *OrbDescriptorExtractor( ORB::PatchSize patch_size );
 *
 */




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

//fonction pour connaitre le type de donnees dans une matrice
string type2str(int type);


/**
 * @function main
 */



int main(int argc, char **argv)
{


    Ptr < DescriptorExtractor > descriptor;
    Ptr < DescriptorMatcher > matcher;



    if (argc != 6) {
	cout << "\nusage incorrect!nn";
	cout << "pathimage1 pathimage2 detectorName descriptorName matcherNamen" << endl;

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

	cout << "\n\n pour les descripteurs SIFT et SURF"<<endl;
	cout << "\n BruteForce";
	cout << "\n BruteForce-L1";

	cout << "\n\n pour les descripteurs BRIEF et ORB"<<endl;
	cout << "\n BruteForce-Hamming";
	cout << "\n FlannBased";
	cout << endl;
	cout << endl;


	exit(0);
    }



    image1 = imread(argv[1],1);


    image2 = imread(argv[2],1);



    //selection et utilisation du detecteur

    if (strcmp(argv[3], "MSER") == 0) {
	/*
	   MSER* detector = new MSER();

	   //(*detector)(image1,Mat(),keypoints1);
	   //(*detector)(image2,Mat(),keypoints2);
	 */

	MserFeatureDetector detector;
	detector.detect(image1, keypoints1);
        detector.detect(image2, keypoints2);


    }


    else if (strcmp(argv[3], "FAST") == 0) {

	FastFeatureDetector detector(50, true);
        //FastFeatureDetector detector;
	detector.detect(image1, keypoints1);
 	detector.detect(image2, keypoints2);

    }


    else if (strcmp(argv[3], "STAR") == 0) {


	StarFeatureDetector detector;
	detector.detect(image1, keypoints1);
	detector.detect(image2, keypoints2);

    }


    else if (strcmp(argv[3], "SIFT") == 0) {

	SiftFeatureDetector detector;
	detector.detect(image1, keypoints1);
	detector.detect(image2, keypoints2);
	/*
	   SIFT detector;
	   detector(image1,Mat(),keypoints1);
	 */

    }

    else if (strcmp(argv[3], "SURF") == 0) {

	SurfFeatureDetector detector;
	detector.detect(image1, keypoints1);
	detector.detect(image2, keypoints2);
	/*
	   SURF detector(100);
	   detector(image1,Mat(),keypoints1);
	 */

    }
    //maniere differente d'implementer
    else if (strcmp(argv[3], "ORB") == 0) {
	ORB detector(200);
	detector(image1, Mat(), keypoints1);
	detector(image2, Mat(), keypoints2);
	/*
	   OrbFeatureDetector detector;
	   detector.detect(image1, keypoints1);
	 */
    }


    else if (strcmp(argv[3], "HARRIS") == 0) {
	GoodFeaturesToTrackDetector detector(1000, 0.01, 1., 3, true, 0.04);
	detector.detect(image1, keypoints1);
        detector.detect(image2, keypoints2);

    } else if (strcmp(argv[3], "GFTT") == 0) {
	GoodFeaturesToTrackDetector detector;
	detector.detect(image1, keypoints1);
        detector.detect(image2, keypoints2);
    }

    else if (strcmp(argv[3], "DENSE") == 0) {
	Ptr < FeatureDetector > detector;
	detector = FeatureDetector::create("Dense");

	//DenseFeatureDetector detector(0.5);
	detector->detect(image1, keypoints1);
        detector->detect(image2, keypoints2);

    } else if (strcmp(argv[3], "SIMPLE BLOB") == 0) {
	cv::SimpleBlobDetector::Params params;
	params.minDistBetweenBlobs = 10.0;	// minimum 10 pixels between blobs
	params.filterByArea = true;	// filter my blobs by area of blob
	params.minArea = 10.0;	// min 20 pixels squared
	params.maxArea = 500.0;	// max 500 pixels squared
	SimpleBlobDetector detector(params);

	detector.detect(image1, keypoints1);
        detector.detect(image2, keypoints2);

    }


    else {

	cout << "\n detecteur inconnu" << endl;
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
	cout << endl;
	exit(0);
    }


    //selection du descripteur

    
    if (strcmp(argv[4], "BRIEF") == 0) {

	//descriptor = cv::DescriptorExtractor::create("BRIEF");
	descriptor = new BriefDescriptorExtractor(64);


    } else if (strcmp(argv[4], "ORB") == 0) {
	//descriptor = cv::DescriptorExtractor::create("ORB");
	descriptor = new OrbDescriptorExtractor();

    } else if (strcmp(argv[4], "SIFT") == 0) {
	descriptor = new SiftDescriptorExtractor();

	//descriptor = cv::DescriptorExtractor::create("SIFT");

    } else if (strcmp(argv[4], "SURF") == 0) {

	//descriptor = cv::DescriptorExtractor::create("SURF");

	descriptor = new SurfDescriptorExtractor();

    }

    /*else if(strcmp(argv[4],"CALONDER")==0){

       //descriptor = cv::DescriptorExtractor::create("SURF");

       descriptor = new CalonderDescriptorExtractor<float>();

       }
     */



    else {

	cout << "\n descripteur inconnu" << endl;
	cout << "\n liste des descripteurs possible:";
	cout << "\n SIFT";
	cout << "\n SURF";
	cout << "\n BRIEF";
	cout << "\n ORB";
	cout << "\n";

	exit(0);
    }

    if (strcmp(argv[5], "BruteForce") == 0 || strcmp(argv[5], "BruteForce-L1") == 0 || strcmp(argv[5], "BruteForce-Hamming") == 0 || strcmp(argv[5], "FlannBased") == 0) {

	matcher = cv::DescriptorMatcher::create(argv[5]);



    }

    else {
	cout << "\n apparieur inconnu" << endl;
	cout << "\n liste des apparieurs possible:";
	cout << "\n BruteForce";
	cout << "\n BruteForce-L1";
	cout << "\n BruteForce-Hamming";
	cout << "\n FlannBased";
	cout << "\n";

	exit(0);


    }
    
   


    //chaine de caractère constitué du detecteur, du descripteur et de l'extracteur
    string st1 = argv[3] + (string) " + " + argv[4] + (string) " + " + argv[5];
    string st2 = "transparence " + st1;

     

    transparency_window = st2;
    matches_window = st1;

    

    namedWindow("image1", WINDOW_AUTOSIZE);
    imshow("image1", image1);
    namedWindow("image2", WINDOW_AUTOSIZE);
    imshow("image2", image2);

    
	//matrice des descripteurs des kp1

    
    Mat descriptors1;
    

    Mat descriptors2;


    //cout << endl <<"nb de kp:"<< keypoints1.size()<<endl;


    (*descriptor).compute(image1, keypoints1, descriptors1);

    
    (*descriptor).compute(image2, keypoints2, descriptors2);


    //cout << endl <<"nb de kp:"<< keypoints1.size()<<endl;

    //matrice auxiliaire des descripteurs d'un Kp
    Mat descriptorAuxKp1;
    //descriptorAuxKp1.create(0, 0, CV_32FC1);

    //matrice des descripteurs du voisinage du Kp étudié
    Mat descriptorVois;
    //descriptorVois.create(0, 0, CV_32FC1);
     

    //pixels du voisinage d'un Kp
    vector < KeyPoint > pixelsVois;


    //nb de points reliés
    int pointCourant = 0;

    for (int i = 0; i < keypoints1.size(); i++) {
	
	//on copie la ligne i du descripteur, qui correspond aux différentes valeurs données par le descripteur pour le Keypoints[i]



       // descriptorAuxKp1.convertTo(descriptorAuxKp1, CV_8UC1);
	descriptors1.row(i).copyTo(descriptorAuxKp1);

        

//on supprime tous les pixels associés au keypoint1 precedent
	pixelsVois.erase(pixelsVois.begin(), pixelsVois.end());

	float p1x = keypoints1[i].pt.x;
	float p1y = keypoints1[i].pt.y;
       
        matcher->match(descriptorAuxKp1, descriptors2, matches);
 
        pointsx.push_back(keypoints1[i]);

        //on a trouvé le keypoints qui va le mieux
	//nrmlt on a trouvé un kp


	KeyPoint kp2 = keypoints2[matches[0].trainIdx];
        pointsy.push_back(kp2);



	matches[0].trainIdx = pointCourant;
	matches[0].queryIdx = pointCourant;

	pointCourant++;
	matchesWithDist.insert(matchesWithDist.end(), matches.begin(), matches.end());




    }				//fin du for i

//on repart dans l'autre sens. Les pixels sélectionnés sont dans pointsy









/**********************************************************************************************/

pointCourant = 0;

//la matrice des descripteurs des pixels gardés
 Mat descriptorsPixs;

 Mat descriptors2Aux;

  Mat descriptorAuxPtsx;
//attention on calcule les descripteurs de l'image 2
 (*descriptor).compute(image2, pointsy, descriptors2Aux);

 for (int i = 0; i < pointsy.size(); i++) {

	//on copie la ligne i du descripteur, qui correspond aux différentes valeurs données par le descripteur pour le pointsy[i]
	descriptors2Aux.row(i).copyTo(descriptorAuxKp1);



	float p1x = pointsy[i].pt.x;
	float p1y = pointsy[i].pt.y;


	    //on calcule le descripteur de tous les pixels retenus comme candidat
            //attention ce sont les descripteurs de image1*/

	    (*descriptor).compute(image1, pointsx, descriptorAuxPtsx);

            
	    matcher->match(descriptorAuxKp1, descriptorAuxPtsx, matches);

	    //on a trouvé le keypoints qui va le mieux
	    //nrmlt on a trouvé un kp


	    KeyPoint kpfind = pointsx[matches[0].trainIdx];

	    //il nous faut comparer les points


            if( (kpfind.pt.x == pointsx[i].pt.x)  && (kpfind.pt.y == pointsx[i].pt.y) ){

                
                matches[0].trainIdx = pointCourant;
	    	matches[0].queryIdx = pointCourant;

		//cout << endl <<matches[0].distance;
                if(abs(matches[0].distance)< seuil){
                //cout << matches[0].distance;
                 
                pointsx2.push_back(kpfind);
                pointsy2.push_back(pointsy[i]);
                
                matchesWithDist2.insert(matchesWithDist2.end(), matches.begin(), matches.end());
                pointCourant++;
                }
           }


    }				//fin du for i


/*********************************************************************************************/

//utilisation de RANSAC

     cout << pointsx2.size()<<endl;
     cout << pointsy2.size()<<endl;

     

     for(int i=0;i<pointsx2.size();i++){
         obj.push_back(pointsx2[i].pt);
         scene.push_back(pointsy2[i].pt);

     }


     Mat H = findHomography( obj,  scene, CV_RANSAC );
  
    
    
     perspectiveTransform( obj, scene_corners, H);





    cout << endl<< "nb d'appariement: " << matchesWithDist2.size() << endl;

   cout <<endl << "pb" << endl;


//ici on trie les matchesWithDist2 par distance des valeurs des descripteurs et non par distance euclidienne
   sort(matchesWithDist2.begin(), matchesWithDist2.end());
    // initial position
    // end position

    //si on veut garder les meilleurs correspondances
/*
     if(matchesWithDist.size()>500){
       matchesWithDist.erase(matchesWithDist.begin() + 500,matchesWithDist.end());
     }
*/

    Mat imageMatches;
    Mat matchesMask;
    drawMatches(image1, pointsx2,	// 1st image and its keypoints
		image2, pointsy2,	// 2nd image and its keypoints
		matchesWithDist2,	// the matches
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

void interface(int, void *)
{

 

    Mat dst;
    image1.copyTo(dst);

    ///on adapte l'importance des pixels de chaque image selon la valeur du trackbar
    for (int i = 0; i < image1.rows; i++) {
	for (int j = 0; j < image1.cols; j++) {

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

    vector < KeyPoint > keypointsKeep1, keypointsKeep2;


    for (int i = 0; i < obj.size(); i++) {


	kp1x = obj[i].x;
	kp1y = obj[i].y;
	kp2x = scene_corners[i].x;
	kp2y = scene_corners[i].y;

	kptx = kp1x * (100. - thresh) / 100. + kp2x * (thresh / 100.);
	kpty = kp1y * (100. - thresh) / 100. + kp2y * (thresh / 100.);

	Point ptkp1 = Point(kptx, kpty);

	int nbColor = 256 * 256 * 256;

	int pascoul = nbColor / matchesWithDist2.size();
	int coulActu = pascoul * i;

	int bleu = coulActu % 256;

	int qb = coulActu / 256;
	int vert = qb % 256;

	int rouge = qb / 256;



	circle(dst, ptkp1, 5, Scalar(rouge, vert, bleu), 2, 8, 0);
    }

    namedWindow(transparency_window, WINDOW_AUTOSIZE);
    imshow(transparency_window, dst);
    imwrite("trans.png", dst);
}


string type2str(int type)
{
    string r;

    uchar depth = type & CV_MAT_DEPTH_MASK;
    uchar chans = 1 + (type >> CV_CN_SHIFT);

    switch (depth) {
    case CV_8U:
	r = "8U";
	break;
    case CV_8S:
	r = "8S";
	break;
    case CV_16U:
	r = "16U";
	break;
    case CV_16S:
	r = "16S";
	break;
    case CV_32S:
	r = "32S";
	break;
    case CV_32F:
	r = "32F";
	break;
    case CV_64F:
	r = "64F";
	break;
    default:
	r = "User";
	break;
    }

    r += "C";
    r += (chans + '0');

    return r;
}


