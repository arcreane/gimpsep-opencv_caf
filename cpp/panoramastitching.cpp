#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;
using namespace std;
Stitcher::Mode mode = Stitcher::PANORAMA;

int panoramastitching() {

    // Get all the images that need to be
    // stitched as arguments from command line

    vector<Mat> imgs;
    Mat img = imread("Ressources/1.jpg");
    Mat img2 = imread("Ressources/2.jpg");
    Mat img3 = imread("Ressources/3.jpg");
    Mat img4 = imread("Ressources/4.jpg");
    Mat img5 = imread("Ressources/5.jpg");
    Mat img6 = imread("Ressources/6.jpg");
    Mat img7 = imread("Ressources/7.jpg");
    Mat img8 = imread("Ressources/8.jpg");
    imgs.push_back(img);
    imgs.push_back(img2);
    imgs.push_back(img3);
    imgs.push_back(img4);
    imgs.push_back(img5);
    imgs.push_back(img6);
    imgs.push_back(img7);
    imgs.push_back(img8);


    // Define object to store the stitched image
    Mat pano;

    // Create a Stitcher class object with mode panoroma
    Ptr<Stitcher> stitcher = Stitcher::create(mode);

    // Command to stitch all the images present in the image array
    Stitcher::Status status = stitcher->stitch(imgs, pano);

    if (status != Stitcher::OK)
    {
        // Check if images could not be stitched
        // status is OK if images are stitched successfully
        cout << "Can't stitch images\n";
        return -1;
    }

    // Store a new image stitched from the given
    //set of images as "result.jpg"
    imwrite("Results/result.jpg", pano);

    // Show the result
    imshow("Result", pano);

    waitKey(0);
    return 0;
}