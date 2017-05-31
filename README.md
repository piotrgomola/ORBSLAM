# ORBSLAM

Project contains implementation of [ORB-SLAM2](https://github.com/raulmur/ORB_SLAM2) library by [Raul Mur-Artal](http://webdiis.unizar.es/~raulmur/) on Android devices.
It is done in a Android Studio project form with use of CMake to manage NDK compilation process. 
The project was tested on devices with armeabi-v7a (smartphones) and x86(tablets) architecture. 
Before using app, you should have in your device storage vocabulary file for ORB-SLAM as well as camera calibration file for your device.
After installation, app initialize ORB-SLAM (it can take few minutes) and after that it opens camera preview and start calculating as it tries to find characteristic points.

To manage compiled device architecture, change abiFilters in app/build.gradle. 
