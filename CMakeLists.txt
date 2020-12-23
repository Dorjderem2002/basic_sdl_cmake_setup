cmake_minimum_required(VERSION 3.0)
project(program)

find_package(SDL2 REQUIRED)

include_directories(
    ${SDL2_INCLUDE_DIRS}
    include
    external/entt
    external/imgui
)

set (CMAKE_CXX_STANDARD 17)


file(GLOB SOURCES
    "external/imgui/*.cpp"
    "src/*.cpp"
    main.cpp
)

add_executable(program ${SOURCES})
target_link_libraries(program ${SDL2_LIBRARIES})