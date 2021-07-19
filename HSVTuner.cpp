#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui_c.h>

int main( int argc, char** argv){
    //import image
    cv::Mat image = cv::imread("example.png");
    cv::Mat original = image.clone();
    //Convert Image Color
    cvtColor(image,image,CV_BGR2HSV);
    cv::imshow("HSV",image);
    
    //display image
    cv::namedWindow("Original", cv::WINDOW_AUTOSIZE);
    cv::imshow("Original",original);

    //Initializing Slider
    int Hmin=0, Hmax=256, Smin=0, Smax=256,Vmin=0,Vmax=256;
    cv::namedWindow("Sliders",cv::WINDOW_NORMAL);
    cv::resizeWindow("Sliders",300,300);
    cv::createTrackbar("Hue Min", "Sliders", &Hmin, 256) ;
    cv::createTrackbar("Hue Max", "Sliders", &Hmax, 256) ;
    cv::createTrackbar("Saturation Min","Sliders", &Smin,256);
    cv::createTrackbar("Saturation Max","Sliders", &Smax,256);
    cv::createTrackbar("Value Min","Sliders", &Vmin,256);
    cv::createTrackbar("Value Max","Sliders", &Vmax,256);
    

     while (true)
     {
        cv::Mat Filtered = image.clone();
        //Filtering Hue, Saturation and Value
        cv::inRange(Filtered, cv::Scalar(Hmin,Smin,Vmin), cv::Scalar(Hmax,Smax,Vmax),Filtered);
        cv::namedWindow("Filtered",cv::WINDOW_AUTOSIZE);
        cv::imshow("Filtered",Filtered);
        cv::waitKey(5);
     }

    return 0;
    
} 
