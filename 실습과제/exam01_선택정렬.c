#include <stdio.h>
#pragma warning(disable:4996)

typedef int element;
int size;

// ���� �����ϴ� ����
void SelectionSort(int a[], int size) {
	int i, j, t, min;
	element temp;
	printf("\n������ ����: ");

	// ���� ���� ���� ���
	for (t = 0; t < size; t++)
		printf("%d ", a[t]);
	printf("\n\n<<<<<<< ���� ���� ���� >>>>>>>\n");
	for (i = 0; i < size - 1; i++) {
		min = i;
		for (j = i + 1; j < size; j++) {
			if (a[j] < a[min]) min = j;
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
		printf("\n%d�ܰ� : ", i + 1);
		for (t = 0; t < size; t++)
			printf("%3d ", a[t]);
	}
}


void main() {
	element list[6] = { 99, 49, 92, 31, 54, 88 }; //������ �ʱ� ���� �迭
	size = 6;
	SelectionSort(list, size); // �������� ���� ȣ��
	getchar();

}