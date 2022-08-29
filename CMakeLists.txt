cmake_minimum_required(VERSION 3.5)

project(lab06_light VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt6 REQUIRED COMPONENTS Widgets REQUIRED)
find_package(Qt6 COMPONENTS Core REQUIRED)

include_directories(src)
include_directories(glm)


set(PROJECT_SOURCES
        main.cpp
        src/mainwindow.cpp
        src/mainwindow.h
        src/mainwindow.ui
        src/Canvas2D.cpp
        src/Canvas2D.h
        src/rgba.cpp
        src/rgba.h
        src/ReflSampler.cpp
        src/ReflSampler.h
        src/lightmodel.cpp
        src/lightmodel.h
        src/param.h
)

qt_add_executable(lab06_light
    ${PROJECT_SOURCES}
)

target_link_libraries(lab06_light PRIVATE
    Qt6::Widgets
    Qt6::Core
)


qt6_add_resources(lab06_light "ray_data"
    PREFIX
        "/"
    FILES
        resource/intersections.dat
        resource/background.png
)
