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

	glClear( GL_COLOR_BUFFER_BIT );

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	glOrtho(0.0f, 640, 480, 0.0f, -1.0f, 1.0f);

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();

	SDL_FreeSurface(screen);

	glClear( GL_COLOR_BUFFER_BIT);
	 glColor3f(0.0, 1.0, 0.0);
	 glBegin(GL_POLYGON);
	  glVertex3f(20.0, 4.0, 0.0);
	  glVertex3f(80.0, 4.0, 0.0);
	  glVertex3f(80.0, 6.0, 0.0);
	  glVertex3f(2.0, 60.0, 0.0);
	 glEnd();
	 SDL_GL_SwapBuffers();
	 glFlush();

	SDL_Delay(10000);
}


