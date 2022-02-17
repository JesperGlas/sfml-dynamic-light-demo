add_library(Game Game.cpp)
target_link_libraries(Game PRIVATE ImGui-SFML::ImGui-SFML)

add_executable(app_exe main.cpp)
target_link_libraries(app_exe PRIVATE sfml-graphics)
target_link_libraries(app_exe PRIVATE ImGui-SFML::ImGui-SFML)
target_link_libraries(app_exe PRIVATE Game)
