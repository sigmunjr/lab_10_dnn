#include "Dnn_lab.h"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"


Dnn_lab::Dnn_lab(std::string data_folder)
  : net_{/* TODO 2.1: Initialize caffe network from MobileNetSSD_deploy.prototxt and MobileNetSSD_deploy.caffemodel */}
  , class_colors_{createClassColors(21)}
{
}

void Dnn_lab::run()
{
  // TODO 0.0 Remove runtime error throw
  throw std::runtime_error{"Dnn_lab::run() not implemented"};

  const std::string win_name = "SSD_demo";
  cv::namedWindow(win_name);
  cv::VideoCapture cap{0};
  for (;;)
  {
    // TODO 1.1: Capture video frame

    // TODO 1.3: Implement and call method detectInFrame on <frame>

    // TODO 1.4: Implement and call drawDetections

    // TODO 1.2: Show image frame
  }
}

void Dnn_lab::drawDetections(cv::Mat& frame, const cv::Mat& detections, const float threshold)
{
  const auto num_detections = detections.size[2];
  for (int i = 0; i < num_detections; ++i)
  {
    //data have the format [class_index, confidence, upper-left x, upper-left y, down-right x, down-right y]
    const auto& data = detections.at<cv::Vec<float, 7>>(0, 0, i);

    //TODO 3.1 Draw detections in frame, if confidence is above threshold

    //TODO 3.2 Draw text label with class and confidence
  }
}

cv::Mat Dnn_lab::detectInFrame(const cv::Mat& frame)
{
  static const cv::Scalar mean = {127.5, 127.5, 127.5};
  static const float scale_factor = 0.007843;
  // TODO 2.2: Resize <Frame> to 300 by 300

  // TODO 2.3 Prepare data by converting it to blob. Use <scale_factor> and the <mean> already defined.
  // size equal to the resized image

  // TODO 2.4 Set the data blob as input to the network

  // TODO 2.5 Run network and return the results

  return {};
}

std::vector<cv::Scalar_<uint8_t>> Dnn_lab::createClassColors(const int length)
{

  std::vector<cv::Scalar_<uint8_t>> class_colors;
  for (int i = 0; i < length; ++i)
  {
    class_colors.push_back(cv::Scalar_<uint8_t>{cv::randu<uint8_t>(), cv::randu<uint8_t>(), cv::randu<uint8_t>()});
  }
  return class_colors;
}
