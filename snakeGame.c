#include<stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

/******** Ű���尪 ���� ********/
#define WIDTH 43
#define HEIGHT 28
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 27


/******** �Լ� ���� ********/
int speed;
int item_x, item_y;
int x[100], y[100];
int key;
int length;
int dir;
int score;

void title();
void gotoxy(int, int, char*);
void drawMap();
void reset();
void item();
void gameOver();
void move(int);

/******** gotoxy �Լ� ********/
void gotoxy(int x, int y, char* s) {
	COORD pos = { x,y };//x,y�� ��ǥ�� �����ϴ� ����ü
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);//Ŀ���� cmdâ���� �̵���Ű�� �Լ�
	printf("%s", s);
}


/******** main �Լ� ********/
int main() {
	title();
	while (1) {
		if (_kbhit())
			do { key = _getch(); }
		while (key == 224);
		Sleep(speed);
		
		switch (key) {
		case LEFT:
		case RIGHT:
		case UP:
		case DOWN:
			if ((dir == LEFT && key != RIGHT) || (dir == RIGHT && key != LEFT) || (dir == UP && key != DOWN) || (dir == DOWN && key != UP))
				dir = key;
			key = 0;
			break;
		case ESC:
			exit(0);
		}
		move(dir);
	}
	return 0;
}

/******** title �Լ� ********/
void title() {
	printf("\n\n\n");
	printf("		������      ������       ���          ������       ������\n");
	printf("		��                  ��          ��  ��         ��       ��          ��\n");
	printf("		������          ��         �����        ������           ��\n");
	printf("			��	    ��        ��      ��       ��      ��           ��\n");
	printf("		������          ��       ��        ��      ��      ��           ��\n");
	printf("\n\n");
	gotoxy(34, 12, "");
	printf("Press 'spacebar' to start the game");
	
	while (1) {
		if (_kbhit())
			key = _getch();
			if (key == 32) {
				system("cls"); //ȭ�� �����
				break;
			}

	}
	reset();
}


/******** drawmap �Լ� ********/
void drawMap() {
	for (int i = 3; i <= 28; i++) {
		gotoxy(3, i, "��");
		gotoxy(43, i, "��");
	}
	for (int j = 4; j <= 43; j++) {
		gotoxy(j, 3, "��");
		gotoxy(j, 28, "��");
	}
	printf("\n");
}

/******** reset �Լ� ********/
void reset() {
	system("cls");
	drawMap();
	while (_kbhit())
		getch();

	dir = LEFT;
	speed = 300;
	length = 5;
	score = 0;

	for (int i = 0; i < length; i++) {
		x[i] = WIDTH / 2+i;
		y[i] = HEIGHT / 2;
		gotoxy(x[i], y[i], "��");
	}
	gotoxy(x[0], y[0], "��");
	item();
}

/******** item �Լ� ********/
void item() {
	int r = 0;
	int item_crush = 0;
	//43, 28
	while (1) {
		srand((unsigned)time(NULL) + r); //��Ӱ��� �ٲ���ֵ��� +r������
		item_x = (rand() % WIDTH - 2) + 1; //1~42����
		item_y = (rand() % HEIGHT - 2) + 1; //1~28����
		
		for (int i = 0; i < length; i++) {
			if (item_x == x[i] && item_y == y[i]) {
				item_crush = 1;
				r++;
				break;
			}
		}

		if (item_crush == 1)
			continue;
		gotoxy(item_x, item_y, "��");
		break;
	}
}

/******** gameOver �Լ� ********/
void gameOver() {
	system("cls");
	printf("\n\n\n");
	gotoxy(34, 12, "�������������������������");
	gotoxy(34, 14, "\t\t   GAME OVER");
	gotoxy(34, 16, "�������������������������");
	printf("\n\n");
	gotoxy(34, 20, "");
	printf("\t\t  Your score is %d", score);

	return;
}

/******** move �Լ� ********/
void move(int dir) {
	int i;

	if (x[0] == item_x && y[0] == item_y) { //item�� �浹���� ���
		score += 10;
		item(); //���ο� food �߰�
		length++;
		x[length] = x[length - 1]; //�����ϼ��� ��ǥ���� ���ؾ��ϱ� ������
								  //���� �ִ� ������ǥ���� ���� ������ ��ǥ���� �־��� 
		y[length] = y[length - 1];
	}
	if (x[0] == 3 || x[0] == WIDTH-1 || y[0] == 3 || y[0] == HEIGHT-1) {
		gameOver();
		return; //gameOver���� ������ �ٽ� �����ϰ� �Ǹ� ���⼭���� �ݺ��ǹǷ� �ʱ�ȭ
	}

	gotoxy(x[length - 1], y[length - 1], "  ");
	//���� ��ǥ�� �����϶����� �ǵ��� ���� ��������� -> ����ó��
	for (i = length - 1; i > 0; i--) {
		x[i] = x[i - 1];
		y[i] = y[i - 1];
	}

	gotoxy(x[0], y[0], "��");
	if (dir == LEFT)
		--x[0];
	if (dir == RIGHT)
		++x[0];
	if (dir == UP)
		--y[0];
	if (dir == DOWN)
		++y[0];
	
	gotoxy(x[i], y[i], "��");
};

