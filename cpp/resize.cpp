#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;
using namespace std;


int resizeFunc(int width, int height, String file) {
    Mat img = imread(file);
    //imshow("Original image", img);
    Mat resized;

    resize(img, resized, Size(width, height),
        INTER_LINEAR);
    imwrite("Results/resultResized.jpg", resized);

    imshow("Resized down by defining height and width", resized);
    
    waitKey();

    destroyAllWindows();
    return 0;
}