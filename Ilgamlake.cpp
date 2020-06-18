#include <iostream>
#include "conio.h"
#include "windows.h"
#include "Ilgamlake.h"
using namespace std;

void Setting::SetConsoleSize(int width, int height) {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}//콘솔크기 정하기
void Setting::gotoxy(int x, int y) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	_COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hConsole, pos);
}//좌표 설정

inline void Player::CalcBodyPos() {
	if (pivotPos.x <= 2) {
		pivotPos.x = 2;
	}
	if (pivotPos.x > screenWidth - 2) {
		pivotPos.x = screenWidth - 2;
	}
	if (pivotPos.y > screenHeight - 2) {
		pivotPos.y = screenHeight - 3;
	}//플레이어가 화면 벗어나지 못하게 막기
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i < 1) bodyPos[i][j].y = pivotPos.y - 1;
			else if (i > 1) bodyPos[i][j].y = pivotPos.y + 1;
			else bodyPos[i][j].y = pivotPos.y;
			if (j < 1) bodyPos[i][j].x = pivotPos.x - 1;
			else if (j > 1) bodyPos[i][j].x = pivotPos.x + 1;
			else bodyPos[i][j].x = pivotPos.x;
		}
	}//플레이어의 좌표를 3x3 배열 bodypos에 저장
}
Player::Player(int posX, int posY) {
	originalPivotPos.x = posX;
	originalPivotPos.y = posY;
	pivotPos = originalPivotPos;
	CalcBodyPos();
	direction = 0;
}
void Player::Reset() {
	pivotPos = originalPivotPos;
	CalcBodyPos();
	direction = 0;
}//플레이어를 다시 원래 위치로
void Player::Move() {
	switch (direction) {
	case 0:
		break;
	case 1:
		pivotPos.x -= 3;
		break;
	case 2:
		pivotPos.x += 3;
		break;
	case 3:
		pivotPos.y -= 3;
		break;
	case 4:
		pivotPos.y += 3;
		break;
	default:
		break;
	}
	CalcBodyPos();
}//방향키 누를때마다 플레이어 움직이게
inline int Player::getPivotPosX() {
	return pivotPos.x;
}
inline int Player::getPivotPosY() {
	return pivotPos.y;
}
inline int Player::getDirection() {
	return direction;
}
inline void Player::setDirection(int dir) {
	direction = dir;
}
inline void Obstacle::CalcBodyPos() {
	if (pivotPos.x > screenWidth) {
		pivotPos.x = -1;
		speed = rand() % 2 + 1;
	}//오른쪽으로 가는 장애물 속도 설정
	if (pivotPos.x < -1) {
		pivotPos.x = screenWidth - 1;
		speed = rand() % 2 + 1;
	}//왼쪽으로 가는 장애물 속도 설정
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i < 1)
				bodyPos[i][j].y = pivotPos.y - 1;
			else if (i > 1) bodyPos[i][j].y = pivotPos.y + 1;
			else bodyPos[i][j].y = pivotPos.y;
			if (j < 1) bodyPos[i][j].x = pivotPos.x - 1;
			else if (j > 1) bodyPos[i][j].x = pivotPos.x + 1;
			else bodyPos[i][j].x = pivotPos.x;
		}
	}
}//장애물의 좌표를 3x3 배열 bodypos에 저장
Obstacle::Obstacle(int posX, int posY, int dir, int spd, char ch) {
	originalPivotPos.x = posX;
	originalPivotPos.y = posY;
	pivotPos = originalPivotPos;
	CalcBodyPos();
	speed = spd;
	direction = dir;
	bodyChar = ch;
}
void Obstacle::Move() {
	switch (direction) {
	case 0:
		break;
	case 1:
		pivotPos.x -= speed;
		break;
	case 2:
		pivotPos.x += speed;
		break;
	default:
		break;
	}
	CalcBodyPos();
}//장애물이 움직이게 위치를 speed만큼 계속 더하기
inline int Obstacle::getPivotPosX() {
	return pivotPos.x;
}
inline int Obstacle::getPivotPosY() {
	return pivotPos.y;
}
inline char Obstacle::getBodyChar() {
	return bodyChar;
}
inline int Obstacle::getDirection() {
	return direction;
}

