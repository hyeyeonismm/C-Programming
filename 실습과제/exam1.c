#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100 //������ �ִ� ������ ����
#pragma warning(disable:4996)

/* ������ ����ü�� �����Ͽ� ��� ������ ����ü �����͸� �޵��� �ߴ�. */
typedef struct StackType //����ü ����
{
	int data[MAX_STACK_SIZE];
	int top;
}StackType;

/* ���� �ʱ�ȭ �Լ� */
void init_stack(StackType* s)
{
	s->top = -1; //���� ���� ���Ҹ� ����ų top������ -1�� �ʱ�ȭ 
	//(������ �ε����� 0���� �����ϱ� ����)
}

/* ���� ���� ���� �Լ� */
int is_empty(StackType* s)
{
	return (s->top == -1); //top������ -1�� ���� ���´ٸ� �ʱ�����̹Ƿ� ����ִ� ��
}

/* ��ȭ ���� ���� �Լ� */
int is_full(StackType* s)
{
	return (s->top >= (MAX_STACK_SIZE - 1));
	//s->top������ MAX_STACK_SIZE -1���� ũ�ų� ���ٸ� ������ �� ���ִ� ����
}

/* �����Լ� */
void push(StackType* s, int item)
{
	if (is_full(s)) { //������ �� ���ִ��� �˻��ϰ�, �׷��ٸ� "������ȭ����" ������ ����Ѵ�.
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item; // �׷��� �ʴٸ� ���Ҹ� ������ ���� �� �κп� �߰��Ѵ�.
}

/* �����Լ� */
int pop(StackType* s)
{
	if (is_empty(s)) { //������ ��������� "���� ���� ����" ���
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--]; //������ ������� �ʴٸ� ���� �� ���� ��ȯ
}

int main(void)
{
	int i = 0, count = 1; //���� ���� �� �ʱ�ȭ
	StackType s; //����ü ���� ����
	init_stack(&s); //init_stack�Լ� ���
	char input[MAX_STACK_SIZE]; //input �ڷ����� �����̱� ������ char�� ����
	printf("����: ");
	scanf("%s", input); //input�� ���� �޾ƿ´�
	printf("��ȣ ��: ");

	while (input[i] != NULL) //input�� �ε��� ���� NULL�� �ƴ� ��� �ݺ��� ����
	{
		if (input[i] == '(') //���� �Էº����� ���� '('���
		{
			push(&s, count); //������ ���ÿ� �����Ѵ�.
			printf("%d ", count); //count�� ���
			count++; //count�� ����
		}
		else
			printf("%d ", pop(&s)); //�׷��� �ʴٸ� pop�� �����Ͽ� ������ ���� �� ������ �����Ѵ�.
		i++;
	}
	return 0;
}
