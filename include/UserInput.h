//
// Created by leon on 9/3/23.
//

#ifndef ELEMENTALPLUSX2_USERINPUT_H
#define ELEMENTALPLUSX2_USERINPUT_H


class UserInput{
private:
    int mouseX;
    int mouseY;

    bool mouseLeft;
    bool mouseRight;
    bool mouseWheelUp;
    bool mouseWheelDown;

    bool keyR;

public:
    UserInput();
    ~UserInput();

    void setMouseX(const int x);
    void setMouseY(const int y);
    void setMouseRight(const bool value);
    void setMouseLeft(const bool value);
    void setMouseWheelUp(const bool value);
    void setMouseWheelDown(const bool value);
    void setKeyR(const bool value);

    int getMouseX() const;
    int getMouseY() const;

    bool getMouseLeft() const;
    bool getMouseRight() const;
    bool getMouseWheelUp() const;
    bool getMouseWheelDown() const;

    bool getKeyR() const;
};

#endif //ELEMENTALPLUSX2_USERINPUT_H
