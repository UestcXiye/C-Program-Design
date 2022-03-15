
#include "cv.h"

#include "highgui.h"

#include <cstdio>



//read the img data from the Memory to own array

void ReadImageData(unsigned char *src, int rows, int cols, int width_step, unsigned char ** &dst)

{

	int count = 0;

	for (int i = 0; i < cols; ++i)

	{

		for (int j = 0; j < rows; ++j)

		{

			// printf("%c\n", *((unsigned char*)dst + rows * i + j));

			// *((unsigned char*)dst + rows * i + j) = src[count];

			dst[i][j] = src[count];

			count++;

		}

	}

	printf("%d\n", count);

	return;

}

//将用户自己数组存储的输入拷贝到图像相应的内存位置

//write the img data ( my array) to the memory

void WriteImageData(unsigned char *src, int rows, int cols, int width_step, unsigned char ** &dst, bool flag)

{

	int count = 0;

	for (int i = 0; i < cols; ++i)

	{

		for (int j = 0; j < rows; ++j)

		{

			if (flag) src[count] = dst[i][j];

			else src[count] = (unsigned char)'a';

			count++;

		}

	}

	printf("%d\n", count);



	return;

}



int main(int args, char * argv[])

{

	//	double PI = 0.0;

		//设定图片的大小

	int width = 500;

	int height = 500;

	//利用opencv创建一个 空的图片图像

	IplImage* img = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 1);

	unsigned char *img_data = (unsigned char *)(img->imageData);

	//获得 一行 大小

	int width_step = img->widthStep;



	//动态创建 正方形的 二维数组  边长为width

	unsigned char **array_of_img;

	array_of_img = new unsigned char *[width_step];

	array_of_img[0] = new unsigned char[width_step * width_step];



	//为每一行 分配地址

	for (int i = 1; i < width_step; ++i)

	{

		array_of_img[i] = array_of_img[i - 1] + width_step;

	}

	//初始化动态 声明的二维数组 0，即黑色

	for (int k = 0; k < width_step; ++k)

	{

		for (int j = 0; j < width_step; ++j)

		{

			array_of_img[k][j] = 0;

		}

	}

	//将数组的数据写入到内存相应的位置

	WriteImageData(img_data, width_step, width_step, width_step, array_of_img, true);

	//画圆

	cvCircle(img, cvPoint(250, 250), 250, cvScalar(255), 1, 8, 0);



	cvNamedWindow("Image", CV_WINDOW_AUTOSIZE);//创建窗口

	cvShowImage("Image", img);//显示图像

	cvWaitKey(0); //等待按键，开始采样随机点



	int sumSquare = 10000;

	int sumCircle = 0;



	double PI = 0.0;

	//generate 100 point(x,y)

	for (int count = 0; count < sumSquare; ++count)

	{

		//数组中所有非零元素的值减5 使颜色变暗

		for (int n = 0; n < width_step; ++n)

		{

			for (int m = 0; m < width_step; ++m)

			{

				if (array_of_img[m][n] > 0)

				{

					array_of_img[m][n] -= 5;

				}

			}

		}

		//产生一个(0,1)之间的 随机点

		double numA = (double)(rand()) / (double)(RAND_MAX);

		double numB = (double)(rand()) / (double)(RAND_MAX);



		//将[0,1]的点 放大到 [0,500] 之间

		int Px = (int)(numA * 500);

		int Py = (int)(numB * 500);

		//标示 刚生成的点

		array_of_img[Px][Py] = 255;

		// 把数组写入图像中

		WriteImageData(img_data, width_step, width_step, width_step, array_of_img, true);

		//重新绘制内切圆

		cvCircle(img, cvPoint(250, 250), 250, cvScalar(255), 1, 8, 0);



		//判断刚生成的点 是否在 园内

		if (((numA - 0.5)*(numA - 0.5) + (numB - 0.5)*(numB - 0.5)) <= 0.25)

		{

			sumCircle++;

		}

		cvShowImage("Image", img);//显示图像

		cvWaitKey(50); //延时50毫秒



		PI = (double)sumCircle / (double)count;

		PI *= 4;

		printf("%d %d\n", sumCircle, count);

		printf("The PI is : %lf\n", PI);

	}

	PI = (double)sumCircle / (double)sumSquare;

	PI *= 4;

	printf("The PI is : %lf\n", PI);

	cvDestroyWindow("Image");//销毁窗口

	cvReleaseImage(&img); //释放图像



	delete[] array_of_img[0];

	delete[] array_of_img;



	return 0;

}
