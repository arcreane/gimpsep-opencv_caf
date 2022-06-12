#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;
using namespace std;


int cannyEdgeDetection(String file) {
    Mat img = imread(file);
    Mat img_gray;
    Mat img_canny;
    Mat new_img = Mat::zeros(img.size(), img.type());
    
    cvtColor(img, img_gray, COLOR_BGR2GRAY);
    Canny(img_gray, img_canny, 100,200);

    namedWindow("Original", 0);
    namedWindow("Result", 0);

    resizeWindow("Original", img.size().width / 3, img.size().height / 3);
    resizeWindow("Result", img.size().width / 3, img.size().height / 3);
    imshow("Original", img_gray);
    imshow("Result", img_canny);
    imwrite("Results/resultCannyEdge.jpg", img_canny);

    waitKey();
    return 0;

}