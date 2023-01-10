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

	for (i = 0; i < size; i++) {
		printf("\n %d단계 : ", i+1); 
		for (j = 0; j < size -1 ; j++) {
			if (a[j] < a[j + 1]) { // 기준으로 잡은 a[j]와 a[j+1]을 비교하여 a[j]가 더 작을경우 if문 실행
				temp = a[j];  // 임시 변수인 temp를 이용하여 a[j]와 a[j+1]의 위치를 바꾸게 된다.
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
