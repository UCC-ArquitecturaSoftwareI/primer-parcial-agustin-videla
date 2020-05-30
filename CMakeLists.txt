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
        clases/Blocks/Block.h clases/Blocks/Block.cpp clases/Blocks/BlockFactory.h clases/Blocks/BlockFactory.cpp clases/Blocks/Block_Dirt.cpp
        clases/Blocks/Block_Iron.cpp clases/Blocks/Block_Iron.h clases/Tools/Tool.h clases/Tools/Tool_Pickaxe.h
        clases/Tools/ToolFactory.h
        clases/Renderer/Renderer.h clases/Renderer/BlockRenderer.h clases/Renderer/BlockRenderer.cpp
		clases/Renderer/PlayerRenderer.h clases/Renderer/PlayerRenderer.cpp
		clases/Vector2Functions/Vector2Hash.h clases/Vector2Functions/HashFacade.cpp clases/Vector2Functions/SingletonHash.h
		clases/Vector2Functions/Vector2Adaptor.h clases/Vector2Functions/HashFacade.h
		clases/Vector2Functions/VectorTransform.h clases/Vector2Functions/VectorTransform.cpp
		clases/Vector2Functions/Vector2Adaptor.cpp
		clases/Player/Player.h clases/Player/Player.cpp
		clases/Collisions/CollisionObserver.h clases/Collisions/CollisionObserver.cpp
		clases/Collisions/CollisionHandler.h clases/Collisions/CollisionHandler.cpp
		resources/Mapa/SingletonMapa.h resources/Mapa/SingletonMapa.cpp)
add_dependencies(${PROJECT_NAME} raylib)
target_link_libraries(${PROJECT_NAME} ${raylib_LDFLAGS})
target_include_directories(${PROJECT_NAME} PRIVATE ${raylib_INCLUDE_DIRS})

file(COPY "resources/"  DESTINATION "resources/")

include("cmake/raylib_web_post.cmake")
