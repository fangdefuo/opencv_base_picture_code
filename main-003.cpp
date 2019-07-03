#include<opencv2/opencv.hpp>
#include<highgui.h>
using namespace cv;
int main(int argc, char** argv)
{
	// ����ͼ��
	Mat testImage = imread("//home//fang//下载//opencv基础代码和ppt//test.jpg");
	CV_Assert(testImage.depth() == CV_8U);
	namedWindow("test_image", CV_WINDOW_AUTOSIZE);
	imshow("test_image", testImage);

	// ʹ��Filter2D����
	Mat result;
	Mat kern = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	filter2D(testImage, result, testImage.depth(), kern);

	// ��ʾ���
	namedWindow("result_image", CV_WINDOW_AUTOSIZE);
	imshow("result_image", result);
    char outfile[100];
    sprintf(outfile, "//home//fang//下载//opencv基础代码和ppt//mask_3.jpg");
    imwrite(outfile,result);

	waitKey(0);
	return 0;
}