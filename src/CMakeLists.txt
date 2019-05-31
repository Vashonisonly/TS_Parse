cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 11)

AUX_SOURCE_DIRECTORY(. DIR_SRCS)

add_executable(ts_parse.out ${DIR_SRCS})
