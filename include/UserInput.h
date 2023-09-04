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
    bool key1;
    bool key2;

public:
    UserInput();
    ~UserInput();

    void setMouseX(int x);
    void setMouseY(int y);
    void setMouseRight(bool value);
    void setMouseLeft(bool value);
    void setMouseWheelUp(bool value);
    void setMouseWheelDown(bool value);
    void setKeyR(bool value);
    void setKey1(bool value);
    void setKey2(bool value);

    int getMouseX() const;
    int getMouseY() const;

    bool getMouseLeft() const;
    bool getMouseRight() const;
    bool getMouseWheelUp() const;
    bool getMouseWheelDown() const;

    bool getKeyR() const;
    bool getKey1() const;
    bool getKey2() const;
};

#endif //ELEMENTALPLUSX2_USERINPUT_H
