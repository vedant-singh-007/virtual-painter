#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////   COLOR handling  //////////////////////


void getcontours(Mat imgDil, Mat img)
{   
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	
	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		if (area > 1000)
		{
			drawContours(img, contours, i, Scalar(255, 0, 255), 2);
		}
	}

}

void main()
{

	Mat img;
	string path = "Resources/shapes.png";
	Mat imgGray, imgBlur, imgDil, imgCanny;
    img = imread(path);
	//preprocessing
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3),3,0);
	Canny(imgBlur, imgCanny, 25, 75);
	Mat kernel;
	kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);
	getcontours(imgDil,img);
	imshow("image" ,img);

	/*imshow("image blur", imgBlur);
	imshow("image gray", imgGray);
	imshow("image Canny", imgCanny);
	imshow("image dilated", imgDil);*/
    waitKey(0);
}