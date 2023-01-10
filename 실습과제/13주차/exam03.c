#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define SWAP(a,b) {int t; t=a; a=b; b=t;} // 값 교환하는 함수 정의

// 배열 출력 함수
void PrintArray(int list[], int sorted, int n, int before)
{
    int unsorted = n - sorted;

    printf("(");
    for (int i = 0; i < sorted; i++)
    {
        if (i == sorted - 1)
            printf("%d", list[i]);
        else
            printf("%d, ", list[i]);
    }
    printf(")   ");
    if (sorted > 0 && sorted < n)
        printf("  ");

    printf("(");
    for (int i = sorted; i < n; i++)
    {
        if (i == n - 1)
            printf("%d", list[i]);
        else
            printf("%d, ", list[i]);
    }
    if (unsorted == 0)
        printf(")");
    else
        printf(")");


    if (before == -1)
        printf("\t\t초기 상태\n");
    else
        printf("\t\t%d 선택 후 %d 교환\n", list[sorted - 1], list[before]);
}
void SelectionSort(int list[], int n)
{
    int i = 0, j;
    int least = -1;

    PrintArray(list, i, n, least);
    for (i = 0; i < n - 1; i++)
    {
        least = i;
        for (int j = i + 1; j < n; j++) //최솟값 탐색
            if (list[j] < list[least])
                least = j;
        SWAP(list[i], list[least]);
        PrintArray(list, i + 1, n, least);
    }
    PrintArray(list, i + 1, n, n - 1);
}

int main(void)
{
    int num;
    int* arr; //배열의 포인터 선언
    printf("배열의 크기 : ");
    scanf_s("%d", &num);

    printf("배열 내용 입력 : ");
    arr = (int*)malloc(sizeof(int) * num); //동적 할당
    for (int i = 0; i < num; i++)
        scanf("%d", &arr[i]);

    SelectionSort(arr, num);

    free(arr); //동적할당 해제
    return 0;
}
