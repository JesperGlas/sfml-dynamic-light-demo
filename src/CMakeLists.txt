add_executable(app_exe main.cpp)
target_link_libraries(app_exe PRIVATE sfml-graphics)
target_link_libraries(app_exe PRIVATE ImGui-SFML::ImGui-SFML)

add_library(Game Game.cpp)
target_link_libraries(app_exe PRIVATE Game)