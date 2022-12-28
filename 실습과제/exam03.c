#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#pragma warning (disable:4996)

/* Stack�� ���� �ּ��� 1�� ������ �����ϴ�. */
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
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--]; 
}

int main() {
	printf("������ �Է��Ͻÿ�: ");
	char input[MAX_STACK_SIZE]; // input ���� �Է¹޴´�. �ѹ��� �޾ƾ��ϱ� ������ char�� ���
	scanf("%s", input, sizeof(input));

	//���� ������ ����ü ���� 2�� ���� �� �ʱ�ȭ
	StackType s1, s2; 
	init_stack(&s1);
	init_stack(&s2);

	int i = 0;
	while (input[i] != NULL) { //�Է°��� �ִٸ� �ݺ��� ����
		if (input[i] != input[i + 1]) //���� input[i]�� ���� input[i+1]���� �ߺ��̶��
			push(&s1, input[i] - '0'); //s1 ���ÿ� ����
		i++; //i�� 1�� �����Ͽ� ���������� ����Ѵ�. 
	}
	while (!is_empty(&s1)) { //s1�� ������ �ƴ϶��
		push(&s2, pop(&s1)); //s2 ���ÿ� �����ϰ�, s1�� ���� ������ ���� �����Ѵ�.
	}
	printf("���: ");
	while (!is_empty(&s2)) { //s2�� ������ �ƴ� ���
		printf("%d", pop(&s2)); //s2�� �����Լ� ���� ����Ѵ�.
	}
	return 0;
}