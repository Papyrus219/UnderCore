cmake_minimum_required(VERSION 3.10)
project(Undercore)

add_library(glad STATIC glad/src/glad.c)

target_include_directories(glad PUBLIC ${CMAKE_SOURCE_DIR}/glad/include)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

set(Camera_src src/camera/camera.cpp
src/camera/fly_camera.cpp
src/camera/fps_camera.cpp)

set(Geometry_src src/geometry/mesh.cpp
src/geometry/vertex.cpp)

set(Texture_src src/texture/stb_image.cpp
src/texture/texture.cpp)

set(Window_src src/window/event.cpp
src/window/window.cpp)

set(Other_src src/setup.cpp
src/shader.cpp)

add_library(${PROJECT_NAME} STATIC ${Camera_src} ${Geometry_src} ${Texture_src} ${Window_src} ${Other_src})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include/)

target_link_libraries(${PROJECT_NAME} PRIVATE
    glm::glm
    glad
    glfw
    OpenGL::GL
)

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()
