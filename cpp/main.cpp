#include <iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "../h/intensity.h"
#include "../h/cannyedgedetection.h"
#include "../h/panoramastitching.h"
#include "../h/resize.h"
#include "../h/erosiondilatation.h"

//using namespace cv;
//using namespace std;

int main()
{
    int choice;
    cout << "Please choose what function you want to use. Type 1 for RESIZE | Type 2 for EROSION/DILATATION" << endl;
    cout << "Type 3 for INTENSITY | Type 4 for panorama stitching | Type 5 for cannyEdgeDetection" << endl;
    cin >> choice;

    if (choice == 1) {
        int height, width;
        cout << "Please choose width and height" << endl;
        cout << "Width : ";
        cin >> width;
        cout << "Height : ";
        cin >> height;
        resize(width, height);
    }

    if (choice == 2) {
        erosiondilatation();
    }

    if (choice == 3) {
        intensity();
    }

    if (choice == 4) {
        panoramastitching();
    }

    if (choice == 5) {
        cannyEdgeDetection();
    }

    return 0;
}
