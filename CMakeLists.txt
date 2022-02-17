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
	${DIR}/platform/sdl/init/Graphics.h
	${DIR}/platform/sdl/init/Graphics.cpp
	${DIR}/sdl/engine/Engine.h
	${DIR}/sdl/engine/Engine.cpp
	${DIR}/platform/time/Time.h
	${DIR}/platform/time/Time.cpp
	${DIR}/platform/sdl/events/InputEvent.h
	${DIR}platform//sdl/events/InputEvent.cpp
	${DIR}/platform/sdl/events/EventDefines.h
	${DIR}/platform/thread/ThreadUtils.h
	${DIR}/platform/thread/ThreadUtils.cpp
	${DIR}/sdl/engine/object/Object.h
	${DIR}/sdl/engine/object/Object.cpp
	${DIR}/sdl/engine/buttons/ButtonManager.h
	${DIR}/sdl/engine/buttons/ButtonManager.cpp
	${DIR}/sdl/engine/animation/AnimationData.h
	${DIR}/sdl/engine/animation/AnimationManager.h
	${DIR}/sdl/engine/animation/AnimationManager.cpp
	${DIR}/sdl/engine/page/Page.h
	${DIR}/sdl/engine/page/Page.cpp
	${DIR}/sdl/engine/factory/GraphicsFactory.h
	${DIR}/sdl/engine/factory/GraphicsFactory.cpp
	${DIR}/sdl/engine/drawables/Drawable.h
	${DIR}/platform/sdl/primitives/Texture.h
	${DIR}/platform/sdl/primitives/Texture.cpp
	${DIR}/renderer/Renderer.h
	${DIR}/renderer/Renderer.cpp
	${DIR}/platform/sdl/components/Window.h
	${DIR}/platform/sdl/components/Window.cpp
	${DIR}/platform/sdl/primitives/Surface.h
	${DIR}/platform/sdl/primitives/Surface.cpp
	${DIR}/sdl/primitives/Point.h
	${DIR}/sdl/primitives/Point.cpp
	${DIR}/platform/sdl/shapes/Rect.h
	${DIR}/platform/sdl/shapes/Rect.cpp
	${DIR}/sdl/primitives/Dimensions.h
	${DIR}/sdl/primitives/Dimensions.cpp
	${DIR}/sdl/primitives/Color.cpp
	${DIR}/sdl/primitives/Color.h
	${DIR}/config/Config.h
	${DIR}/config/ConfigData.h
	${DIR}/config/ConfigLoader.h
	${DIR}/config/Globals.h
	${DIR}/config/ConfigLoader.cpp
	${DIR}/platform/sdl/enums/Flip.h
	${DIR}/sdl/components/Button.cpp
	${DIR}/sdl/components/Button.h
	#${DIR}/chess-entrypoint/ChessEntryPoint.h
	#${DIR}/chess-entrypoint/ChessEntryPoint.cpp
	#${DIR}/chess-game/pages/LandingPage.h
	#${DIR}/chess-game/pages/LandingPage.cpp
	#${DIR}/chess-game/pages/ChessPage.h
	#${DIR}/chess-game/pages/ChessPage.cpp
	#${DIR}/chess-game/board/Cell.h
	#${DIR}/chess-game/board/Cell.cpp
	#${DIR}/chess-game/board/Board.h
	#${DIR}/chess-game/board/Board.cpp
	#${DIR}/chess-game/pieces/Piece.h
	#${DIR}/chess-game/pieces/Piece.cpp
	#${DIR}/chess-game/pieces/Rank.h
	#${DIR}/chess-game/pieces/Side.h
	#${DIR}/chess-game/pieces/Move.h
	#${DIR}/chess-game/pieces/Move.cpp
	#${DIR}/chess-game/pieces/PieceMoveGenerator.h
	#${DIR}/chess-game/pieces/PieceMoveGenerator.cpp
	#${DIR}/chess-game/pieces/ValidMovesGenerator.h
	#${DIR}/chess-game/pieces/ValidMovesGenerator.cpp
	#${DIR}/chess-game/pieces/PieceValue.h
	#${DIR}/chess-game/states/ChessState.h
	#${DIR}/chess-game/board/PieceSelectionManager.h
	#${DIR}/chess-game/board/PieceSelectionManager.cpp
	#${DIR}/chess-game/board/CellUtils.h
	#${DIR}/chess-game/board/CellUtils.cpp
	#${DIR}/chess-game/ai/AI.h
	#${DIR}/chess-game/ai/AI.cpp
	#${DIR}/chess-game/ai/ScoredMove.h
	#${DIR}/chess-game/ai/ScoredMove.cpp
	#${DIR}/chess-game/utils/VectorShuffler.h
	#${DIR}/chess-game/utils/VectorShuffler.cpp
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