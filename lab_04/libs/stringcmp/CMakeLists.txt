cmake_minimum_required(VERSION 3.10)

project(stringcmp)


add_library(${PROJECT_NAME} STATIC
  include/stringcmp/stringcmp.h
  src/stringcmp.cpp
  )

target_include_directories(${PROJECT_NAME} PUBLIC
  include/
  )

target_link_libraries(${PROJECT_NAME}
  pthread
  )
