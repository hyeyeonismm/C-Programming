#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#pragma warning (disable:4996)

/* Stack에 대한 주석은 1번 문제와 동일하다. */
typedef struct StackType {
	int data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType* s) {
	s->top = -1;
}

void push(StackType* s, char item) {
	s->data[++(s->top)] = item;
	return;
}

bool is_empty(StackType* s) {
	return (s->top == -1);
}

int pop(StackType* s) {
	if (is_empty(s)) { 
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--]; 
}

int main() {
	printf("정수를 입력하시오: ");
	char input[MAX_STACK_SIZE]; // input 값을 입력받는다. 한번에 받아야하기 때문에 char형 사용
	scanf("%s", input, sizeof(input));

	//값을 저장할 구조체 변수 2개 선언 및 초기화
	StackType s1, s2; 
	init_stack(&s1);
	init_stack(&s2);

	int i = 0;
	while (input[i] != NULL) { //입력값이 있다면 반복문 진행
		if (input[i] != input[i + 1]) //만약 input[i]의 값이 input[i+1]값과 중복이라면
			push(&s1, input[i] - '0'); //s1 스택에 저장
		i++; //i를 1씩 증감하여 순차적으로 계산한다. 
	}
	while (!is_empty(&s1)) { //s1이 공백이 아니라면
		push(&s2, pop(&s1)); //s2 스택에 저장하고, s1의 가장 마지막 값을 삭제한다.
	}
	printf("출력: ");
	while (!is_empty(&s2)) { //s2가 공백이 아닐 경우
		printf("%d", pop(&s2)); //s2의 삭제함수 값을 출력한다.
	}
	return 0;
}