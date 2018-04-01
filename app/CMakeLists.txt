cmake_minimum_required(VERSION 3.4.1)
set(CMAKE_VERBOSE_MAKEFILE on)

set(opencvSDK "/path/to/OpenCV-android-sdk")

include_directories(${opencvSDK}/sdk/native/jni/include)

add_library(libopencv_java3 SHARED IMPORTED )
set_target_properties(libopencv_java3 PROPERTIES IMPORTED_LOCATION "${opencvSDK}/sdk/native/libs/${ANDROID_ABI}/libopencv_java3.so")

add_library( native-lib SHARED src/main/cpp/native-lib.cpp )
find_library( log-lib log )

target_link_libraries( native-lib libopencv_java3 ${log-lib} )