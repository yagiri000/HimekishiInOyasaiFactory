#pragma once

#include "func.h"


void keyupdate()
{
	GetHitKeyStateAll(buf);
	buf[250] =  GetMouseInput() & MOUSE_INPUT_LEFT;
	buf[251] =  ( (GetMouseInput() & MOUSE_INPUT_RIGHT) == 0) ? 0 : 1;
	for(int i = 0; i< 256; i++)
	{
		if(buf[i] == 1) keystate[i]++;
		else keystate[i] = 0;
	}
}

//2“_‚Ì‹——£‚ð•Ô‚·
double dist(double x1, double y1, double x2, double y2){
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}


double randarc(){
	return -1.0 + GetRand(65536) / 32768.0;
}

double randvalue(){
	return GetRand(65536) / 65536.0;
}

double randrange(double min, double max){
	return min + (max - min) * randvalue();
}

void randoncircle(const double &r, double &xx, double &yy){
	double randang = 2 * PI * GetRand(32767) / 32767.0;
	xx = r * cos(randang);
	yy = r * sin(randang);
}

void randoncircle(const double &r, double &xx, double &yy, double &ang){
	double randang = 2 * PI * GetRand(32767) / 32767.0;
	xx = r * cos(randang);
	yy = r * sin(randang);
	ang = randang;
}

void randincircle(const double &r, double &xx, double &yy){
	double randang = 2 * PI * GetRand(32767) / 32767.0;
	double rr = r * GetRand(32767) / 32767.0;
	xx = rr * cos(randang);
	yy = rr * sin(randang);
}

void randincircle(const double &r, double &xx, double &yy, double &ang){
	double randang = 2 * PI * GetRand(32767) / 32767.0;
	double rr = r * GetRand(32767) / 32767.0;
	xx = rr * cos(randang);
	yy = rr * sin(randang);
	ang = randang;
}

double randPM1(){
	return -1.0 + GetRand(1) * 2.0;
}


void load_png_wav(){
	GHandle[0] = LoadGraph("images/dot32.png");
	GHandle[1] = LoadGraph("images/dot100.png");
	GHandle[2] = LoadGraph("images/rect32.png");
	GHandle[3] = LoadGraph("images/rect100.png");
	GHandle[4] = LoadGraph("images/redrect32.png");
	
	LoadDivGraph("images/zangeki.png", 5, 5, 1, 1080/5, 108, &(GHandle[80]));
	LoadDivGraph("images/tachi.png", 4, 4, 1, 864/4, 108, &(GHandle[85]));
	
	LoadDivGraph("images/streffect.png", 4, 1, 4, 256, 64, &(GHandle[100]));
	GHandle[110] = LoadGraph("images/shock128.png");

	GHandle[60] = LoadGraph("images/select_64.png");
	
	LoadDivGraph("images/yasai.png", 8, 1, 8, 64, 64, &(GHandle[70]));
	LoadDivGraph("images/yasai.png", 32, 2, 16, 32, 32, &(GHandle[120]));
	
	GHandle[200] = LoadGraph("images/haikei1_1.png");
	GHandle[201] = LoadGraph("images/haikei1_2.png");
	GHandle[202] = LoadGraph("images/haikei1_3.png");
	GHandle[203] = LoadGraph("images/haikei2_1.png");
	GHandle[204] = LoadGraph("images/haikei2_2.png");
	GHandle[205] = LoadGraph("images/haikei3.png");
	GHandle[207] = LoadGraph("images/seiuchi_r1.png");
	GHandle[208] = LoadGraph("images/seiuchi_r2.png");
	GHandle[210] = LoadGraph("images/backscreen.png");
	GHandle[211] = LoadGraph("images/yuka.png");
	GHandle[212] = LoadGraph("images/danbo-ru.png");

	GHandle[220] = LoadGraph("images/nabe1.png");
	GHandle[221] = LoadGraph("images/nabe2.png");

	GHandle[230] = LoadGraph("images/tokei.png");
	GHandle[231] = LoadGraph("images/hari_L.png");
	GHandle[232] = LoadGraph("images/hari_S.png");

	
	GHandle[240] = LoadGraph("images/title.png");
	GHandle[241] = LoadGraph("images/explain.png");
	GHandle[242] = LoadGraph("images/gameover.png");
	GHandle[249] = LoadGraph("images/pressz.png");

	SHandle[0] = LoadSoundMem("sounds/hit52.wav") ;
	SHandle[1] = LoadSoundMem("sounds/chari05.wav") ;
	SHandle[2] = LoadSoundMem("sounds/swing02.wav") ;
	SHandle[3] = LoadSoundMem("sounds/chari05.wav") ;
	SHandle[4] = LoadSoundMem("sounds/attack00.wav") ;
	SHandle[5] = LoadSoundMem("sounds/bom03.wav") ;

	FontHandle[0] = CreateFontToHandle( "Segoe UI" , 20 , 5 ,DX_FONTTYPE_ANTIALIASING_4X4) ;
	FontHandle[1] = CreateFontToHandle( "Segoe UI" , 40 , 6 ,DX_FONTTYPE_ANTIALIASING_4X4) ;
}
