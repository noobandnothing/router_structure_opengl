vector<point> mainpoints;
float raduis = 1;

vector<point> drawMainPologon(){
    vector<point> backup ;
    cord.push_back(point(1.5,1.0,colorRGB(1,1,1)));
    cord.push_back(point(-1.5,1.0,USE_PREV));
    cord.push_back(point(-1.5,-1.0,USE_PREV));
    cord.push_back(point(1.5,-1.0,USE_PREV));
    backup = cord;
    drawPOLYGON();
    return backup;
}

void drawCarvyBorder(){
    glColor3f(1,1,1);
    for(int counter = 0 ; counter < (int)mainpoints.size() ; counter++){
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(mainpoints.at(counter).x,mainpoints.at(counter).y);
        for(float angle =(counter*90.0f);angle < ((counter+1)*90.0f); angle+=0.2){
            glVertex2f (mainpoints.at(counter).x+cos(angle*M_PI/180)*raduis, mainpoints.at(counter).y+sin(angle*M_PI/180)*raduis);
        }
        glEnd ();
    }
}

void drawLEFTRIGHT_Border(){
    //RIGHT_PART
    cord.push_back(point(mainpoints.at(0).x,mainpoints.at(0).y,colorRGB(1,1,1)));
    cord.push_back(point(mainpoints.at(0).x+raduis,mainpoints.at(0).y,USE_PREV));
    cord.push_back(point(mainpoints.at(3).x+raduis,mainpoints.at(3).y,USE_PREV));
    cord.push_back(point(mainpoints.at(3).x,mainpoints.at(3).y,USE_PREV));
    drawPOLYGON();
    //LEFT_PART
    cord.push_back(point(mainpoints.at(1).x,mainpoints.at(1).y,USE_PREV));
    cord.push_back(point(mainpoints.at(1).x-raduis,mainpoints.at(1).y,USE_PREV));
    cord.push_back(point(mainpoints.at(2).x-raduis,mainpoints.at(2).y,USE_PREV));
    cord.push_back(point(mainpoints.at(2).x,mainpoints.at(2).y,USE_PREV));
    drawPOLYGON();
}

void drawUPDOWN_Border(){
    //UP_PART
    cord.push_back(point(mainpoints.at(0).x,mainpoints.at(0).y,colorRGB(1,1,1)));
    cord.push_back(point(mainpoints.at(0).x,mainpoints.at(0).y+raduis,USE_PREV));
    cord.push_back(point(mainpoints.at(1).x,mainpoints.at(1).y+raduis,USE_PREV));
    cord.push_back(point(mainpoints.at(1).x,mainpoints.at(1).y,USE_PREV));
    drawPOLYGON();
    //DOWN_PART
    cord.push_back(point(mainpoints.at(3).x,mainpoints.at(3).y,USE_PREV));
    cord.push_back(point(mainpoints.at(3).x,mainpoints.at(3).y-raduis,USE_PREV));
    cord.push_back(point(mainpoints.at(2).x,mainpoints.at(2).y-raduis,USE_PREV));
    cord.push_back(point(mainpoints.at(2).x,mainpoints.at(2).y,USE_PREV));
    drawPOLYGON();
}

void drawSTAND(){
    cord.push_back(point(mainpoints.at(2).x,mainpoints.at(2).y-raduis,colorRGB(1,0,1)));
    cord.push_back(point(mainpoints.at(2).x,mainpoints.at(2).y-raduis-0.5,USE_PREV));
    drawLine(2);
    cord.push_back(point(mainpoints.at(3).x,mainpoints.at(3).y-raduis,USE_PREV));
    cord.push_back(point(mainpoints.at(3).x,mainpoints.at(3).y-raduis-0.5,USE_PREV));
    drawLine(2);
    //##############
    cord.push_back(point(mainpoints.at(2).x,mainpoints.at(2).y-raduis-0.5,USE_PREV));
    cord.push_back(point(mainpoints.at(3).x,mainpoints.at(3).y-raduis-0.5,USE_PREV));
    drawLine(4);
    //##############
}

void drawROUTERDOTS(){
    float raduis = 0.2;
    for(int counter = 0 ; counter < 4 ; counter++){
        drawCircle(raduis,point(mainpoints.at(1).x+counter,mainpoints.at(1).y,colorRGB(1,1,0)));
    }
}

void drawMYROUTER(){
    mainpoints = drawMainPologon();
    drawCarvyBorder();
    drawLEFTRIGHT_Border();
    drawUPDOWN_Border();
    drawSTAND();
    drawROUTERDOTS();
}