#include <stdio.h>
#include <math.h> //sqrt 함수를 사용할 수 있음
#pragma warning (disable:4996)

struct coordinate { //coordinate 구조체 선언
	double x; //x,y좌표를 멤버로 갖는다.
	double y;
};

/* 거리 구하는 함수 선언 */
double distance(struct coordinate p1, struct coordinate p2)
{
	//두 점 사이의 거리를 구하는 공식은 구글을 참고했다.
	int a, b; 
	a = p1.x - p2.x; 
	b = p1.y - p2.y;
	return sqrt(a * a + b * b);
}

int main()
{
	double result = 0; //결과값 변수 선언 및 초기화
	struct coordinate p1, p2; //구조체 변수 선언
	int i = 0; //반복 횟수 변수 선언 및 초기화

	while (i<2) //i가 2번 반복하고 while문을 탈출하도록 함
	{
		scanf("%lf %lf", &p1.x, &p1.y); //p1좌표의 값을 입력받는다.
		scanf("%lf %lf", &p2.x, &p2.y); //p2좌표의 값을 입력받는다.

		result = distance(p1, p2); //결과 변수에는 distance함수의 반환값을 대입한다.
		
		printf("점(%.lf, %.lf)과 (%.lf, %.lf) 사이의 거리 = %.3lf\n", p1.x, p1.y, p2.x, p2.y, result);
		//p1, p2의 값은 정수형이기 때문에 소수점이 안나오도록 설정하였고, 결과값만 소수점 셋째자리까지 나오도록 설정하였다.

		i++; //i를 1씩 증가시킨다.
	}

	return 0;
}