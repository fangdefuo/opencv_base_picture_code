#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
int main(int argc, char** argv) {
	Mat src, dst;
	src = imread("//home//fang//下载//opencv基础代码和ppt//test.jpg");
	if (!src.data) {
		printf("could not load image...\n");
	}
	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	imshow("input image", src);
	char output_title[] = "morphology demo";
	namedWindow(output_title, CV_WINDOW_AUTOSIZE);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(11, 11), Point(-1, -1));
	morphologyEx(src, dst, CV_MOP_BLACKHAT, kernel);
	imshow(output_title, dst);

    char outfile[100];
    sprintf(outfile, "//home//fang//下载//opencv基础代码和ppt//morphologyEx_13.jpg");
    imwrite(outfile,dst);

	waitKey(0);
	return 0;
}