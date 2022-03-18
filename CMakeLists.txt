cmake_minimum_required(VERSION 3.15)
project(realtime-light-shadow-2D
  LANGUAGES CXX
  VERSION 1.0
)

# Add project source directories
aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}/src" PROJECT_SRCS)

# Add project include directories
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src")

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

FetchContent_MakeAvailable(SFML)

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

# Set extra compiler flags
set(CMAKE_CXX_FLAGS "-W -Wall -std=c++14 -fopenmp")

# Create executable
add_executable(${PROJECT_NAME} ${PROJECT_SRCS})

target_link_libraries(
  ${PROJECT_NAME} PRIVATE
  sfml-system
  sfml-graphics
  ImGui-SFML::ImGui-SFML
)