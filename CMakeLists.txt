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
	${DIR}/platform/sdl/init/Audio.h
	${DIR}/platform/sdl/init/Audio.cpp
	${DIR}/engine/Engine.h
	${DIR}/engine/Engine.cpp
	${DIR}/platform/time/Time.h
	${DIR}/platform/time/Time.cpp
	${DIR}/platform/sdl/events/InputEvent.h
	${DIR}/platform/sdl/events/InputEvent.cpp
	${DIR}/platform/sdl/events/EventDefines.h
	${DIR}/platform/thread/ThreadUtils.h
	${DIR}/platform/thread/ThreadUtils.cpp
	${DIR}/renderer/primitives/Object.h
	${DIR}/renderer/primitives/Object.cpp
	${DIR}/engine/managers/ButtonManager.h
	${DIR}/engine/managers/ButtonManager.cpp
	${DIR}/engine/widget/Widget.h
	${DIR}/engine/widget/Widget.cpp
	${DIR}/engine/factory/GraphicsFactory.h
	${DIR}/engine/factory/GraphicsFactory.cpp
	${DIR}/renderer/drawable/Drawable.h
	${DIR}/platform/sdl/primitives/Texture.h
	${DIR}/platform/sdl/primitives/Texture.cpp
	${DIR}/platform/sdl/primitives/Font.h
	${DIR}/platform/sdl/primitives/Font.cpp
	${DIR}/renderer/Renderer.h
	${DIR}/renderer/Renderer.cpp
	${DIR}/platform/sdl/components/Window.h
	${DIR}/platform/sdl/components/Window.cpp
	${DIR}/platform/sdl/primitives/Surface.h
	${DIR}/platform/sdl/primitives/Surface.cpp
	${DIR}/renderer/primitives/Point.h
	${DIR}/renderer/primitives/Point.cpp
	${DIR}/renderer/shapes/Rect.h
	${DIR}/renderer/shapes/Rect.cpp
	${DIR}/renderer/primitives/Dimensions.h
	${DIR}/renderer/primitives/Dimensions.cpp
	${DIR}/renderer/primitives/Color.cpp
	${DIR}/renderer/primitives/Color.h
	${DIR}/renderer/utils/PrimitivesUtils.h
	${DIR}/renderer/utils/PrimitivesUtils.cpp
	${DIR}/engine/components/buttons/BaseButton.h
	${DIR}/engine/components/buttons/BaseButton.cpp
	${DIR}/engine/components/buttons/RectTextButton.h
	${DIR}/engine/components/buttons/RectTextButton.cpp
	${DIR}/engine/components/textstack/TextStack.h
	${DIR}/engine/components/textstack/TextStack.cpp
	${DIR}/engine/repositories/TextRepository.h
	${DIR}/engine/repositories/TextRepository.cpp
	${DIR}/engine/config/EngineConfig.h
	${DIR}/platform/sdl/enums/Flip.h
	${DIR}/renderer/primitives/Button.cpp
	${DIR}/renderer/primitives/Button.h
	${DIR}/core/math/geometry/Geometry.h
	${DIR}/core/math/geometry/Geometry.cpp
	${DIR}/renderer/primitives/Transformation.h
	${DIR}/renderer/primitives/Transformation.cpp
	${DIR}/renderer/primitives/Text.h
	${DIR}/renderer/primitives/Text.cpp
	${DIR}/engine/primitives/cell/Cell.h
	${DIR}/engine/primitives/cell/Cell.cpp
	${DIR}/examples/chess/chess-engine/ChessBoard.cpp
	${DIR}/examples/chess/chess-engine/ChessBoard.h
	${DIR}/examples/chess/chess-engine/ChessMoveManager.cpp
	${DIR}/examples/chess/chess-engine/ChessMoveManager.h
	${DIR}/examples/chess/chess-engine/ChessEngine.cpp
	${DIR}/examples/chess/chess-engine/ChessEngine.h
	${DIR}/examples/chess/chess-engine/Move.h
	${DIR}/examples/chess/chess-engine/Move.cpp
	${DIR}/examples/chess/chess-engine/Piece.h
	${DIR}/examples/chess/chess-engine/Piece.cpp
	${DIR}/examples/chess/chess-engine/Rank.h
	${DIR}/examples/chess/chess-engine/Side.h
	${DIR}/examples/chess/ChessGame.h
	${DIR}/examples/chess/ChessGame.cpp
	${DIR}/examples/chess/chess-engine/ChessState.h
	${DIR}/engine/primitives/cell/CellUtils.h
	${DIR}/examples/chess/chess-engine/BoardBoundsPieceMoveGenerator.h
	${DIR}/examples/chess/chess-engine/BoardBoundsPieceMoveGenerator.cpp
	${DIR}/examples/chess/chess-engine/FriendlyFireExcludedMoveGenerator.h
	${DIR}/examples/chess/chess-engine/FriendlyFireExcludedMoveGenerator.cpp
	${DIR}/examples/chess/chess-engine/ChessMoveLog.h
	${DIR}/examples/chess/chess-engine/ChessMoveLog.cpp
	${DIR}/examples/chess/chess-engine/MoveLogWidget.h
	${DIR}/examples/chess/chess-engine/MoveLogWidget.cpp
	${DIR}/examples/chess/chess-engine/PlayerType.h
	${DIR}/examples/chess/GameConfig.h
	${DIR}/platform/ids/IdGenerator.h
	${DIR}/platform/ids/IdGenerator.cpp
	${DIR}/platform/ids/ForwardIdGenerator.h
	${DIR}/platform/ids/ForwardIdGenerator.cpp
	${DIR}/platform/ids/ReverseIdGenerator.h
	${DIR}/platform/ids/ReverseIdGenerator.cpp
	${DIR}/platform/filesys/FileSystem.h
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_CURRENT_SOURCE_DIR}/resources/chess
	$<TARGET_FILE_DIR:${PROJECT_NAME}>/resources/chess)

