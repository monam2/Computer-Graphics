#define _CRT_SECURE_NO_WARNINGS
#include <GL/glut.h>
#include <GL/GLU.h>
#include <GL/GL.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include "glaux.h"
#pragma comment(lib, "glaux.lib")
#pragma comment(lib, "legacy_stdio_definitions.lib")

int maze[30][30] = {
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
{1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1},
{1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
{1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
{1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
{1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
{1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1},
{1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1},
{1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
{1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
{1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
{1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
{1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1},
{1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1},
{1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
{1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1},
{1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1},
{1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1},
{1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1},
{1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
{1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
{1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

#define FPS 30
#define TO_RADIANS 3.14/180.0

GLuint g_textureID = -1;

//윈도우 창 너비,높이 설정
const int width = 16 * 50;
const int height = 9 * 50;


float pitch = 0.0, yaw = 0.0;
float camX = -1, camZ = 1;


bool Forward = false;
bool Backward = false;
bool Left = false;
bool Right = false;


void loadTexture(void) { //텍스쳐 로딩
    AUX_RGBImageRec* pTextureImage = auxDIBImageLoad("C:/Users/182947/source/repos/miro/Data/Data.bmp");

    if (pTextureImage != NULL) {
        glGenTextures(1, &g_textureID);

        glBindTexture(GL_TEXTURE_2D, g_textureID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, 3, pTextureImage->sizeX, pTextureImage->sizeY, 0,
            GL_RGB, GL_UNSIGNED_BYTE, pTextureImage->data);
    }

    if (pTextureImage) {
        if (pTextureImage->data)
            free(pTextureImage->data);

        free(pTextureImage);
    }
}

void init() //마우스 커서를 윈도우 창의 높이/2, 너비/2 지점에 위치
{
    glutSetCursor(GLUT_CURSOR_NONE);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glutWarpPointer(width / 2, height / 2);
}

void timer(int)
{
    glutPostRedisplay();
    glutWarpPointer(width / 2, height / 2);
    glutTimerFunc(1000 / FPS, timer, 0);
}

void camera() {
    if (Forward)
    {
        camX += cos((yaw + 90) * TO_RADIANS) / 5.0;
        camZ -= sin((yaw + 90) * TO_RADIANS) / 5.0;
    }
    if (Backward)
    {
        camX += cos((yaw + 90 + 180) * TO_RADIANS) / 5.0;
        camZ -= sin((yaw + 90 + 180) * TO_RADIANS) / 5.0;
    }
    if (Left)
    {
        camX += cos((yaw + 90 + 90) * TO_RADIANS) / 5.0;
        camZ -= sin((yaw + 90 + 90) * TO_RADIANS) / 5.0;
    }
    if (Right)
    {
        camX += cos((yaw + 90 - 90) * TO_RADIANS) / 5.0;
        camZ -= sin((yaw + 90 - 90) * TO_RADIANS) / 5.0;
    }

    /*limit the values of pitch
      between -60 and 70
    */
    if (pitch >= 70)
        pitch = 70;
    if (pitch <= -60)
        pitch = -60;

    glRotatef(-pitch, 1.0, 0.0, 0.0); // Along X axis
    glRotatef(-yaw, 0.0, 1.0, 0.0);    //Along Y axis

    glTranslatef(-camX, 0.0, -camZ);
}

void passive_motion(int x, int y)
{
    /* two variables to store X and Y coordinates, as observed from the center
      of the window
    */
    int dev_x, dev_y;
    dev_x = (width / 2) - x;
    dev_y = (height / 2) - y;

    /* apply the changes to pitch and yaw*/
    yaw += (float)dev_x / 10.0;
    pitch += (float)dev_y / 10.0;
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'W':
    case 'w':
        Forward = true;
        break;
    case 'A':
    case 'a':
        Left = true;
        break;
    case 'S':
    case 's':
        Backward = true;
        break;
    case 'D':
    case 'd':
        Right = true;
        break;
    }
}
void keyboard_up(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'W':
    case 'w':
        Forward = false;
        break;
    case 'A':
    case 'a':
        Left = false;
        break;
    case 'S':
    case 's':
        Backward = false;
        break;
    case 'D':
    case 'd':
        Right = false;
        break;
    }
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 16.0 / 9.0, 1, 75);
    glMatrixMode(GL_MODELVIEW);
}

void drawMaze() { //미로 그리기 + 텍스쳐

    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            glPushMatrix();
            glTranslatef(-i, 0.0, j);  // xz 평면
            if (maze[i][j] == 1) { //벽
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, g_textureID);

                glBegin(GL_QUADS);
                //윗면
                glTexCoord2f(0.0, 1.0); glVertex3f(-0.5, 0.5, -0.5);
                glTexCoord2f(1.0, 1.0); glVertex3f(0.5, 0.5, -0.5);
                glTexCoord2f(1.0, 0.0); glVertex3f(0.5, 0.5, 0.5);
                glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, 0.5, 0.5);

                //아랫면
                glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, -0.5, 0.5);
                glTexCoord2f(1.0, 0.0); glVertex3f(0.5, -0.5, 0.5);
                glTexCoord2f(1.0, 1.0); glVertex3f(0.5, -0.5, -0.5);
                glTexCoord2f(0.0, 1.0); glVertex3f(-0.5, -0.5, -0.5);

                // 앞면
                glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, -0.5, -0.5);
                glTexCoord2f(0.0, 1.0); glVertex3f(0.5, -0.5, -0.5);
                glTexCoord2f(1.0, 1.0); glVertex3f(0.5, 0.5, -0.5);
                glTexCoord2f(1.0, 0.0); glVertex3f(-0.5, 0.5, -0.5);

                // 뒷면
                glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, -0.5, 0.5);
                glTexCoord2f(0.0, 1.0); glVertex3f(0.5, -0.5, 0.5);
                glTexCoord2f(1.0, 1.0); glVertex3f(0.5, 0.5, 0.5);
                glTexCoord2f(1.0, 0.0); glVertex3f(-0.5, 0.5, 0.5);

                //왼쪽면
                glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, -0.5, -0.5);
                glTexCoord2f(0.0, 1.0); glVertex3f(-0.5, 0.5, -0.5);
                glTexCoord2f(1.0, 1.0); glVertex3f(-0.5, 0.5, 0.5);
                glTexCoord2f(1.0, 0.0); glVertex3f(-0.5, -0.5, 0.5);

                //오른쪽면
                glTexCoord2f(0.0, 0.0); glVertex3f(0.5, -0.5, 0.5);
                glTexCoord2f(0.0, 1.0); glVertex3f(0.5, 0.5, 0.5);
                glTexCoord2f(1.0, 1.0); glVertex3f(0.5, 0.5, -0.5);
                glTexCoord2f(1.0, 0.0); glVertex3f(0.5, -0.5, -0.5);

                glEnd();

                glDisable(GL_TEXTURE_2D);
            }
            else { //빈공간

            }
            glPopMatrix();
        }
    }
    glutSwapBuffers();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    camera();
    drawMaze();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);  // 창 크기 800*600
    glutCreateWindow("aaaa");

    glEnable(GL_DEPTH_TEST);

    init();
    loadTexture();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutPassiveMotionFunc(passive_motion);
    glutTimerFunc(0, timer, 0);    //more info about this is given below at definition of timer()
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard_up);

    glutMainLoop();

    return 0;
}
