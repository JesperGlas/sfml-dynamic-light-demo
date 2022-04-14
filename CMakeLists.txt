cmake_minimum_required(VERSION 3.16)
project(realtime-light-shadow-2D
  LANGUAGES CXX
  VERSION 1.0
)

# Set extra compiler flags
set(CMAKE_CXX_FLAGS "-W -Wall -std=c++14 -fopenmp")

# Set binary destinations
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Dependencies
include(FetchContent)
set (FETCHCONTENT_QUIET FALSE)

# SFML
message (STATUS "Adding SFML..")
FetchContent_Declare(
  sfml
  GIT_REPOSITORY "https://github.com/SFML/SFML"
  GIT_TAG 218154cf0098de3f495e31ced489da24b7318638 # Latest
  GIT_PROGRESS TRUE
)

# No need to build audio and network modules
set(SFML_BUILD_AUDIO FALSE)
set(SFML_BUILD_NETWORK FALSE)

FetchContent_MakeAvailable(sfml)

# ImGui
message (STATUS "Adding ImGui")
FetchContent_Declare(
  imgui
  GIT_REPOSITORY https://github.com/ocornut/imgui
  GIT_TAG 5c8f8d031166765d2f1e2ac2de27df6d3691c05a # Latest
  GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(imgui)

# ImGui-SFML
message (STATUS "Adding ImGui-SFML")
FetchContent_Declare(
  imgui-sfml
  GIT_REPOSITORY https://github.com/eliasdaler/imgui-sfml
  GIT_TAG 4129d276d45845581b6ba99ede50db6f761e5089 # Latest
  GIT_PROGRESS TRUE
)
set(IMGUI_DIR ${imgui_SOURCE_DIR})
set(IMGUI_SFML_FIND_SFML OFF)
set(IMGUI_SFML_IMGUI_DEMO ON)

FetchContent_MakeAvailable(imgui-sfml)

# dynamic-shadows-lib
message( STATUS "Adding dynamic-shadow-lib")
FetchContent_Declare(
  dynamic-shadows-lib
  GIT_REPOSITORY https://github.com/JesperGlas/dynamic-shadows-lib/
  GIT_TAG 9dea9abb4c7f0e5c272e9d27f7c8358a2446a0e7 # Latest
  GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(dynamic-shadows-lib)

# Set header dir
set(HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${HEADERS_DIR})

# Set source dir
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(TARGET_BIN ${CMAKE_PROJECT_NAME})

add_executable(
  ${TARGET_BIN}
  ${SOURCE_DIR}/main.cpp
  ${SOURCE_DIR}/Game.cpp
)

target_link_libraries(
  ${TARGET_BIN}
  PUBLIC
    sfml-system
    sfml-graphics
    ImGui-SFML::ImGui-SFML
    dynamic-shadows-lib
)