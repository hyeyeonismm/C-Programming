#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define MAX_QUEUE_SIZE 4 //큐의 범위 정의

typedef int element; 
//큐와 다른 요소의 구분을 위해 사용자 정의자료형 사용

typedef struct { //큐 타입 구조체 정의
	element data[MAX_QUEUE_SIZE];
	int front, rear; 
}QueueType;

//오류함수
void error(char* message) 
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//큐 생성 함수
void init_queue(QueueType* q) {
	q->front = q->rear = 0; //front와 rear 값을 0으로 초기화
}

//공백 상태 검출 함수
int is_empty(QueueType* q) { 
	return (q->front == q->rear); //공백이라면 front값과 rear의 값이 같음
}

//포화 상태 검출 함수
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front); 
	//큐에서 rear+1을 MAX_QUEUE_SIZE로 나눈 나머지 값이 front와 같으면 full이다.
}

//삽입 함수
void enqueue(QueueType* q, element item) {
	if (is_full(q)) //큐가 가득 찼는지 검사
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; //큐의 마지막 요소 뒤를 가리킴
	q->data[q->rear] = item; //마지막 요소 뒤에 데이터를 삽입한다.
}

//삭제 함수
element dequeue(QueueType* q) {
	if (is_empty(q)) { //큐가 공백인지 검사
		error("큐가 공백상태입니다.");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE; //(q->front+1)% MAX_QUEUE_SIZE는 큐의 앞의 첫 요소를 가리킴
	return q->data[q->front]; //첫 요소를 반환한다.
}

//피보나치 수열 계산 함수
int fibonacci(QueueType* q, int n)
{
	for (int i = 0; i < n; i++) //n까지 반복문 실행
	{
		if (i == 0) //만약 i가 0이면 0 출력
			printf("0\n");
		if (i == 1) //만약 i가 1이면 1 출력
			printf("1\n");
		if (i >= 2) { //만약 i가 2보다 크면
			int temp = dequeue(q); //temp 변수에 큐의 첫 번째 요소를 저장한다.
			enqueue(q, temp + (q->data[q->rear])); //큐의 첫 번째 요소와 마지막 요소를 더해서 마지막 다음 요소에 삽입
			printf("%d\n", q->data[q->rear]); //큐의 마지막 요소를 출력
		}
	}
}



int main(void) {
	QueueType q; //큐 생성
	int num = 0; //입력받을 num 변수 생성

	init_queue(&q); //큐 초기화
	enqueue(&q, 0); //첫 번째 요소에 0 대입
	enqueue(&q, 1); //두 번째 요소에 1 대입

	printf("몇 번째 피보나치 수열을 구하겠어요? ");
	scanf("%d", &num);
	fibonacci(&q, num); //피보나치 수열 계산 함수 호출
	system("pause"); //exe파일이 바로 꺼지지 않도록 함
	return 0;
}