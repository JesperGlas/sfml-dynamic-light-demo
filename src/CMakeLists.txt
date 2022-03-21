set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.hpp *.h *.cpp)

set(SOURCES ${SOURCES})

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

# Set extra compiler flags
set(CMAKE_CXX_FLAGS "-W -Wall -std=c++14 -fopenmp")

# Create executable
add_executable(${BINARY}_run ${SOURCES})

target_link_libraries(
  ${BINARY}_run PRIVATE
  sfml-system
  sfml-graphics
  ImGui-SFML::ImGui-SFML
)

add_library(${BINARY}_lib STATIC ${SOURCES})

target_link_libraries(
  ${BINARY}_lib PRIVATE
  sfml-system
  sfml-graphics
  ImGui-SFML::ImGui-SFML
)