cmake_minimum_required(VERSION 3.29)
project(flood_it)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(flood_it main.cpp)
target_link_libraries(flood_it
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

