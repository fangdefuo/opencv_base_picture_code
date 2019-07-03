#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
int main(int argc, char** argv) {
	Mat src, dst;
	src = imread("//home//fang//下载//opencv基础代码和ppt//test.jpg");
	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}

	cvtColor(src, src, CV_BGR2GRAY);
	equalizeHist(src, dst);
	char INPUT_T[] = "input image";
	char OUTPUT_T[] = "result image";
	namedWindow(INPUT_T, CV_WINDOW_AUTOSIZE);
	namedWindow(OUTPUT_T, CV_WINDOW_AUTOSIZE);

	imshow(INPUT_T, src);
	imshow(OUTPUT_T, dst);

    char outfile[100];
    sprintf(outfile, "//home//fang//下载//opencv基础代码和ppt//equalizeHist_25.jpg");
    imwrite(outfile, dst);

	waitKey(0);
	return 0;
}