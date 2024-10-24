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

qt_add_executable(${PROJECT_NAME}
        ${SOURCES}
        ${HEADERS}
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)

target_include_directories(${PROJECT_NAME} PUBLIC
    include
)

set_target_properties(${PROJECT_NAME} PROPERTIES
        WIN32_EXECUTABLE ON
        MACOSX_BUNDLE ON
)