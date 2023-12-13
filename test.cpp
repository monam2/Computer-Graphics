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
{1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
{1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1},
{1, 2, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
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
{1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 2},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

#define FPS 60 // 1000/FPS로 타이머 콜백할거임
#define TO_RADIANS 3.14/180.0

GLuint g_textureID1 = -1; //텍스쳐1 : Data/wall
GLuint g_textureID2 = -1; //텍스쳐2 : Data/Lawn
GLuint g_textureID3 = -1; //텍스쳐2 : Data/Sky

const int width = 1400; //윈도우 창 너비,높이
const int height = 600;


float pitch = 0.0, yaw = 0.0;
float camX = 1, camZ = 1; //카메라 초기위치(시작점)


bool Forward = false;
bool Backward = false;
bool Left = false;
bool Right = false;

float camSpeed = 18.0; //이속

float teapotRotation = 5.0; // 티팟 회전 속도
float teapotVerticalMotion = 0.0;
float teopotRotateAngle = 1;
bool teapotMovingUp = true;


void loadTexture(void) {
    AUX_RGBImageRec* pTextureImage1 = auxDIBImageLoad("C:/Users/kcw01/source/repos/Project11/Project11/Data/Wall.bmp");

    if (pTextureImage1 != NULL) {
        glGenTextures(1, &g_textureID1);
        glBindTexture(GL_TEXTURE_2D, g_textureID1);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, 3, pTextureImage1->sizeX, pTextureImage1->sizeY, 0,
            GL_RGB, GL_UNSIGNED_BYTE, pTextureImage1->data);
    }

    AUX_RGBImageRec* pTextureImage2 = auxDIBImageLoad("C:/Users/kcw01/source/repos/Project11/Project11/Data/Lawn.bmp");
    if (pTextureImage2 != NULL) {
        glGenTextures(1, &g_textureID2);
        glBindTexture(GL_TEXTURE_2D, g_textureID2);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, 3, pTextureImage2->sizeX, pTextureImage2->sizeY, 0,
            GL_RGB, GL_UNSIGNED_BYTE, pTextureImage2->data);
    }

    AUX_RGBImageRec* pTextureImage3 = auxDIBImageLoad("C:/Users/kcw01/source/repos/Project11/Project11/Data/Sky.bmp");
    if (pTextureImage3 != NULL) {
        glGenTextures(1, &g_textureID3);
        glBindTexture(GL_TEXTURE_2D, g_textureID3);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, 3, pTextureImage3->sizeX, pTextureImage3->sizeY, 0,
            GL_RGB, GL_UNSIGNED_BYTE, pTextureImage3->data);
    }

    if (pTextureImage1) {
        if (pTextureImage1->data)
            free(pTextureImage1->data);

        free(pTextureImage1);
    }
    if (pTextureImage2) {
        if (pTextureImage2->data)
            free(pTextureImage2->data);

        free(pTextureImage2);
    }
    if (pTextureImage3) {
        if (pTextureImage3->data)
            free(pTextureImage3->data);

        free(pTextureImage3);
    }
}

void init() //마우스 커서를 윈도우 창의 높이/2, 너비/2 지점에 위치
{
    glutSetCursor(GLUT_CURSOR_NONE);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glutWarpPointer(width / 2, height / 2);
}

void camera() {
    if (Forward)
    {
        camX += cos((yaw + 90) * TO_RADIANS) / camSpeed;
        camZ -= sin((yaw + 90) * TO_RADIANS) / camSpeed;
    }
    if (Backward)
    {
        camX += cos((yaw + 90 + 180) * TO_RADIANS) / camSpeed;
        camZ -= sin((yaw + 90 + 180) * TO_RADIANS) / camSpeed;
    }
    if (Left)
    {
        camX += cos((yaw + 90 + 90) * TO_RADIANS) / camSpeed *0.5;
        camZ -= sin((yaw + 90 + 90) * TO_RADIANS) / camSpeed * 0.5;
    }
    if (Right)
    {
        camX += cos((yaw + 90 - 90) * TO_RADIANS) / camSpeed * 0.5;
        camZ -= sin((yaw + 90 - 90) * TO_RADIANS) / camSpeed * 0.5;
    }
    if (pitch >= 80)//상
        pitch = 80;
    if (pitch <= -20)//하
        pitch = -20;
    
    glRotatef(-pitch, 1.0, 0.0, 0.0);
    glRotatef(-yaw, 0.0, 1.0, 0.0);
    glTranslatef(-camX, 0.0, -camZ);
    
}

