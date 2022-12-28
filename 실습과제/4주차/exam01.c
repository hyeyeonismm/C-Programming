#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100 //스택의 최대 사이즈 정의
#pragma warning(disable:4996)

/* 스택을 구조체로 정의하여 모든 연산은 구조체 포인터를 받도록 했다. */
typedef struct StackType //구조체 선언
{
	int data[MAX_STACK_SIZE];
	int top;
}StackType;

/* 스택 초기화 함수 */
void init_stack(StackType* s)
{
	s->top = -1; //가장 위의 원소를 가리킬 top변수를 -1로 초기화 
	//(스택의 인덱스를 0부터 시작하기 위함)
}

/* 공백 상태 검출 함수 */
int is_empty(StackType* s)
{
	return (s->top == -1); //top변수가 -1의 값을 갖는다면 초기상태이므로 비어있는 것
}

/* 포화 상태 검출 함수 */
int is_full(StackType* s)
{
	return (s->top >= (MAX_STACK_SIZE - 1));
	//s->top변수가 MAX_STACK_SIZE -1보다 크거나 같다면 스택이 꽉 차있는 상태
}

/* 삽입함수 */
void push(StackType* s, int item)
{
	if (is_full(s)) { //스택이 꽉 차있는지 검사하고, 그렇다면 "스택포화에러" 문구를 출력한다.
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item; // 그렇지 않다면 원소를 스택의 가장 윗 부분에 추가한다.
}

/* 삭제함수 */
int pop(StackType* s)
{
	if (is_empty(s)) { //스택이 비어있으면 "스택 공백 에러" 출력
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--]; //스택이 비어있지 않다면 가장 윗 원소 반환
}

int main(void)
{
	int i = 0, count = 1; //변수 선언 및 초기화
	StackType s; //구조체 변수 선언
	init_stack(&s); //init_stack함수 사용
	char input[MAX_STACK_SIZE]; //input 자료형은 문자이기 때문에 char로 설정
	printf("수식: ");
	scanf("%s", input); //input의 값을 받아온다
	printf("괄호 수: ");

	while (input[i] != NULL) //input의 인덱스 값이 NULL이 아닐 경우 반복문 실행
	{
		if (input[i] == '(') //만약 입력변수의 값이 '('라면
		{
			push(&s, count); //변수를 스택에 저장한다.
			printf("%d ", count); //count값 출력
			count++; //count값 증가
		}
		else
			printf("%d ", pop(&s)); //그렇지 않다면 pop을 실행하여 스택의 가장 윗 변수를 삭제한다.
		i++;
	}
	return 0;
}
