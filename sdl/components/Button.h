//
// Created by ubuntu on 12/4/21.
//

#ifndef ANGINA_BUTTON_H
#define ANGINA_BUTTON_H
#include <cstdlib>

struct Texture;
struct Point;
struct Rect;

class Button {
public:
    Button(int32_t x, int32_t y, const Texture& texture);
    ~Button();
    int32_t getX();
    int32_t getY();
    bool isClicked(const Point& p);
private:
    int32_t x;
    int32_t y;
    Texture& texture;
    Rect* rect;
};


#endif //ANGINA_BUTTON_H
