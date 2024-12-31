#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////   COLOR handling  //////////////////////

void main() 
{
	
	Mat imgHSV, mask;
    string path = "Resources/lambo.png";
	Mat img = imread(path);
	cvtColor(img, imgHSV, COLOR_BGR2HSV);
	namedWindow("Trackbar", (640, 500));
	int hmin = 0, smin = 110, vmin = 153;
	int hmax = 19, smax = 255, vmax = 255;
	createTrackbar("Hue min", "Trackbar", &hmin, 179);
	createTrackbar("Saturation min ", "Trackbar", &smin, 255);
	createTrackbar("value min", "Trackbar", &vmin, 255);
	createTrackbar("Hue max", "Trackbar", &hmax, 179);
	createTrackbar("saturation max", "Trackbar", &smax, 255);
	createTrackbar("value max", "Trackbar", &vmax, 255);
	while (true)
	{
		Scalar lower(hmin, vmin, smin);
		Scalar upper(hmax, vmax, smax);
		inRange(imgHSV, lower, upper, mask);
		imshow("Image", img);
		imshow("ImageHSV", imgHSV);
		imshow("Imagemasked", mask);
		waitKey(1);
	}

}