#include <DxLib.h>
#include <iostream>
#include <vector>
#include <string>

#include "myglobal.h"
#include "func.h"
#include "jiki.h"

#include "effects.h"
#include "effectbase.h"
#include "effectmanager.h"
#include "title.h"
#include "explain.h"
#include "result.h"


enumGAMESTATE GAMESTATE = TITLE;

int GHandle[999];
int SHandle[99];
int FontHandle[9];
int mousex=0 , mousey=0;//�}�E�X���W
int keika = 0;//�o�߃t���[��

int score = 0;
int miss = 0;

//�L�[�擾�}�E�X�t��
char buf[256] = {0};
int keystate[256] = {0};

int speedrate = 15;


int WINAPI WinMain( HINSTANCE hInstance , HINSTANCE hPrevInstance , LPSTR lpCmdLine , int nCmdShow )
{
	ChangeWindowMode( TRUE );
	SetGraphMode( ScreenX , ScreenY , 32 );
	SetOutApplicationLogValidFlag( FALSE ) ;//log�𐶐����Ȃ��悤�ɐݒ�
	SetMainWindowText("�P�R�min���₳���ӂ����Ƃ肢");
	if(DxLib_Init() == 1){return -1;}//�������Ɏ��s���ɃG���[��f�����ďI��
	SetDrawScreen( DX_SCREEN_BACK ) ;
	load_png_wav();//�t�H���g�E���E�摜�ǂݍ���

	jiki ob_jiki;
	title ob_title;
	explain ob_explain;
	result ob_result;

	while( ProcessMessage()==0)
	{
		ClearDrawScreen();//����ʏ���
		SetDrawScreen( DX_SCREEN_BACK ) ;
		GetMousePoint( &mousex, &mousey ); //�}�E�X���W�X�V
		keyupdate();//�L�[�X�V
		keika++;
		
		int stry = 0;

		switch (GAMESTATE)
		{
		case TITLE:
			ob_title.update();
			ob_title.draw();
			break;

		case EXPLAIN:
			ob_explain.update();
			ob_explain.draw();
			break;

		case GAMEMAIN:
			ob_jiki.update();
			ob_jiki.draw();
			ob_result.init();//FEXME�@result��etime�����Z�b�g
			break;

		case RESULT:
			ob_result.update();
			ob_result.draw();
			break;

		default:
			break;
		}

		if(GAMESTATE == EXIT){
			break;
		}

		ScreenFlip();//����ʂ�\��ʂɃR�s�[
	}

	DxLib_End();
	return 0;
}

