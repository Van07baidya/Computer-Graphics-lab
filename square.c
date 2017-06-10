#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void init(void)
 {
 glClearColor (0.0, 0.0, 0.0, 0.0);
 glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
 glMatrixMode(GL_PROJECTION);
 }

void Render()
{     
    //clear color and depth buffer 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();//load identity matrix
    glMatrixMode(GL_MODELVIEW);
    //glTranslatef(1.0f,0.0f,0.0f);//move forward 4 units
    //glRotatef(45,0,0,1.0);
    glScalef(1,-1,1); 
    glColor3f(1.0f,1.0f,1.0f); //blue color
    
    //glPointSize(10.0f);//set point size to 10 pixels
    
    glBegin(GL_LINE_LOOP); //starts drawing of points
      glVertex3f(50.0f,50.0f,0.0f);//upper-right corner
      glVertex3f(-50.0f,50.0f,0.0f);
      glVertex3f(-50.0f,-50.0f,0.0f);
      glVertex3f(50.0f,-50.0f,0.0f);//lower-left corner
    glEnd();
 
   glBegin(GL_POINTS);
    glColor3f (1.0, 1.0, 1.0);

 for(int i=-100 ; i<=100 ; i++)
 {
 glVertex2s(i,0);
 glVertex2s(0,i);
 }

 for(int i=-2; i<=2 ; i++)
 {
 glVertex2s(95+i,4+i);
 glVertex2s(95-i,4+i);
 }

 for(int i=0; i<=2 ; i++)
 {
 glVertex2s(4+i,95+i);
 glVertex2s(4-i,95+i);
 glVertex2s(4,95-i);
 }
  
  glEnd();//end drawing of points
 glFlush();
}

int main(int argc, char** argv)
{

 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (800, 900);
 glutInitWindowPosition (400, 800);
 glutCreateWindow ("square ");
 init ();
 glutDisplayFunc(Render);
 glutMainLoop();
 return 0;
}

