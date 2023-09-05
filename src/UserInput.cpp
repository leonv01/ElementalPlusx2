//
// Created by leon on 9/3/23.
//

#include "../include/UserInput.h"


void UserInput::setMouseX(const int x) {
    mouseX = x;
}

void UserInput::setMouseY(const int y) {
    mouseY = y;
}

int UserInput::getMouseX() const {
    return mouseX;
}

int UserInput::getMouseY() const {
    return mouseY;
}

bool UserInput::getMouseLeft() const {
    return mouseLeft;
}

bool UserInput::getMouseRight() const {
    return mouseRight;
}

bool UserInput::getMouseWheelUp() const {
    return mouseWheelUp;
}

bool UserInput::getMouseWheelDown() const {
    return mouseWheelDown;
}

bool UserInput::getKeyR() const {
    return keyR;
}
void UserInput::setMouseRight(const bool value){
    mouseRight = value;
}
void UserInput::setMouseLeft(const bool value){
    mouseLeft = value;
}
void UserInput::setMouseWheelUp(const bool value){
    mouseWheelUp = value;
}
void UserInput::setMouseWheelDown(const bool value){
    mouseWheelDown = value;
}
void UserInput::setKeyR(const bool value){
    keyR = value;
}

UserInput::UserInput() {
     mouseX = 0;
     mouseY = 0;

     mouseLeft= false;
     mouseRight= false;
     mouseWheelUp= false;
     mouseWheelDown= false;

     keyR = false;
}

bool UserInput::getKey1() const {
    return key1;
}

bool UserInput::getKey2() const {
    return key2;
}

void UserInput::setKey1(const bool value) {
    key1 = value;
}

void UserInput::setKey2(bool value) {
    key2 = value;
}

bool UserInput::getKeyQ() const {
    return keyQ;
}

void UserInput::setKeyQ(bool value) {
    keyQ = value;
}

UserInput::~UserInput() = default;
