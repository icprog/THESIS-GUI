#include "camera.hpp"

// Constructor

Camera::Camera(int id) :x_(0),
						y_(0),
						width_(640),
						height_(480),
						imgOriginal_(),
						imgHSV_(),
						imgThresholded_(),
						camera_(id),
						objMoments_(),
						objMoment01_(0.0),
						objMoment10_(0.0),
						objArea_(0.0),

						fail_(false),
						errorString_(""),

						lowH_(0),
						highH_(255),
						lowS_(0),
						highS_(255),
						lowV_(0),
						highV_(255),
						start_(0),
						fps_(0),
						myROI(0,0,width_,height_)
{
        if ( !camera_.isOpened() )  // If not success, exit program
        {
                this->setFail();
                this->setErrorStr( "Failed to open camera." );
        }
}

// Destructor
Camera::~Camera()
{
	width_ = -1;
	height_ = -1;
    x_ = -1;
    y_ = -1;

    camera_.~VideoCapture();

    imgOriginal_.~Mat();
    imgHSV_.~Mat();
    imgThresholded_.~Mat();

    objMoments_.~Moments();
    objMoment01_ = -1;
    objMoment10_ = -1;
    objArea_     = -1;

    fail_ = true;
    errorString_ = "";
}

void
Camera::setSize(int width, int height)
{
	width_ = width;
	height_ = height;
	camera_.set(CV_CAP_PROP_FRAME_WIDTH, width_);
	camera_.set(CV_CAP_PROP_FRAME_HEIGHT, height_);
	MAX_OBJECT_AREA = height_*width_ * 2 / 3;
}
void
Camera::getFrame()
{
    int ret = 0;
    ret = camera_.read(imgFullframe_); // Reading new frame from video stream
#ifdef DEBUG
	cv::imshow("Input data", imgFullframe_);
#endif // DEBUG

	//cv::flip(imgOriginal_, imgOriginal_, 1);
	imgFullframe_(myROI).copyTo(imgOriginal_);
    if ( !ret )
    {
            this->setFail();
            this->setErrorStr( "Failed to read frame from video stream." );
            return;
    }
#ifdef DEBUG
	cv::imshow("Input data cut", imgOriginal_);
#endif // DEBUG

}
void
Camera::detectBall()
{
	cv::cvtColor(imgOriginal_,imgHSV_,cv::COLOR_BGR2HSV);
	//filter HSV image between values and store filtered image to
	//threshold matrix
#ifdef DEBUG
	cv::imshow("HSV", imgHSV_);
#endif // DEBUG

	cv::inRange(imgHSV_,cv::Scalar(lowH_,lowS_,lowV_),cv::Scalar(highH_,highS_,highV_),imgThresholded_);
#ifdef DEBUG
	cv::imshow("HSV filter", imgThresholded_);
#endif // DEBUG
	//perform morphological operations on thresholded image to eliminate noise
	//and emphasize the filtered object(s)
	morphOps(imgThresholded_);
	//pass in thresholded frame to our object tracking function
	//this function will return the x and y coordinates of the
	//filtered object
	trackFilteredObject(x_,y_,imgThresholded_,imgFullframe_);
	//show frames
}
void
Camera::showCamera(int id)
{
	//rectangle(img, textOrg + Point(0, baseline),textOrg + Point(textSize.width, -textSize.height),Scalar(0, 0, 255));
	rectangle(imgFullframe_, cv::Point(myROI.x, myROI.y), cv::Point(myROI.x+ myROI.width, myROI.y+ myROI.height), cv::Scalar(255, 0, 0),2);
	putText(imgFullframe_, "X : " + intToString((int)x_), cv::Point(0, 60), 2, 1, cv::Scalar(0, 255, 0), 2);
	putText(imgFullframe_, "Y : " + intToString((int)y_), cv::Point(0, 90), 2, 1, cv::Scalar(0, 255, 0), 2);
	putText(imgFullframe_, "FPS : " + intToString((int)fps_), cv::Point(0, 30), 2, 1, cv::Scalar(0, 255, 0), 2);
	if(id == 0 || id==2)
		cv::imshow("Threshold", imgThresholded_); // Showing the original image
	if(id == 1 || id == 2)
		cv::imshow("Original", imgFullframe_); // Showing the original image		
}
void
Camera::unshowCamera(int id)
{
	if (id == 0)
		cv::destroyWindow("Threshold");
	else if (id == 1)
		cv::destroyWindow("Original");
	else if (id == 2)
		cv::destroyAllWindows();
}
int
Camera::getX()
{
        return x_;
}

int
Camera::getY()
{
        return y_;
}

void
Camera::setFail()
{
        fail_ = true;
}

bool
Camera::fail()
{
        return fail_;
}

void
Camera::setErrorStr( std::string errorString)
{
        errorString_ = errorString;
}

std::string
Camera::getErrorStr()
{
        return errorString_;
}
void 
Camera::drawObject(int x, int y, cv::Mat &frame) {

	//use some of the openCV drawing functions to draw crosshairs
	//on your tracked image!

	//UPDATE:JUNE 18TH, 2013
	//added 'if' and 'else' statements to prevent
	//memory errors from writing off the screen (ie. (-25,-25) is not within the window!)

	circle(frame, cv::Point(x + myROI.x, y + myROI.y), 30, cv::Scalar(0, 255, 0), 5);
	circle(frame, cv::Point(x + myROI.x, y + myROI.y), 1, cv::Scalar(0, 255, 0), 2);

}
void 
Camera::morphOps(cv::Mat &thresh) {

	//create structuring element that will be used to "dilate" and "erode" image.
	//the element chosen here is a 3px by 3px rectangle

	cv::Mat erodeElement = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
	//dilate with larger element so make sure object is nicely visible
	cv::Mat dilateElement = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(10, 10));

	erode(thresh, thresh, erodeElement);
