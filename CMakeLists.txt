cmake_minimum_required(VERSION 3.5.1)

set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

include(${DIR}/cmake_helpers/helpers.cmake)
set(CMAKE_MODULE_PATH
${CMAKE_MODULE_PATH}
${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/find_modules)

project(chess LANGUAGES CXX)

add_executable(${PROJECT_NAME} 
	${DIR}/main.cpp
	${DIR}/sdl/resources/ResourceLoader.h 
	${DIR}/sdl/resources/ResourceLoader.cpp
	${DIR}/exceptions/ResourceLoadException.h
	${DIR}/exceptions/ResourceLoadException.cpp
	${DIR}/exceptions/GraphicsInitException.h
	${DIR}/exceptions/GraphicsInitException.cpp
	${DIR}/exceptions/WindowInitException.h
	${DIR}/exceptions/WindowInitException.cpp
	${DIR}/exceptions/BaseException.h
	${DIR}/exceptions/BaseException.cpp
	${DIR}/resources/Resources.h
	${DIR}/sdl/graphics/Graphics.h
	${DIR}/sdl/graphics/Graphics.cpp
	${DIR}/sdl/engine/Engine.h
	${DIR}/sdl/engine/Engine.cpp
	${DIR}/sdl/engine/time/Time.h
	${DIR}/sdl/engine/time/Time.cpp
	${DIR}/sdl/engine/thread/ThreadUtils.h
	${DIR}/sdl/engine/thread/ThreadUtils.cpp
	${DIR}/sdl/graphics/Texture.h
	${DIR}/sdl/graphics/Texture.cpp
	${DIR}/sdl/graphics/Renderer.h
	${DIR}/sdl/graphics/Renderer.cpp
	${DIR}/sdl/components/Window.h
	${DIR}/sdl/components/Window.cpp
	${DIR}/sdl/graphics/Surface.h
	${DIR}/sdl/graphics/Surface.cpp
	${DIR}/sdl/primitives/Point.h
	${DIR}/sdl/primitives/Point.cpp
	${DIR}/sdl/primitives/Rect.h
	${DIR}/sdl/primitives/Rect.cpp
	${DIR}/sdl/primitives/Dimensions.h
	${DIR}/sdl/primitives/Color.cpp
	${DIR}/sdl/primitives/Color.h
	${DIR}/config/Config.h
	${DIR}/config/ConfigData.h
	${DIR}/config/ConfigLoader.h
	${DIR}/config/Globals.h
	${DIR}/config/ConfigLoader.cpp
	${DIR}/sdl/graphics/Transformer.h
	${DIR}/sdl/graphics/Transformer.cpp
#	${DIR}/chess/Piece.h
#	${DIR}/chess/Piece.cpp
#	${DIR}/chess/Pawn.h
#	${DIR}/chess/Pawn.cpp
#	${DIR}/chess/Knight.cpp
#	${DIR}/chess/Knight.h
#	${DIR}/chess/Bishop.cpp
#	${DIR}/chess/Bishop.h
#	${DIR}/chess/Rook.cpp
#	${DIR}/chess/Rook.h
#	${DIR}/chess/Queen.cpp
#	${DIR}/chess/Queen.h
#	${DIR}/chess/King.cpp
#	${DIR}/chess/King.h
#	${DIR}/chess/State.h
#	${DIR}/chess/Chess.h
#	${DIR}/chess/Chess.cpp
#	${DIR}/sdl/components/Button.cpp
#	${DIR}/sdl/components/Button.h
#	${DIR}/chess/Move.h
#	${DIR}/chess/Constants.h)
	${DIR}/test/Test.h
	${DIR}/test/Test.cpp
)

set_target_cpp_standard(${PROJECT_NAME} 17)
enable_target_warnings(${PROJECT_NAME})

find_package(SDL2 REQUIRED)

if (WIN32)
	find_package(SDL2_IMAGE REQUIRED)
endif (WIN32)

if (UNIX)
	find_package(SDL2_image REQUIRED)
endif (UNIX)

find_package(SDL2_ttf REQUIRED)
#find_package(SDL2_mixer REQUIRED)

target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR} ${INTERFACE_INCLUDE_DIRECTORIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY})