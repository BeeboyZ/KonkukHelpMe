#pragma once
#include<iostream>
#include<windows.h>
#include<cstdlib>
#include "SystemEvent.h"
#include "RankingView.h"
#include "EvadeGrade.h"
#include "card.h"
#include "Ilgamlake.h"
#include "Game.h"

using namespace std;

class SystemUI
{
private:
	RankingView rankingView;
	EvadeGrade evadeGrade;
	Card card;
	Ilgamlake ilgamlake;

public:
	SystemUI();
	~SystemUI();
	void initFrame(int width, int height);
	void mainTitle();
	//void cursorMoveXY(int x, int y);
	int mainTitleMenu();
	void mainMenuAction(int index);
};

