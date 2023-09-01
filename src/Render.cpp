//
// Created by leon on 9/2/23.
//

#include "../include/Render.h"

Render::Render() = default;

void Render::renderGrid() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 400, 0, 400, -1, 1); // Set up orthographic projection

    glColor3f(1.0, 1.0, 1.0); // Set the initial color to white

    // Draw the 20x20 pixel grid with alternating colors
    glPointSize(20.0); // Set the point size to 20x20 pixels
    glBegin(GL_POINTS);
    for (int x = 10; x < 400; x += 20) {
        for (int y = 10; y < 400; y += 20) {
            if ((x / 20 + y / 20) % 2 == 0) {
                glColor3f(0.0, 0.0, 0.0); // Set color to black for even tiles
            } else {
                glColor3f(1.0, 1.0, 1.0); // Set color to white for odd tiles
            }
            glVertex2i(x, y);
        }
    }
    glEnd();

    glFlush(); // Flush the OpenGL pipeline
}

