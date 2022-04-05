cmake_minimum_required(VERSION 3.5.1)

set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

include(${DIR}/cmake_helpers/helpers.cmake)
set(CMAKE_MODULE_PATH
${CMAKE_MODULE_PATH}
${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/find_modules)

project(angina LANGUAGES CXX)

add_executable(${PROJECT_NAME} 
	${DIR}/main.cpp
	
	${DIR}/platform/sdl/resource-loader/ResourceLoader.h 
	${DIR}/platform/sdl/resource-loader/ResourceLoader.cpp
	${DIR}/platform/sdl/events/InputEvent.h
	${DIR}/platform/sdl/events/InputEvent.cpp
	${DIR}/platform/sdl/events/EventDefines.h
	${DIR}/platform/sdl/primitives/Texture.h
	${DIR}/platform/sdl/primitives/Texture.cpp
	${DIR}/platform/sdl/primitives/Font.h
	${DIR}/platform/sdl/primitives/Font.cpp
	${DIR}/platform/sdl/components/Window.h
	${DIR}/platform/sdl/components/Window.cpp
	${DIR}/platform/sdl/primitives/Surface.h
	${DIR}/platform/sdl/primitives/Surface.cpp
	${DIR}/platform/sdl/enums/Flip.h
	${DIR}/platform/sdl/repositories/SurfaceRepository.h
	${DIR}/platform/sdl/repositories/Cache.h
	${DIR}/platform/sdl/repositories/SurfaceCache.h
	${DIR}/platform/sdl/repositories/TextureCache.h
	${DIR}/platform/sdl/repositories/TextureRepository.h
	${DIR}/platform/sdl/repositories/TextureRepository.cpp
	${DIR}/platform/sdl/repositories/SurfaceRepository.h
	${DIR}/platform/sdl/repositories/SurfaceRepository.cpp
	${DIR}/platform/sdl/init/Graphics.h
	${DIR}/platform/sdl/init/Graphics.cpp
	${DIR}/platform/sdl/init/Audio.h
	${DIR}/platform/sdl/init/Audio.cpp
	
	${DIR}/platform/time/Time.h
	${DIR}/platform/time/Time.cpp
	${DIR}/platform/thread/ThreadUtils.h
	${DIR}/platform/thread/ThreadUtils.cpp
	
	${DIR}/platform/ids/IdGenerator.h
	${DIR}/platform/ids/IdGenerator.cpp
	${DIR}/platform/ids/ForwardIdGenerator.h
	${DIR}/platform/ids/ForwardIdGenerator.cpp
	${DIR}/platform/ids/ReverseIdGenerator.h
	${DIR}/platform/ids/ReverseIdGenerator.cpp
	${DIR}/platform/filesys/FileSystem.h
	${DIR}/platform/sdl/translators/Translators.h
	
	${DIR}/exceptions/ResourceLoadException.h
	${DIR}/exceptions/ResourceLoadException.cpp
	${DIR}/exceptions/GraphicsInitException.h
	${DIR}/exceptions/GraphicsInitException.cpp
	${DIR}/exceptions/WindowInitException.h
	${DIR}/exceptions/WindowInitException.cpp
	${DIR}/exceptions/BaseException.h
	${DIR}/exceptions/BaseException.cpp
	
	${DIR}/resources/Resources.h
	
	${DIR}/renderer/primitives/Object.h
	${DIR}/renderer/primitives/Object.cpp
	${DIR}/renderer/primitives/Point.h
	${DIR}/renderer/primitives/Point.cpp
	${DIR}/renderer/primitives/Dimensions.h
	${DIR}/renderer/primitives/Dimensions.cpp
	${DIR}/renderer/primitives/Color.cpp
	${DIR}/renderer/primitives/Color.h
	${DIR}/renderer/primitives/Button.cpp
	${DIR}/renderer/primitives/Button.h
	${DIR}/renderer/shapes/Rect.h
	${DIR}/renderer/shapes/Rect.cpp
	${DIR}/renderer/utils/PrimitivesUtils.h
	${DIR}/renderer/utils/PrimitivesUtils.cpp
	${DIR}/renderer/drawable/Drawable.h
	${DIR}/renderer/primitives/Transformation.h
	${DIR}/renderer/primitives/Transformation.cpp
	${DIR}/renderer/primitives/Text.h
	${DIR}/renderer/primitives/Text.cpp
	${DIR}/renderer/Renderer.h
	${DIR}/renderer/Renderer.cpp
	
	${DIR}/engine/managers/ButtonManager.h
	${DIR}/engine/managers/ButtonManager.cpp
	${DIR}/engine/widget/Widget.h
	${DIR}/engine/widget/Widget.cpp
	${DIR}/engine/factory/GraphicsFactory.h
	${DIR}/engine/factory/GraphicsFactory.cpp
	${DIR}/engine/components/buttons/BaseButton.h
	${DIR}/engine/components/buttons/BaseButton.cpp
	${DIR}/engine/components/buttons/RectTextButton.h
	${DIR}/engine/components/buttons/RectTextButton.cpp
	${DIR}/engine/components/textstack/TextStack.h
	${DIR}/engine/components/textstack/TextStack.cpp
	${DIR}/engine/primitives/cell/CellUtils.h
	${DIR}/engine/primitives/cell/Cell.h
	${DIR}/engine/primitives/cell/Cell.cpp
	${DIR}/engine/config/EngineConfig.h
	${DIR}/engine/Engine.h
	${DIR}/engine/Engine.cpp
	
	${DIR}/core/math/geometry/Geometry.h
	${DIR}/core/math/geometry/Geometry.cpp
	
	${DIR}/examples/test/Test.h
	${DIR}/examples/test/Test.cpp
	
	#${DIR}/examples/chess/chess-engine/ChessBoard.cpp
#	${DIR}/examples/chess/chess-engine/ChessBoard.h
#	${DIR}/examples/chess/chess-engine/ChessMoveManager.cpp
#	${DIR}/examples/chess/chess-engine/ChessMoveManager.h
#	${DIR}/examples/chess/chess-engine/ChessEngine.cpp
#	${DIR}/examples/chess/chess-engine/ChessEngine.h
#	${DIR}/examples/chess/chess-engine/Move.h
#	${DIR}/examples/chess/chess-engine/Move.cpp
#	${DIR}/examples/chess/chess-engine/Piece.h
#	${DIR}/examples/chess/chess-engine/Piece.cpp
#	${DIR}/examples/chess/chess-engine/Rank.h
#	${DIR}/examples/chess/chess-engine/Side.h
#	${DIR}/examples/chess/ChessGame.h
#	${DIR}/examples/chess/ChessGame.cpp
#	${DIR}/examples/chess/chess-engine/ChessState.h
#	${DIR}/examples/chess/chess-engine/BoardBoundsPieceMoveGenerator.h
#	${DIR}/examples/chess/chess-engine/BoardBoundsPieceMoveGenerator.cpp
#	${DIR}/examples/chess/chess-engine/FriendlyFireExcludedMoveGenerator.h
#	${DIR}/examples/chess/chess-engine/FriendlyFireExcludedMoveGenerator.cpp
#	${DIR}/examples/chess/chess-engine/ChessMoveLog.h
#	${DIR}/examples/chess/chess-engine/ChessMoveLog.cpp
#	${DIR}/examples/chess/chess-engine/MoveLogWidget.h
#	${DIR}/examples/chess/chess-engine/MoveLogWidget.cpp
#	${DIR}/examples/chess/chess-engine/PlayerType.h
#	${DIR}/examples/chess/GameConfig.h
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_CURRENT_SOURCE_DIR}/resources/chess
	$<TARGET_FILE_DIR:${PROJECT_NAME}>/resources/chess)

set_target_cpp_standard(${PROJECT_NAME} 17)
enable_target_warnings(${PROJECT_NAME})

find_package(SDL2 REQUIRED)

if (WIN32)
	find_package(SDL2_IMAGE REQUIRED)
endif (WIN32)

if (UNIX)
	find_package(SDL2_image REQUIRED)
endif (UNIX)

if (UNIX)
	find_package(SDL2_ttf REQUIRED)
endif (UNIX)

if (WIN32)
	find_package(SDL2_TTF REQUIRED)
endif (WIN32)

if (WIN32)
	find_package(SDL2_MIXER REQUIRED)
endif (WIN32)

if (UNIX)
	find_package(SDL2_mixer REQUIRED)
endif (UNIX)

target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIR} ${SDL2_MIXER_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR} ${INTERFACE_INCLUDE_DIRECTORIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY} ${SDL2_MIXER_LIBRARY})