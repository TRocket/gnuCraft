/*
 * window.cpp
 *
 *  Created on: 18 Apr 2013
 *      Author: TRocket
 */

#include "window.h"

void openGNUCraftWindow(void) {
	if ( SDL_Init(SDL_INIT_VIDEO) != 0 ) {
		std::cout <<  "Unable to initialize SDL: %s\n" << SDL_GetError() << std::endl;
	}

	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

	SDL_Surface* screen = SDL_SetVideoMode( 640, 480, 16, SDL_OPENGL );

	glEnable( GL_TEXTURE_2D );

	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );

	glViewport( 0, 0, 640, 480 );

	glClear( GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT );

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	glOrtho(0.0f, 640, 480, 0.0f, -1.0f, 1.0f);

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();

	SDL_FreeSurface(screen);

	glClear( GL_COLOR_BUFFER_BIT);
	 glColor3f(0.0, 1.0, 0.0);
	 //glRotatef( 5, 1.0, 0.0, 0.0 );
	//  glRotatef( 5, 0.0, 1.0, 0.0 );

	  // Other Transformations
	  // glScalef( 2.0, 2.0, 0.0 );          // Not included

	  //Multi-colored side - FRONT
	  glBegin(GL_POLYGON);

	  glColor3f( 1.0, 0.0, 0.0 );     glVertex3f(  0.5, -0.5, -0.5 );      // P1 is red
	  glColor3f( 0.0, 1.0, 0.0 );     glVertex3f(  0.5,  0.5, -0.5 );      // P2 is green
	  glColor3f( 0.0, 0.0, 1.0 );     glVertex3f( -0.5,  0.5, -0.5 );      // P3 is blue
	  glColor3f( 1.0, 0.0, 1.0 );     glVertex3f( -0.5, -0.5, -0.5 );      // P4 is purple

	  glEnd();

	  // White side - BACK
	  glBegin(GL_POLYGON);
	  glColor3f(   1.0,  1.0, 1.0 );
	  glVertex3f(  0.5, -0.5, 0.5 );
	  glVertex3f(  0.5,  0.5, 0.5 );
	  glVertex3f( -0.5,  0.5, 0.5 );
	  glVertex3f( -0.5, -0.5, 0.5 );
	  glEnd();

	  // Purple side - RIGHT
	  glBegin(GL_POLYGON);
	  glColor3f(  1.0,  0.0,  1.0 );
	  glVertex3f( 0.5, -0.5, -0.5 );
	  glVertex3f( 0.5,  0.5, -0.5 );
	  glVertex3f( 0.5,  0.5,  0.5 );
	  glVertex3f( 0.5, -0.5,  0.5 );
	  glEnd();

	  // Green side - LEFT
	  glBegin(GL_POLYGON);
	  glColor3f(   0.0,  1.0,  0.0 );
	  glVertex3f( -0.5, -0.5,  0.5 );
	  glVertex3f( -0.5,  0.5,  0.5 );
	  glVertex3f( -0.5,  0.5, -0.5 );
	  glVertex3f( -0.5, -0.5, -0.5 );
	  glEnd();

	  // Blue side - TOP
	  glBegin(GL_POLYGON);
	  glColor3f(   0.0,  0.0,  1.0 );
	  glVertex3f(  0.5,  0.5,  0.5 );
	  glVertex3f(  0.5,  0.5, -0.5 );
	  glVertex3f( -0.5,  0.5, -0.5 );
	  glVertex3f( -0.5,  0.5,  0.5 );
	  glEnd();

	  // Red side - BOTTOM
	  glBegin(GL_POLYGON);
	  glColor3f(   1.0,  0.0,  0.0 );
	  glVertex3f(  0.5, -0.5, -0.5 );
	  glVertex3f(  0.5, -0.5,  0.5 );
	  glVertex3f( -0.5, -0.5,  0.5 );
	  glVertex3f( -0.5, -0.5, -0.5 );
	  glEnd();

	 SDL_GL_SwapBuffers();
	 glFlush();

	 SDL_Delay(10000);


}


