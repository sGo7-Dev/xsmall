cmake_minimum_required(VERSION 4.0)
project("XSMALL" LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

include("${CMAKE_CURRENT_SOURCE_DIR}/dependencies.cmake")

set(SOURCES "src/main.cpp" "src/app.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE glfw spdlog::spdlog)