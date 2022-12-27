#include <stdio.h>
#pragma warning (disable : 4996)

int findLength(char* pStr); //문자열의 길이 구하는 함수 선언
int main()
{
	char str[100]; //문자열을 100자 미만으로 입력받을 수 있도록 변수를 선언한다. 

	/* 실습 화면과 동일하게 출력되도록 printf함수를 사용하여 만듦 */
	printf("\n 포인터 : 문자열의 길이 계산 :\n");
	printf("---------------------------------------\n");
	printf(" 문자열 입력 : ");
	scanf("%s", str);  //문자열을 입력받음

	int strLen = findLength(str); //입력받은 문자열의 길이는 findLength함수를 사용하여 출력한다.


	printf(" 입력받은 문자열 길이 : %d\n", strLen); //strLen 값 출력

	return 0;
}

int findLength(char* pStr) //문자열 길이를 체크할 메모리의 시작 주소
{
	int length = 0; //문자열의 길이를 저장할 변수 선언

	while (*pStr++ != 0) //pStr의 메모리 값이 NULL에 해당하는 0이 아닐 때까지 반복문 실행
		length++; //pStr의 값이 NULL이 아니라면 문자열의 길이를 저장할 변수를 1씩 증가한다.

	return length; //반복문에서 탈출하면 length값을 출력하도록 한다.
}