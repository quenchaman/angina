# angina

## Steps to run:

- Go to `build` folder
- `cmake ..`
- `make`
- `./chess`

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