#include <GL/glut.h>
#include "include/Render.h"
#include "include/Simulation.h"

Render* renderPtr;
Simulation* simulation;

void update(int value){
    simulation->update();

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(Render::WIN_WIDTH, Render::WIN_HEIGHT);
    glutCreateWindow("ElementalPlusx2");

    simulation = new Simulation;

    std::vector<std::vector<unsigned int>>* idMap;
    idMap = simulation->getIdMap();
    renderPtr = new Render(idMap, simulation->getMouseX(), simulation->getMouseY(), simulation->getLeftMouse());

    glutDisplayFunc([](){
        renderPtr->renderGrid();
    });
    glutMouseFunc([](int button, int state, int x, int y){
       renderPtr->mouseButtonDown(button, state, x, y);
    });
    glutMotionFunc([](int x, int y){
        renderPtr->mousePosition(x, y);
    });
    glutReshapeFunc([](int x, int y){
        Render::resize(x,y);
    });


    glutTimerFunc(0,update, 0);
    glutMainLoop();
    return 0;
}