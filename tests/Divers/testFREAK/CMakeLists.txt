cmake_minimum_required(VERSION 2.8)
project( FREAK )
find_package( OpenCV REQUIRED )
add_executable( FREAK FREAK.cpp )
target_link_libraries( FREAK ${OpenCV_LIBS} )
