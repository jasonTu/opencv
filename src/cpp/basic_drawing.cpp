/**
 * The example code descript basic drawing with OpenCV.
 * Author: Jason Tu
 * Date: 2016-12-12
 * You can refer to the following materials:
 * http://docs.opencv.org/2.4/doc/tutorials/core/basic_geometric_drawing/basic_geometric_drawing.html#drawing-1
 * https://github.com/opencv/opencv/blob/master/samples/cpp/tutorial_code/core/Matrix/Drawing_1.cpp#L135
 */
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#define W 400

using namespace cv;

void MyEllipse(Mat img, double angle);
void MyFilledCircle(Mat img, Point center);
void MyPolygon(Mat img);
void MyLine(Mat img, Point start, Point end);

int main()
{
    char atom_window[] = "Drawing 1: Atom";
    char rook_window[] = "Drawing 2: Rook";

    Mat atom_image = Mat::zeros(W, W, CV_8UC3);
    Mat rook_image = Mat::zeros(W, W, CV_8UC3);

    // Create atom
    MyEllipse(atom_image, 90);
    MyEllipse(atom_image, 0);
    MyEllipse(atom_image, 45);
    MyEllipse(atom_image, -45);

    MyFilledCircle(atom_image, Point(W / 2, W / 2));

    // Create Rook
    MyPolygon(rook_image);

    rectangle(rook_image, Point(0, 7 * W / 8), Point(W, W), 
        Scalar(0, 255, 255), FILLED, LINE_8);

    MyLine(rook_image, Point(0, 15 * W / 16), Point(0, 15 * W / 16));
    MyLine(rook_image, Point(W / 4, 7 * W / 8), Point(W / 4, W));
    MyLine(rook_image, Point(W / 2, 7 * W / 8), Point(W / 2, W));
    MyLine(rook_image, Point(3 * W / 4, 7 * W / 8), Point(3 * W / 4, W));

    // Display atom and rook
    imshow(atom_window, atom_image);
    moveWindow(atom_window, 0, 200);
    imshow(rook_window, rook_image);
    moveWindow(rook_window, W, 200);

    waitKey();
    return 0;
}

void MyEllipse(Mat img, double angle)
{
    int thickness = 2;
    int line_type = 8;

    ellipse(img, Point(W / 2, W / 2), Size(W / 4, W / 16), angle, 0,
        360, Scalar(255, 0, 0), thickness, line_type);
}

void MyFilledCircle(Mat img, Point center)
{
    circle(img, center, W / 32, Scalar(0, 0, 255), FILLED, LINE_8);
}

void MyPolygon(Mat img)
{
    int line_type = LINE_8;

    Point rook_points[1][20];
    rook_points[0][0] = Point(W / 4, 7 * W / 8);
    rook_points[0][1] = Point(3 * W / 4, 7 * W / 8);
    rook_points[0][2] = Point(3 * W / 4, 13 * W / 16);
    rook_points[0][3] = Point(11 * W / 16, 13 * W / 16);
    rook_points[0][4] = Point(19 * W / 32, 3 * W / 8);
    rook_points[0][5] = Point(3 * W / 4, 3 * W / 8);
    rook_points[0][6] = Point(3 * W / 4, W / 8);
    rook_points[0][7] = Point(26 * W / 40, W / 8);
    rook_points[0][8] = Point(26 * W / 40, W / 4);
    rook_points[0][9] = Point(22 * W / 40, W / 4);
    rook_points[0][10] = Point(22 * W / 40, W / 8);
    rook_points[0][11] = Point(18 * W / 40, W / 8);
    rook_points[0][12] = Point(18 * W / 40, W / 4);
    rook_points[0][13] = Point(14 * W / 40, W / 4);
    rook_points[0][14] = Point(14 * W / 40, W / 8);
    rook_points[0][15] = Point(W / 4, W / 8);
    rook_points[0][16] = Point(W / 4, 3 * W / 8);
    rook_points[0][17] = Point(13 * W / 32, 3 * W / 8);
    rook_points[0][18] = Point(5 * W / 16, 13 * W / 16);
    rook_points[0][19] = Point(W / 4, 13 * W / 16);

    const Point *ppt[1] = { rook_points[0] };
    int npt[] = { 20 };

    fillPoly(img, ppt, npt, 1, Scalar(255, 255, 255), line_type);
}

void MyLine(Mat img, Point start, Point end)
{
    int thickness = 2;
    int line_type = LINE_8;
    line(img, start, end, Scalar(0, 0, 0), thicknesne_type);
}s
