cmake_minimum_required(VERSION 3.1...3.25)

project(
    sandbox
    VERSION 0.1.0
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_subdirectory(src)

add_subdirectory(external/glad/cmake)

glad_add_library(glad REPRODUCIBLE MX API gl:core=3.3)

add_subdirectory(external/glfw)

add_subdirectory(external/glm)

add_subdirectory(external/googletest)

add_subdirectory(testbed)

