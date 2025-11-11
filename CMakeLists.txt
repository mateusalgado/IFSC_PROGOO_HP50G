cmake_minimum_required(VERSION 3.19)
project(Sema LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Graphs Mqtt Sql)

qt_standard_project_setup()

qt_add_executable(Sema
    WIN32 MACOSX_BUNDLE
    code/main.cpp
    code/windowmanager.cpp
    code/windowmanager.h
    code/settings.hpp
)

target_link_libraries(Sema
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Graphs
        Qt::Mqtt
)

include(GNUInstallDirs)

install(TARGETS Sema
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Sema
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
