#include <GL/glut.h>
#include "include/Render.h"

Render* renderPtr;

void display(){
    if(renderPtr)
        renderPtr->renderGrid();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("20x20 Pixel Grid");

    renderPtr = new Render;
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}