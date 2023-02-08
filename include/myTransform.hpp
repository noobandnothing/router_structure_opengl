float posX = 0.0f, posY = 0.0f ,posZ = -5.0f;
float move_unit = 0.2f;
 
float sx = 2.0f, sy = 2.0f,sz = 2.0f;
float scale_unit = 0.5f;
 
float rx = 0 , ry = 0 , rz = 0;
float angle = 0.0;

void keyboardArrowsTrans(int key,int x, int y){
    switch(key){
    case GLUT_KEY_RIGHT:
        posX += move_unit;
        break;
    case GLUT_KEY_LEFT:
        posX -= move_unit;
        break;
    case GLUT_KEY_UP:
        posY += move_unit;
        break;
    case GLUT_KEY_DOWN:
        posY -= move_unit;
        break;
    default:
        break;
    }
    glutPostRedisplay();
}
 
void keyboardKeysScale(unsigned char key,int x, int y){
    switch(key){
        //Scaling :
        // SMALLER
        case 's': sx-= scale_unit;sy-=scale_unit;break;
        // BITGGER
        case 'S': sx+= scale_unit;sy+=scale_unit;break;
        //Rotate Around X :
        // WARA L ODAM
        case 'u':
        case 'U':{angle+= 5.0;rx = 1.0;}break;
        // ODAM L WARA
        case 'd':
        case 'D':{angle-= 5.0;rx = 1;}break;
        //Rotate Around Y :
        // Ymeen L SHEMAL
        case 'l':
        case 'L':{angle+= 5.0;ry = 1;}break;
        // SHEMAL L Ymeen
        case 'r':
        case 'R':{angle-= 5.0;ry = 1;}break;
        default:break;
    }
    glutPostRedisplay();
}