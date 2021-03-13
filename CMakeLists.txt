cmake_minimum_required (VERSION 3.18.2)
set(CMAKE_CXX_STANDARD 17)
project(arkavquarium)
set(APP_TARGET arkavquarium)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
                    ${SDL2_IMAGE_INCLUDE_DIR}
                    ${SDL2_TTF_INCLUDE_DIR})

add_custom_target(copy_assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/assets ${CMAKE_CURRENT_BINARY_DIR}/assets
)

enable_testing()
include(GoogleTest)
add_subdirectory(test)

include_directories(
    include
)

add_library(ArkavQuariumLib STATIC 
    include/LinkedList.hpp
    src/Aquarium.cpp
    src/Aquatic.cpp
    src/Coin.cpp
    src/Fish.cpp
    src/Game.cpp
    src/Graphics.cpp
    src/Guppy.cpp
    src/Helper.cpp
    src/Pellet.cpp
    src/Piranha.cpp
    src/Snail.cpp
)

add_executable(
    ${PROJECT_NAME}
    main.cpp
)

add_dependencies(${PROJECT_NAME} copy_assets)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC ${SDL2_INCLUDE_DIR}
)

target_link_libraries(
    ${PROJECT_NAME}
    ${SDL2_LIBRARY}
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
    ArkavQuariumLib
)
