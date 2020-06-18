#include "RankingView.h"

RankingView::RankingView()
{
	readRankingFile();
}


RankingView::~RankingView()
{
}

void RankingView::showRankingView()
{
	//�ܼ�â �����
	system("cls");
	rankingViewFrame();
}

void RankingView::rankingViewFrame()
{
	printf("\n\n\n\n");
	cout << "               ______                _     _" << endl;
	cout << "               | ___                | |   (_)" << endl;
	cout << "               | |_/ /  __ _  _ __  | | __ _  _ __    __ _" << endl;
	cout << "               |    /  / _` || '_   | |/ /| || '_    / _` |" << endl;
	cout << "               | |  | (_| | || | | ||   < | || | | |(_| | |" << endl;
	cout << "               |_| |_| |__,_||_| |_||_| _||_||_| |_|  __, |" << endl;
	cout << "                                                      __/ |" << endl;
	cout << "                                                     |___/" << endl;

	printf(" =================================================================================\n");
	printf(" ||%3s %10s %25s %25s         ||\n", "����", "�̸�", "����", "���"); //����10ĭ
	printf(" =================================================================================\n");

	//������ ���¿� ����
	for (int i = 0; i < userdata.size(); i++) {
		printf(" ||%3d %10s %24d %24d            ||\n", i + 1, (userdata.at(i).name).c_str(), userdata.at(i).score, userdata.at(i).grade); //���� 12ĭ
		Sleep(200); //���� ������ �� �̤���
	}
	printf(" =================================================================================\n");
	printf(" �ƹ�Ű�� ������ �ʱ�ȭ������");

	char tmp = _getch();
}

//�ٸ� Ŭ�������� ranking�� ���ο� ���������� �߰�
void RankingView::addGameResult(string name, int score, int grade)
{
	UserData tmpData;
	
	tmpData.name = name;
	tmpData.score = score;
	tmpData.grade = grade;
	//csv���Ͽ� �ֱ�
	writeRankingFile(tmpData);
}

void RankingView::showResultPage(Game game1, Game game2, Game game3)
{
	system("cls");
	SystemEvent systemEvent;
	cout << "\n\n\n\n\n";
	cout << "               ==============================================" << endl;
	cout << "               ||           _______    _______    __       ||" << endl;
	cout << "               ||         /  _____|   /  _____|  |  |      ||" << endl;
	cout << "               ||         |  |  __   |  |  __    |  |      ||" << endl;
	cout << "               ||         |  | |_ |  |  | |_ |   |  |      ||" << endl;
	cout << "               ||         |  |__| |  |  |__| |   |__|      ||" << endl;
	cout << "               ||         |_______|  |_______|   (__)      ||" << endl;
	cout << "               ||                                          ||" << endl;
	cout << "               ==============================================\n";
	cout << "\n";
	cout << "                  __   __       ___       ___  ___   _______" << endl;
	cout << "                 |  | |  |     /   |     |   |/   | |   ____|" << endl;
	cout << "                 |   ||  |    /  ^  |    |  |  /  | |  |__" << endl;
	cout << "                 |  . `  |   /  /_|  |   |  ||/|  | |   __|" << endl;
	cout << "                 |  ||   |  /  _____  |  |  |  |  | |  |____" << endl;
	cout << "                 |__| |__| /__/     |__| |__|  |__| |_______|" << endl;
	cout << "\n\n\n";
	cout << "               ==============================================" << endl;
	cout << "               ||                                          ||" << endl;
	cout << "               ||                    ___                   ||" << endl;
	cout << "               ||                                          ||" << endl;
	cout << "               ==============================================" << endl;

	systemEvent.cursorMoveXY(35, 26);
	cout << "> ";
	cin >> tmpUsername;

	getUserScore(game1, game2, game3);
}

//������ �о userdata ���ͺ����� ����
void RankingView::readRankingFile()
{
	fstream file;
	char ch[100];
	char *context;
	string line;
	UserData tmpdata;
	file.open("Ranking.csv");
	if (file.fail()) {
		cout << "cannot found ranking fild" << endl;
		exit(0);
	}

	//Ÿ��Ʋ�κ� ����
	getline(file, line, '\n');
	//���δ����� �о �ӽ÷� line�� ����
	while (getline(file, line, '\n')) {
		//string to char >> stringd�� charŸ�Ժ����� ����
		//strtok�� ���ؼ�
		strcpy_s(ch, sizeof(ch), line.c_str());

		char *tok = strtok_s(ch, ",", &context);
		tmpdata.name = tok;
		tok = strtok_s(NULL, ",", &context);
		tmpdata.score = atoi(tok);
		tok = strtok_s(NULL, ",", &context);
		tmpdata.grade = atoi(tok);

		userdata.push_back(tmpdata);
		
	}
	bubbleSort();

	file.close();
}

void RankingView::bubbleSort()
{
	for (int i = 0; i < userdata.size()-1; i++) {
		for (int j = 0; j < userdata.size() - i-1; j++) {
			if (userdata.at(j).score<userdata.at(j+1).score) {
				UserData tmp = userdata.at(j);
				userdata.at(j) = userdata.at(j + 1);
				userdata.at(j + 1) = tmp;
			}
		}
	}
}

void RankingView::writeRankingFile(UserData tmpData)
{
	ofstream file;

	//���� ������ ���� ��ġ
	file.open("Ranking.csv", ios::app);
	if (file.fail()) {
		cout << "file open fail" << endl;
		exit(0);
	}

	file << tmpData.name << ", "
		<< tmpData.score << ", "
		<< tmpData.grade << ", "
		<< "\n";

	file.close();
}

void RankingView::getUserScore(Game game1, Game game2, Game game3)
{
	UserData setuser;
	int sum = 0;

	setuser.name = tmpUsername;
	tmpScore = calculateScore(game1, game2, game3);
	tmpGrade = calculateGrade(tmpScore);
	setuser.score = tmpScore;
	setuser.grade = tmpGrade;

	userdata.push_back(setuser);
	writeRankingFile(setuser);

	bubbleSort();
}

/*
* ���⼭���ʹ� ���������� ���� score�� grade��
* score�� 100���������� ȯ���ϰ� grade�� 100�������� �������� ȯ��
*/
int RankingView::calculateScore(Game game1, Game game2, Game game3)
{
	int score = 0;

	try {
		score += game1.getScore();
	}
	catch (const exception& e) {
		e.what();
	}
	try {
		score += game2.getScore();
	}
	catch (const exception& e) {
		e.what();
	}


	score = score / 3;
	
	return score;
}

int RankingView::calculateGrade(int score)
{
	if (score >= 90) {
		return 1;
	}
	else if (score >= 80) {
		return 2;
	}
	else if (score >= 70) {
		return 3;
	}
	else if (score >= 60) {
		return 4;
	}
	else if (score >= 50) {
		return 5;
	}
	else if (score >= 40) {
		return 6;
	}
	else {
		return 7;
	}
}