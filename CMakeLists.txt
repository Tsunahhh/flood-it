cmake_minimum_required(VERSION 3.29)
project(flood_it)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(floodit
        src/controller/main.cpp
        include/Grid.h
        include/Game.h
        include/Settings.h
        src/model/Grid.cpp
        src/model/Game.cpp
        src/view/SetupView.cpp
        include/SetupView.h
        src/view/GameView.cpp
        src/view/InfoGameView.cpp
        include/Colors.h
)

target_link_libraries(floodit PRIVATE Qt6::Widgets)

set_target_properties(floodit PROPERTIES
        WIN32_EXECUTABLE ON
        MACOSX_BUNDLE ON
)