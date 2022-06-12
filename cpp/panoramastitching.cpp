#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;
using namespace std;
Stitcher::Mode mode = Stitcher::PANORAMA;

int panoramastitching() {



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


   
    Mat pano;

    
    Ptr<Stitcher> stitcher = Stitcher::create(mode);

   
    Stitcher::Status status = stitcher->stitch(imgs, pano);

    if (status != Stitcher::OK)
    {
    
        cout << "Can't stitch images\n";
        return -1;
    }

    
    imwrite("Results/resultPanorama.jpg", pano);

    
    imshow("Result", pano);


    waitKey(0);
    return 0;
}