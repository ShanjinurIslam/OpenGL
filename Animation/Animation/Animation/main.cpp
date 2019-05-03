//
//  main.cpp
//  Animation
//
//  Created by Shanjinur Islam on 5/3/19.
//  Copyright © 2019 Shanjinur Islam. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

//global var

double x = -10 ;
double y = 0 ;
int state = 1 ;

void triangle() ;

void display(){
    
    glClear(GL_COLOR_BUFFER_BIT) ;
    glLoadIdentity() ;
    triangle() ;
    glutSwapBuffers() ;
}

void triangle(){
    glBegin(GL_POLYGON);
    glColor3f(0.0,0, 1.0) ;
    glVertex2d(x, 0+y) ;
    glVertex2d(x+3, 0+y) ;
    
    glColor3f(1.0,0, 1.0) ;
    glVertex2d(x+3, 3+y) ;
    
    glColor3f(0.0,1.0, 1.0) ;
    glVertex2d(x, 3+y) ;
    glEnd() ;
}


void reshape(int x,int y) {
    glViewport(0, 0, x, y) ;
    glMatrixMode(GL_PROJECTION) ;
    glLoadIdentity() ;
    gluOrtho2D(-10,+10, -10,+10) ;
    glMatrixMode(GL_MODELVIEW) ;
}

void timer(int sec){
    glutPostRedisplay() ;
    glutTimerFunc(1000/60,timer,0) ;
    switch (state) {
        case 1:
            if(x<7) x+=.30 ;
            else state = 2;
            break;
            
        case 2:
            if(x>-10) x-=.30 ;
            else state = 1;
            break;
    }
}

void func(int key,int a,int b){
    if(key==101 && y<7){
        y += 1 ;
    }
    if(key==103 && y>-10){
        y -= 1 ;
    }
    if(key==100 && x>-10){
        x -= 1 ;
    }
    if(key==102 && x<7){
        x += 1 ;
    }
}

int main(int argc, char * argv[]) {
    glutInit(&argc,argv) ;
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE ) ;
    glutInitWindowPosition(300,200) ;
    glutInitWindowSize(500,500) ;
    glutCreateWindow("Window 1") ;
    glutDisplayFunc(display) ;
    glutReshapeFunc(reshape) ;
    glutSpecialFunc(func) ;
    glutTimerFunc(0,timer,0) ;
    glutMainLoop();
    return 0;
}
