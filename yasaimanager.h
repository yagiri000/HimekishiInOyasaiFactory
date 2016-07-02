#pragma once

#include <DxLib.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

#include "myglobal.h"
#include "func.h"
#include "yasai.h"

#include "effectmanager.h"

class yasaimanager{
public:
	std::vector<std::shared_ptr<yasai>> v;
	
	effectmanager* p_ef;
	void setptr(effectmanager* p){
		p_ef = p;
	}

	int makeCool;

	yasaimanager(){
		makeCool = 0;
	}

	void draw();
	void update();
	int ishit();
	int isout();

};