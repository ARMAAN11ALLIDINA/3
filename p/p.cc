#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cstdlib>
#include <time.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
int Window_ID;
int Window_Width = 600;
int Window_Height = 400;
float X_Rot   = 0.9f;
float Y_Rot   = 0.0f;
float X_Speed = 0.0f;
float Y_Speed = 0.0125f;
float Z_Off =0.0f;
float xEye=0.0f;
float yEye=0.0f;
float zEye=5.0f;
void RenderScene(void){
   char buf[80];
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt(xEye, yEye, zEye, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
   glTranslatef(0.0f, 0.0f, Z_Off);
   glRotatef(X_Rot,1.0f,0.0f,0.0f);
   glRotatef(Y_Rot,0.0f,1.0f,0.0f);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glBegin(GL_TRIANGLES);
   glColor3f(0.0f, 1.0f, 0.0f);
   glVertex3f(0.0f, 1.0f, 0.0f);
   glVertex3f(-1.0f, -1.0f, 1.0f);
   glVertex3f(1.0f, -1.0, 1.0f);
   glColor3f(1.0f, 0.0f, 0.0f);
   glVertex3f(0.0f, 1.0f, 0.0f);
   glVertex3f(1.0f, -1.0f, 1.0f);
   glVertex3f(1.0f, -1.0f, -1.0f);
   glColor3f(0.0f, 0.0f, 1.0f);
   glVertex3f(0.0f, 1.0f, 0.0f);
   glVertex3f(1.0f, -1.0f, -1.0f);
   glVertex3f(-1.0f, -1.0f, -1.0f);
   glColor3f(0.0f, 0.0f, 0.0f);
   glVertex3f(0.0f, 1.0f, 0.0f);
   glVertex3f(-1.0f, -1.0f, -1.0f);
   glVertex3f(-1.0f, -1.0f, 1.0f);
   glEnd();
   glTranslatef(2.0f, 0.0f, 0.0f);
   glBegin(GL_TRIANGLES);
   glColor3f(0.0f, 1.0f, 0.0f);
   glVertex3f(0.0f, 1.0f, 0.0f);
   glVertex3f(-1.0f, -1.0f, 1.0f);
   glVertex3f(1.0f, -1.0, 1.0f);
   glColor3f(1.0f, 0.0f, 0.0f);
   glVertex3f(0.0f, 1.0f, 0.0f);
   glVertex3f(1.0f, -1.0f, 1.0f);
   glVertex3f(1.0f, -1.0f, -1.0f);
   glColor3f(0.0f, 0.0f, 1.0f);
   glVertex3f(0.0f, 1.0f, 0.0f);
   glVertex3f(1.0f, -1.0f, -1.0f);
   glVertex3f(-1.0f, -1.0f, -1.0f);
   glColor3f(0.0f, 0.0f, 0.0f);
   glVertex3f(0.0f, 1.0f, 0.0f);
   glVertex3f(-1.0f, -1.0f, -1.0f);
   glVertex3f(-1.0f, -1.0f, 1.0f);
   glEnd();
   glTranslatef(-4.0f, 0.0f, 0.0f);
   glBegin(GL_TRIANGLES);
   glColor3f(0.0f, 1.0f, 0.0f);
   glVertex3f(0.0f, 1.0f, 0.0f);
   glVertex3f(-1.0f, -1.0f, 1.0f);
   glVertex3f(1.0f, -1.0, 1.0f);
   glColor3f(1.0f, 0.0f, 0.0f);
   glVertex3f(0.0f, 1.0f, 0.0f);
   glVertex3f(1.0f, -1.0f, 1.0f);
   glVertex3f(1.0f, -1.0f, -1.0f);
   glColor3f(0.0f, 0.0f, 1.0f);
   glVertex3f(0.0f, 1.0f, 0.0f);
   glVertex3f(1.0f, -1.0f, -1.0f);
   glVertex3f(-1.0f, -1.0f, -1.0f);
   glColor3f(0.0f, 0.0f, 0.0f);
   glVertex3f(0.0f, 1.0f, 0.0f);
   glVertex3f(-1.0f, -1.0f, -1.0f);
   glVertex3f(-1.0f, -1.0f, 1.0f);
   glEnd();
   glutSwapBuffers();
   X_Rot+=X_Speed;
   Y_Rot+=Y_Speed;
}
void CallBackMyControlMouse(int button, int state, int Width, int Height){
   if(state==GLUT_DOWN && button==GLUT_RIGHT_BUTTON){
      xEye=5.0f;
      yEye=5.0f;
   }
   else if(state==GLUT_UP && button==GLUT_RIGHT_BUTTON){
      xEye=0.0f;
      yEye=0.0f;
   }
}
void ResizeScene(int Width, int Height){
   if (Height == 0)
      Height = 1;
   glViewport(0, 0, Width, Height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);
   glMatrixMode(GL_MODELVIEW);
   Window_Width  = Width;
   Window_Height = Height;
}
void MyInit(int Width, int Height) {
   glClearColor(0.1f, 0.1f, 0.1f, 0.0f);
   glClearDepth(1.0);
   glDepthFunc(GL_LESS);
   glEnable(GL_DEPTH_TEST);
   glShadeModel(GL_SMOOTH);
   ResizeScene(Width,Height);
}
int main(int argc, char **argv){
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
   glutInitWindowSize(Window_Width, Window_Height);
   Window_ID = glutCreateWindow("cube");
   glutDisplayFunc(&RenderScene);
   glutIdleFunc(&RenderScene);
   glutReshapeFunc(&ResizeScene);
   glutMouseFunc(&CallBackMyControlMouse);
   MyInit(Window_Width, Window_Height);
   printf("\n%s\n", "cube");
   glutMainLoop();
   return 0;
}
