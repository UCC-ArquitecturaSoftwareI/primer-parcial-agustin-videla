cmake_minimum_required(VERSION 3.12)
project(SquareCraft)

set(CMAKE_CXX_STANDARD 17)

# Get the source together
file(GLOB sources *.cpp)

# Get the source  of classes toegher
file(GLOB sources_clases clases/*.cpp)


include("cmake/raylib_web.cmake")
include("cmake/raylib.cmake")


add_executable(SquareCraft main.cpp
        clases/Blocks/Block.h clases/Blocks/BlockFactory.h clases/Blocks/BlockFactory.cpp clases/Blocks/Block_Dirt.cpp
        clases/Blocks/Block_Iron.cpp clases/Blocks/Block_Iron.h clases/Tools/Tool.h clases/Tools/Tool_Pickaxe.h
		clases/Tools/ToolFactory.h
		Libraries/tileson.hpp
		clases/Renderer/Renderer.h clases/Renderer/BlockRenderer.h clases/Renderer/BlockRenderer.cpp
		clases/Vector2Hash/Vector2Hash.h clases/Vector2Hash/SingletonHash.h clases/Vector2Hash/Vector2Adaptor.h)
add_dependencies(${PROJECT_NAME} raylib)
target_link_libraries(${PROJECT_NAME} ${raylib_LDFLAGS})
target_include_directories(${PROJECT_NAME} PRIVATE ${raylib_INCLUDE_DIRS})

file(COPY "resources/"  DESTINATION "resources/")

include("cmake/raylib_web_post.cmake")
