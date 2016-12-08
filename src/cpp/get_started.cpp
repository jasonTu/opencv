#include <stdio.h>
#include <stdlib.h>
#include "opencv2/opencv.hpp"

using namespace cv;

int main()
{
    Mat picture = imread("img/affine_transf.png",  CV_LOAD_IMAGE_COLOR);
    imshow("testing", picture);
    waitKey(6000);
}
