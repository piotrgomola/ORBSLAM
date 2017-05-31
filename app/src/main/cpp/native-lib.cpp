#include <jni.h>
#include <string>
#include <opencv2/core.hpp>
#include<iostream>
#include<fstream>
#include<chrono>
#include<System.h>
using namespace cv;
#include <android/log.h>
#define LOG_TAG "ORB_SLAM_SYSTEM"
#define LOG(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG, __VA_ARGS__)
static ORB_SLAM2::System *s;
bool init_end = false;

/*
 * Class:     orb_slam2_android_nativefunc_OrbNdkHelper
 * Method:    initSystemWithParameters
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
extern "C"
JNIEXPORT void JNICALL
Java_pl_poznan_put_orbslam_MainActivity_initSystemWithParameters(JNIEnv *env, jobject, jstring VOCPath, jstring calibrationPath) {
    LOG("ORBSLAM INIT START");
    const char *calChar = env->GetStringUTFChars(calibrationPath, JNI_FALSE);
    const char *vocChar = env->GetStringUTFChars(VOCPath, JNI_FALSE);
    // use your string
    std::string voc_string(vocChar);
    std::string cal_string(calChar);
    s=new ORB_SLAM2::System(voc_string,cal_string,ORB_SLAM2::System::MONOCULAR,true);
    env->ReleaseStringUTFChars(calibrationPath, calChar);
    env->ReleaseStringUTFChars(VOCPath, vocChar);
    init_end=true;
    LOG("ORBSLAM INIT END");
}

extern "C"
JNIEXPORT jintArray JNICALL
Java_pl_poznan_put_orbslam_MainActivity_startCurrentORBForCamera(JNIEnv *env, jclass cls,jdouble timestamp, jlong addr,jint w,jint h) {
    LOG("ORBSLAM CAMERA MEASSURE START");
    const cv::Mat *im = (cv::Mat *) addr;
    cv::Mat ima = s->TrackMonocular(*im, timestamp);
    jintArray resultArray = env->NewIntArray(ima.rows * ima.cols);
    jint *resultPtr;
    resultPtr = env->GetIntArrayElements(resultArray, JNI_FALSE);
    for (int i = 0; i < ima.rows; i++)
    for (int j = 0; j < ima.cols; j++) {
    int R = ima.at < Vec3b > (i, j)[0];
    int G = ima.at < Vec3b > (i, j)[1];
    int B = ima.at < Vec3b > (i, j)[2];
    resultPtr[i * ima.cols + j] = 0xff000000 + (R << 16) + (G << 8) + B;
    }
    env->ReleaseIntArrayElements(resultArray, resultPtr, 0);
    LOG("ORBSLAM CAMERA MEASSURE END");
    return resultArray;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_pl_poznan_put_orbslam_MainActivity_stringFromJNI(JNIEnv *env, jobject /* this */) {
    std::string hello = "Hello from C++";
    Eigen::Matrix2f matrix2f;
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_pl_poznan_put_orbslam_MainActivity_validate(JNIEnv *env, jobject, jlong addrGray, jlong addrRgba) {
    cv::Rect();
    cv::Mat();
    std::string hello2 = "Hello from validate";
    return env->NewStringUTF(hello2.c_str());
}
