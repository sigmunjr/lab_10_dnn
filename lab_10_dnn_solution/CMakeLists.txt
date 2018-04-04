cmake_minimum_required(VERSION 3.1.3)
project(Lab_10_dnn_solutions)

set(CMAKE_CXX_STANDARD 11)

# Add libraries.
find_package(OpenCV 3 REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(sophus REQUIRED)


add_executable(${PROJECT_NAME}
  Dnn_lab.h
  Dnn_lab.cpp
  main.cpp
  )

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${EIGEN3_INCLUDE_DIR} ${sophus_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PRIVATE
  -Wall
  -Wextra
  -Wno-unknown-pragmas
  )
