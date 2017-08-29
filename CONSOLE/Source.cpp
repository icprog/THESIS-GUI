#include "opencv2/opencv.hpp"
#include <time.h>
#include <string>
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
int main(int, char**)
{
	VideoCapture cap(0); // open the default camera
	if (!cap.isOpened())  // check if we succeeded
		return -1;

	Mat frame;
	for (;;)
	{
		int64 start = getTickCount();
		cap >> frame; // get a new frame from camera
		imshow("edges", frame);
		if (waitKey(1) == 27) break;
		double fps = getTickFrequency() / (getTickCount() - start);
		cout << "Frames per second : " << fps << endl;
	}
	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}