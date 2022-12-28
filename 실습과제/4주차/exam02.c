#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#pragma warning (disable:4996)

/* Stack에 대한 주석은 1번 문제와 동일하다. */
typedef struct StackType {
	char data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s)
{
	return (s->top == -1); 
}

int is_full(StackType* s)
{
	return (s->top >= (MAX_STACK_SIZE - 1));	
}

void push(StackType* s, int item)
{
	if (is_full(s)) { 
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item; 
}

int pop(StackType* s)
{
	if (is_empty(s)) { 
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--]; 
}

int peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택공백에러\n");
		exit(1);
	}
	else return s->data[s->top];
}


int main() {
	printf("문자열을 입력하시오: ");
	char input[MAX_STACK_SIZE];
	scanf("%s", input, sizeof(input));

	StackType s1, s2; //두 개의 구조체 변수 선언 및 초기화
	init_stack(&s1);
	init_stack(&s2);

	int i = 0, count = 0;
	while (input[i] != NULL) { //입력값이 NULL이 아닌 경우 반복문 실행
		count = 0;
		char now = input[i++]; //now변수 선언 및 초기화
		count++;
		// now의 값이 입력값이거나, 대문자 입력값일 경우
		while (now == input[i] || now + ('A' - 'a') == input[i] || now - ('A' - 'a') == input[i]) {
			count++; //count해준다.
			i++;
		}
		push(&s1, count + '0'); //입력값과 count값을 stack1에 저장한다.
		if ('a' <= now && now <= 'z') //만약 now변수가 a~z까지라면
			push(&s1, now); //s1에 값을 저장하고
		else
			push(&s1, now - ('A' - 'a')); //그렇지 않다면 s1에 대문자를 소문자로 바꾼 값을 저장한다.
	}

	while (!is_empty(&s1)) { //s1이 공백이 아닐 경우
		push(&s2, pop(&s1)); //s2에 저장하고, s1의 값을 삭제한다.
	}
	printf("압축된 문자열: ");
	while (!is_empty(&s2)) { //s2가 공백이 아닐 경우
		printf("%c", pop(&s2)); //s2의 스택 값을 삭제하며 출력한다.
	} //
	return 0;
}
