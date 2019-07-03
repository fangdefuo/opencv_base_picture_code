#include <opencv2/opencv.hpp> 
#include <iostream> 
using namespace cv;

int main(int argc, char** argv) {
	Mat src, dst;
	src = imread("//home//fang//下载//opencv基础代码和ppt//test.jpg");
	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}
	char input_title[] = "input image";
	char output_title[] = "blur image";
	namedWindow(input_title, CV_WINDOW_AUTOSIZE);
	namedWindow(output_title, CV_WINDOW_AUTOSIZE);
	imshow(input_title, src);

	blur(src, dst, Size(11, 11), Point(-1, -1));
	imshow(output_title, dst);

	Mat gblur;
	GaussianBlur(src, gblur, Size(11, 11), 11, 11);
	imshow("gaussian blur", gblur);

	char outfile[100];
	sprintf(outfile, "//home//fang//下载//opencv基础代码和ppt//Blur_10.jpg");
	imwrite(outfile,gblur);

	waitKey(0);
	return 0;
}