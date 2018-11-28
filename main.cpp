#include <opencv2/opencv.hpp>
#include <stdio.h>
using namespace cv;
int main(int argc, char **argv) {
    char filename[30] = "../INPUT/test_pos_1.ppm";
    Mat image, gray, output;
    Size outsize;
    image = imread(filename, 1);
    if (!image.data) {
        printf("No image data \n");
        return -1;
    }
    //  void cvtColor(InputArray src, OutputArray dst, int code, int dstCn=0 )
    cvtColor(image, gray, CV_RGB2GRAY);
    // resize(InputArray src, OutputArray dst, Size dsize, double fx=0, double
    // fy=0, int interpolation=INTER_LINEAR )
    outsize =
            Size(round(image.cols * (1.0 / 1.25)), round(image.rows * (1.0 / 1.25)));
    resize(gray, output, outsize, 0, 0, INTER_LINEAR);

    //    ファイルに出力
    imwrite("../OUTPUT/gray.pgm", gray);
    imwrite("../OUTPUT/output.pgm", output);

    //    画面にそのまま表示
    /*
    namedWindow("Display Image", WINDOW_AUTOSIZE);
    imshow("Display Image", image);
    imshow("Display Gray", gray);
    imshow("Display Bilinear", output);
    waitKey(0);
     */
    return 0;
}
