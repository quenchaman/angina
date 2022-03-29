# angina

`angina` is a cross-platform game engine with graphics, audio handled by SDL 2 and build system with CMake.

It is written from scratch, with help of tutorials on [LazyFoo Game Tuts with SDL](https://lazyfoo.net/tutorials/SDL/index.php) and [C++ Applications Dev Course](https://softuni.bg/trainings/3556/applications-development-with-c-plus-plus-october-2021)

Users of `angina` should inherit from the main `Engine` class and build their own game! :)

## Project structure

- `platform` - Low level module. SDL wrappers (Surface, Texture), thread and time libraries.
- `renderer` - Low level module. Renderer and primitives - Object, Point.
- `engine` - Mid level module. Uses renderer, contains class that drives game loop.
- `core` - Low level module for math, physics libraries, etc. of that sort.
- `examples` - Implementations of games, built with the engine.
- `resources` - Place for all the assets of the game and a header file that exposes paths to them.

## Steps to run:

- Go to `build` folder
- `cmake ..`

Ubuntu 20.04 (TODO: add compiler version here)
- `make`
- `./angina`

Windows 10 using MinGW (TODO: add compiler version here)
- `mingw32-make`
- `./angina.exe`

MacOS (TODO: Test whether it runs on MACOS!)

## Getting started with your own game!

Step 1: Inherit Engine class and implement virtual methods.
Step 2: Create a component and add it to main screen

```cpp
void Test::callbackFunc() {
	std::cout << "Hello ! I am the clicked button! The secret is " << privateNumber << std::endl;
}

void Test::init() {
	Point p = { 0, 0 };
	Dimensions dim = { 200, 70 };
	Color background = Color::BLUE;
	Color textColor = Color::RED;
	std::string txt = "Click me!";

  // Here we use a factory to create a button and add a callback to it.
	RectTextButton* btn = getFactory().createButton(p, dim, background, textColor, txt, defaultFont, std::bind(&Test::callbackFunc, this));

	rootScreen.put(*btn); --> Putting the button on the main screen.
}
```

Step 3: Instantiate your game engine and do not forget to startup SDL.

```cpp
#include <cstdint>
#include <cstdlib>
#include <iostream>

#include "platform/sdl/init/Graphics.h"

#include "test/Test.h"
#include "exceptions/BaseException.h"

int32_t main([[maybe_unused]] int32_t argc, [[maybe_unused]] char** argv) {
	try {
		Graphics::boot();
		Graphics::bootImageExtension();
		Graphics::bootTTFExtensions();

		Engine* game = new Test();

		game->start();

		delete game;

		Graphics::shutdown();

		return EXIT_SUCCESS;
	} catch (const BaseException& ex) {
		std::cerr << ex << std::endl;

		Graphics::shutdown();

		return EXIT_FAILURE;
	}
}
```

## Nice to have
1. Create common interface for piece move generators.