#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable:4996)

typedef struct TreeNode { //구조체로 노드 정의
	int data;
	struct TreeNode* left, * right;
}TreeNode;


//============== 원형큐 코드 시작 ====================//
#define MAX_QUEUE_SIZE 100
typedef TreeNode* element;
typedef struct { // 큐 타입
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 초기화 함수
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 삽입 함수
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

void level_order(TreeNode* ptr)
{
	QueueType q;
	init_queue(&q); // 큐 초기화
	if (ptr == NULL) return;
	enqueue(&q, ptr);
	while (!is_empty(&q)) {
		ptr = dequeue(&q);
		printf(" %d ", ptr->data);
		if (ptr->left)
			enqueue(&q, ptr->left);
		if (ptr->right)
			enqueue(&q, ptr->right);
	}
}

// 			     20
//	      15             28
//	   10     17       26    33
//   4   12     19         30   35

TreeNode n1 = { 4, NULL, NULL }; //각각의 노드 정의
TreeNode n2 = { 12, NULL, NULL };
TreeNode n3 = { 19, NULL, NULL };
TreeNode n4 = { 10, &n1, &n2 };
TreeNode n5 = { 17, NULL, &n3 };
TreeNode n6 = { 15, &n4, &n5 };
TreeNode n7 = { 30, NULL, NULL };
TreeNode n8 = { 35, NULL, NULL };
TreeNode n9 = { 26, NULL, NULL };
TreeNode n10 = { 33, &n7, &n8 };
TreeNode n11 = { 28, &n9, &n10 };
TreeNode n12 = { 20, &n6, &n11 };
TreeNode* root = &n12;

int main(void)
{
	printf("레벨 순회=");
	level_order(root);
	printf("\n");
	return 0;
}