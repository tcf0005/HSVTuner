cmake_minimum_required(VERSION 2.8)
project( HSVTuner.cpp )                                 #replace test
find_package( OpenCV REQUIRED )
add_executable( HSVTuner HSVTuner.cpp )                 #replace test and test.cpp
target_link_libraries( HSVTuner ${OpenCV_LIBS} )    #replace test
