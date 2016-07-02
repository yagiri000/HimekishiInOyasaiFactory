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
int mousex=0 , mousey=0;//マウス座標
int keika = 0;//経過フレーム

int score = 0;
int miss = 0;

//キー取得マウス付き
char buf[256] = {0};
int keystate[256] = {0};

int speedrate = 15;


int WINAPI WinMain( HINSTANCE hInstance , HINSTANCE hPrevInstance , LPSTR lpCmdLine , int nCmdShow )
{
	ChangeWindowMode( TRUE );
	SetGraphMode( ScreenX , ScreenY , 32 );
	SetOutApplicationLogValidFlag( FALSE ) ;//logを生成しないように設定
	SetMainWindowText("姫騎士inおやさいふぁくとりい");
	if(DxLib_Init() == 1){return -1;}//初期化に失敗時にエラーを吐かせて終了
	SetDrawScreen( DX_SCREEN_BACK ) ;
	load_png_wav();//フォント・音・画像読み込み

	jiki ob_jiki;
	title ob_title;
	explain ob_explain;
	result ob_result;

	while( ProcessMessage()==0)
	{
		ClearDrawScreen();//裏画面消す
		SetDrawScreen( DX_SCREEN_BACK ) ;
		GetMousePoint( &mousex, &mousey ); //マウス座標更新
		keyupdate();//キー更新
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
			ob_result.init();//FEXME　resultのetimeをリセット
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

		ScreenFlip();//裏画面を表画面にコピー
	}

	DxLib_End();
	return 0;
}