void passive_motion(int x, int y)
{
    int dev_x, dev_y;
    dev_x = (width / 2) - x;
    dev_y = (height / 2) - y;

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
    gluPerspective(70, 16/10, 0.1, 200);
    glMatrixMode(GL_MODELVIEW);
    
}

void draw_block() {
    glColor3f(1, 1, 1);
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_textureID1);

    // Front Face
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, -0.5, 0.5);
    glTexCoord2f(1.0, 0.0); glVertex3f(0.5, -0.5, 0.5);
    glTexCoord2f(1.0, 1.0); glVertex3f(0.5, 0.5, 0.5);
    glTexCoord2f(0.0, 1.0); glVertex3f(-0.5, 0.5, 0.5);
    glEnd();

    // Back Face
    glBegin(GL_QUADS);
    glTexCoord2f(1.0, 0.0); glVertex3f(-0.5, -0.5, -0.5);
    glTexCoord2f(1.0, 1.0); glVertex3f(-0.5, 0.5, -0.5);
    glTexCoord2f(0.0, 1.0); glVertex3f(0.5, 0.5, -0.5);
    glTexCoord2f(0.0, 0.0); glVertex3f(0.5, -0.5, -0.5);
    glEnd();

    // Top Face
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0); glVertex3f(-0.5, 0.5, -0.5);
    glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, 0.5, 0.5);
    glTexCoord2f(1.0, 0.0); glVertex3f(0.5, 0.5, 0.5);
    glTexCoord2f(1.0, 1.0); glVertex3f(0.5, 0.5, -0.5);
    glEnd();

    // Bottom Face
    glBegin(GL_QUADS);
    glTexCoord2f(1.0, 1.0); glVertex3f(-0.5, -0.5, -0.5);
    glTexCoord2f(0.0, 1.0); glVertex3f(0.5, -0.5, -0.5);
    glTexCoord2f(0.0, 0.0); glVertex3f(0.5, -0.5, 0.5);
    glTexCoord2f(1.0, 0.0); glVertex3f(-0.5, -0.5, 0.5);
    glEnd();

    // Right Face
    glBegin(GL_QUADS);
    glTexCoord2f(1.0, 0.0); glVertex3f(0.5, -0.5, -0.5);
    glTexCoord2f(1.0, 1.0); glVertex3f(0.5, 0.5, -0.5);
    glTexCoord2f(0.0, 1.0); glVertex3f(0.5, 0.5, 0.5);
    glTexCoord2f(0.0, 0.0); glVertex3f(0.5, -0.5, 0.5);
    glEnd();

    // Left Face
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, -0.5, -0.5);
    glTexCoord2f(1.0, 0.0); glVertex3f(-0.5, -0.5, 0.5);
    glTexCoord2f(1.0, 1.0); glVertex3f(-0.5, 0.5, 0.5);
    glTexCoord2f(0.0, 1.0); glVertex3f(-0.5, 0.5, -0.5);
    glEnd();

    glPopMatrix();
}

void drawTeapot(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y + teapotVerticalMotion, z);
    glRotatef(teopotRotateAngle, 0, 1, 0);
    glutSolidTeapot(0.25);  // teapot 크기
    glPopMatrix();
}


void teapottimer(int) {
    // 티팟의 위아래 움직임 업데이트
    if (teapotMovingUp) {
        teapotVerticalMotion += 0.005;
        if (teapotVerticalMotion >= 0.15) {
            teapotMovingUp = false;
        }
    }
    else {
        teapotVerticalMotion -= 0.005;
        if (teapotVerticalMotion <= -0.1) {
            teapotMovingUp = true;
        }
    }
    teopotRotateAngle += 1;
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glutPostRedisplay();
    glutTimerFunc(1000 / FPS, teapottimer, 0);
}

