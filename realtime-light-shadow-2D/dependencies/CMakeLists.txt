include(FetchContent)

FetchContent_Declare(
  sfml
  GIT_REPOSITORY "https://github.com/SFML/SFML"
  GIT_TAG 218154cf0098de3f495e31ced489da24b7318638 # Latest
)

add_subdirectory(sfml)

FetchContent_Declare(
  imgui
  GIT_REPOSITORY https://github.com/ocornut/imgui
  GIT_TAG 5c8f8d031166765d2f1e2ac2de27df6d3691c05a # Latest
)

FetchContent_MakeAvailable(imgui)

FetchContent_Declare(
  imgui-sfml
  GIT_REPOSITORY https://github.com/eliasdaler/imgui-sfml
  GIT_TAG 4129d276d45845581b6ba99ede50db6f761e5089 # Latest
)
add_subdirectory(imgui-sfml)