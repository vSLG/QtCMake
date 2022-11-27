cmake_minimum_required(VERSION 3.19)

set(PROJECT "example")

project(${PROJECT} VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Qml QuickControls2 REQUIRED)

add_executable(${PROJECT}
  src/main.cpp
  src/resources.qrc)

target_link_libraries(${PROJECT}
  Qt::Qml
  Qt::QuickControls2)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
 set_property(TARGET ${PROJECT} PROPERTY WIN32_EXECUTABLE false)
endif()
