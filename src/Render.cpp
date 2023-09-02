//
// Created by leon on 9/2/23.
//

#include <iostream>
#include "../include/Render.h"

Render::Render(std::vector<std::vector<unsigned int>>* id){
    idMap = id;
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
            unsigned int id = (*idMap)[((WIN_HEIGHT / CELL_SIZE) - 1) - y][x];

            if(id == 0){
                glColor3f(0.0, 0.0, 0.0); // Set color to black for even tiles
            }
            else if(id == 1){
                glColor3f(1.0, 0.65, 0.0); // Set color to white for odd tiles
            }
            glVertex2i((x * CELL_SIZE) + CELL_CENTER, (y * CELL_SIZE) + CELL_CENTER);
        }
    }
    glEnd();

    glFlush(); // Flush the OpenGL pipeline
}

void Render::init() {

}
