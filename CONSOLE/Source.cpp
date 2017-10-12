#include "opencv2/opencv.hpp"
#include <time.h>
#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <vector>
#include "../BALL_BALANCE/camera/camera.hpp"
#include "../BALL_BALANCE/pid/pid.hpp"
#include <string>
#include <thread>
using namespace cv;
using namespace std;


//int main(int argc, char** argv)
//{
//
//	// Start default camera
//	VideoCapture video(0);
//
//	// With webcam get(CV_CAP_PROP_FPS) does not work.
//	// Let's see for ourselves.
//
//	double fps = video.get(CV_CAP_PROP_FPS);
//	// If you do not care about backward compatibility
//	// You can use the following instead for OpenCV 3
//	// double fps = video.get(CAP_PROP_FPS);
//	cout << "Frames per second using video.get(CV_CAP_PROP_FPS) : " << fps << endl;
//
//
//	// Number of frames to capture
//	int num_frames = 120;
//
//	// Start and end times
//	time_t start, end;
//
//	// Variable for storing video frames
//	Mat frame;
//
//	cout << "Capturing " << num_frames << " frames" << endl;
//
//	// Start time
//	time(&start);
//
//	// Grab a few frames
//	for (int i = 0; i < num_frames; i++)
//	{
//		video >> frame;
//	}
//
//	// End Time
//	time(&end);
//
//	// Time elapsed
//	double seconds = difftime(end, start);
//	cout << "Time taken : " << seconds << " seconds" << endl;
//
//	// Calculate frames per second
//	fps = num_frames / seconds;
//	cout << "Estimated frames per second : " << fps << endl;
//
//	// Release video
//	video.release();
//	cin.get();
//	return 0;
//}
//int main(int, char**)
//{
//	VideoCapture cap(0); // open the default camera
//	if (!cap.isOpened())  // check if we succeeded
//		return -1;
//
//	Mat frame;
//	for (;;)
//	{
//		int64 start = getTickCount();
//		cap >> frame; // get a new frame from camera
//		imshow("edges", frame);
//		if (waitKey(1) == 27) break;
//		double fps = getTickFrequency() / (getTickCount() - start);
//		cout << "Frames per second : " << fps << endl;
//	}
//	// the camera will be deinitialized automatically in VideoCapture destructor
//	return 0;
//}


Camera camera(0);
PID pidX;
PID pidY;

double posX = 0;
double posY = 0;
double errX = 0;
double errY = 0;
double timeGraph = 0;
double setpointX = 0;
double setpointY = 0;
bool SCROLL_GRAPH = false;

int main(int argc, char* argv[])
{
	camera.setCropFrame(118, 11, 400, 400);
	camera.applyCropFrame();
	camera.setHSVParam(0,255, 0, 255, 0, 100);
	camera.createTrackbars();
	while (1)
	{
		camera.getFPS_start();
		camera.getFrame();
		camera.detectBall();

		//posX = camera.getX();
		//posY = camera.getY();
		//setpointX = 100;
		//setpointY = 100;
		//errX = setpointX - posX;
		//errY = setpointY - posX;
		//
		//pidX.setPIDParam(1,0,0,100);
		//pidX.setPIDPeriod(5);
		//pidX.setPIDOutputLimit(-20, 20);
		//pidX.compute(errX);

		//pidY.setPIDParam(1, 0, 0, 100);
		//pidY.setPIDPeriod(5);
		//pidY.setPIDOutputLimit(-7, 7);
		//pidY.compute(errY);

		//cout << "X : " << posX << "   PID X : " << pidX.getOutput(0) << endl;
		//cout << "Y : " << posY << "   PID Y : " << pidY.getOutput(0) << endl;

		if (waitKey(1) == 27) break;
		camera.showCamera(2);
		camera.getFPS_end();
		//cout << "FPS : " << camera.fps_ << endl;
	}
}