cmake_minimum_required(VERSION 3.14)

project(myapp LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(myapp
  main.cpp
)

add_library(mylib STATIC IMPORTED) # or STATIC instead of SHARED
set_target_properties(mylib PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/lib/mylib.lib"
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/inc"
)

target_link_libraries(myapp mylib Qt${QT_VERSION_MAJOR}::Core)

install(TARGETS myapp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
