#pragma once

const double PI = 4 * atan(1);
const double arcrad = PI / 180;
const int ScreenX = 800;
const int ScreenY = 600;
const int maxPlayTime = 10 * 60;//ゲームプレイ時間

const int Xnum = 25;
const int Ynum = 20;
const int TileSize = 32;

const int beatx = 400;
const int beaty = 340;


const int combereX = 210;

extern int score;
extern int miss;

extern int speedrate;


enum enumGAMESTATE{TITLE, EXPLAIN, GAMEMAIN, RESULT, EXIT};
extern enumGAMESTATE GAMESTATE;

extern int GHandle[999];
extern int SHandle[99];
extern int FontHandle[9];
extern int mousex , mousey;//マウス座標
extern int keika;//経過フレーム

//キー取得マウス付き
extern char buf[256];
extern int keystate[256];
