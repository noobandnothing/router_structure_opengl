#include "shapes2D.hpp"
#include "mydraw.hpp"
#include "myTransform.hpp"


void myinit() {
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(700,250);
    glutCreateWindow("Geometric Shapes");
}


void important_STUFF(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0,0,0);
    glLoadIdentity();
    glTranslated(posX,posY,posZ);
    glScalef(sx,sy,sz);
    glRotatef(angle,rx,ry,rz);
}

void display() {
    important_STUFF();
    drawMYROUTER();
    glutSpecialFunc(keyboardArrowsTrans);
    glutKeyboardFunc(keyboardKeysScale);
    glFlush();
}


void reshape(int width,int height){
    glMatrixMode(GL_PROJECTION);
    glViewport(0,0,width,height);
    float aspect = ((double)width)/height;
    glLoadIdentity();
    gluPerspective(160.0,aspect,1.0,100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	myinit();
	glutDisplayFunc(display);
    glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
