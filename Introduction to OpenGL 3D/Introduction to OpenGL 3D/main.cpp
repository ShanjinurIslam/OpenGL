//
//  main.cpp
//  Introduction
//
//  Created by Shanjinur Islam on 5/2/19.
//  Copyright © 2019 Shanjinur Islam. All rights reserved.
//
#define GL_SILENCE_DEPRECATION
#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

void drawAxes()
{
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
    
        glVertex3f( 100,0,0);
        glVertex3f(-100,0,0);
            
        glVertex3f(0,-100,0);
        glVertex3f(0, 100,0);
            
        glVertex3f(0,0, 100);
        glVertex3f(0,0,-100);
        glEnd();
}

void init(){
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80, 1, 1,1000) ;
}


void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0,100,0,0,0,0,1,0) ;
    drawAxes() ;
    glutSwapBuffers();
}

void animate(){
    glutPostRedisplay();
}

int main(int argc, char *argv[]){
    glutInit(&argc,argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);    //Depth, Double buffer, RGB color
    glutCreateWindow("My OpenGL Program");
    glEnable(GL_DEPTH_TEST);
    
    init() ;
    
    glutDisplayFunc(display);
    glutIdleFunc(animate);
    glutMainLoop() ;
    
    return 0;
}
