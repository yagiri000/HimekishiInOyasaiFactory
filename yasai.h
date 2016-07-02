#pragma once

#include <DxLib.h>
#include <iostream>
#include <vector>
#include <string>

#include "myglobal.h"
#include "func.h"

#include "effectmanager.h"

class yasai{
public:

	int state;
	int xshift;
	int imagenum;
	double yshift, vy;
	yasai(){
		yshift = 0;
		vy = 0;
		imagenum = GetRand(4);
		xshift = 900;
		state = 0;
	}
	effectmanager* p_ef;
	void setptr(effectmanager* p){
		p_ef = p;
	}
	void draw();
	void update();
	int ishit();
	int isout();

};