cmake_minimum_required(VERSION 3.0.2)

project(gdhm_api DESCRIPTION "GDHM API" LANGUAGES CXX)

add_library(gdhm INTERFACE)

target_include_directories(gdhm INTERFACE "includes")

target_link_libraries(gdhm INTERFACE
  ${CMAKE_CURRENT_LIST_DIR}/lib/ToastedMarshmellow.lib)
