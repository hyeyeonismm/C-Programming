#include <stdio.h>
#pragma warning(disable:4996)

typedef int element;
int size;

// ���� ���� �Լ�
void insertionSort(int a[], int size) {
	int i, j, t, temp;
	printf("\n������ ���� : ");
	for (t = 0; t < size; t++)
		printf("%d ", a[t]);
	printf("\n\n<<<<<<< ���� ���� ���� >>>>>>>\n");
	for (i = 1; i < size; i++) {
		temp = a[i];
		j = i;
		while ((j > 0) && (a[j - 1] > temp)) {
			a[j] = a[j - 1];
			j = j - 1;
		}
		a[j] = temp;
		printf("\n %d�ܰ� : ", i);
		for (t = 0; t < size; t++)
			printf("%3d ", a[t]);
	}
}

void main() {
	element list[6] = { 99, 49, 92, 31, 54, 88 }; //������ �ʱ� ���� �迭
	size = 6;
	insertionSort(list, size); // ���Ļ��� ���� ȣ��
	getchar();

}