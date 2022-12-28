#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#pragma warning (disable:4996)

/* Stack�� ���� �ּ��� 1�� ������ �����ϴ�. */
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
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item; 
}

int pop(StackType* s)
{
	if (is_empty(s)) { 
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--]; 
}

int peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���ð��鿡��\n");
		exit(1);
	}
	else return s->data[s->top];
}


int main() {
	printf("���ڿ��� �Է��Ͻÿ�: ");
	char input[MAX_STACK_SIZE];
	scanf("%s", input, sizeof(input));

	StackType s1, s2; //�� ���� ����ü ���� ���� �� �ʱ�ȭ
	init_stack(&s1);
	init_stack(&s2);

	int i = 0, count = 0;
	while (input[i] != NULL) { //�Է°��� NULL�� �ƴ� ��� �ݺ��� ����
		count = 0;
		char now = input[i++]; //now���� ���� �� �ʱ�ȭ
		count++;
		// now�� ���� �Է°��̰ų�, �빮�� �Է°��� ���
		while (now == input[i] || now + ('A' - 'a') == input[i] || now - ('A' - 'a') == input[i]) {
			count++; //count���ش�.
			i++;
		}
		push(&s1, count + '0'); //�Է°��� count���� stack1�� �����Ѵ�.
		if ('a' <= now && now <= 'z') //���� now������ a~z�������
			push(&s1, now); //s1�� ���� �����ϰ�
		else
			push(&s1, now - ('A' - 'a')); //�׷��� �ʴٸ� s1�� �빮�ڸ� �ҹ��ڷ� �ٲ� ���� �����Ѵ�.
	}

	while (!is_empty(&s1)) { //s1�� ������ �ƴ� ���
		push(&s2, pop(&s1)); //s2�� �����ϰ�, s1�� ���� �����Ѵ�.
	}
	printf("����� ���ڿ�: ");
	while (!is_empty(&s2)) { //s2�� ������ �ƴ� ���
		printf("%c", pop(&s2)); //s2�� ���� ���� �����ϸ� ����Ѵ�.
	} //
	return 0;
}