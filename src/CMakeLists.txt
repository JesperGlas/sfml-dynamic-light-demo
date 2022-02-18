add_library(RectObject RectObject.cpp)
target_link_libraries(RectObject PRIVATE sfml-graphics)
target_link_libraries(RectObject PRIVATE ImGui-SFML::ImGui-SFML)

add_library(Canvas Canvas.cpp)
target_link_libraries(Canvas PRIVATE sfml-graphics)
target_link_libraries(Canvas PRIVATE ImGui-SFML::ImGui-SFML)
target_link_libraries(Canvas PRIVATE RectObject)

add_library(Game Game.cpp)
target_link_libraries(Game PRIVATE sfml-graphics)
target_link_libraries(Game PRIVATE ImGui-SFML::ImGui-SFML)
target_link_libraries(Game PRIVATE Canvas)
target_link_libraries(Game PRIVATE RectObject)

add_executable(app_exe main.cpp)
target_link_libraries(app_exe PRIVATE sfml-graphics)
target_link_libraries(app_exe PRIVATE ImGui-SFML::ImGui-SFML)
target_link_libraries(app_exe PRIVATE Game)
