cmake_minimum_required(VERSION 3.16)
project(QtShapesMotion LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_executable(QtShapesMotion
    main.cpp
    gui/MainWindow.h
    gui/MainWindow.cpp
    gui/CanvasWidget.h
    gui/CanvasWidget.cpp
    shapes/GraphicObject.h
    shapes/GraphicObject.cpp
    shapes/IsoscelesTriangle.h
    shapes/IsoscelesTriangle.cpp
    shapes/Parallelogram.h
    shapes/Parallelogram.cpp
    shapes/BowShape.h
    shapes/BowShape.cpp
)

target_link_libraries(QtShapesMotion PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
