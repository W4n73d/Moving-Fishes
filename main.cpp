#include<windows.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<GL/glut.h>
#define c (3.141/180)

GLfloat x,tr,t,r=.032,s=7,angle=180,factor=1;
const float DEG2RAD = 3.14159 / 180;
float radius = 0.05;
void myInit()
{
 glClearColor(0,0,1,1);
 glColor3f(1,1,1);
 glPointSize(5);
}
void display()
{
         glClearColor(.45, .29, .76, 0);
         glClear(GL_COLOR_BUFFER_BIT);
         glColor3f(0.19, 0.27, 0.39);
 while(s){
        factor-=0.1;
        GLfloat i=-45;
        glScalef(factor,factor,0);
        glRotatef(-1*angle, 0,1,0);

        while(i<=(130+4*r))
         {
                 x=c*i;
                 //fish1
                 glColor3f(1,1,0);
                 glBegin(GL_QUADS);
                 glVertex2f(-.9+x,-.05+sin(7*x));
                 glVertex2f(-1+x,-.1+sin(7*x));
                 glVertex2f(-1+x,.1+sin(7*x));
                 glVertex2f(-.9+x,.05+sin(7*x));
                 glEnd();

                 glBegin(GL_POLYGON);
                 glVertex2f(-.9+x,.05+sin(7*x));
                 glVertex2f(-.8+x,.15+sin(7*x));
                 glVertex2f(-.7+x,.12+sin(7*x));
                 glVertex2f(-.6+x,0+sin(7*x));
                 glVertex2f(-.7+x,-.12+sin(7*x));
                 glVertex2f(-.8+x,-.15+sin(7*x));
                 glVertex2f(-.9+x,-.05+sin(7*x));
                 glEnd();

                 glColor3f(0,0,0);
                 glBegin(GL_LINE_STRIP);
                 glVertex2f(-.75+x,.08+sin(7*x));
                 glVertex2f(-.8+x,.04+sin(7*x));
                 glVertex2f(-.75+x,0+sin(7*x));
                 glEnd();

                 //fish2
                 glColor3f(1,0,0);
                 glBegin(GL_QUADS);
                 glVertex2f(-.4+x,-.05+sin(9*x));
                 glVertex2f(-.5+x,-.1+sin(9*x));
                 glVertex2f(-.5+x,.1+sin(9*x));
                 glVertex2f(-.4+x,.05+sin(9*x));
                 glEnd();

                 glBegin(GL_POLYGON);
                 glVertex2f(-.4+x,.05+sin(9*x));
                 glVertex2f(-.3+x,.15+sin(9*x));
                 glVertex2f(-.2+x,.12+sin(9*x));
                 glVertex2f(-.1+x,0+sin(9*x));
                 glVertex2f(-.2+x,-.12+sin(9*x));
                 glVertex2f(-.3+x,-.15+sin(9*x));
                 glVertex2f(-.4+x,-.05+sin(9*x));
                 glEnd();

                 glColor3f(1,1,1);
                 glBegin(GL_LINE_STRIP);
                 glVertex2f(-.25+x,.08+sin(9*x));
                 glVertex2f(-.3+x,.04+sin(9*x));
                 glVertex2f(-.25+x,0+sin(9*x));
                 glEnd();


                 glFlush();
                 glClear(GL_COLOR_BUFFER_BIT);
                 _sleep(100);
                 i++;
         }
 s--;
 }
}


void handleKeypress(unsigned char key, //The key that was pressed
	int x, int y) {    //The current mouse coordinates

	switch (key) {
	case 27: //Escape key
		exit(0); //Exit the program
	}
}


int main(int argc,char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(800,600);
 glutCreateWindow("fish");
 glutDisplayFunc(display);
 myInit();
 glutKeyboardFunc(handleKeypress);


 glutMainLoop();
}
