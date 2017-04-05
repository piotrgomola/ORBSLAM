#include <jni.h>
#include <string>
#include <opencv2/core.hpp>
#include "Eigen/Eigen"

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