#ifdef DEBUG
	cv::imshow("Erosion 1", thresh);
#endif // DEBUG
	erode(thresh, thresh, erodeElement);
//#ifdef DEBUG
//	cv::imshow("Erosion 2", thresh);
//#endif // DEBUG
//	dilate(thresh, thresh, dilateElement);
//#ifdef DEBUG
//	cv::imshow("Dilation 1", thresh);
//#endif // DEBUG
	dilate(thresh, thresh, dilateElement);
#ifdef DEBUG
	cv::imshow("Diation 2", thresh);
#endif // DEBUG
}
void 
Camera::trackFilteredObject(int &x, int &y, cv::Mat threshold, cv::Mat &cameraFeed) {

	cv::Mat temp;
	threshold.copyTo(temp);
	//these two vectors needed for output of findContours
	std::vector< std::vector<cv::Point> > contours;
	std::vector<cv::Vec4i> hierarchy;
	//find contours of filtered image using openCV findContours function
	findContours(temp, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
	//use moments method to find our filtered object
	double refArea = 0;
	bool objectFound = false;
	this->setErrorStr("Not detect object");
	if (hierarchy.size() > 0) {
		int numObjects = (int)hierarchy.size();
		//if number of objects greater than MAX_NUM_OBJECTS we have a noisy filter
		if (numObjects<MAX_NUM_OBJECTS) {
			for (int index = 0; index >= 0; index = hierarchy[index][0]) {

				cv::Moments moment = moments((cv::Mat)contours[index]);
				double area = moment.m00;

				//if the area is less than 20 px by 20px then it is probably just noise
				//if the area is the same as the 3/2 of the image size, probably just a bad filter
				//we only want the object with the largest area so we safe a reference area each
				//iteration and compare it to the area in the next iteration.
				if (area>MIN_OBJECT_AREA && area<MAX_OBJECT_AREA && area>refArea) {
					x = (int)(moment.m10 / area);
					y = (int)(moment.m01 / area);
					objectFound = true;
					refArea = area;
				}
				else objectFound = false;
			}
			//let user know you found an object
			if (objectFound == true) 
			{
				//putText(cameraFeed, "Tracking Object", cv::Point(0, 10), 2, 1, cv::Scalar(0, 255, 0), 2);
				this->setErrorStr("Tracking Object");
				//draw object location on screen
				drawObject(x, y, cameraFeed);
			}
		}
		else putText(cameraFeed, "TOO MUCH NOISE! ADJUST FILTER", cv::Point(0, 50), 1, 2, cv::Scalar(0, 0, 255), 2);
	}
}
std::string 
Camera::intToString(int number) {
	std::stringstream ss;
	ss << number;
	return ss.str();
}

void 
Camera::createTrackbars(){
	//create window for trackbars
    cv::namedWindow("TB",0);
	//create memory to store trackbar name on window
	/*char TrackbarName[50];
	sprintf( TrackbarName, "H_MIN", lowH_);
	sprintf( TrackbarName, "H_MAX", highH_);
	sprintf( TrackbarName, "S_MIN", lowS_);
	sprintf( TrackbarName, "S_MAX", highS_);
	sprintf( TrackbarName, "V_MIN", lowV_);
	sprintf( TrackbarName, "V_MAX", highV_);*/
	//create trackbars and insert them into window
	//3 parameters are: the address of the variable that is changing when the trackbar is moved(eg.H_LOW),
	//the max value the trackbar can move (eg. H_HIGH), 
	//and the function that is called whenever the trackbar is moved(eg. on_trackbar)
	//                                  ---->    ---->     ---->      
    cv::createTrackbar( "H_MIN", "TB", &lowH_, 255);
    cv::createTrackbar( "H_MAX", "TB", &highH_, 255);
    cv::createTrackbar( "S_MIN", "TB", &lowS_, 255);
    cv::createTrackbar( "S_MAX", "TB", &highS_, 255);
    cv::createTrackbar( "V_MIN", "TB", &lowV_, 255);
    cv::createTrackbar( "V_MAX", "TB", &highV_, 255);
	cv::createTrackbar("X", "TB", &myROI.x, width_/2);
	cv::createTrackbar("Y", "TB", &myROI.y, height_/2);
	cv::createTrackbar("WIDTH", "TB", &myROI.width, width_);
	cv::createTrackbar("HEIGHT", "TB", &myROI.height, height_);
}


void
Camera::setHSVParam(int lowH, int highH, int lowS, int highS, int lowV, int highV)
{
	lowH_ = lowH;
	highH_ = highH;
	lowS_ = lowS;
	highS_ = highS;
	lowV_ = lowV;
	highV_ = highV;
}

void Camera::setCropFrame(int PointX, int PointY, int width, int height)
{
	xcrop_ = PointX;
	ycrop_ = PointY;
	widthcrop_ = width;
	heightcrop_ = height;
}
void Camera::callback_func(int, void* ptr)
{
	Camera *tmp = (Camera*)ptr;
	tmp->applyCropFrame();
}

void Camera::applyCropFrame()
{
	myROI.x = xcrop_;
	myROI.y = ycrop_;
	myROI.width = widthcrop_;
	myROI.height = heightcrop_;
}

void
Camera::getFPS_end()
{
	//fps_ = (long double)(clock() - start_2) * 1000 / CLOCKS_PER_SEC;
	//fps_ = 1 / fps_;
	fps_ = cv::getTickFrequency() / (cv::getTickCount() - start_);
}
void
Camera::getFPS_start()
{
	//start_2 = clock();
	start_ = cv::getTickCount();
}