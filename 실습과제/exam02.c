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

	for (i = 0; i < size; i++) {
		printf("\n %d�ܰ� : ", i+1); 
		for (j = 0; j < size -1 ; j++) {
			if (a[j] < a[j + 1]) { // �������� ���� a[j]�� a[j+1]�� ���Ͽ� a[j]�� �� ������� if�� ����
				temp = a[j];  // �ӽ� ������ temp�� �̿��Ͽ� a[j]�� a[j+1]�� ��ġ�� �ٲٰ� �ȴ�.
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
