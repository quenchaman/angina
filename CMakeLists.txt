cmake_minimum_required(VERSION 3.5.1)

set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

include(${DIR}/cmake_helpers/helpers.cmake)
set(CMAKE_MODULE_PATH
${CMAKE_MODULE_PATH}
${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/find_modules)

project(angina LANGUAGES CXX)

add_executable(${PROJECT_NAME} 
	${DIR}/main.cpp
	${DIR}/sdl/resources/ImageResource.h 
	${DIR}/sdl/resources/ImageResource.cpp
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
	${DIR}/sdl/graphics/Engine.h
	${DIR}/sdl/graphics/Engine.cpp
	${DIR}/sdl/graphics/Texture.h
	${DIR}/sdl/graphics/Texture.cpp
	${DIR}/sdl/graphics/Renderer.h
	${DIR}/sdl/graphics/Renderer.cpp
	${DIR}/sdl/graphics/Drawable.h
	${DIR}/sdl/components/Window.h
	${DIR}/sdl/components/Window.cpp
	${DIR}/sdl/components/Surface.h
	${DIR}/sdl/components/Surface.cpp
	${DIR}/sdl/primitives/Point.h
	${DIR}/sdl/primitives/Point.cpp
	${DIR}/sdl/primitives/Rect.h
	${DIR}/sdl/primitives/Rect.h
	${DIR}/config/Config.h
	${DIR}/spacekillz/SpaceKillz.h
	${DIR}/spacekillz/SpaceKillz.cpp
	${DIR}/sdl/components/Transformer.h
	${DIR}/sdl/components/Transformer.cpp
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

#find_package(SDL2_ttf REQUIRED)
#find_package(SDL2_mixer REQUIRED)

target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})