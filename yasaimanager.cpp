#pragma once

#include "yasaimanager.h"

void yasaimanager::update(){
	if(makeCool <= 0 ){
		if(keika % speedrate == 0){
			if(GetRand(100) < 80){
				std::shared_ptr<yasai> p = std::make_shared<yasai>();
				p->setptr(p_ef);
				v.push_back(p);
			}
		}
	}else{
		makeCool--;
	}
	for(auto i : v){
		i->update();
	}

	//remove_if
	auto rmv = std::remove_if(v.begin(), v.end(),
		[](std::shared_ptr<yasai> i){
			if( i->state == 1){//aŒ‚
				return true;
			}else{
				return false;
			}
	}
	);
	//remove_if¨erase‚ÅŠ®‘Síœ
	v.erase(rmv, v.end());
}

void yasaimanager::draw(){
	for(auto i : v){
		i->draw();
	}
}

int yasaimanager::ishit(){
	int scoreplus = 0;
	for(auto i : v){
		scoreplus += i->ishit();
		if(scoreplus != 0){
			break;
		}
	}

	return scoreplus;
}

int yasaimanager::isout(){
	
	int scoreplus = 0;
	for(auto i : v){
		scoreplus += i->isout();
	}

	return scoreplus;


}