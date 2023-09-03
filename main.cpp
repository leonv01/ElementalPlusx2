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

    renderPtr = new Render(simulation->getParticleVec(),simulation->getUserInput());

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
    glutKeyboardFunc([](unsigned char key, int x, int y){
        renderPtr->keyboardPress(key, x, y);
    });
    glutMouseWheelFunc([](int wheel, int direction, int x, int y){
        renderPtr->mouseWheel(wheel, direction, x, y);
    });


    glutTimerFunc(0,update, 0);
    glutMainLoop();
    return 0;
}