cmake_minimum_required(VERSION 3.30)
project(SPA4)

set(CMAKE_CXX_STANDARD 14)

# Find the Qt libraries
set(CMAKE_PREFIX_PATH "C:/Qt/6.8.2/mingw_64")
#set(CMAKE_PREFIX_PATH "C:/Qt/6.8.2/mingw_64/lib/cmake/Qt6/")
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# Enable automatic MOC processing
set(CMAKE_AUTOMOC ON)

qt_add_resources(SPA4 resources.qrc)

# Include Qt headers
include_directories(${Qt6Widgets_INCLUDE_DIRS})


add_executable(SPA4
        src/Character.cpp
        src/Character.h
        src/Clown.cpp
        src/Clown.h
        src/Enemy.cpp
        src/Enemy.h
        src/Entity.cpp
        src/Entity.h
        src/Ghost.cpp
        src/Ghost.h
        src/main.cpp
        src/Player.cpp
        src/Player.h
        )

# Link Qt libraries
target_link_libraries(SPA4 Qt6::Core Qt6::Gui Qt6::Widgets)
