#include <opencv2/opencv.hpp>
#include <iostream>
#include "math.h"

using namespace cv;
Mat src, dst, map_x, map_y;
const char* OUTPUT_TITLE = "remap demo";
int t = 0;
void update_map(void);
int main(int argc, char** argv) {
	src = imread("//home//fang//下载//opencv基础代码和ppt//ORB-SLAM2-RGBD.png");
	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}
	char input_win[] = "input image";
	namedWindow(input_win, CV_WINDOW_AUTOSIZE);
	namedWindow(OUTPUT_TITLE, CV_WINDOW_AUTOSIZE);
	imshow(input_win, src);

	map_x.create(src.size(), CV_32FC1);
	map_y.create(src.size(), CV_32FC1);

	int c = 0;
	while (true) {
		c = waitKey(500);
		if ((char)c == 27) {
			break;
		}
		t = c % 4;
		update_map();
		remap(src, dst, map_x, map_y, INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 255, 255));
		imshow(OUTPUT_TITLE, dst);

		char outfile[100];
		sprintf(outfile, "//home//fang//下载//opencv基础代码和ppt//ORB-SLAM2-RGBD.png_24.png");
		imwrite(outfile, dst);

	}

	return 0;
}

void update_map(void) {
	for (int row = 0; row < src.rows; row++) {
		for (int col = 0; col < src.cols; col++) {
			//旋转１８０
//			switch (t) {
//			case 0:
//				if (col > (src.cols * 0.25) && col <= (src.cols*0.75) && row > (src.rows*0.25) && row <= (src.rows*0.75)) {
//					map_x.at<float>(row, col) = 2 * (col - (src.cols*0.25));
//					map_y.at<float>(row, col) = 2 * (row - (src.rows*0.25));
//				}
//				else {
//					map_x.at<float>(row, col) = 0;
//					map_y.at<float>(row, col) = 0;
//				}
//				break;
//			case 1:
//				map_x.at<float>(row, col) = (src.cols - col - 1);
//				map_y.at<float>(row, col) = row;
//				break;
//			case 2:
//				map_x.at<float>(row, col) = col;
//				map_y.at<float>(row, col) = (src.rows - row - 1);
//				break;
//			case 3:
//				map_x.at<float>(row, col) = (src.cols - col - 1);
//				map_y.at<float>(row, col) = (src.rows - row - 1);
//				break;
			map_x.at<float>(row, col) = (src.cols - col);//ｘ方向对调
			map_y.at<float>(row, col) = row;

//			map_x.at<float>(row, col) = col;//y方向对调
//			map_y.at<float>(row, col) = (src.rows - row);//

//			map_x.at<float>(row, col) = (src.cols - col);//x
//			map_y.at<float>(row, col) = (src.rows - row);

			}

		}
	}
//}
