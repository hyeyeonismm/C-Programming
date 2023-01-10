#include <stdio.h>
#pragma warning(disable:4996)

typedef int element;
int size;

// 선택 정렬하는 연산
void SelectionSort(int a[], int size) {
	int i, j, t, min;
	element temp;
	printf("\n정렬할 원소: ");

	// 정렬 전의 원소 출력
	for (t = 0; t < size; t++)
		printf("%d ", a[t]);
	printf("\n\n<<<<<<< 선택 정렬 수행 >>>>>>>\n");
	for (i = 0; i < size - 1; i++) {
		min = i;
		for (j = i + 1; j < size; j++) {
			if (a[j] < a[min]) min = j;
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
		printf("\n%d단계 : ", i + 1);
		for (t = 0; t < size; t++)
			printf("%3d ", a[t]);
	}
}


void main() {
	element list[6] = { 99, 49, 92, 31, 54, 88 }; //정렬할 초기 원소 배열
	size = 6;
	SelectionSort(list, size); // 선택정렬 연산 호출
	getchar();

}
