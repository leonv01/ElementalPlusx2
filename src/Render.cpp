//
// Created by leon on 9/2/23.
//

#include "../include/Render.h"

Render::Render(std::vector<std::vector<Particle>>* particleMap, int* mouseX, int* mouseY, bool* leftMouse){
    this->particleMap = particleMap;
    this->mouseX = mouseX;
    this->mouseY = mouseY;
    this->leftButton = leftMouse;
    //this->leftButton = rightMouse;
}

Render::~Render() = default;

void Render::renderGrid() {

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WIN_WIDTH, 0, WIN_HEIGHT, -1, 1); // Set up orthographic projection

    glColor3f(1.0, 1.0, 1.0); // Set the initial color to white

    // Draw the grid with alternating colors
    glPointSize(CELL_SIZE);
    glBegin(GL_POINTS);

    for(int y = 0; y < WIN_HEIGHT / CELL_SIZE; y++){
        for(int x = 0; x < WIN_WIDTH / CELL_SIZE; x++){
            float color[3];
            (*particleMap)[((WIN_HEIGHT / CELL_SIZE) - 1) - y][x].getColor(&color[0], &color[1], &color[2]);

            glColor3f(color[0], color[1], color[2]);

            glVertex2i((x * CELL_SIZE) + CELL_CENTER, (y * CELL_SIZE) + CELL_CENTER);
        }
    }
    glEnd();

    glFlush(); // Flush the OpenGL pipeline
}

void Render::init() {

}

void Render::mousePosition(int x, int y) const {
    *leftButton = true;
    *mouseX = x / CELL_SIZE;
    *mouseY = y / CELL_SIZE;

    printf("Mouse: (%d, %d)\n", *mouseX, *mouseY);
}

void Render::mouseButtonDown(int button, int state, int x, int y) const {
    if(button == GLUT_LEFT_BUTTON){
        if(state == GLUT_DOWN)
            *leftButton = true;
        else
            *leftButton = false;
    }
}

void Render::resize(int x, int y) {
    glutReshapeWindow(WIN_WIDTH, WIN_HEIGHT);
}
