#include <iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "../h/intensity.h"
#include "../h/cannyedgedetection.h"
#include "../h/panoramastitching.h"
#include "../h/resize.h"
#include "../h/erosiondilatation.h"
#include "../h/faceDetection.h"

//using namespace cv;
//using namespace std;

int main()
{
    int choice;
    int pictureNum;
    String img;
    cout << "Please choose what function you want to use. Type 1 for RESIZE | Type 2 for EROSION/DILATATION" << endl;
    cout << "Type 3 for INTENSITY | Type 4 for panorama stitching | Type 5 for cannyEdgeDetection" << endl;
    cout << "Type 6 for Face Detection" << endl;
    cin >> choice;

    if (choice != 4) {
        cout << "Select picture: type 1 for the male picture, type 2 for the female picture" << endl;
        cin >> pictureNum;
        switch (pictureNum) {
            case 1:
                img = "Ressources/homme.jpg";
                break;
            case 2:
                img = "Ressources/femme.jpg";
                break;
            default:
                return 0;
        }
    }

    if (choice == 1) {
        int height, width;
        cout << "Please choose width and height" << endl;
        cout << "Width : ";
        cin >> width;
        cout << "Height : ";
        cin >> height;
        resizeFunc(width, height, img);
    }

    if (choice == 2) {
        erosiondilatation(img);
       
    }

    if (choice == 3) {
        intensity(img);
    }

    if (choice == 4) {
        panoramastitching();
    }

    if (choice == 5) {
        cannyEdgeDetection(img);
    }

    if (choice == 6) {
        faceDetection(img);
    }
    return 0;
}
