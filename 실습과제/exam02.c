#include<stdio.h>
#pragma warning(disable:4996)
#define MAX_QUEUE_SIZE 100 //���� ����

typedef struct { //ť Ÿ�� ����ü ����
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
        printf("\nť�� ��ȭ�����Դϴ�");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->data[++q->rear] = item;
}

char dequeue_front(QueueType* q) { 
    //ť�� ���� ù ��Ҹ� ��ȯ�Ѵ�.
    return q->data[q->front++];
}

char dequeue_end(QueueType* q) {
    // ť�� ���� ù ��Ҹ� ��ȯ�Ѵ�.
    return q->data[q->rear--];
}

//ȸ�� �Լ�
void palindrome(QueueType* q) {
    int ans; //ans ���� ����
    while (q->front <= q->rear) { //front�� rear�� ������ ���ų� �۴ٸ� �ݺ��� ����
        if (dequeue_front(q) != dequeue_end(q)) { //���� ù��° ���ڿ� ������ ���ڰ� ���� �ʴٸ�
            ans = 0;
            break; //ȸ���� �ƴϴ�.
        }
        else {
            ans = 1; //ȸ���̴�.
        }
    }
    if (ans == 1) {
        printf("ȸ���Դϴ�");
    }
    else {
        printf("ERROR");
    }

}

int main() {
    char word[100]; //word ������ �迭
    QueueType deque;
    QueueType* q = &deque;
    q->front = -1; //front�� rear�� -1�� �ʱ�ȭ
    q->rear = -1;
    printf("ȸ���� �Ǻ��� �ܾ �Է��ϼ���: \n\n");
    scanf("%s", &word);
    for (int i = 0; word[i] != '\0'; i++) { //�ܾ ������ �ƴ϶�� �ݺ��� ���� 
        enqueue(q, word[i]);//ť�� �ܾ� ����
    }
    
    palindrome(q); //ȸ���Լ� ����
    return 0;
}