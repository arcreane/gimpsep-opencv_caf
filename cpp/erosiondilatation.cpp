#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;
using namespace std;


int erosiondilatation() {
    int choice;
    int morph_size = 2;
    Mat img = imread("Ressources/brossolet_pic.jpg");
    Mat erosion, dilatation;
    Mat element = getStructuringElement(
        MORPH_RECT, Size(2 * morph_size + 1,
            2 * morph_size + 1),
        Point(morph_size, morph_size));

    cout << "Type 1 for erosion, type 2 for dilatation";
    cin >> choice;
    do {
        if (choice == 1) {
            erode(img, erosion, element, Point(-1, -1), 1);
            imshow("erosion", erosion);
            waitKey();
        }
        else {
            dilate(img, dilatation, element, Point(-1, -1), 1);
            imshow("dilatation", dilatation);
            waitKey();
        }
    } while (choice != 1 && choice != 2);
    return 0;
}