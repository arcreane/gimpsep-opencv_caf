#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;
using namespace std;


int cannyEdgeDetection() {
    Mat img = imread("Ressources/brossolet_pic.jpg");
    Mat img_gray;
    Mat img_canny;
    Mat new_img = Mat::zeros(img.size(), img.type());
    double min_threshold, max_threshold;
    int kernel_size;
    cout << "Please choose the minimum threshold" << endl;
    cin >> min_threshold;
    cout << "Please choose the maximum threshold" << endl;
    cin >> max_threshold;
    cout << "Please choose the kernel size" << endl;
    cin >> kernel_size;

    cvtColor(img, img_gray, COLOR_BGR2GRAY);
    Canny(img_gray, img_canny, min_threshold, max_threshold, kernel_size);
    imshow("Original", img_gray);
    imshow("Result", img_canny);
    waitKey();
    return 0;

}