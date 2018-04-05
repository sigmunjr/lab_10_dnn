# Lab 10 - Object detection
## Object recognition with deep neural networks

- Using dnn-module in OpenCV-contributed (https://docs.opencv.org/3.3.1/d6/d0f/group__dnn.html)[https://docs.opencv.org/3.3.1/d6/d0f/group__dnn.html]
- Pretrained models from Caffe. (with new OpenCV you should also be able to run tensorflow.pb models)
- SSD with MobileNet

## Download and setup project

- Download from https://github.com/sigmunjr/lab_10_dnn.git
- write code in lab_10_dnn/Dnn_lab.cpp
- Follow instructions marked by TODO in the code

Check out the documentation to learn how to read caffe models.

Test other caffemodels?

## Advanced: "training" model in tensorflow
Start with following code to load a classification model. Train the model to recognized **you** vs **background** and other people. Try training it live.

import tensorflow as tf
import tensorflow_hub as hub

import numpy as np

import cv2


images = tf.placeholder(tf.float32, [None, None, None, 3])
labels = tf.placeholder(tf.int64, [None])

module = hub.Module("https://tfhub.dev/google/imagenet/mobilenet_v2_140_224/feature_vector/1")

height, width = hub.get_expected_image_size(module)
features = module(images)
