#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>

using namespace cv;
Mat src, gray_src, dst;
int threshold_value = 127;
int threshold_max = 255;
int type_value = 2;
int type_max = 4;
const char* output_title = "binary image";
void Threshold_Demo(int, void*);
int main(int argc, char** argv) {
	src = imread("//home//fang//下载//opencv基础代码和ppt//test.jpg");
	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	namedWindow(output_title, CV_WINDOW_AUTOSIZE);
	imshow("input image", src);
	
	createTrackbar("Threshold Value:", output_title, &threshold_value, threshold_max, Threshold_Demo);
	createTrackbar("Type Value:", output_title, &type_value, type_max, Threshold_Demo);
	Threshold_Demo(0, 0);

	waitKey(0);
	return 0;
}

void Threshold_Demo(int, void*) {
	cvtColor(src, gray_src, CV_BGR2GRAY);
	threshold(src, dst, 0, 255, THRESH_TRIANGLE );
	imshow(output_title, dst);

	char outfile[100];
	sprintf(outfile, "//home//fang//下载//opencv基础代码和ppt//createTrackbar_16.jpg");
	imwrite(outfile,dst);
}