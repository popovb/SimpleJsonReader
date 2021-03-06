cmake_minimum_required(VERSION 3.5)

set(CurrentDir   "${CMAKE_CURRENT_SOURCE_DIR}")
set(RootDir      "${CurrentDir}/..")
set(IncludeDir   "${RootDir}/include")
set(SourceDir    "${RootDir}/src")

link_directories   ("${CurrentDir}/gtest")
include_directories(
  "${IncludeDir}"
  "${SourceDir}"
  )

set(CMAKE_CXX_FLAGS "-g -W -Wall -Wextra -std=c++1y")

aux_source_directory("${SourceDir}" sources)

#add_library(xml
#  ${sd}
#  ${xd}
#  )

##################################################################
add_executable(first_test
  first_test.cpp
  )

target_link_libraries(first_test
  gtest_main
  gtest
  pthread
  )
##################################################################

##################################################################
add_executable(handler_test
  handler_test.cpp
  ${sources}
  )

target_link_libraries(handler_test
  gtest_main
  gtest
  pthread
  )
##################################################################

##################################################################
add_executable(reader_test
  reader_test.cpp
  ${sources}
  )

target_link_libraries(reader_test
  gtest_main
  gtest
  pthread
  )
##################################################################
