/**
 * The example code descript image contrast and brightness manufacture.
 * Author: Jason Tu
 * Date: 2016-12-12  
 * You can refer to the following materials:
 * http://docs.opencv.org/2.4/doc/tutorials/core/basic_linear_transform/basic_linear_transform.html#basic-linear-transform
 */
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
    double alpha = 1.0;
    int beta = 20;

    Mat image = imread("img/lenna.jpg");
    Mat new_image = Mat::zeros(image.size(), image.type());
    Mat K;

    for (int y = 0; y < image.rows; y++) {
        for (int x = 0; x < image.cols; x++) {
            for (int c = 0; c < 3; c++) {
                new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>(
                    alpha*(image.at<Vec3b>(y,x)[c]) + beta);
            }
        }
    }

    namedWindow("Original", CV_WINDOW_AUTOSIZE);
    namedWindow("New", CV_WINDOW_AUTOSIZE);

    imshow("Original", image);
    imshow("New", new_image);

    image.convertTo(K, -1, alpha, beta);
    namedWindow("Use core function", CV_WINDOW_AUTOSIZE);
    imshow("Use core function", K);

    waitKey();
    return 0;
}
