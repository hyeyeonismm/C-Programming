#include<stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

/******** 키보드값 정의 ********/
#define WIDTH 43
#define HEIGHT 28
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 27


/******** 함수 선언 ********/
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

/******** gotoxy 함수 ********/
void gotoxy(int x, int y, char* s) {
	COORD pos = { x,y };//x,y의 좌표를 저장하는 구조체
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);//커서를 cmd창에서 이동시키는 함수
	printf("%s", s);
}


/******** main 함수 ********/
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

/******** title 함수 ********/
void title() {
	printf("\n\n\n");
	printf("		■■■■■      ■■■■■       ■■          ■■■■■       ■■■■■\n");
	printf("		■                  ■          ■  ■         ■       ■          ■\n");
	printf("		■■■■■          ■         ■■■■        ■■■■■           ■\n");
	printf("			■	    ■        ■      ■       ■      ■           ■\n");
	printf("		■■■■■          ■       ■        ■      ■      ■           ■\n");
	printf("\n\n");
	gotoxy(34, 12, "");
	printf("Press 'spacebar' to start the game");
	
	while (1) {
		if (_kbhit())
			key = _getch();
			if (key == 32) {
				system("cls"); //화면 지우기
				break;
			}

	}
	reset();
}


/******** drawmap 함수 ********/
void drawMap() {
	for (int i = 3; i <= 28; i++) {
		gotoxy(3, i, "■");
		gotoxy(43, i, "■");
	}
	for (int j = 4; j <= 43; j++) {
		gotoxy(j, 3, "■");
		gotoxy(j, 28, "■");
	}
	printf("\n");
}

/******** reset 함수 ********/
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
		gotoxy(x[i], y[i], "○");
	}
	gotoxy(x[0], y[0], "◎");
	item();
}

/******** item 함수 ********/
void item() {
	int r = 0;
	int item_crush = 0;
	//43, 28
	while (1) {
		srand((unsigned)time(NULL) + r); //계속값이 바뀔수있도록 +r을해줌
		item_x = (rand() % WIDTH - 2) + 1; //1~42까지
		item_y = (rand() % HEIGHT - 2) + 1; //1~28까지
		
		for (int i = 0; i < length; i++) {
			if (item_x == x[i] && item_y == y[i]) {
				item_crush = 1;
				r++;
				break;
			}
		}

		if (item_crush == 1)
			continue;
		gotoxy(item_x, item_y, "★");
		break;
	}
}

/******** gameOver 함수 ********/
void gameOver() {
	system("cls");
	printf("\n\n\n");
	gotoxy(34, 12, "■■■■■■■■■■■■■■■■■■■■■■■■");
	gotoxy(34, 14, "\t\t   GAME OVER");
	gotoxy(34, 16, "■■■■■■■■■■■■■■■■■■■■■■■■");
	printf("\n\n");
	gotoxy(34, 20, "");
	printf("\t\t  Your score is %d", score);

	return;
}

/******** move 함수 ********/
void move(int dir) {
	int i;

	if (x[0] == item_x && y[0] == item_y) { //item과 충돌했을 경우
		score += 10;
		item(); //새로운 food 추가
		length++;
		x[length] = x[length - 1]; //움직일수록 좌표값이 변해야하기 때문에
								  //전에 있던 몸통좌표값을 새로 움직인 좌표값에 넣어줌 
		y[length] = y[length - 1];
	}
	if (x[0] == 3 || x[0] == WIDTH-1 || y[0] == 3 || y[0] == HEIGHT-1) {
		gameOver();
		return; //gameOver에서 게임을 다시 시작하게 되면 여기서부터 반복되므로 초기화
	}

	gotoxy(x[length - 1], y[length - 1], "  ");
	//뱀의 좌표가 움직일때마다 맨뒤의 값을 지워줘야함 -> 공백처리
	for (i = length - 1; i > 0; i--) {
		x[i] = x[i - 1];
		y[i] = y[i - 1];
	}

	gotoxy(x[0], y[0], "○");
	if (dir == LEFT)
		--x[0];
	if (dir == RIGHT)
		++x[0];
	if (dir == UP)
		--y[0];
	if (dir == DOWN)
		++y[0];
	
	gotoxy(x[i], y[i], "◎");
};

