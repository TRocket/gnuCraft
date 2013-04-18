/*
 * gnucraft.cpp
 *
 *  Created on: 18 Apr 2013
 *      Author: TRocket
 */
#include <iostream>
#include "version.h"
#include "window.h"

int main(void) {
	std::cout << "gnucraft v." << GIT_VERSION << std::endl;
	openGNUCraftWindow();
}



