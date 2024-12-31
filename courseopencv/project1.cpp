#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;
Mat img;
vector<vector<int>> newpoints; //{x,y,(color from colorrgb 0,1,2...)}

/////////////////   virtual painter  //////////////////////
vector<vector<int>> myColors{
	{124, 48, 117, 143, 170, 255},  // Purple
	{68, 72, 156, 102, 126, 255},  // Green
	{0, 120, 70, 10, 255, 255},    // Red
	{94, 80, 2, 126, 255, 255},    // Blue
	{22, 93, 100, 45, 255, 255},   // Yellow
	{35, 52, 72, 85, 255, 255},    // Light Green
	{0, 0, 200, 180, 30, 255}      // White
};

vector<Scalar> colorrgb{
	{255, 0, 255},  // Purple
	{0, 255, 0},    // Green
	{0, 0, 255},    // Red
	{255, 0, 0},    // Blue
	{0, 255, 255},  // Yellow
	{144, 238, 144}, // Light Green
	{255, 255, 255} // White
};



Point getContours(Mat img) {

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(img, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);

	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());
	Point mypoints(0, 0);

	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		

		if (area > 1000)
		{
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			
			boundRect[i] = boundingRect(conPoly[i]);
			mypoints.x = boundRect[i].x + boundRect[i].width/2;
			mypoints.y = boundRect[i].y;
            drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
			
		}
	}
	return mypoints;
}
vector<vector<int>> detectcolor(Mat img)
{
	Mat imgHSV;
	cvtColor(img, imgHSV, COLOR_BGR2HSV);
	for (int i = 0; i < myColors.size(); i++)
	{
		Scalar lower(myColors[i][0], myColors[i][1], myColors[i][2]);
		Scalar upper(myColors[i][3], myColors[i][4], myColors[i][5]);
		Mat mask;
		inRange(imgHSV, lower, upper, mask);
		Point mypoint = getContours(mask);
		newpoints.push_back({ mypoint.x, mypoint.y, i });
	}
	return newpoints;
}
void draw(vector<vector<int>> newpoints, vector<Scalar> colorrgb)
{
	for (int i = 0; i < newpoints.size(); i++)
	{
		circle(img, Point(newpoints[i][0], newpoints[i][1]), 10, colorrgb[newpoints[i][2]], FILLED);
	}
}

void main()
{
	VideoCapture cap(0);
	
	while (true)
	{
		cap.read(img);
		newpoints=detectcolor(img);
		draw(newpoints,colorrgb);
		imshow("img", img);
		waitKey(1);
	}
}
