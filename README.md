# Opencv Android Native Starter Project

Intructions for importing in Android Studio

- Download the latest opencv sdk for android from <a href="https://opencv.org/releases.html">here</a> and extract it.
- Make the following changes in /Opencv-Android-Native-Starter/app/CMakeLists.txt
  - In this line - set(opencvSDK "/path/to/OpenCV-android-sdk") 
    change the directory where you extracted the sdk in previous step
- Adjust android build and build tools version according to your preference
- Then sync, and done
<br><br>

PS: Camera permission may be needed by the app before starting <br>
TODO: ask for the camera permission interactively
