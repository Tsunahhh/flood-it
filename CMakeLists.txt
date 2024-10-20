cmake_minimum_required(VERSION 3.29)
project(flood_it)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

file(GLOB_RECURSE SOURCES
        src/main.cpp
        src/utils/*.cpp
        src/view/*.cpp
        src/model/*.cpp
)

file(GLOB_RECURSE HEADERS
        include/*.h
)

add_executable(test_console
        src/main2.cpp
        src/model/Grid.cpp
        include/Grid.h
        src/model/Game.cpp
        include/Game.h
        include/Settings.h
        include/Colors.h
)

qt_add_executable(${PROJECT_NAME}
        ${SOURCES}
        ${HEADERS}
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)

target_include_directories(${PROJECT_NAME} PUBLIC
    include
)

target_include_directories(test_console PUBLIC include)

set_target_properties(${PROJECT_NAME} PROPERTIES
        WIN32_EXECUTABLE ON
        MACOSX_BUNDLE ON
)