set_target_cpp_standard(${PROJECT_NAME} 17)

# Add static lib headers for linux
if (UNIX)
include_directories(
    ${DIR}/libs/linux/SDL/include/SDL2
)

target_link_libraries(
    ${PROJECT_NAME} PRIVATE ${DIR}/libs/linux/SDL/lib/libSDL2.a
)
endif(UNIX)

# Add static libraries' headers for windows
if (WIN32)
include_directories(
    ${DIR}/libs/win/SDL2-2.28.1/include
    ${DIR}/libs/win/SDL2_ttf-2.20.2/include
    ${DIR}/libs/win/SDL2_mixer-2.6.3/include
    ${DIR}/libs/win/SDL2_image-2.6.3/include
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    ${DIR}/libs/win/SDL2-2.28.1/lib/x64/SDL2.lib
    ${DIR}/libs/win/SDL2_image-2.6.3/lib/x64/SDL2_image.lib
    ${DIR}/libs/win/SDL2_ttf-2.20.2/lib/x64/SDL2_ttf.lib
    ${DIR}/libs/win/SDL2_mixer-2.6.3/lib/x64/SDL2_mixer.lib
)

# Function to add a post-build command for copying DLLs to the output directory
function(move_to_exe_folder dllSrcPath dllName)
    add_custom_command(
        TARGET ${PROJECT_NAME}  # Assumes you have a target defined with the project name
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${dllSrcPath}/${dllName}  # Source path to the DLL
            $<TARGET_FILE_DIR:${PROJECT_NAME}>  # Destination: directory of the target executable
    )
endfunction()

# Call the function to copy each DLL to the executable output folder
move_to_exe_folder(${CMAKE_CURRENT_SOURCE_DIR}/libs/win/SDL2-2.28.1/lib/x64 SDL2.dll)
move_to_exe_folder(${CMAKE_CURRENT_SOURCE_DIR}/libs/win/SDL2_image-2.6.3/lib/x64 SDL2_image.dll)
move_to_exe_folder(${CMAKE_CURRENT_SOURCE_DIR}/libs/win/SDL2_ttf-2.20.2/lib/x64 SDL2_ttf.dll)
move_to_exe_folder(${CMAKE_CURRENT_SOURCE_DIR}/libs/win/SDL2_mixer-2.6.3/lib/x64 SDL2_mixer.dll)

endif(WIN32)

target_include_directories(${PROJECT_NAME} PRIVATE ${DIR})
