cmake_minimum_required(VERSION 3.31)
project(Image_Processing)

set(CMAKE_CXX_STANDARD 20)

add_executable(Image_Processing main.cpp
        Image.cpp Image.h
        Size.cpp Size.h
        Point.h
        Point.cpp
        Rectangle.h
        Rectangle.cpp
        ImageProcessing.h
        ImageProcessing.cpp)

