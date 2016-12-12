/**
 * The example code descript mask operations on matrices.
 * Author: Jason Tu
 * You can refer to the following materials:
 * http://docs.opencv.org/2.4/doc/tutorials/core/mat-mask-operations/mat-mask-operations.html#maskoperationsfilter
 * http://docs.opencv.org/2.4/_downloads/mat_mask_operations.cpp
 */
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

void sharpen(const Mat &myImage, Mat &result);

int main()
{
    Mat image, result, K;
    image = imread("img/dota.jpg", CV_LOAD_IMAGE_COLOR);

    sharpen(image, result);

    namedWindow("Original Picture", CV_WINDOW_AUTOSIZE);
    imshow("Original Picture", image);

    namedWindow("Sharpen Picture", CV_WINDOW_AUTOSIZE);
    imshow("Sharpen Picture", result);

    // 下面我们进行一个简单的滤波操作，滤波算子为[0 –1 0;-1 5 –1;0 –1 0]
    Mat kern = (Mat_<char>(3, 3) << 0, -1, 0,
        -1, 5, -1,
        0, -1, 0);

    filter2D(image, K, image.depth(), kern);

    namedWindow("Sharpen With Core", CV_WINDOW_AUTOSIZE);
    imshow("Sharpen With Core", K);

    waitKey();
    return 0;
}

void sharpen(const Mat &myImage, Mat &result)
{
    CV_Assert(myImage.depth() == CV_8U);  // Accept only uchar images

    result.create(myImage.size(), myImage.type());
    const int nChannels = myImage.channels();

    for (int j = 1; j < myImage.rows - 1; ++j) {
        const uchar* previous = myImage.ptr<uchar>(j - 1);
        const uchar* current = myImage.ptr<uchar>(j);
        const uchar* next = myImage.ptr<uchar>(j + 1);

        uchar* output = result.ptr<uchar>(j);

        for (int i = nChannels; i < nChannels * (myImage.cols - 1); ++i) {
            *output++ = saturate_cast<uchar>(5 * current[i]
                - current[i - nChannels] - current[i + nChannels]
                - previous[i] - next[i]);
        }
    }

    result.row(0).setTo(Scalar(0));
    result.row(result.rows - 1).setTo(Scalar(0));
    result.col(0).setTo(Scalar(0));
    result.col(result.cols - 1).setTo(Scalar(0));
}
