cmake_minimum_required(VERSION 3.10)

project(leven_run)


add_subdirectory(
  libs/levenshtein
  )


add_executable(${PROJECT_NAME}
  src/main.c
  )

target_include_directories(${PROJECT_NAME} PUBLIC
  libs/levenshtein/include/
  )

target_link_libraries(${PROJECT_NAME} PUBLIC
  levenshtein
  )


set(TIME_TEST time_test)

add_executable(${TIME_TEST}
  tests/main.c
  )

target_include_directories(${TIME_TEST} PUBLIC
  libs/levenshtein/include/
  )

target_link_libraries(${TIME_TEST} PUBLIC
  levenshtein
  )
