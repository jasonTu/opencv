/**
 * The example code descript linear blending process.
 * Author: Jason Tu
 * You can refer to the following materials:
 * http://docs.opencv.org/2.4/doc/tutorials/core/adding_images/adding_images.html#adding-images
 */
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
    double alpha = 0.5;
    double beta, input;

    Mat src1, src2, dst;

    // Warning Since we are adding src1 and src2,
    // they both have to be of the same size (width and height) and type.
    src1 = imread("img/screen1.png", CV_LOAD_IMAGE_COLOR);
    src2 = imread("img/screen2.png", CV_LOAD_IMAGE_COLOR);

    if (!src1.data || !src2.data) {
        return -1;
    }

    namedWindow("Linear blending", CV_WINDOW_AUTOSIZE);

    beta = 1.0 - alpha;
    addWeighted(src1, alpha, src2, beta, 0.0, dst);

    imshow("Linear blending", dst);

    waitKey();
    return 0;
}
