#include "Dnn_lab.h"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

Dnn_lab::Dnn_lab(std::string data_folder)
  : net_{cv::dnn::readNetFromCaffe(data_folder + std::string("/MobileNetSSD_deploy.prototxt"),
                                   data_folder + std::string("/MobileNetSSD_deploy.caffemodel"))/* TODO 2.1: Initialize caffe network */}
  , class_colors_{createClassColors(21)}
{
}

void Dnn_lab::run()
{
  const std::string win_name = "SSD_demo";
  cv::namedWindow(win_name);
  cv::VideoCapture cap{0};
  for (;;)
  {


    // TODO 1.1: Show video in a loop
    cv::Mat frame;
    cap >> frame;

    // TODO 1.3: Call method detectInFrame on <frame>
    auto detections = detectInFrame(frame);

    // TODO 1.4: Call drawDetections
    drawDetections(frame, detections, 0.2f);

    cv::imshow(win_name, frame);
    if (cv::waitKey(30) >= 0)
    {
      break;
    }
  }
}

void Dnn_lab::drawDetections(cv::Mat& frame, const cv::Mat& detections, const float threshold)
{
  const auto num_detections = detections.size[2];
  for (int i = 0; i < num_detections; ++i)
  {
    //data have the format [class_index, confidence, upper-left x, upper-left y, down-right x, down-right y]
    const auto& data = detections.at<cv::Vec<float, 7>>(0, 0, i);

    const auto& confidence = data[2];
    if (confidence > threshold)
    {
      const int class_idx = static_cast<int>(data[1]);
      const int x_start = static_cast<int>(data[3] * frame.cols);
      const int y_start = static_cast<int>(data[4] * frame.rows);
      const int x_end = static_cast<int>(data[5] * frame.cols);
      const int y_end = static_cast<int>(data[6] * frame.rows);

      //TODO 3.1 Draw detections in frame, if confidence is above threshold
      cv::rectangle(frame, {x_start, y_start}, {x_end, y_end}, class_colors_[class_idx], 2);

      //TODO 3.2 Draw text label with class and confidence
      std::stringstream label;
      label << class_labels_[class_idx] << ": " << confidence * 100;
      const int y_label = y_start - 15 > 15 ? y_start - 15 : y_start + 15;
      cv::putText(frame, label.str(), {x_start, y_label}, cv::FONT_HERSHEY_SIMPLEX, 0.5, class_colors_[class_idx], 2);
    }

  }
}

cv::Mat Dnn_lab::detectInFrame(const cv::Mat& frame)
{
  static const cv::Scalar mean = {104, 117, 123};
  // TODO 2.2: Resize <Frame> to 300 by 300
  cv::Mat resized_img;
  cv::resize(frame, resized_img, {300, 300});

  // TODO 2.3 Prepare data by converting it to blob. Use scale factor 1.0 and the <mean> already defined
  auto blob = cv::dnn::blobFromImage(resized_img, 0.007843, resized_img.size(), {127.5, 127.5, 127.5}, true);

  // TODO 2.4 Set the data blob as input to the network
  net_.setInput(blob);

  // TODO 2.5 Run network and return the results
  auto detections = net_.forward();

  return detections;
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
