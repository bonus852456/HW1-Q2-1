

#include "stdafx.h"
#include <iostream>
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main(){

	cv::Mat image;
	image = cv::imread("../image/view.jpg");   // Read the file
	uchar *pixptr;
	if(image.empty()){
		std::cout << "�Ϥ������FQQ";
		system ("pause");
		return 0;
	}
	int x, y,p,q,r,c,m,n;
	//cout << image.rows<<endl;  //686��
	//cout << image.cols << endl; //1024��
	x = image.rows / 2;
	y = image.cols / 40;
	m = image.cols / 2;
	r = image.rows-y;	
	c = image.cols-y;
	for(int i=0; i<image.rows; i++){
		pixptr = image.ptr<uchar>(i);
		for(int j=0; j<image.cols; j++){
			if (j < y && i < x){						//���W
				p = i + 1;
				q = j + 1;
				pixptr[0] = pixptr[0] * p / x;
				pixptr[1] = pixptr[1] * p / x;
				pixptr[2] = pixptr[2] * p / x;
				pixptr += 3;
			}
			else if (j > c && i < x){				   //�k�W
				p = i + 1;
				q = j + 1;
				pixptr[0] = pixptr[0] * p / x ;
				pixptr[1] = pixptr[1] * p / x ;
				pixptr[2] = pixptr[2] * p / x ;
				pixptr += 3;
			}
			else if (j < y && i > x){				  //���U
				p = i + 1;
				q = j + 1;
				pixptr[0] = pixptr[0] * x / p ;
				pixptr[1] = pixptr[1] * x / p;
				pixptr[2] = pixptr[2] * x / p ;
				pixptr += 3;
			}
			else if (j > c && i > x){				  //�k�U
				p = i + 1;
				q = j + 1;
				pixptr[0] = pixptr[0] * x / p ;
				pixptr[1] = pixptr[1] * x / p ;
				pixptr[2] = pixptr[2] * x / p ;
				pixptr += 3;
			}
			else if (j < m && i > r){				   //�U��
				p = i + 1;
				q = j + 1;
				pixptr[0] = pixptr[0] *q / m;
				pixptr[1] = pixptr[1] *q / m;
				pixptr[2] = pixptr[2] *q / m;
				pixptr += 3;
			}
			else if (j < m && i < y){				   //�W��
				p = i + 1;
				q = j + 1;
				pixptr[0] = pixptr[0] * q / m;
				pixptr[1] = pixptr[1] * q / m;
				pixptr[2] = pixptr[2] * q / m;
				pixptr += 3;
			}
			else if (j > m && i > r){				   //�U�k
				p = i + 1;
				q = j + 1;
				pixptr[0] = pixptr[0] * m / q;
				pixptr[1] = pixptr[1] * m / q;
				pixptr[2] = pixptr[2] * m / q;
				pixptr += 3;
			}
			else if (j > m && i <y ){				   //�W�k
				p = i + 1;
				q = j + 1;
				pixptr[0] = pixptr[0] * m / q;
				pixptr[1] = pixptr[1] * m / q;
				pixptr[2] = pixptr[2] * m / q;
				pixptr += 3;
			}
			else{
				pixptr[0] = pixptr[0] * 1;
				pixptr[1] = pixptr[1] * 1;
				pixptr[2] = pixptr[2] * 1;
				pixptr += 3;
			}
		}
		
	}

	cv::imwrite("../image/Result1.png", image);
	cv::imshow("Traverse result", image);
    cv::waitKey(0);
	return(0);
}