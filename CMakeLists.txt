CMAKE_MINIMUM_REQUIRED(VERSION 3.29)
project(xwm)
set(CMAKE_CXX_STANDARD 20)

add_definitions(-DVERSION="0.1")

find_package(X11 REQUIRED)
find_package(Freetype REQUIRED)

add_library(drw SHARED src/drw.cpp src/util.cpp)
target_include_directories(drw PRIVATE include ${FREETYPE_INCLUDE_DIRS})
target_link_libraries(drw ${X11_LIBRARIES} ${FREETYPE_LIBRARIES} ${X11_Xft_LIB})

add_library(dwm SHARED src/dwm.cpp src/util.cpp)
target_include_directories(dwm PRIVATE include ${FREETYPE_INCLUDE_DIRS})
target_link_libraries(dwm drw ${X11_LIBRARIES} ${FREETYPE_LIBRARIES})

add_executable(xwm main.cpp src/util.cpp)
target_include_directories(xwm PRIVATE include ${FREETYPE_INCLUDE_DIRS})
target_link_libraries(xwm drw dwm ${X11_LIBRARIES} ${FREETYPE_LIBRARIES})