GameManager::GameManager(int h, int w) {
	height = h, width = w;
	score = 0;
	gameOver = false;
	player = new Player(width / 2 - 1, height - 3);
	for (int i = 0; i < 10; i++) {
		int randomSpeed = rand() % 2 + 1;
		{
			if (i % 2 == 0) {
				obs[i] = new Obstacle(2, i * 3 + 2, 2, randomSpeed, '>');
			}
			else {
				obs[i] = new Obstacle(width - 2, i * 3 + 2, 1, randomSpeed, '<');
			}
		}//장애물 객체를 오른쪽 5개 왼쪽 5개 만들기
	}

}
GameManager::~GameManager() {
	delete player, obs;
}
void GameManager::CheckInput() {
	if (_kbhit()) {
		char current = _getch();
		if (current == 'w' || current == 'W') {
			player->setDirection(3);
		}
		else if (current == 's' || current == 'S') {
			if (player->getPivotPosY() < height - 3)
				player->setDirection(4);
		}
		else if (current == 'a' || current == 'A') {
			player->setDirection(1);
		}
		else if (current == 'd' || current == 'D') {
			player->setDirection(2);
		}
	}
	else player->setDirection(0);
}
void GameManager::scoreUp() {
	score += 20;
	set->gotoxy(width / 2 - 6, height / 2);
	cout << "20점 획득!";
	Sleep(1000);
	player->Reset();
}
void GameManager::Logic() {
	player->Move();
	for (int t = 0; t < 10; t++) {
		obs[t]->Move();
	}
	if (player->getPivotPosY() < 2) {
		scoreUp();
	}
}
void GameManager::Draw() {
	set->gotoxy(0, 0);
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			bool isPrinted = false;
			bool playerPrinted = false;
			if (y == 0 || y == height - 1) {
				cout << '#';
				isPrinted = true;
			}//시작과 끝에 # 그리기
			if (!isPrinted) {
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						if (y == player->bodyPos[i][j].y && x == player->bodyPos[i][j].x) {
							cout << '^';
							isPrinted = true;
							playerPrinted = true;
						} //콘솔 좌표와 플레이어 객체 좌표가 같다면 플레이어 그리기
					}
				}
			}
			for (int t = 0; t < 10; t++) {
				for (int u = 0; u < 3; u++) {
					for (int v = 0; v < 3; v++) {
						if (y == obs[t]->bodyPos[u][v].y && x == obs[t]->bodyPos[u][v].x) {
							if (!playerPrinted) {
								cout << obs[t]->getBodyChar();
								isPrinted = true;
							}//플레이어가 그려져있지 않고 콘솔 좌표와 장애물 객체 좌표가 같다면 장애물 그리기
							else gameOver = true;
						}//장애물 보다 플레이어가 먼저 그려져 있으면 게임오버 시키기 
					}
				}
			}
			if (!isPrinted) cout << ' ';
		}
		cout << endl;
	}
	if (score == 100) {
	gameOver = true;
	}//스코어가 100점이 되면 게임 종료
	set->gotoxy(width / 2 - 3, height + 1);
	cout << "START";
	set->gotoxy(screenWidth / 2 + 36, screenHeight / 2);
	cout << "건국대 살려조";
	set->gotoxy(screenWidth / 2 + 35, screenHeight / 2 + 1);
	cout << "일감호를 건너라";
	set->gotoxy(screenWidth / 2 + 39, screenHeight / 2 + 2);
	cout << "점수: " << score;
}
void GameManager::Run() {
	while (!gameOver) {
		CheckInput();
		Logic();
		Draw();
	}
	GameOver();
}
void GameManager::GameOver() {
	if (score == 0) {
		grade = 'F';
	}
	else if (score == 20) {
		grade = 'D';
	}
	else if (score == 40 || score == 60) {
		grade = 'C';
	}
	else if (score == 80) {
		grade = 'B';
	}
	else {
		grade = 'A';
	}//점수따라 학점 계산
	system("cls");
	for (int i = 0; i < 5; i++) { cout << "                                                                 " << endl; }
	cout << " " << "###################################################################################" << endl;
	cout << " " << "                                  게임 오버 ㅠ_ㅠ                                   " << endl;
	cout << " " << "                            획득한 총 점수는 " << score << "점 입니다.                  " << endl;
	cout << " " << "                                     " << grade << " 학점!!                                       " << endl;
	cout << " " << "###################################################################################" << endl;

	for (int i = 0; i < 3; i++) { cout << "                                                                 " << endl; }
	cout << " " << ".d8888b.                                        .d88888b." << endl;
	cout << " " << "d88P  Y88b                                     d88P' 'Y88b" << endl;
	cout << " " << "888    888                                     888     888" << endl;
	cout << " " << "888         8888b.  88888b.d88b.   .d88b.      888     888 888  888  .d88b.  888d888" << endl;
	cout << " " << "888  88888     '88b 888 '888 '88b d8P  Y8b     888     888 888  888 d8P  Y8b 888P'" << endl;
	cout << " " << "888    888 .d888888 888  888  888 88888888     888     888 Y88  88P 88888888 888" << endl;
	cout << " " << "Y88b  d88P 888  888 888  888  888 Y8b.         Y88b. .d88P  Y8bd8P  Y8b.     888" << endl;
	cout << " " << "'Y8888P88  'Y888888 888  888  888  'Y8888       'Y88888P'    Y88P    'Y8888  888" << endl;
	cout << " " << endl;
}
int GameManager::sendScore(){
	return score;
}//게임 메인 클래스용 점수게터

int Ilgamlake::playIlgam() {
	system("cls");
	Setting* sett = new Setting();
	sett->SetConsoleSize(720, 640);
	GameManager GM(screenHeight, screenWidth);
	GM.Run();
	score = GM.sendScore();
	return 0;
}//게임 메인 클래스

/*
int Ilgamlake::getScore() { 
	return score;
}//systemui용 점수게터
*/