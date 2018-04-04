#ifndef LAB10_DNN_LAB_H
#define LAB10_DNN_LAB_H
#include <iostream>
#include <opencv2/dnn.hpp>

class Dnn_lab
{
public:
  explicit Dnn_lab(std::string data_folder);

  void run();

private:
  cv::dnn::Net net_;
  std::vector<cv::Scalar_<uint8_t>> class_colors_;

  const std::vector<std::string> class_labels_ = {
    "background", "aeroplane", "bicycle", "bird", "boat",
    "bottle", "bus", "car", "cat", "chair", "cow", "diningtable",
    "dog", "horse", "motorbike", "person", "pottedplant", "sheep",
    "sofa", "train", "tvmonitor"};

  cv::Mat detectInFrame(const cv::Mat& frame);

  void drawDetections(cv::Mat& frame, const cv::Mat& detections, const float threshold);

  std::vector<cv::Scalar_<uint8_t>> createClassColors(const int length);
};

#endif
