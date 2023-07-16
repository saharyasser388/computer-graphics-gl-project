#include <GL/glut.h>
static float XSphere = 0, YSphere = 0, ZSphere = -14; // this variable is used to Translate the object
int xAxisRotation, yAxisRotation, zAxisRotation = 0;
float Projection = 0.5; // this variable is used to zoom in and zoom out on the object
//Initializes 3D rendering
void initRendering() {
    glClearColor(0.0, 0.1, 0.2, 0.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING); //Enable lighting
    glEnable(GL_LIGHT0); //Enable light #0
    glEnable(GL_NORMALIZE); //Automatically normalize normals
    glShadeModel(GL_SMOOTH); //Enable smooth shading
}
//Called when the window is resized


float _angle = -70.0f;

//Mouse & Keyboard functions

void MyMouse(int button, int state, int x, int y)
{

    switch (button)
    {
    case GLUT_LEFT_BUTTON:

        if (state == GLUT_UP)
        {
            XSphere = (x - 450) * 30.0 / 900;
            YSphere = (450 - y) * 30.0 / 900;
            ZSphere = -14;
            glutPostRedisplay();
        }
        break;
    }
}

void keyboard(unsigned char key, int x, int y) //
{

    switch (key) {
    case 'x':
        yAxisRotation = zAxisRotation = 0;
        xAxisRotation = 1;
        break;
    case 'y':
        xAxisRotation = zAxisRotation = 0;
        yAxisRotation = 1;
        break;

    case 'z':
        xAxisRotation = yAxisRotation = 0;
        zAxisRotation = 1;
        break;
    case 'w':
        Projection += .05;
        break;
    case 's':
        Projection -= .05;
        break;
    default:
        break;
    }
}
//Draws the 3D scene
void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); // keep it like this
    glLoadIdentity();
    glScalef(Projection, Projection, 1.0);
    glTranslatef(XSphere, YSphere, ZSphere);
    glRotatef(_angle, xAxisRotation, yAxisRotation, zAxisRotation);
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);

    //Front
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-2.0f, -0.2f, 2.0f);
    glVertex3f(2.0f, -0.2f, 2.0f);
    glVertex3f(2.0f, 0.2f, 2.0f);
    glVertex3f(-2.0f, 0.2f, 2.0f);

    //Right
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(2.0f, -0.2f, -2.0f);
    glVertex3f(2.0f, 0.2f, -2.0f);
    glVertex3f(2.0f, 0.2f, 2.0f);
    glVertex3f(2.0f, -0.2f, 2.0f);

    //Back
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(-2.0f, -0.2f, -2.0f);
    glVertex3f(-2.0f, 0.2f, -2.0f);
    glVertex3f(2.0f, 0.2f, -2.0f);
    glVertex3f(2.0f, -0.2f, -2.0f);

    //Left
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-2.0f, -0.2f, -2.0f);
    glVertex3f(-2.0f, -0.2f, 2.0f);
    glVertex3f(-2.0f, 0.2f, 2.0f);
    glVertex3f(-2.0f, 0.2f, -2.0f);

    //top
    glNormal3f(0.0f, 1.0f, 0.0f);

    glVertex3f(2.0f, 0.2f, 2.0f);
    glVertex3f(-2.0f, 0.2f, 2.0f);
    glVertex3f(-2.0f, 0.2f, -2.0f);
    glVertex3f(2.0f, 0.2f, -2.0f);

    //bottom
    glNormal3f(0.0f, -1.0f, 0.0f);

    glVertex3f(2.0f, -0.2f, 2.0f);
    glVertex3f(-2.0f, -0.2f, 2.0f);
    glVertex3f(-2.0f, -0.2f, -2.0f);
    glVertex3f(2.0f, -0.2f, -2.0f);

    //chair front leg
    //front
    glNormal3f(0.0f, 0.0f, 1.0f);

    glVertex3f(1.8f, -0.2f, 1.6f);
    glVertex3f(1.4f, -0.2f, 1.6f);
    glVertex3f(1.4f, -3.0f, 1.6f);
    glVertex3f(1.8f, -3.0f, 1.6f);

    //back
    glNormal3f(0.0f, 0.0f, -1.0f);

    glVertex3f(1.8f, -0.2f, 1.2f);
    glVertex3f(1.4f, -0.2f, 1.2f);
    glVertex3f(1.4f, -3.0f, 1.2f);
    glVertex3f(1.8f, -3.0f, 1.2f);

    //right
    glNormal3f(1.0f, 0.0f, 0.0f);

    glVertex3f(1.8f, -0.2f, 1.6f);
    glVertex3f(1.8f, -0.2f, 1.2f);
    glVertex3f(1.8f, -3.0f, 1.2f);
    glVertex3f(1.8f, -3.0f, 1.6f);

    //left
    glNormal3f(-1.0f, 0.0f, 0.0f);

    glVertex3f(1.4f, -0.2f, 1.6f);
    glVertex3f(1.4f, -0.2f, 1.2f);
    glVertex3f(1.4f, -3.0f, 1.2f);
    glVertex3f(1.4f, -3.0f, 1.6f);

    //back leg back
    //front
    glNormal3f(0.0f, 0.0f, -1.0f);

    glVertex3f(1.8f, -0.2f, -1.2f);
    glVertex3f(1.4f, -0.2f, -1.2f);
    glVertex3f(1.4f, -3.0f, -1.2f);
    glVertex3f(1.8f, -3.0f, -1.2f);

    //back
    glNormal3f(0.0f, 0.0f, -1.0f);

    glVertex3f(1.8f, -0.2f, -1.6f);
    glVertex3f(1.4f, -0.2f, -1.6f);
    glVertex3f(1.4f, -3.0f, -1.6f);
    glVertex3f(1.8f, -3.0f, -1.6f);

    //right
    glNormal3f(1.0f, 0.0f, 0.0f);

    glVertex3f(1.8f, -0.2f, -1.6f);
    glVertex3f(1.8f, -0.2f, -1.2f);
    glVertex3f(1.8f, -3.0f, -1.2f);
    glVertex3f(1.8f, -3.0f, -1.6f);

    //left
    glNormal3f(1.0f, 0.0f, 0.0f);

    glVertex3f(1.4f, -0.2f, -1.6f);
    glVertex3f(1.4f, -0.2f, -1.2f);
    glVertex3f(1.4f, -3.0f, -1.2f);
    glVertex3f(1.4f, -3.0f, -1.6f);

    //leg left front
    glNormal3f(0.0f, 0.0f, 1.0f);

    glVertex3f(-1.8f, -0.2f, 1.6f);
    glVertex3f(-1.4f, -0.2f, 1.6f);
    glVertex3f(-1.4f, -3.0f, 1.6f);
    glVertex3f(-1.8f, -3.0f, 1.6f);

    //back
    glNormal3f(0.0f, 0.0f, -1.0f);

    glVertex3f(-1.8f, -0.2f, 1.2f);
    glVertex3f(-1.4f, -0.2f, 1.2f);
    glVertex3f(-1.4f, -3.0f, 1.2f);
    glVertex3f(-1.8f, -3.0f, 1.2f);

    //right
    glNormal3f(1.0f, 0.0f, 0.0f);

    glVertex3f(-1.8f, -0.2f, 1.6f);
    glVertex3f(-1.8f, -0.2f, 1.2f);
    glVertex3f(-1.8f, -3.0f, 1.2f);
    glVertex3f(-1.8f, -3.0f, 1.6f);

    //left
    glNormal3f(-1.0f, 0.0f, 0.0f);

    glVertex3f(-1.4f, -0.2f, 1.6f);
    glVertex3f(-1.4f, -0.2f, 1.2f);
    glVertex3f(-1.4f, -3.0f, 1.2f);
    glVertex3f(-1.4f, -3.0f, 1.6f);

    //left leg back front

    //front
    glNormal3f(0.0f, 0.0f, -1.0f);

    glVertex3f(-1.8f, -0.2f, -1.2f);
    glVertex3f(-1.4f, -0.2f, -1.2f);
    glVertex3f(-1.4f, -3.0f, -1.2f);
    glVertex3f(-1.8f, -3.0f, -1.2f);

    //back
    glNormal3f(0.0f, 0.0f, -1.0f);

    glVertex3f(-1.8f, -0.2f, -1.6f);
    glVertex3f(-1.4f, -0.2f, -1.6f);
    glVertex3f(-1.4f, -3.0f, -1.6f);
    glVertex3f(-1.8f, -3.0f, -1.6f);

    //right
    glNormal3f(1.0f, 0.0f, 0.0f);

    glVertex3f(-1.8f, -0.2f, -1.6f);
    glVertex3f(-1.8f, -0.2f, -1.2f);
    glVertex3f(-1.8f, -3.0f, -1.2f);
    glVertex3f(-1.8f, -3.0f, -1.6f);

    //left
    glNormal3f(-1.0f, 0.0f, 0.0f);

    glVertex3f(-1.4f, -0.2f, -1.6f);
    glVertex3f(-1.4f, -0.2f, -1.2f);
    glVertex3f(-1.4f, -3.0f, -1.2f);
    glVertex3f(-1.4f, -3.0f, -1.6f);

    //chair back
    //front
    glColor3f(1, 1, 1);
    //glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-1.8f, 0.2f, -1.8f);
    glVertex3f(1.8f, 0.2f, -1.8f);
    glVertex3f(1.8f, 3.5f, -1.8f);
    glVertex3f(-1.8f, 3.5f, -1.8f);

    //back
 //glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-1.8f, 0.2f, -2.0f);
    glVertex3f(1.8f, 0.2f, -2.0f);
    glVertex3f(1.8f, 3.5f, -2.0f);
    glVertex3f(-1.8f, 3.5f, -2.0f);


    //  glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-1.8f, 0.2f, -2.0f);
    glVertex3f(-1.8f, 3.5f, -2.0f);
    glVertex3f(-1.8f, 3.5f, -1.8f);
    glVertex3f(-1.8f, 0.2f, -1.8f);


    glVertex3f(1.8f, 0.2f, -2.0f);
    glVertex3f(1.8f, 3.5f, -2.0f);
    glVertex3f(1.8f, 3.5f, -1.8f);
    glVertex3f(1.8f, 0.2f, -1.8f);

    glVertex3f(-1.8f, 3.5f, -2.0f);
    glVertex3f(-1.8f, 3.5f, -1.8f);
    glVertex3f(1.8f, 3.5f, -1.8f);
    glVertex3f(1.8f, 3.5f, -2.0f);
    glEnd();
    glutSwapBuffers();
}
void update(int value) {
    _angle += 1.5f;
    if (_angle > 360) {
        _angle -= 360;
    }

    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}
int main(int argc, char** argv) {
    //Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(900, 900);
    glutInitWindowPosition(300, -100);
    //Create the window
    glutCreateWindow("Lighting");
    initRendering();
    //Set handler functions
    glutDisplayFunc(drawScene);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(MyMouse);
    update(0);
    glutMainLoop();
    return 0;
}
