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

void initDefaultColor(){
    glClearColor(0.0,0.0,0.0, 1.0) ;
}

void callBack(){
    //clear
    glClear(GL_COLOR_BUFFER_BIT) ;
    glLoadIdentity() ; //transformation or scaling
    
    //draw
    //draw points
    glPointSize(10.0) ;
    
    glBegin(GL_POINTS) ;
     
    
    glVertex2i(5,5) ;
    glVertex2i(-5,-5) ;
    //points ;
    glEnd() ;
    
    
    glBegin(GL_TRIANGLES) ;

    //t-1
    glVertex2i(5,0) ;
    glVertex2i(-5,-0) ;
    glVertex2i(0,5) ;
    
    //t-2
    glVertex2i(-2,-2) ;// dekhay nai.
    glVertex2i(-2,0) ;// dekhay nai.
    glVertex2i(0,-2) ;// dekhay nai.
    
    glEnd() ;
    
    glBegin(GL_POLYGON) ;
    
    glVertex2i(5,0) ;
    glVertex2i(0,0) ;
    glVertex2i(0,5) ;
    glVertex2i(5,5) ;
    
    glEnd() ;
    
    
    //flush
    
    glFlush() ;
}

void reshape(int x,int y){
    // viewport
    glViewport(0,0,(GLsizei)x,(GLsizei)y) ;
    glMatrixMode(GL_PROJECTION) ;
    glLoadIdentity() ;//reset kore dibe
    gluOrtho2D(-10, +10, -10, +10) ;
    glMatrixMode(GL_MODELVIEW) ;
    // openGL 1. Model View Mode/Matrix 2. Projection Mode/Matrix
    //projection
}

int main(int argc,char * argv[]) {
    glutInit(&argc,argv) ;
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(300, 200) ;
    glutInitWindowSize(500, 500) ;
    glutCreateWindow("Tutorial1") ;
    glutDisplayFunc(callBack) ;
    glutReshapeFunc(reshape) ;
    
    initDefaultColor() ;
    glutMainLoop() ;
    return 0;
}
