#include "menuObjects.hpp"
#include "../input.hpp"
#include "../render.hpp"

#define REFERENCE_WIDTH 400
#define REFERENCE_HEIGHT 240

double MenuObject::getScaleFactor(int windowX, int windowY) {
    double scaleX = static_cast<double>(Render::getWidth()) / windowX;
    double scaleY = static_cast<double>(Render::getHeight()) / windowY;
    return std::min(scaleX, scaleY);
}

ButtonObject::ButtonObject(std::string buttonText, int w, int h, int xPos, int yPos) {
    width = w;
    height = h;
    x = xPos;
    y = yPos;
    scale = 1.0;
    text = createTextObject(buttonText, x, y);
    text->setCenterAligned(true);
}

bool ButtonObject::isPressed() {
    std::vector<int> touchPos = Input::getTouchPosition();

    int touchX = touchPos[0];
    int touchY = touchPos[1];

    double scaleFactor = getScaleFactor(REFERENCE_WIDTH, REFERENCE_HEIGHT);

    double scaledWidth = width * scaleFactor;
    double scaledHeight = height * scaleFactor;

    double proportionX = static_cast<double>(x) / REFERENCE_WIDTH;
    double proportionY = static_cast<double>(y) / REFERENCE_HEIGHT;

    double actualX = proportionX * Render::getWidth();
    double actualY = proportionY * Render::getHeight();

    bool withinX = touchX >= (actualX - scaledWidth) && touchX <= (actualX + (scaledWidth / 2));
    bool withinY = touchY >= actualY && touchY <= (actualY + scaledHeight);

    return withinX && withinY;
}

void ButtonObject::render() {
    double scaleFactor = getScaleFactor(REFERENCE_WIDTH, REFERENCE_HEIGHT);
    double proportionX = static_cast<double>(x) / REFERENCE_WIDTH;
    double proportionY = static_cast<double>(y) / REFERENCE_HEIGHT;

    double actualX = proportionX * Render::getWidth();
    double actualY = proportionY * Render::getHeight();

    text->setScale(scale * scaleFactor);
    text->render(actualX, actualY);
}

MenuImage::MenuImage(std::string filePath, int xPos, int yPos) {
    x = xPos;
    y = yPos;
    image = new Image(filePath);
}

void MenuImage::render() {

    double proportionX = static_cast<double>(x) / REFERENCE_WIDTH;
    double proportionY = static_cast<double>(y) / REFERENCE_HEIGHT;

    double actualX = proportionX * Render::getWidth();
    double actualY = proportionY * Render::getHeight();

    image->render(actualX, actualY, true);
}

MenuImage::~MenuImage() {
    delete image;
}