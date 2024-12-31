#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include<opencv2/objdetect.hpp>

using namespace cv;
using namespace std;


/////////////////   FACE DETECTION  //////////////////////

void main()
{

	string path = "C:/Users/HP/Pictures/WhatsApp Image 2024-12-26 at 20.35.07_850cbf29.jpg";
	Mat img = imread(path);
	Mat resizedImg;
	resize(img, resizedImg, Size(), 0.5, 0.5); // Adjust the scaling as needed
	

	CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");
	vector<Rect> faces;
	faceCascade.detectMultiScale(resizedImg, faces, 1.05, 9);
	for (int i = 0; i < faces.size(); i++)
	{
		rectangle(resizedImg, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 2);
    }
	for ( int i = 0; i < faces.size(); i++) {
		cout << "Face " << i + 1 << ": " << faces[i] << endl;
	}

	imshow("face", resizedImg);
	waitKey(0);
}