void drawsky() {
    // 하늘 그리기
    glPushMatrix();
    glColor3f(1, 1, 1);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_textureID3);
    glBegin(GL_QUADS);
    //윗면
    glTexCoord2f(0.0, 0.0); glVertex3f(100,50,-100);// 좌측 상단
    glTexCoord2f(0.0, 1.0); glVertex3f(100,50,100);// 좌측 하단
    glTexCoord2f(1.0, 1.0); glVertex3f(-100,50,100);// 우측 하단
    glTexCoord2f(1.0, 0.0); glVertex3f(-100,50,-100);// 우측 상단
    //오른쪽면
    glTexCoord2f(0.0, 0.0); glVertex3f(100,50,-100);// 좌측 상단
    glTexCoord2f(0.0, 1.0); glVertex3f(100,-0.5,-100);// 좌측 하단
    glTexCoord2f(1.0, 1.0); glVertex3f(-100,-0.5,-100);// 우측 하단
    glTexCoord2f(1.0, 0.0); glVertex3f(-100,50,-100);// 우측 상단
    //왼쪽면
    glTexCoord2f(0.0, 0.0); glVertex3f(100, 50, 100);// 좌측 상단
    glTexCoord2f(0.0, 1.0); glVertex3f(100, -0.5, 100);// 좌측 하단
    glTexCoord2f(1.0, 1.0); glVertex3f(-100, -0.5, 100);// 우측 하단
    glTexCoord2f(1.0, 0.0); glVertex3f(-100, 50, 100);// 우측 상단

    //앞쪽면
    glTexCoord2f(0.0, 0.0); glVertex3f(-100, 50, -100);// 좌측 상단
    glTexCoord2f(0.0, 1.0); glVertex3f(-100, 50, 100);// 좌측 하단
    glTexCoord2f(1.0, 1.0); glVertex3f(-100, -0.5, 100);// 우측 하단
    glTexCoord2f(1.0, 0.0); glVertex3f(-100, -0.5, -100);// 우측 상단

    //뒷쪽면
    glTexCoord2f(0.0, 0.0); glVertex3f(100, 50, -100);// 좌측 상단
    glTexCoord2f(0.0, 1.0); glVertex3f(100, 50, 100);// 좌측 하단
    glTexCoord2f(1.0, 1.0); glVertex3f(100, -0.5, 100);// 우측 하단
    glTexCoord2f(1.0, 0.0); glVertex3f(100, 0.5, -100);// 우측 상단

    glEnd();

    glPopMatrix();
}

void drawground() {
    // 바닥 그리기
    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_textureID2);
    glBegin(GL_QUADS);
    glBegin(GL_QUADS);
    for (int i = -10; i < 10; i++) {
        for (int j = -10; j < 10; j++) {
            glTexCoord2f(0.0, 0.0); glVertex3f(i * 30, -0.5, j * 30);                 // 좌측 상단
            glTexCoord2f(0.0, 1.0); glVertex3f(i * 30, -0.5, (j + 1) * 30);          // 좌측 하단
            glTexCoord2f(1.0, 1.0); glVertex3f((i + 1) * 30, -0.5, (j + 1) * 30);    // 우측 하단
            glTexCoord2f(1.0, 0.0); glVertex3f((i + 1) * 30, -0.5, j * 30);          // 우측 상단
        }
    }
    glEnd();
    glEnd();

    glPopMatrix();
}

void drawMaze() { //미로 그리기 + 텍스쳐

    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            if (maze[i][j] == 1) { //벽
                glPushMatrix();
                glTranslatef(-i, 0.0, j);
                draw_block();
                glPopMatrix();

            }
            else if (maze[i][j] == 2) { //도착점
                glColor3d(1, 0, 0);
                glPushMatrix();
                drawTeapot(-i, 0.0, j);
                glPopMatrix();
            }
            else { //빈공간
                
            }
            glPopMatrix();
        }
    }
    drawsky();
    drawground();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(width / 2 - 100, 0, 800, height); //오른쪽 뷰포트
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();  // 모델뷰 행렬 초기화
    camera();
    drawMaze();


    glViewport(0, 0, height, height);//왼쪽 뷰포트
    glLoadIdentity();  // 모델뷰 행렬 초기화
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(
        -15, 28, 15,
        -15, 0, 15,
        1, 0, 0
    );
    drawMaze();
    // 왼쪽 뷰포트에 점 그리기
    glPointSize(8.0f);
    glBegin(GL_POINTS);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(camX, 0.0f, camZ); // 원하는 좌표에 점 찍기
    glEnd();


    


    glutSwapBuffers();
}



void timer(int)
{

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glutPostRedisplay();
    glutWarpPointer(width / 2, height / 2);
    glutTimerFunc(1000 / FPS, timer, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);  // 창 크기
    glutCreateWindow("182947 강창우");

    glEnable(GL_DEPTH_TEST);

    init();
    loadTexture();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutPassiveMotionFunc(passive_motion);
    glutTimerFunc(0, timer, 0);
    glutTimerFunc(0, teapottimer, 0);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard_up);

    glutMainLoop();

    return 0;
}
