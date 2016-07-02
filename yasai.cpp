#pragma once

#include "yasai.h"


void yasai::update(){
	xshift -= 5;

	if(xshift + beatx  < 0 || beaty+ yshift > 510){
		miss ++;
		PlaySoundMem(SHandle[4], DX_PLAYTYPE_BACK);
		p_ef->add<streffect>(100, 400,  GHandle[100]);
		state = 1;
	}

	if(beatx +xshift < combereX){
		yshift += vy;
		vy += 0.6;
	}
}

void yasai::draw(){
	//”š’e‚¾‚Á‚½‚ç@¨imagenum = 4
	if(imagenum == 4){
		int im = 0;
		if(keika % 8 < 4){
			im = 1;
		}
		DrawRotaGraph((int)(beatx + xshift), (int)(beaty + yshift), 1.0, 0, GHandle[70+im+4], 1, 0);
	}else{
		DrawRotaGraph((int)(beatx +xshift), (int)(beaty+ yshift), 1.0, 0, GHandle[70+imagenum], 1, 0);
	}

}



int yasai::ishit(){
	//”š’e‚¾‚Á‚½‚ç
	if(abs(xshift) < 40){
		int scoreplus = 0;

		if(imagenum == 4){
			state = 1;
			p_ef->add<streffect>(beatx, beaty, GHandle[100]);
		for(int i = 0; i < 4; i++){
			p_ef->add<yasai_hahen>(beatx, beaty, GHandle[120 + i + imagenum*4]);
		}
			PlaySoundMem(SHandle[5], DX_PLAYTYPE_BACK);
			miss++;
			return -100;
		}
		state = 1;
		PlaySoundMem(SHandle[0], DX_PLAYTYPE_BACK);
		for(int i = 0; i < 4; i++){
			p_ef->add<yasai_hahen>(beatx, beaty, GHandle[120 + i + imagenum*4]);
		}
		scoreplus = (90 - abs(xshift)) + 1;
		double ef_x = beatx + randrange(-70, 70);
		double ef_y = beaty + randrange(-70, -170);
		p_ef->add<aaa>(beatx, beaty);
		p_ef->add<shock>(beatx, beaty);
		if(scoreplus > 85){
			p_ef->add<streffect>(ef_x, ef_y, GHandle[103]);
		}else if(scoreplus >80){
			p_ef->add<streffect>(ef_x, ef_y, GHandle[102]);
		}else{
			p_ef->add<streffect>(ef_x, ef_y,  GHandle[101]);
		}
		for(int i = 0; i < 10; i++){
			p_ef->add<ccc>(beatx, beaty);
		}
		return scoreplus;
	}else{
		return 0;
	}
}


int yasai::isout(){
	if(abs(xshift) < 40){
		int scoreplus = 0;

		if(imagenum != 4){
			state = 1;
				p_ef->add<hahen>(beatx, beaty, GHandle[70 + imagenum]);
			p_ef->add<streffect>(beatx, beaty, GHandle[100]);
			PlaySoundMem(SHandle[5], DX_PLAYTYPE_BACK);
			miss++;
			return -100;
		}
		PlaySoundMem(SHandle[0], DX_PLAYTYPE_BACK);
				p_ef->add<hahen>(beatx, beaty, GHandle[70 + imagenum]);
		scoreplus = (90 - abs(xshift)) + 1;
		double ef_x = beatx + randrange(-70, 70);
		double ef_y = beaty + randrange(-70, -170);
		//p_ef->add<aaa>(beatx, beaty);
		p_ef->add<shock>(beatx, beaty);
		if(scoreplus > 85){
			p_ef->add<streffect>(ef_x, ef_y, GHandle[103]);
		}else if(scoreplus >80){
			p_ef->add<streffect>(ef_x, ef_y, GHandle[102]);
		}else{
			p_ef->add<streffect>(ef_x, ef_y,  GHandle[101]);
		}
		//for(int i = 0; i < 10; i++){p_ef->add<ccc>(beatx, beaty);	}
		state = 1;
		return scoreplus;
	}else{
		return 0;
	}
}
