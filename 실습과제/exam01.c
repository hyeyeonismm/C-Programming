#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

// ���׽� ����Ʈ�� ��� Ÿ���� ����ü�� ����
typedef struct ListNode {
	int coef; //���
	int expon; //����
	struct ListNode* link;
}ListNode;

// ���׽� ���� ����Ʈ�� ����� ����ü�� ����
typedef struct ListType {
	int size;
	ListNode* head;
	ListNode* tail;
}ListType;

// ���� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ����Ʈ ��� ���� �Լ� (��� ��带 �������� �����ϰ� �ʱ�ȭ)
ListType* create() {
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

// plist�� ���� ����Ʈ�� ����� ����Ű�� ������, coef�� ���, expon�� ����
void insert_last(ListType* plist, int coef, int expon) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode)); //temp ���� ����
	if (temp == NULL) //���� temp���� NULL�̶�� ���� ���
		error("�޸� �Ҵ� ����");
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
	while (a && b) { //a�� b�� NULL�� �Ǳ� ������ �ݺ�
		if (a->expon == b->expon) { // a�� ������ b�� ������ ���ٸ�
			sum = a->coef + b->coef; //a�� ����� b�� ����� ���ؼ� �����Ѵ�
			if (sum != 0) 
				insert_last(plist3, sum, a->expon); //list3�� sum�� a�� ������ �����Ͽ� ��带 �����Ѵ�.
			a = a->link; //a, b�� ��带 �Ҵ��Ѵ�.
			b = b->link;
		}
		else if (a->expon > b->expon) { // a�� ���� > b�� �������
			insert_last(plist3, a->coef, a->expon); //list3�� a�� ����� a�� ������ �����Ͽ� ��带 �����Ѵ�.
			a = a->link; //a�� ��带 �Ҵ��Ѵ�.
		}
		else { // a�� ���� < b�� �������
			insert_last(plist3, b->coef, b->expon); //list3�� b�� ����� b�� ������ �����Ͽ� ��带 �����Ѵ�.
			b = b->link; //b�� ��� �Ҵ�
		}
	}
	// a, b �� �ϳ��� ���� ������ �Ǹ� �����ִ� �׵��� ���
	// list3���� ����
	for (; a != NULL; a = a->link)
		insert_last(plist3, a->coef, a->expon);
	for (; b != NULL; b = b->link)
		insert_last(plist3, b->coef, b->expon);
}

// ��� �Լ�
void poly_print(ListType* plist)
{
	ListNode* p = plist->head; //input���� head�� p�� �����Ѵ�.
	for (; p; p = p->link) { //p�� NULL�� �� ������ p�� link�� ���� ��带 �־�� �ݺ��� ����
		printf("%d %d\n", p->coef, p->expon);
	}
}

// ���׽��� ���� ���ϴ� �Լ�
void add_print(ListType* plist)
{
	printf("\n���׽��� ����: ");
	ListNode* p = plist->head; //���� ������ �����ϴ�.
	for (; p; p = p->link) {
		printf("%+dx^%d", p->coef, p->expon);
	}
	printf("\n");
}


int main(void)
{
	ListType* list1, * list2, * list3;
	// ���� ����Ʈ ��� ����
	list1 = create();
	list2 = create();
	list3 = create();
	// ���׽� 1�� ����
	insert_last(list1, 2, 6);
	insert_last(list1, 7, 3);
	insert_last(list1, -2, 2);
	insert_last(list1, -7, 0);
	// ���׽� 2�� ����
	insert_last(list2, -4, 6);
	insert_last(list2, -5, 4);
	insert_last(list2, 6, 2);
	insert_last(list2, 6, 1);
	insert_last(list2, 1, 0);
	// ���׽� 3 = ���׽� 1 + ���׽� 2
	poly_add(list1, list2, list3);
	poly_print(list3);
	add_print(list3);
	free(list1); free(list2); free(list3);
	system("pause");
}