#include <stdio.h>
#pragma warning(disable:4996)

typedef int element;
int size;

// ���� ���� �Լ�
void bubbleSort(element a[], int size) {
	int i, j, t;
	element temp;
	printf("\n������ ���� : ");
	for (t = 0; t < size; t++)
		printf("%d ", a[t]);
	printf("\n\n<<<<<<< ���� ���� ���� >>>>>>>\n");
	for (i = size - 1; i > 0; i--) {
		printf("\n %d�ܰ� : ", size - i);
		for (j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
			printf("\n\t");
			for (t = 0; t < size; t++)
				printf("%3d ", a[t]);
		}
	}
}

void main() {
	element list[6] = { 99, 49, 92, 31, 54, 88 }; //������ �ʱ� ���� �迭
	size = 6;
	bubbleSort(list, size); // �������� ���� ȣ��
	getchar();
}