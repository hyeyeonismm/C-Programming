#include <stdio.h>
#pragma warning(disable:4996)

typedef int element;
int size;

// 삽입 정렬 함수
void insertionSort(int a[], int size) {
	int i, j, t, temp;
	printf("\n정렬할 원소 : ");
	for (t = 0; t < size; t++)
		printf("%d ", a[t]);
	printf("\n\n<<<<<<< 삽입 정렬 수행 >>>>>>>\n");
	for (i = 1; i < size; i++) {
		temp = a[i];
		j = i;
		while ((j > 0) && (a[j - 1] > temp)) {
			a[j] = a[j - 1];
			j = j - 1;
		}
		a[j] = temp;
		printf("\n %d단계 : ", i);
		for (t = 0; t < size; t++)
			printf("%3d ", a[t]);
	}
}

void main() {
	element list[6] = { 99, 49, 92, 31, 54, 88 }; //정렬할 초기 원소 배열
	size = 6;
	insertionSort(list, size); // 정렬삽입 연산 호출
	getchar();

}
