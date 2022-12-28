cmake_minimum_required(VERSION 3.5.1)

set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

include(${DIR}/cmake_helpers/helpers.cmake)
set(CMAKE_MODULE_PATH
${CMAKE_MODULE_PATH}
${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/find_modules)

project(angina LANGUAGES CXX)

add_executable(${PROJECT_NAME} 
	${DIR}/main.cpp
	${DIR}/enginev2/graphics/sdl/init/Graphics.h
	${DIR}/enginev2/graphics/sdl/init/Graphics.cpp
	${DIR}/enginev2/graphics/sdl/renderer/SurfaceRendererComponent.h
	${DIR}/enginev2/graphics/sdl/renderer/SurfaceRendererComponent.cpp
	${DIR}/enginev2/graphics/sdl/renderer/TextureRendererComponent.h
	${DIR}/enginev2/graphics/sdl/renderer/TextureRendererComponent.cpp
	${DIR}/enginev2/graphics/sdl/renderer/TextureLoaderComponent.h
	${DIR}/enginev2/graphics/sdl/renderer/TextureLoaderComponent.cpp
	${DIR}/enginev2/graphics/sdl/window/Window.h
	${DIR}/enginev2/graphics/sdl/window/Window.cpp
	${DIR}/enginev2/graphics/sdl/primitives/Surface.h
	${DIR}/enginev2/graphics/sdl/primitives/Surface.cpp
	${DIR}/enginev2/graphics/sdl/primitives/Texture.h
	${DIR}/enginev2/graphics/sdl/primitives/Texture.cpp
	${DIR}/enginev2/graphics/sdl/primitives/Rectangle.h
	${DIR}/enginev2/graphics/sdl/primitives/Rectangle.cpp
	${DIR}/enginev2/graphics/commons/primitives/Width.h
	${DIR}/enginev2/graphics/commons/primitives/Height.h
	${DIR}/enginev2/graphics/commons/primitives/Dimensions.h
	${DIR}/enginev2/graphics/commons/primitives/Dimensions.cpp
	${DIR}/enginev2/graphics/commons/primitives/Point.h
	${DIR}/enginev2/graphics/commons/primitives/Point.cpp
	${DIR}/enginev2/graphics/commons/primitives/Color.h
	${DIR}/enginev2/graphics/commons/primitives/Color.cpp
	${DIR}/enginev2/graphics/commons/primitives/Pixel.h
	${DIR}/enginev2/graphics/commons/primitives/Pixel.cpp
	${DIR}/enginev2/graphics/commons/primitives/Line.h
	${DIR}/enginev2/graphics/commons/primitives/Line.cpp
	
	${DIR}/enginev2/models/GameObject.h
	${DIR}/enginev2/models/GameObject.cpp
	
	${DIR}/enginev2/events/EventDefines.h
	${DIR}/enginev2/events/GlobalInputComponent.h
	${DIR}/enginev2/events/GlobalInputComponent.cpp
	
	${DIR}/enginev2/components/SurfaceComponent.h
	${DIR}/enginev2/components/SurfaceComponent.cpp
	${DIR}/enginev2/components/TextureComponent.h
	${DIR}/enginev2/components/TextureComponent.cpp
	${DIR}/enginev2/components/RectangleComponent.h
	${DIR}/enginev2/components/RectangleComponent.cpp
	${DIR}/enginev2/components/PixelComponent.h
	${DIR}/enginev2/components/PixelComponent.cpp
	${DIR}/enginev2/components/LineComponent.h
	${DIR}/enginev2/components/LineComponent.cpp
	${DIR}/enginev2/storage/Container.h
	${DIR}/enginev2/components/GameObjectComponent.h
	${DIR}/enginev2/components/GameObjectComponent.cpp
	${DIR}/enginev2/components/AnimationComponent.h
	${DIR}/enginev2/components/AnimationComponent.cpp
	${DIR}/enginev2/components/PrimitivesComponent.h
	
	${DIR}/enginev2/GameEngine.h
	${DIR}/enginev2/GameEngine.cpp

	${DIR}/enginev2/graphics/animation/Sprite.h
	${DIR}/enginev2/graphics/animation/Sprite.cpp
	${DIR}/enginev2/graphics/animation/SpriteAnimator.h
	${DIR}/enginev2/graphics/animation/SpriteAnimator.cpp

	${DIR}/enginev2/collisions/BoundingBox.h
	${DIR}/enginev2/collisions/BoundingBox.cpp

	${DIR}/platform/ids/ForwardIdGenerator.h
	${DIR}/platform/ids/ForwardIdGenerator.cpp
	${DIR}/platform/ids/IdGenerator.h
	${DIR}/platform/ids/IdGenerator.cpp

	${DIR}/platform/time/TimeUtils.h
	
	${DIR}/examples/test/TestEngine.h
	${DIR}/examples/test/TestEngine.cpp

	
	${DIR}/exceptions/ResourceLoadException.h
	${DIR}/exceptions/ResourceLoadException.cpp
	${DIR}/exceptions/GraphicsInitException.h
	${DIR}/exceptions/GraphicsInitException.cpp
	${DIR}/exceptions/WindowInitException.h
	${DIR}/exceptions/WindowInitException.cpp
	${DIR}/exceptions/BaseException.h
	${DIR}/exceptions/BaseException.cpp
	
	${DIR}/resources/Resources.h
)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_CURRENT_SOURCE_DIR}/resources/chess
	$<TARGET_FILE_DIR:${PROJECT_NAME}>/resources/chess)

set_target_cpp_standard(${PROJECT_NAME} 17)

if (UNIX)
enable_target_warnings(${PROJECT_NAME})
endif (UNIX)


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