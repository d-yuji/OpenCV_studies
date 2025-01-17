#include <cv.h>
#include <highgui.h>
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace cv;

#define _USE_MATH_DEFINES 
#define NO_GAP
int lx=  250;
int ly = 250;
// void hexagon(int x,int y,double l,double angle,Mat hsv_img);
bool hexagon(double x,double y);
int main (int argc, char **argv){
	const int w=500, h=500;
 
	// (1)create an image with specified size
#ifdef NO_GAP
	Mat img = Mat::zeros(Size(w,h), CV_8UC3);
	Mat hsv_img;
	cvtColor(img, hsv_img, CV_BGR2HSV);
#else
	Mat img = Mat::zeros(Size(w+1,h), CV_8UC3);
	cvtColor(img, img, CV_BGR2HSV);
	Rect roi_rect(0,0,w,h);
	Mat hsv_img(img, roi_rect);
#endif
	int ch = img.channels(); // =3
	std::cout << "step:" << hsv_img.step << ", size:" << w*ch << std::endl;
	double c, f = getTickFrequency()/1000;
	int width = hsv_img.cols, height = hsv_img.rows;
 
	// (2a)create hue-value gradation image
	c = getTickCount();
	for(int y=0; y<height; ++y) {
		for(int x=0; x<width; ++x) {
			int a = hsv_img.step*y+(x*ch);
			hsv_img.data[a+0] = (x*180/width);
			hsv_img.data[a+1] = 255;
			hsv_img.data[a+2] = ((height-y)*255/height);
		}
	}
	std::cout << (getTickCount()-c)/f << "\t";
 
// 	// (2b)create hue-value gradation image
// 	c = getTickCount();
// 	for(int y=0; y<height; ++y) {
// 		uchar *p = hsv_img.ptr(y);
// 		for(int x=0; x<width; ++x) {
// 			p[x*ch+0] = (x*180/width);
// 			p[x*ch+1] = 255;
// 			p[x*ch+2] = ((height-y)*255/height);
// 		}
// 	}
// 	std::cout << (getTickCount()-c)/f << "\t";
 
// 	// (2c)create hue-value gradation image
// 	c = getTickCount();
// 	if(hsv_img.isContinuous()) {
// 		width *= height;
// 		height = 1;
// 	}
// 	for(int y=0; y<height; ++y) {
// 		uchar *p = hsv_img.ptr(y);
// 		for(int x=0; x<width; ++x) {
// 			p[x*ch+0] = (x*180/width);
// 			p[x*ch+1] = 255;
// 			p[x*ch+2] = ((height-y)*255/height);
// 		}
// 	}
// 	std::cout << (getTickCount()-c)/f << "\t";
// 	width = hsv_img.cols;
// 	height = hsv_img.rows;
	 
// 	// (2d)create hue-value gradation image
// 	c = getTickCount();
// 	for(int y=0; y<height; ++y) {
// 		for(int x=0; x<width; ++x) {
// 			Vec3b &p = hsv_img.at<Vec3b>(y,x);
// 			p[0] = (x*180/width);
// 			p[1] = 255;
// 			p[2] = ((height-y)*255/height);
// 		}
// 	}
// 	std::cout << (getTickCount()-c)/f << "\t";
 
// 	// (2e)create hue-value gradation image
// 	c = getTickCount();
// 	Mat_<Vec3b>& ref_img = (Mat_<Vec3b>&)hsv_img;
// 	for(int y=0; y<height; ++y) {
// 		for(int x=0; x<width; ++x) {
// 			ref_img(y, x)[0] = (x*180/width);
// 			ref_img(y, x)[1] = 255;
// 			ref_img(y, x)[2] = ((height-y)*255/height);
// 		}
// 	}
// 	std::cout << (getTickCount()-c)/f << "\t";
 
// 	// (2f)create hue-value gradation image
// 	c = getTickCount();
// 	vector<Mat> planes;
// 	split(hsv_img, planes);
// 	MatIterator_<uchar> it_h = planes[0].begin<uchar>();
// 	MatIterator_<uchar> it_s = planes[1].begin<uchar>();
// 	MatIterator_<uchar> it_v = planes[2].begin<uchar>();
// 	for(int c=0; it_h!=planes[0].end<uchar>(); ++it_h, ++it_s, ++it_v, ++c) {
// 		*it_h = ((c%width)*180/width);
// 		*it_s = 255;
// 		*it_v = ((height-c/width)*255/height);
// 	}
// 	merge(planes, hsv_img);
// 	std::cout << (getTickCount()-c)/f << "\t";
 
// 	// (2g)create hue-value gradation image (when no-gap)
// #ifdef NO_GAP
// 	c = getTickCount();
// 	MatIterator_<Vec3b> it = hsv_img.begin<Vec3b>();
// 	for(int c=0; it!=hsv_img.end<Vec3b>(); ++it,++c) {
// 		int x=c%width;
// 		int y=c/width;
// 		(*it)[0] = (x*180/width);
// 		(*it)[1] = 255;
// 		(*it)[2] = ((height-y)*255/height);
// 	}
// 	std::cout << (getTickCount()-c)/f << "\t";
// #endif
// 	std::cout << std::endl;
	printf("%d %d\n",hsv_img.rows,hsv_img.cols);

/*	for(int y=0; y<height; ++y) {
		for(int x=0; x<width; ++x) {
			int a = hsv_img.step*y+(x*ch);
			if(x > 50 && x<100 && y > 50 && y < 100){
				hsv_img.data[a+0] = 105;
				hsv_img.data[a+1] = 255;
				hsv_img.data[a+2] = 255;
			}
		}
	}
*/
//	hexagon(0.5*w,0.5*h,200.0,40.0,hsv_img);
	for(int y = 0; y < height; ++y){
		for(int x = 0; x < width; ++x){
				int a = hsv_img.step*y+(x*ch);
			if(hexagon((double)x,(double)y) == true){
				// printf("true\n");
				hsv_img.data[a+0] = 105;
				hsv_img.data[a+1] = 255;
				hsv_img.data[a+2] = 255;
			}else{
				// printf("false\n");
				// hsv_img.data[a+0] = 0;
				// hsv_img.data[a+1] = 0;
				// hsv_img.data[a+2] = 0;
			}
		}
	}
	// (3)show created gradation image
	cvtColor(hsv_img, img, CV_HSV2BGR);
	namedWindow("Garadation", CV_WINDOW_AUTOSIZE);
	imshow("Gradation", img);
	waitKey(0);
	 
	return 0;
}
/*
void hexagon(int x,int y,double l,double ang,Mat hsv_img){
	int npt[] = {6};
	Point pt1[1][6];
	const Point *ppt[1] = {pt1[0]};

	double angle = (M_PI/180)*ang;
	double tempX,tempY;

	printf("%lf\n",angle);

	for(int i = 0;i < 6;i++){
		tempX = x + l * cos(angle + ((M_PI/3) * i));
		tempY = y + l * sin(angle + ((M_PI/3) * i));
		pt1[0][i] = Point(tempX,tempY);
	}

	for(int i =0;i<6;i++){
		printf("%d %d\n",pt1[0][i].x,pt1[0][i].y);
	}
	polylines(hsv_img, ppt, npt, 3, true, Scalar(0,0,200), 1, CV_AA,0);

	return;
}*/
bool hexagon(double x,double y){
	int l = 50;
	double root3 = sqrt(3);
	double area = 2*root3*l;

	double cheak = (2*fabs(y-ly)) + fabs((root3*(x-lx))-(y-ly)) + fabs((root3*(x-lx))+(y-ly));
	// printf("%2f %2f %4f %4f \n",x,y,area,cheak);

	if( area > cheak){
		return true;
	}else{
		return false;
	}
}