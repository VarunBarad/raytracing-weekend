cmake_minimum_required(VERSION 3.21)
project(raytracing_weekend)

set(CMAKE_CXX_STANDARD 14)

add_executable(raytracing_weekend main.cpp vec3.h color.h ray.h hittable.h sphere.h hittable_list.h common.h camera.h)
