cmake_minimum_required(VERSION 3.30)
project(SPA4)

set(CMAKE_CXX_STANDARD 14)

add_executable(SPA4
        src/Character/Clown.cpp
        src/Character/Clown.h
        src/Character/Entity.cpp
        src/Character/Entity.h
        src/Character/Ghost.cpp
        src/Character/Ghost.h
        src/Character/Player.cpp
        src/Character/Player.h

        src/Item/Pickup.cpp
        src/Item/Pickup.h
        src/Item/Health.cpp
        src/Item/Health.h
        src/Item/Weapon.cpp
        src/Item/Weapon.h

        src/main.cpp
        src/Map.cpp
        src/Map.h
        src/Messages.cpp
        src/Messages.h
        )