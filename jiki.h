#pragma once

#include <DxLib.h>
#include <iostream>
#include <vector>
#include <string>

#include "myglobal.h"
#include "func.h"
#include "yasai.h"
#include "yasaimanager.h"
#include "backdraw.h"

#include "effectmanager.h"

class jiki{
public:

	int state;
	int statetime;
	int x, y;
	int e_time;
	
	yasaimanager ob_yasai;
	effectmanager ef;
	backdraw backd;
	
	jiki(){
		state = 0;
		statetime = 0;
		x = beatx - 48;
		y = beaty - 48 - 10;
		miss = 0;
		e_time = 0;
		ob_yasai.setptr(&ef);
	}

	void drawchara();
	void drawstr();
	void slash();
	void draw();
	void update();
	void ishit();
	void isout();


};