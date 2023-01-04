#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

//이중 연결 리스트 노드
typedef int element;
typedef struct DListNode
{
    element data;
    struct DListNode* llink;
    struct DListNode* rlink; //prev;
}DListNode;


//이중 연결 리스트의 시작 부분에 있는 노드를 삽입하는 함수
void dinsert(struct DListNode** head, element data)
{
    DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
    newnode->data = data;
    newnode->rlink = NULL;
    newnode->llink = *head;

    //기존 헤드 노드의 `rlink`를 새 노드를 가리키도록 변경
    if (*head != NULL) {
        (*head)->rlink = newnode;
    }

    //헤드 포인터 업데이트
    *head = newnode;
}

//이중 연결 리스트의 노드를 출력하는 함수
void print_dlist(DListNode* phead)
{
    while (phead != NULL)
    {
        printf("%d ", phead->data);
        phead = phead->llink;
    }
    printf("\n");
}

//주어진 노드의 `llink` 및 `rlink` 포인터를 교환하는 함수
void swap(DListNode* newnode)
{
    DListNode* rlink = newnode->rlink;
    newnode->rlink = newnode->llink;
    newnode->llink = rlink;
}

//반전 함수
void reverse(DListNode** head)
{
    DListNode* rlink = NULL;
    DListNode* curr = *head;

    //리스트 순회
    while (curr != NULL)
    {
        //현재 노드에 대한 rlink, llink 포인터 교환
        swap(curr);

        //다음 노드로 이동하기 전에 이전 노드를 업데이트한다.
        rlink = curr;

        //이중 연결 리스트의 다음 노드로 이동
        //llink와 rlink 포인터가 교환되었기 때문에 rlink의 포인터를 사용하여 진행
        curr = curr->rlink;
    }

    //마지막 노드에 대한 헤드 포인터 업데이트
    if (rlink != NULL) {
        *head = rlink;
    }
}

int main()
{
    int keys[] = { 0,1, 2, 3, 4, 5,6,7,8,9 }; //숫자 배열 선언
    int n = sizeof(keys) / sizeof(keys[0]);

    DListNode* head = NULL;
    for (int i = 0; i < n; i++) {
        dinsert(&head, keys[i]);
    }

    print_dlist(head);
    reverse(&head); //역순
    print_dlist(head);

    return 0;
}


