#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;
using namespace std;


int erosiondilatation(String file) {
    int choice;
    int morph_size = 2;
    Mat img = imread(file);
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

            namedWindow("Erosion", 0);
            resizeWindow("Erosion", img.size().width / 3, img.size().height / 3);
            imshow("Erosion", erosion);
            imwrite("Results/resultErosion.jpg", erosion);
            waitKey();
        }
        else {
            dilate(img, dilatation, element, Point(-1, -1), 1);

            namedWindow("Dilatation", 0);
            resizeWindow("Dilatation", img.size().width / 3, img.size().height / 3);
            imshow("Dilatation", dilatation);
            imwrite("Results/resultDilatation.jpg", dilatation);
            waitKey();
        }
    } while (choice != 1 && choice != 2);
    return 0;
}