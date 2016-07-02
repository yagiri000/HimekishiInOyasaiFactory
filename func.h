#pragma once

#include <DxLib.h>
#include <iostream>
#include <vector>
#include <string>

#include "myglobal.h"


void keyupdate();

//2“_‚Ì‹——£‚ð•Ô‚·
double dist(double x1, double y1, double x2, double y2);

double randarc();

double randvalue();

double randrange(double min, double max);

void randoncircle(const double &r, double &xx, double &yy);

void randoncircle(const double &r, double &xx, double &yy, double &ang);

void randincircle(const double &r, double &xx, double &yy);

void randincircle(const double &r, double &xx, double &yy, double &ang);

double randPM1();

void load_png_wav();