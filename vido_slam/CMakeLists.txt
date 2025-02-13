cmake_minimum_required(VERSION 3.16)
project(vido_slam)


IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Release)
ENDIF()

MESSAGE("Build type: " ${CMAKE_BUILD_TYPE})

# ======  start c++ compile  ======
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall   -O3 -march=native")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}  -Og -Wall ")

LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)

# set(OpenCV_DIR "/usr/local/lib/cmake/opencv4")
set(OpenCV_DIR "/usr/local/share/OpenCV")
find_package(OpenCV REQUIRED NO_DEFAULT_PATH)
# if(NOT OpenCV_FOUND)
#    find_package(OpenCV 2.4.3 QUIET)
#    if(NOT OpenCV_FOUND)
#       message(FATAL_ERROR "OpenCV > 2.4.3 not found.")
#    endif()
# endif()

# find_package(Eigen3 3.1.0 REQUIRED)
set(Eigen3_DIR "/usr/local/share/eigen3/cmake")
find_package(Eigen3 REQUIRED NO_DEFAULT_PATH)
find_package(CSparse REQUIRED)
find_package(Pangolin REQUIRED)

include_directories(
   ${PROJECT_SOURCE_DIR}
   ${PROJECT_SOURCE_DIR}/include
   ${EIGEN3_INCLUDE_DIR}
   ${OpenCV_INCLUDE_DIR}
   ${CSPARSE_INCLUDE_DIR}
   ${Pangolin_INCLUDE_DIRS}
)


set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)


add_library(${PROJECT_NAME} SHARED
   src/System.cc
   src/ImuTypes.cc
   src/Tracking.cc
   src/ORBextractor.cc
   src/Converter.cc
   src/G2oTypes.cc
   src/Map.cc
   src/Optimizer.cc
   src/Frame.cc
   src/viewer/VidoViewer.cc
   src/cvplot/color.cc
   src/cvplot/figure.cc
   src/cvplot/highgui.cc
   src/cvplot/window.cc
)

target_link_libraries(
   ${PROJECT_NAME}
   ${OpenCV_LIBS}
   ${EIGEN3_LIBS}
   ${CSPARSE_LIBRARY}
   ${Pangolin_LIBRARIES}
   ${OpenCV_INCLUDE_DIR}
   ${PROJECT_SOURCE_DIR}/3rdparty/g2o/lib/libg2o.so
)

add_executable(run_vido demo/run_vido_slam.cc)
target_link_libraries(run_vido ${PROJECT_NAME}
                               ${OpenCV_LIBS})



