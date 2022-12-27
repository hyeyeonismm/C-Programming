#include <stdio.h>
#pragma warning (disable:4996)

struct person { //person 구조체 생성
	char name[10]; //문자 배열로 된 이름 변수(문자 자료형의 크기는 처리조건에 따라 10으로 설정)
	int age; //사람의 나이를 나타내는 정수값의 변수
	double money; //개인의 월급을 나타내는 실수값의 변수
};

int main()
{
	struct person hong;
	struct person* pHong; //구조체 person을 가리키는 포인터 변수 pHong 선언

	pHong = &hong; //구조체 변수 hong의 주소가 저장됨

	/* 값 입력받기 */
	printf("\n 이름을 입력해주세요: ");
	scanf("%s", &pHong->name); //화살표 연산자는 구조체 포인터로 구조체의 멤버에 접근할 수 있게 해준다.
	printf(" 나이를 입력해주세요: ");
	scanf("%d", &pHong->age);
	printf(" 월급을 입력해주세요: ");
	scanf("%lf", &pHong->money);

	printf("================================\n");

	printf(" 이름: %s\n", (*pHong).name); //구조체 포인터 pHong을 입력해서 구조체 변수 hong의 멤버들을 참조한다.
	/*** (*pHong).name은 hong.name과 같은 의미라고 보면 됨 ***/
	printf(" 나이: %d\n", (*pHong).age);
	printf(" 월급: %.2lf\n", (*pHong).money); //실습의 결과화면에 소수점 둘째자리까지 표기되어있기 때문에 .2lf를 사용한다.

	return 0;
}
