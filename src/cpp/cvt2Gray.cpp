#include <cv.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;

int main()
{
    Mat image = imread("img/dota.jpg");
    Mat gray_image;
    cvtColor(image, gray_image, CV_BGR2GRAY);

    namedWindow("original", CV_WINDOW_AUTOSIZE);
    namedWindow("gray picture", CV_WINDOW_AUTOSIZE);

    imshow("original", image);
    imshow("gray picture", gray_image);

    waitKey();

    return 0;
}
