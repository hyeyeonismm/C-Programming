#include<stdio.h>
#pragma warning(disable:4996)
#define MAX_QUEUE_SIZE 100 //범위 정의

typedef struct { //큐 타입 구조체 정의
    int data[MAX_QUEUE_SIZE];
    int front, rear;
}QueueType;

int is_full(QueueType* q) {
    if (q->rear == MAX_QUEUE_SIZE) {
        return 1;
    }
    else
    {
        return 0;
    }

}

void enqueue(QueueType* q, char item) {
    if (is_full(q)) {
        printf("\n큐가 포화상태입니다");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->data[++q->rear] = item;
}

char dequeue_front(QueueType* q) { 
    //큐의 앞의 첫 요소를 반환한다.
    return q->data[q->front++];
}

char dequeue_end(QueueType* q) {
    // 큐의 뒤의 첫 요소를 반환한다.
    return q->data[q->rear--];
}

//회문 함수
void palindrome(QueueType* q) {
    int ans; //ans 변수 선언
    while (q->front <= q->rear) { //front가 rear의 값보다 같거나 작다면 반복문 실행
        if (dequeue_front(q) != dequeue_end(q)) { //만약 첫번째 문자와 마지막 문자가 같지 않다면
            ans = 0;
            break; //회문이 아니다.
        }
        else {
            ans = 1; //회문이다.
        }
    }
    if (ans == 1) {
        printf("회문입니다");
    }
    else {
        printf("ERROR");
    }

}

int main() {
    char word[100]; //word 문자형 배열
    QueueType deque;
    QueueType* q = &deque;
    q->front = -1; //front와 rear값 -1로 초기화
    q->rear = -1;
    printf("회문을 판별할 단어를 입력하세요: \n\n");
    scanf("%s", &word);
    for (int i = 0; word[i] != '\0'; i++) { //단어가 공백이 아니라면 반복문 실행 
        enqueue(q, word[i]);//큐에 단어 저장
    }
    
    palindrome(q); //회문함수 실행
    return 0;
}