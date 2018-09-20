cmake_minimum_required(VERSION 3.8)
project(pluginTemplate)

SET(CMAKE_CXX_STANDARD 11)

SET(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cgcmake/modules)

SET(SOURCE_FILES "plugin.h;plugin.cpp")

FIND_PACKAGE(Maya REQUIRED)
ADD_LIBRARY(pluginTemplate SHARED ${SOURCE_FILES})
TARGET_LINK_LIBRARIES(pluginTemplate PRIVATE Maya::Maya)
TARGET_INCLUDE_DIRECTORIES(pluginTemplate PRIVATE Maya::Maya)
MAYA_PLUGIN(pluginTemplate)
