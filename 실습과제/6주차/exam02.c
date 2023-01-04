#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

// 출력 함수
void poly_print(ListType* plist)
{
	ListNode* p = plist->head; //input받은 head를 p에 저장한다.
	printf("polynomial = ");
	for (; p; p = p->link) { //p가 NULL이 될 때까지 p의 link에 다음 노드를 넣어가며 반복문 실행
		printf("%d*x^%d + ", p->coef, p->expon);
	}
	printf("\n");
}
 // poly_eval 함수
int poly_eval(ListType* plist, int x) {
	ListNode* p = plist->head;
	int result, eval = 0; 
	for (; p; p = p->link) {
		result = 1;
		for (int i = 0; i < p->expon; i++) //i가 지수보다 작다면 반복문 실행
			result *= x; //result = result*x
		result = p->coef * result;
		eval += result; //eval = eval+result
	}
	return eval;
}

int main(void)
{
	ListType* list;
	int x = 0;
	list = create();

	/* 문제와 동일하게 계수와 지수 설정*/
	insert_last(list, 3, 2);
	insert_last(list, 2, 1);
	insert_last(list, 1, 0);

	
	poly_print(list); //출력 함수 불러오기
	printf("미지수 x의 값: ");
	scanf("%d", &x); //미지수의 값 입력받기

	printf("다항식의 값 = %d\n", poly_eval(list, x));
	free(list); //동적 메모리 해제
	system("pause");
}
