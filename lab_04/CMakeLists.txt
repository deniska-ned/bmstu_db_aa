cmake_minimum_required(VERSION 3.10)

project(stringcmp_run)


add_subdirectory(
  libs/stringcmp
  )


add_executable(${PROJECT_NAME}
  src/main.cpp
  )

target_include_directories(${PROJECT_NAME} PUBLIC
  libs/stringcmp/include/
  )

target_link_libraries(${PROJECT_NAME} PUBLIC
  stringcmp
  )


set(TIME_TEST time_test)

add_executable(${TIME_TEST}
  tests/main.cpp
  )

target_include_directories(${TIME_TEST} PUBLIC
  libs/stringcmp/include/
  )

target_link_libraries(${TIME_TEST} PUBLIC
  stringcmp
  )
