cmake_minimum_required(VERSION 3.10)

project(levenshtein)

add_library(${PROJECT_NAME} STATIC
  include/levenshtein/leven_dist.h
  src/leven_dist.c
  )

target_include_directories(${PROJECT_NAME} PUBLIC
  include/
  )
