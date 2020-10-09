cmake_minimum_required(VERSION 3.12...3.20)

project("Rho Tetris" VERSION 0.1 LANGUAGES CXX)

find_package(SFML 2.5 COMPONENTS audio graphics window system REQUIRED)

set(SRC
        src/Game.cpp
        src/GameState.cpp
        src/GetReadyState.cpp
        src/PlayingState.cpp
        src/EndGameState.cpp
        src/Piece.cpp
        src/Point.cpp)

add_library(rhotetris ${SRC})
target_compile_features(rhotetris PUBLIC cxx_std_17)
set_target_properties(rhotetris PROPERTIES CXX_EXTENSIONS OFF)

add_executable(rhotetrisapp src/main.cpp)
target_compile_features(rhotetrisapp PUBLIC cxx_std_17)
set_target_properties(rhotetrisapp PROPERTIES CXX_EXTENSIONS OFF)
target_link_libraries(rhotetrisapp PUBLIC
        rhotetris
        sfml-graphics
        sfml-audio
        sfml-window
        sfml-system)

# Copy images directory into build directory
# https://stackoverflow.com/questions/13429656/how-to-copy-contents-of-a-directory-into-build-directory-after-make-with-cmake
add_custom_command(TARGET rhotetrisapp POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:rhotetris>/assets)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
endif()

option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)
endif()
