//#include "opencv2/opencv.hpp"
#include <time.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
//#include <vector>
#include "../BALL_BALANCE/camera/camera.hpp"
//#include "../BALL_BALANCE/pid/pid.hpp"
#include <string>
//#include <thread>
using namespace cv;
using namespace std;


Camera camera(0);

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
	while(1)
	{
		clock_t start = clock();
		camera.getFPS_start();
		camera.getFrame();
		camera.detectBall();
	//======INIT KALMAN FILTER===================================
	// >>>> Kalman Filter
		
	//================================================
	//	camera.showCamera(0);
		if (waitKey(1) == 27)
			break;
		camera.getFPS_end();
		//cout << "MS : " << 1000 / camera.fps_ << endl;
		//printf("Time: %.2fms\n", (long double)(clock() - start)*1000 / CLOCKS_PER_SEC);
	}
}
