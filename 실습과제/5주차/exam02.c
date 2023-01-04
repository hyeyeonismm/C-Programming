#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

// ��� �Լ�
void poly_print(ListType* plist)
{
	ListNode* p = plist->head; //input���� head�� p�� �����Ѵ�.
	printf("polynomial = ");
	for (; p; p = p->link) { //p�� NULL�� �� ������ p�� link�� ���� ��带 �־�� �ݺ��� ����
		printf("%d*x^%d + ", p->coef, p->expon);
	}
	printf("\n");
}
 // poly_eval �Լ�
int poly_eval(ListType* plist, int x) {
	ListNode* p = plist->head;
	int result, eval = 0; 
	for (; p; p = p->link) {
		result = 1;
		for (int i = 0; i < p->expon; i++) //i�� �������� �۴ٸ� �ݺ��� ����
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

	/* ������ �����ϰ� ����� ���� ����*/
	insert_last(list, 3, 2);
	insert_last(list, 2, 1);
	insert_last(list, 1, 0);

	
	poly_print(list); //��� �Լ� �ҷ�����
	printf("������ x�� ��: ");
	scanf("%d", &x); //�������� �� �Է¹ޱ�

	printf("���׽��� �� = %d\n", poly_eval(list, x));
	free(list); //���� �޸� ����
	system("pause");
}