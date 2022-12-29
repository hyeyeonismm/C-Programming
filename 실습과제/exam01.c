#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define MAX_QUEUE_SIZE 4 //ť�� ���� ����

typedef int element; 
//ť�� �ٸ� ����� ������ ���� ����� �����ڷ��� ���

typedef struct { //ť Ÿ�� ����ü ����
	element data[MAX_QUEUE_SIZE];
	int front, rear; 
}QueueType;

//�����Լ�
void error(char* message) 
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//ť ���� �Լ�
void init_queue(QueueType* q) {
	q->front = q->rear = 0; //front�� rear ���� 0���� �ʱ�ȭ
}

//���� ���� ���� �Լ�
int is_empty(QueueType* q) { 
	return (q->front == q->rear); //�����̶�� front���� rear�� ���� ����
}

//��ȭ ���� ���� �Լ�
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front); 
	//ť���� rear+1�� MAX_QUEUE_SIZE�� ���� ������ ���� front�� ������ full�̴�.
}

//���� �Լ�
void enqueue(QueueType* q, element item) {
	if (is_full(q)) //ť�� ���� á���� �˻�
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; //ť�� ������ ��� �ڸ� ����Ŵ
	q->data[q->rear] = item; //������ ��� �ڿ� �����͸� �����Ѵ�.
}

//���� �Լ�
element dequeue(QueueType* q) {
	if (is_empty(q)) { //ť�� �������� �˻�
		error("ť�� ��������Դϴ�.");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE; //(q->front+1)% MAX_QUEUE_SIZE�� ť�� ���� ù ��Ҹ� ����Ŵ
	return q->data[q->front]; //ù ��Ҹ� ��ȯ�Ѵ�.
}

//�Ǻ���ġ ���� ��� �Լ�
int fibonacci(QueueType* q, int n)
{
	for (int i = 0; i < n; i++) //n���� �ݺ��� ����
	{
		if (i == 0) //���� i�� 0�̸� 0 ���
			printf("0\n");
		if (i == 1) //���� i�� 1�̸� 1 ���
			printf("1\n");
		if (i >= 2) { //���� i�� 2���� ũ��
			int temp = dequeue(q); //temp ������ ť�� ù ��° ��Ҹ� �����Ѵ�.
			enqueue(q, temp + (q->data[q->rear])); //ť�� ù ��° ��ҿ� ������ ��Ҹ� ���ؼ� ������ ���� ��ҿ� ����
			printf("%d\n", q->data[q->rear]); //ť�� ������ ��Ҹ� ���
		}
	}
}



int main(void) {
	QueueType q; //ť ����
	int num = 0; //�Է¹��� num ���� ����

	init_queue(&q); //ť �ʱ�ȭ
	enqueue(&q, 0); //ù ��° ��ҿ� 0 ����
	enqueue(&q, 1); //�� ��° ��ҿ� 1 ����

	printf("�� ��° �Ǻ���ġ ������ ���ϰھ��? ");
	scanf("%d", &num);
	fibonacci(&q, num); //�Ǻ���ġ ���� ��� �Լ� ȣ��
	system("pause"); //exe������ �ٷ� ������ �ʵ��� ��
	return 0;
}