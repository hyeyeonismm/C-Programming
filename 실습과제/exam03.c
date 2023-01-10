#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define SWAP(a,b) {int t; t=a; a=b; b=t;} // �� ��ȯ�ϴ� �Լ� ����

// �迭 ��� �Լ�
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
        printf("\t\t�ʱ� ����\n");
    else
        printf("\t\t%d ���� �� %d ��ȯ\n", list[sorted - 1], list[before]);
}
void SelectionSort(int list[], int n)
{
    int i = 0, j;
    int least = -1;

    PrintArray(list, i, n, least);
    for (i = 0; i < n - 1; i++)
    {
        least = i;
        for (int j = i + 1; j < n; j++) //�ּڰ� Ž��
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
    int* arr; //�迭�� ������ ����
    printf("�迭�� ũ�� : ");
    scanf_s("%d", &num);

    printf("�迭 ���� �Է� : ");
    arr = (int*)malloc(sizeof(int) * num); //���� �Ҵ�
    for (int i = 0; i < num; i++)
        scanf("%d", &arr[i]);

    SelectionSort(arr, num);

    free(arr); //�����Ҵ� ����
    return 0;
}
