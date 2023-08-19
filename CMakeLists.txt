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
	${DIR}/enginev2/graphics/models/Width.h
	${DIR}/enginev2/graphics/models/Height.h
	${DIR}/enginev2/graphics/models/Dimensions.h
	${DIR}/enginev2/graphics/models/Dimensions.cpp
	${DIR}/enginev2/graphics/models/Point.h
	${DIR}/enginev2/graphics/models/Point.cpp
	${DIR}/enginev2/graphics/models/Color.h
	${DIR}/enginev2/graphics/models/Color.cpp
	${DIR}/enginev2/graphics/models/Pixel.h
	${DIR}/enginev2/graphics/models/Pixel.cpp
	${DIR}/enginev2/graphics/models/Line.h
	${DIR}/enginev2/graphics/models/Line.cpp
	
	${DIR}/enginev2/models/GameObject.h
	${DIR}/enginev2/models/GameObject.cpp
	${DIR}/enginev2/models/Direction.h
	
	${DIR}/enginev2/events/EventDefines.h
	${DIR}/enginev2/events/GlobalInputComponent.h
	${DIR}/enginev2/events/GlobalInputComponent.cpp
	${DIR}/enginev2/components/AnimationComponent.h
	${DIR}/enginev2/components/AnimationComponent.cpp
	${DIR}/enginev2/components/PrimitivesStorage.h
	${DIR}/enginev2/components/ID.h
	
	${DIR}/enginev2/GameEngine.h
	${DIR}/enginev2/GameEngine.cpp

	${DIR}/enginev2/graphics/animation/Sprite.h
	${DIR}/enginev2/graphics/animation/Sprite.cpp
	${DIR}/enginev2/graphics/animation/SpriteAnimator.h
	${DIR}/enginev2/graphics/animation/SpriteAnimator.cpp

	${DIR}/enginev2/debug/Debug.h
	${DIR}/enginev2/debug/Debug.cpp

	${DIR}/enginev2/collisions/BoundingBox.h
	${DIR}/enginev2/collisions/BoundingBox.cpp
	${DIR}/enginev2/collisions/CollisionDetector.h
	${DIR}/enginev2/collisions/CollisionDetector.cpp

	${DIR}/enginev2/platform/time/Time.h
	${DIR}/enginev2/platform/time/Time.cpp

	${DIR}/enginev2/platform/thread/ThreadUtils.h
	${DIR}/enginev2/platform/thread/ThreadUtils.cpp

	${DIR}/enginev2/movement/MovementCmpt.h
	${DIR}/enginev2/movement/MovementCmpt.cpp

	${DIR}/platform/ids/ForwardIdGenerator.h
	${DIR}/platform/ids/ForwardIdGenerator.cpp
	${DIR}/platform/ids/IdGenerator.h
	${DIR}/platform/ids/IdGenerator.cpp
	
	${DIR}/examples/SkeletalRainOfBlood/Game.h
	${DIR}/examples/SkeletalRainOfBlood/Game.cpp
	
	${DIR}/exceptions/BaseException.h
	${DIR}/exceptions/BaseException.cpp
	
	${DIR}/resources/Resources.h
)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_CURRENT_SOURCE_DIR}/resources
	$<TARGET_FILE_DIR:${PROJECT_NAME}>/resources)

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