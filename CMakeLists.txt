cmake_minimum_required(VERSION 3.12...3.20)

project("Rho Tetris" VERSION 0.1 LANGUAGES CXX)

find_package(SFML 2.5 COMPONENTS audio graphics window system REQUIRED)

set(SRC src/main.cpp)

add_executable(rhotetris ${SRC})
target_compile_features(rhotetris PUBLIC cxx_std_17)
set_target_properties(rhotetris PROPERTIES CXX_EXTENSIONS OFF)
target_link_libraries(rhotetris PUBLIC
        sfml-graphics
        sfml-audio
        sfml-window
        sfml-system)
