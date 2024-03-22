cmake_minimum_required(VERSION 3.5)

project(SU-PA2-SEM2 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Sql REQUIRED)
find_package(Qt5 REQUIRED COMPONENTS Core Quick Sql)

add_executable(SU-PA2-SEM2 main.cpp Client.cpp Client.h Robot.cpp Robot.h)

target_link_libraries(SU-PA2-SEM2 Qt5::Sql Qt5::Core Qt5::Quick)

include(GNUInstallDirs)
install(TARGETS SU-PA2-SEM2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
