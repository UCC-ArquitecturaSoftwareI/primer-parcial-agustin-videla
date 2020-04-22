cmake_minimum_required(VERSION 3.12)
project(SquareCraft)

set(CMAKE_CXX_STANDARD 17)

# Get the source together
file(GLOB sources *.cpp)

# Get the source  of classes toegher
file(GLOB sources_clases clases/blocks/*.cpp)


include("cmake/raylib_web.cmake")
include("cmake/raylib.cmake")


add_executable(${PROJECT_NAME} ${sources} ${sources_clases}
        clases/blocks/Block.h clases/blocks/BlockFactory.h clases/blocks/Block_Dirt.cpp clases/blocks/Block_Iron.cpp clases/blocks/Block_Iron.h)
add_dependencies(${PROJECT_NAME} raylib)
target_link_libraries(${PROJECT_NAME} ${raylib_LDFLAGS})
target_include_directories(${PROJECT_NAME} PRIVATE ${raylib_INCLUDE_DIRS})

file(COPY "resources/"  DESTINATION "resources/")

include("cmake/raylib_web_post.cmake")