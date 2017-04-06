//
//  main.cpp
//  TP5
//
//  Created by faq on 4/5/17.
//  Copyright © 2017 faq. All rights reserved.
//

#include <iostream>
#include <ncurses.h>

#define TICKRATE 100

#define WORLD_WIDTH 50
#define WORLD_HEIGHT 20

#define SNAKEY_LENGTH 40

int main(int argc, const char * argv[]) {

	WINDOW *snakeys_world;
	int offsetx, offsety;
 
	initscr();
	refresh();
 
	offsetx = (COLS - WORLD_WIDTH) / 2;
	offsety = (LINES - WORLD_HEIGHT) / 2;
 
	snakeys_world = newwin(WORLD_HEIGHT,
						   WORLD_WIDTH,
						   offsety,
						   offsetx);
 
	box(snakeys_world, 0 , 0);
 
	wrefresh(snakeys_world);
 
	getch();
 
	delwin(snakeys_world);
 
	endwin();
 
	return 0;
}
