cmake_minimum_required(VERSION 3.16)

# Sets project name
project(lab06 LANGUAGES CXX C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Sets C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specifies required Qt components
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Allows you to include files from within those directories, without prefixing their filepaths
include_directories(src)
include_directories(glm)

# Specifies .cpp and .h files to be passed to the compiler
add_executable(${PROJECT_NAME}
  src/main.cpp
  
  src/mainwindow.cpp
  src/Canvas2D.cpp
  src/ReflSampler.cpp
  src/lightmodel.cpp
  
  src/mainwindow.h
  src/Canvas2D.h
  src/rgba.h
  src/ReflSampler.h
  src/lightmodel.h
  src/param.h

  src/mainwindow.ui
)

# Specifies libraries to be linked (Qt components, glew, etc)
target_link_libraries(${PROJECT_NAME} PRIVATE
  Qt6::Widgets
  Qt6::Core
)

# Specifies other files
qt6_add_resources(${PROJECT_NAME} "Resources"
  PREFIX
  "/"
  FILES
  resources/intersections.dat
  resources/background.png
)
