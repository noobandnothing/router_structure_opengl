#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <math.h>
using namespace std;

    typedef struct colork
    {
        float R;
        float G;
        float B;
        colork(){
        }
        colork(float R_i ,float G_i, float B_i){
            R = R_i;
            G = G_i;
            B = B_i;
        }
    }colorRGB;

    typedef struct point_s
    {
        float x;
        float y;
        colorRGB  color;
        point_s(float x_i ,float y_i, colorRGB color_i){
            x = x_i;
            y = y_i;
            color = color_i;
        }
        point_s(float x_i ,float y_i){
            x = x_i;
            y = y_i;
        }
    }point;

    vector<point> cord;

    void cordClear(){
        cord.clear();
    }

    colorRGB  USE_PREV   = colorRGB(-1,-1,-1);
    colorRGB  RED   = colorRGB(1,0,0);
    colorRGB  GREEN = colorRGB(0,1,0);
    colorRGB  BLUE  = colorRGB(0,0,1);

    void Vertex2d_Apply(){
        for (vector<point>::iterator iter = cord.begin(); iter != cord.end(); ++iter) {
            if(iter->color.R != -1){
                 glColor3f(iter->color.R,iter->color.G,iter->color.B);
            }
            glVertex2d(iter->x,iter->y);
        }
        cord.clear();
    }
    
    void drawPoint(int size) {
        glPointSize(size);
        glBegin(GL_POINTS);
        Vertex2d_Apply();
        glEnd();
    }

    void drawLine(int size) {
        glLineWidth(size);
        glBegin(GL_LINES);
        Vertex2d_Apply();
        glEnd();
    }

    void drawTriangle() {
        glBegin(GL_TRIANGLES);
        Vertex2d_Apply();
        glEnd();
    }

    void drawQuade() {
        glBegin(GL_QUADS);
        Vertex2d_Apply();
        glEnd();
    }

    void drawPOLYGON() {
        glBegin(GL_POLYGON);
        Vertex2d_Apply();
        glEnd();
    }
    
    void drawCircle(float raduis,point centerpoint){
        glColor3f(centerpoint.color.R,centerpoint.color.G,centerpoint.color.B);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(centerpoint.x,centerpoint.y);
        for(float angle =0;angle < 361; angle+=0.2){
            glVertex2f(centerpoint.x+cos(angle*M_PI/180)*raduis, centerpoint.y+sin(angle*M_PI/180)*raduis);
        }
        glEnd ();
    }