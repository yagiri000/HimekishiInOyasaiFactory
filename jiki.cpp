#pragma once

#include "jiki.h"

//�a��or�͂���
void jiki::slash(){

	if(keystate[250] == 1 || keystate[KEY_INPUT_Z] == 1){
		state = 1;
		statetime = 0;
		ishit();
	}
	
	if(keystate[251] == 1 || keystate[KEY_INPUT_X] == 1){
		state = 1;
		statetime = 0;
		isout();
	}
}

void jiki::update(){

	//���Ԍv��
	e_time++;
	statetime++;

	switch (state)
	{
	case 0://�ҋ@
		slash();
		break;

	case 1://�a��
		slash();
		if(statetime > 5){
			state = 0;
			statetime = 0;
		}
		break;

	case 2:

		break;


	default:
		break;
	}

	if(e_time % maxPlayTime == 0){
		miss = 0;
		ob_yasai.makeCool = 10;
		speedrate -= 1;
	}
	if(miss >= 5){
		GAMESTATE = RESULT;
	}
	
	backd.update();
	ob_yasai.update();
	ef.update();
}

//���@�`��
void jiki::drawchara(){
	switch (state)
	{
	case 0://�ҋ@

		if(statetime % 24 <6){
			DrawRotaGraph(x, y, 1.0, 0, GHandle[85], 1, 1);
		}else if(statetime % 24 < 12){
			DrawRotaGraph(x, y, 1.0, 0, GHandle[86], 1, 1);
		}else if(statetime % 24 < 18){
			DrawRotaGraph(x, y, 1.0, 0, GHandle[87], 1, 1);
		}else{
			DrawRotaGraph(x, y, 1.0, 0, GHandle[88], 1, 1);
		}


		break;

	case 1://�a��

		if(statetime < 1){
			DrawRotaGraph(x, y, 1.0, 0, GHandle[80], 1, 1);
		}else if(statetime < 2){
			DrawRotaGraph(x, y, 1.0, 0, GHandle[81], 1, 1);
		}else if(statetime < 3){
			DrawRotaGraph(x, y, 1.0, 0, GHandle[82], 1, 1);
		}else if(statetime < 4){
			DrawRotaGraph(x, y, 1.0, 0, GHandle[83], 1, 1);
		}else{
			DrawRotaGraph(x, y, 1.0, 0, GHandle[84], 1, 1);
		}


		break;

	case 2:

		break;


	default:
		break;
	}
	
	//��؂ւ̃J�[�\���l�p�`��
	DrawRotaGraph(beatx, beaty, 1.0, 0, GHandle[60], 1, 0);
}

//����@�X�R�A�`��
void jiki::drawstr(){
	int strx = 507;
	int stry = 507;

	//stry = 450;

	SetDrawBlendMode( DX_BLENDMODE_ALPHA , 100 );	SetDrawBright(255,255,255);
	DrawBox(strx, stry,strx+300, stry+120, 0x000000, 1);
	SetDrawBlendMode( DX_BLENDMODE_ALPHA , 250 );	SetDrawBright(255,255,255);
	//DrawFormatStringToHandle(20, stry+=20, 0xFFFFFF, FontHandle[0] , "X:%3d Y:%3d", mousex,mousey) ;
	DrawFormatStringToHandle(strx, stry+=5, 0xFFFFFF, FontHandle[1] , "SCORE : %d", score) ;
	DrawFormatStringToHandle(strx, stry+=40, 0xFFFFFF, FontHandle[1] , "MISS : %d", miss) ;
	DrawFormatStringToHandle(180, 70, 0xFFFFFF, FontHandle[1] , "%d���o��", (int)((double)e_time / maxPlayTime)) ;
}

void jiki::draw(){

	backd.draw_f1();//�w�i�`��t�F�C�Y_1
	backd.draw_f2();//�w�i�`��t�F�C�Y_2
	
	drawchara();
	
	ob_yasai.draw();
	ef.draw();
	backd.draw_f3();//�w�i�`��t�F�C�Y_3
	backd.drawclock(e_time);
	drawstr();
}

//��؎a��
void jiki::ishit(){
	int scoreplus = ob_yasai.ishit();
	score += scoreplus;
	
	if(scoreplus < 0){

	}else{
	
	}
}

//���e�e��
void jiki::isout(){
	int scoreplus = ob_yasai.isout();
	score += scoreplus;
	
	if(scoreplus < 0){
	}else{
	}
}