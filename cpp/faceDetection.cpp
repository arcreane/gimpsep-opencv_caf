#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <stdio.h>


using namespace std;
using namespace cv;

int faceDetection() {
	CascadeClassifier f_cascade;
	Mat img;
	Mat img_gray;
	img = imread("Ressources/brossolet_pic.jpg", COLOR_BGR2GRAY);
	

	f_cascade.load("HaarCascade/haarcascade_frontalface_alt.xml");
	vector<Rect> faces;
	cvtColor(img, img_gray, COLOR_BGR2GRAY);
	equalizeHist(img_gray, img_gray);
	f_cascade.detectMultiScale(img_gray, faces, 1.3, 5, 0, Size(30,30));

	for (int i = 0; i < faces.size(); i++)
	{
		Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
		ellipse(img, center, Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);
	}
	imshow("Detected Face", img);

	waitKey(0);
	return 0;
}