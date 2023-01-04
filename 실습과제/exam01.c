#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

// 다항식 리스트의 노드 타입을 구조체로 정의
typedef struct ListNode {
	int coef; //계수
	int expon; //지수
	struct ListNode* link;
}ListNode;

// 다항식 연결 리스트의 헤더를 구조체로 정의
typedef struct ListType {
	int size;
	ListNode* head;
	ListNode* tail;
}ListType;

// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 리스트 헤더 생성 함수 (헤더 노드를 동적으로 생성하고 초기화)
ListType* create() {
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

// plist는 연결 리스트의 헤더를 가리키는 포인터, coef는 계수, expon은 지수
void insert_last(ListType* plist, int coef, int expon) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode)); //temp 변수 선언
	if (temp == NULL) //만약 temp값이 NULL이라면 에러 출력
		error("메모리 할당 에러");
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
}

// list3 = list1 + list2
void poly_add(ListType* plist1, ListType* plist2, ListType* plist3)
{
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;
	int sum;
	while (a && b) { //a와 b가 NULL이 되기 전까지 반복
		if (a->expon == b->expon) { // a의 지수와 b의 지수가 같다면
			sum = a->coef + b->coef; //a의 계수와 b의 계수를 더해서 저장한다
			if (sum != 0) 
				insert_last(plist3, sum, a->expon); //list3에 sum과 a의 지수를 포함하여 노드를 생성한다.
			a = a->link; //a, b에 노드를 할당한다.
			b = b->link;
		}
		else if (a->expon > b->expon) { // a의 지수 > b의 지수라면
			insert_last(plist3, a->coef, a->expon); //list3에 a의 계수와 a의 지수를 포함하여 노드를 생성한다.
			a = a->link; //a에 노드를 할당한다.
		}
		else { // a의 지수 < b의 지수라면
			insert_last(plist3, b->coef, b->expon); //list3에 b의 계수와 b의 지수를 포함하여 노드를 생성한다.
			b = b->link; //b에 노드 할당
		}
	}
	// a, b 중 하나가 먼저 끝나게 되면 남아있는 항들을 모두
	// list3으로 복사
	for (; a != NULL; a = a->link)
		insert_last(plist3, a->coef, a->expon);
	for (; b != NULL; b = b->link)
		insert_last(plist3, b->coef, b->expon);
}

// 출력 함수
void poly_print(ListType* plist)
{
	ListNode* p = plist->head; //input받은 head를 p에 저장한다.
	for (; p; p = p->link) { //p가 NULL이 될 때까지 p의 link에 다음 노드를 넣어가며 반복문 실행
		printf("%d %d\n", p->coef, p->expon);
	}
}

// 다항식의 합을 구하는 함수
void add_print(ListType* plist)
{
	printf("\n다항식의 합은: ");
	ListNode* p = plist->head; //위의 과정과 동일하다.
	for (; p; p = p->link) {
		printf("%+dx^%d", p->coef, p->expon);
	}
	printf("\n");
}


int main(void)
{
	ListType* list1, * list2, * list3;
	// 연결 리스트 헤더 생성
	list1 = create();
	list2 = create();
	list3 = create();
	// 다항식 1을 생성
	insert_last(list1, 2, 6);
	insert_last(list1, 7, 3);
	insert_last(list1, -2, 2);
	insert_last(list1, -7, 0);
	// 다항식 2를 생성
	insert_last(list2, -4, 6);
	insert_last(list2, -5, 4);
	insert_last(list2, 6, 2);
	insert_last(list2, 6, 1);
	insert_last(list2, 1, 0);
	// 다항식 3 = 다항식 1 + 다항식 2
	poly_add(list1, list2, list3);
	poly_print(list3);
	add_print(list3);
	free(list1); free(list2); free(list3);
	system("pause");
}