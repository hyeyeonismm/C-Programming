#include <stdio.h>
#pragma warning(disable:4996)

typedef int element;
int size;

// 버블 정렬 함수
void bubbleSort(element a[], int size) {
	int i, j, t;
	element temp;
	printf("\n정렬할 원소 : ");
	for (t = 0; t < size; t++)
		printf("%d ", a[t]);
	printf("\n\n<<<<<<< 버블 정렬 수행 >>>>>>>\n");
	for (i = size - 1; i > 0; i--) {
		printf("\n %d단계 : ", size - i);
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
	element list[6] = { 99, 49, 92, 31, 54, 88 }; //정렬할 초기 원소 배열
	size = 6;
	bubbleSort(list, size); // 버블정렬 연산 호출
	getchar();
}
