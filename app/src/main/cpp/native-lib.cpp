#include <jni.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d.hpp>
#include <vector>
#include <iostream>

using namespace cv;
using namespace std;

extern "C"
JNIEXPORT void JNICALL Java_x_jnitry_MainActivity_processFrame(JNIEnv *env,jobject,jlong rgb)
{
    Mat& RGB = *(cv::Mat *)rgb;
    cvtColor(RGB,RGB,CV_RGB2GRAY);

    int board_height = 6;
    int board_width = 6;

    int square_size = 128; // size of each square black or white square

    vector<Point2f> corners_detected;
    Size checkerBoardsize = Size(board_height,board_width);
    bool found = false;
    found = findChessboardCorners(RGB,checkerBoardsize
            ,corners_detected,CALIB_CB_ADAPTIVE_THRESH | CALIB_CB_NORMALIZE_IMAGE);

    if(found){

        cornerSubPix(RGB,corners_detected
                ,Size(2*board_height+1,2*board_height+1),Size(-1,1),TermCriteria(
                        CV_TERMCRIT_EPS | CV_TERMCRIT_ITER,30,0.001));
        //drawChessboardCorners(RGB,checkerBoardsize,corners_detected,found);

    }

    vector<Point3f> objPoints;
    for (int i = 0; i < board_height; i++)
        for (int j = 0; j < board_width; j++)
            objPoints.push_back(Point3f((float)j * square_size, (float)i * square_size, 0));

    Mat K;
    Mat D;
    vector<Mat> rvec,tvecs;
    int flag = 0;
    flag |= CV_CALIB_FIX_K4;
    flag |= CV_CALIB_FIX_K5;

    calibrateCamera(objPoints,corners_detected,RGB.size(),K,D,rvec,tvecs,flag);

    // trying to undistort
    Mat undistorted;
    undistort(RGB,undistorted,K,D);
    RGB = undistorted;

}
