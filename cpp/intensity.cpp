#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;
using namespace std;




int intensity(String file) {
    int morph_size = 2;
    Mat img = imread(file);

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
    namedWindow("Original image", 0);
    namedWindow("New image", 0);
    resizeWindow("Original image", img.size().width/3, img.size().height/3);
    resizeWindow("New image", img.size().width / 3, img.size().height / 3);

    imshow("Original image", img);
    imshow("New image", new_image);
    
    imwrite("Results/resultIntensity.jpg", new_image);
    waitKey();
    return 0;
}