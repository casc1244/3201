#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	cv::Mat binaryMat;
	cv::Mat ErodeMat;
	cv::Mat DilateMat;
	cv::Mat OpenMat;
	cv::Mat CloseMat;
	cv::Mat srcMat = imread("D:\\360downloads\\4.png", 0);
	cv::Mat kernel;
	kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	cv::threshold(srcMat, binaryMat, 0, 255, THRESH_OTSU);
	cv::morphologyEx(binaryMat, ErodeMat, 0, kernel);
	cv::morphologyEx(binaryMat, DilateMat, 1, kernel);
	cv::morphologyEx(binaryMat, OpenMat, 2, kernel);
	cv::morphologyEx(binaryMat, CloseMat, 3, kernel);
	imshow("ErodeMat", ErodeMat);
	imshow("DilateMat", DilateMat);
	imshow("OpenMat", OpenMat);
	imshow("CloseMat", CloseMat);
	waitKey(0);
	return 0;
}
