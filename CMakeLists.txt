cmake_minimum_required(VERSION 3.20)

project(GladeDemos LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM gtkmm-3.0)

#
# collect shared libs for all targets
#
add_library(gtkmm_3 INTERFACE)

target_include_directories(gtkmm_3
    INTERFACE
        ${GTKMM_INCLUDE_DIRS}
)
target_link_directories(gtkmm_3
    INTERFACE
        ${GTKMM_LIBRARY_DIRS}
)
target_link_libraries(gtkmm_3
    INTERFACE
        ${GTKMM_LIBRARIES}
)

#
# GtkMM + Glade from file
#
add_executable(gmm_demo WIN32)

target_sources(gmm_demo
    PRIVATE
        main.cpp
        main_view.cpp main_view.h
        scene_view.cpp scene_view.h
)

target_link_libraries(gmm_demo
    PRIVATE
        gtkmm_3
)