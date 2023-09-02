#include <GL/glut.h>
#include "include/Render.h"
#include "include/Simulation.h"

Render* renderPtr;
Simulation* simulation;


void display(){
    if(renderPtr)
        renderPtr->renderGrid();
}

void update(int value){
    simulation->update();

    glutPostRedisplay();
    glutTimerFunc(1, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(Render::WIN_WIDTH, Render::WIN_HEIGHT);
    glutCreateWindow("ElementalPlusx2");

    simulation = new Simulation;

    std::vector<std::vector<unsigned int>>* idMap;
    idMap = simulation->getIdMap();
    renderPtr = new Render(idMap);

    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}