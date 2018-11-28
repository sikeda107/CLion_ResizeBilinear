cmake_minimum_required(VERSION 3.12)
project(ResizeBilinear)

set(CMAKE_CXX_STANDARD 14)

add_executable(ResizeBilinear main.cpp)

# For OpenCV
cmake_minimum_required(VERSION 2.8)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
target_link_libraries( ResizeBilinear ${OpenCV_LIBS} )