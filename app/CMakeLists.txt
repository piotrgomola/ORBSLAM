set(pathToProject /home/pgomola/Dokumenty/ORBSLAM)
set(pathToOpenCv /home/pgomola/Dokumenty/ORBSLAM/app/OpenCV-android-sdk)
set(pathToEigen /home/pgomola/Dokumenty/ORBSLAM/Thirdparty/eigen3)

cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

# MY NATIVE
add_library( native-lib SHARED src/main/cpp/native-lib.cpp )

# OPENCV
include_directories(${pathToOpenCv}/sdk/native/jni/include)
add_library( lib_opencv SHARED IMPORTED )
set_target_properties(lib_opencv PROPERTIES IMPORTED_LOCATION ${pathToProject}/app/src/main/jniLibs/${ANDROID_ABI}/libopencv_java3.so)

# NATIVE LOG LIB
find_library( log-lib log )

# EIGEN
include_directories(eigen INTERFACE ${pathToProject}/Thirdparty/eigen3)

target_link_libraries( native-lib $\{log-lib} lib_opencv)