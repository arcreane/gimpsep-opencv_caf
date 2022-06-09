#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;
using namespace std;




int intensity() {
    int morph_size = 2;
    Mat img = imread("Ressources/brossolet_pic.jpg");

    Mat new_image = Mat::zeros(img.size(), img.type());
    double alpha = 1.0;
    int beta = 0;
    cout << "* [BRIGHTNESS] Enter the alpha value [0.1-3.0]: "; cin >> alpha;
    cout << "* [CONTRAST] Enter the beta value  [0-100]: ";    cin >> beta;
    for (int y = 0; y < img.rows; y++) {
        for (int x = 0; x < img.cols; x++) {
            for (int c = 0; c < img.channels(); c++) {
                new_image.at<Vec3b>(y, x)[c] =
                    saturate_cast<uchar>(alpha * img.at<Vec3b>(y, x)[c] + beta);
            }
        }
    }
    imshow("Original Image", img);
    imshow("New Image", new_image);
    waitKey();
    return 0;
}