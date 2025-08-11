#pragma once
#include "../image.hpp"
#include "../text.hpp"

class MenuObject {
  public:
    double x;
    double y;
    double scale;
    virtual void render() = 0;
    double getScaleFactor(int windowX, int windowY);
};

class ButtonObject : public MenuObject {
  private:
    int width;
    int height;
    TextObject *text;

  public:
    bool isSelected = false;
    ButtonObject *buttonUp;
    ButtonObject *buttonDown;
    ButtonObject *buttonLeft;
    ButtonObject *buttonRight;

    void render() override;
    bool isPressed();

    /*
     * Simple button object.
     * @param buttonText
     * @param width
     * @param height
     * @param xPosition
     * @param yPosition
     */
    ButtonObject(std::string buttonText, int w = 16, int h = 16, int xPos = 0, int yPos = 0);
};

class MenuImage : public MenuObject {
  private:
    Image *image;

  public:
    void render() override;

    /*
     * Similar to Image class, but with auto scaling and positioning.
     * @param filePath
     * @param xPosition
     * @param yPosition
     */
    MenuImage(std::string filePath, int xPos = 0, int yPos = 0);
    ~MenuImage();
};