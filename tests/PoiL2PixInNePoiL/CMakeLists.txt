cmake_minimum_required(VERSION 2.8)
project( PoiL2PixInNePoiL )
find_package( OpenCV REQUIRED )
add_executable( PoiL2PixInNePoiL PoiL2PixInNePoiL.cpp )
target_link_libraries( PoiL2PixInNePoiL ${OpenCV_LIBS} )
