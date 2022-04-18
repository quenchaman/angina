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
	${DIR}/enginev2/graphics/sdl/window/Window.h
	${DIR}/enginev2/graphics/sdl/window/Window.cpp
	${DIR}/enginev2/graphics/sdl/primitives/Surface.h
	${DIR}/enginev2/graphics/sdl/primitives/Surface.cpp
	${DIR}/enginev2/graphics/sdl/primitives/Texture.h
	${DIR}/enginev2/graphics/sdl/primitives/Texture.cpp
	${DIR}/enginev2/graphics/commons/primitives/Width.h
	${DIR}/enginev2/graphics/commons/primitives/Height.h
	
	${DIR}/enginev2/events/EventDefines.h
	${DIR}/enginev2/events/GlobalInputComponent.h
	${DIR}/enginev2/events/GlobalInputComponent.cpp
	
	${DIR}/enginev2/components/SurfaceComponent.h
	${DIR}/enginev2/components/SurfaceComponent.cpp
	${DIR}/enginev2/components/TextureComponent.h
	${DIR}/enginev2/components/TextureComponent.cpp
	
	${DIR}/enginev2/GameEngine.h
	${DIR}/enginev2/GameEngine.cpp
	
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