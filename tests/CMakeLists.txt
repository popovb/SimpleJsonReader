cmake_minimum_required(VERSION 3.5)

set(CurrentDir   "${CMAKE_CURRENT_SOURCE_DIR}")
set(RootDir      "${CurrentDir}/..")
set(IncludeDir   "${RootDir}/include")

#set(SourceDir    "${CurrentDir}/../src")

link_directories   ("${CurrentDir}/gtest")
include_directories(
  "${IncludeDir}"
  )

set(CMAKE_CXX_FLAGS "-g -W -Wall -Wextra -std=c++1y")

#aux_source_directory("${SaxDir}"       sd)
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
