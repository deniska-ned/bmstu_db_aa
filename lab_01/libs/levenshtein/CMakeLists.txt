cmake_minimum_required(VERSION 3.10)

project(levenshtein)


add_library(${PROJECT_NAME} STATIC
  include/levenshtein/leven_dist.h
  src/leven_dist.c
  )

target_include_directories(${PROJECT_NAME} PUBLIC
  include/
  )


set(U_TEST_TARGET unit_tests)
add_subdirectory(libs/googletest)

add_executable(${U_TEST_TARGET}
  tests/leven_rec.cpp
  tests/leven_iter.cpp
  )

target_include_directories(${U_TEST_TARGET} PUBLIC
  include/
  )

target_link_libraries(${U_TEST_TARGET} PUBLIC
  gtest
  gtest_main

  levenshtein
  )
