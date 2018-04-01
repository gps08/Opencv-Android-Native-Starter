#include <jni.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

extern "C"
JNIEXPORT void JNICALL Java_x_jnitry_MainActivity_processFrame(JNIEnv *env,jobject,jlong rgb)
{
    Mat& RGB = *(cv::Mat *)rgb;
    cvtColor(RGB,RGB,CV_RGB2GRAY);
    Canny(RGB, RGB, 50, 250);
}