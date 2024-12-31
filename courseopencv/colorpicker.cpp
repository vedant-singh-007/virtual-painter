#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////   COLOR handling  //////////////////////
Mat imgHSV, mask, img;

int hmin = 0, smin = 0, vmin = 0;
int hmax = 179, smax = 255, vmax = 255;
VideoCapture cap(0);
void main()
{   
	namedWindow("Trackbar", (640, 500));
	int hmin = 0, smin = 0, vmin = 0;
	int hmax = 179, smax = 255, vmax = 255;
	createTrackbar("Hue min", "Trackbar", &hmin, 179);
	createTrackbar("Saturation min ", "Trackbar", &smin, 255);
	createTrackbar("value min", "Trackbar", &vmin, 255);
	createTrackbar("Hue max", "Trackbar", &hmax, 179);
	createTrackbar("saturation max", "Trackbar", &smax, 255);
	createTrackbar("value max", "Trackbar", &vmax, 255);
	while (true)
	{
		cap.read(img);
		cvtColor(img, imgHSV, COLOR_BGR2GRAY);
		Scalar lower(hmin, vmin, smin);
		Scalar upper(hmax, vmax, smax);
		inRange(imgHSV, lower, upper, mask);
		imshow("Image", img);
        imshow("Imagemasked", mask);
		waitKey(1);
	}
}
	