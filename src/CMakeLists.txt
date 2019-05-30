cmake_minimum_required(VERSION 3.9)
project(ts_parse_out)

set(CMAKE_CXX_STANDARD 11)

add_executable(my_programs ts_parse.cpp analysis.cpp pat.cpp pes.cpp pmt.cpp section.cpp tsheader.cpp)
