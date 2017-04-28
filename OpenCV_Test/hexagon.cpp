#include <cv.h>
#include <highgui.h>
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace cv;

#define _USE_MATH_DEFINES 
#define NO_GAP

// void hexagon(int x,int y,double l,double angle,Mat hsv_img);
bool hexagon(double x,double y,int l,int lx,int ly);

int main (int argc, char **argv){
	const int w = 500, h = 500;


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
	int ch = img.channels();
	int width = hsv_img.cols;
	int height = hsv_img.rows;


	for(int y = 0; y < height; ++y){
		for(int x = 0; x < width; ++x){
			int a = hsv_img.step*y+(x*ch);
			if(hexagon((double)x,(double)y,200,w/2,h/2)){
				hsv_img.data[a+0] = 105;
				hsv_img.data[a+1] = 255;
				hsv_img.data[a+2] = 255;
			}
		}
	}
	//	hexagon(0.5*w,0.5*h,200.0,40.0,hsv_img);
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


	for(int i = 0;i < 6;i++){
		tempX = x + l * cos(angle + ((M_PI/3) * i));
		tempY = y + l * sin(angle + ((M_PI/3) * i));
		pt1[0][i] = Point(tempX,tempY);
	}

	// for(int i =0;i<6;i++){
	// 	printf("%d %d\n",pt1[0][i].x,pt1[0][i].y);
	// }
	polylines(hsv_img, ppt, npt, 3, true, Scalar(0,0,200), 1, CV_AA,0);

	return;
}*/
bool hexagon(double x,double y,int l,int lx,int ly){
	double root3 = sqrt(3);
	double area = 2*root3*l;

	double check = (2*fabs(y-ly)) + fabs((root3*(x-lx))-(y-ly)) + fabs((root3*(x-lx))+(y-ly));

	if(area > check){
		return true;
	}else{
		return false;
	}
}