#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct TreeNode { //구조체로 트리 선언
    int data;
    struct TreeNode* left, * right;
} TreeNode;

// 			     20
//	      15             28
//	   10     17       26    33
//   4   12     19         30   35


TreeNode n1 = { 4, NULL, NULL }; //각각의 노드 정의
TreeNode n2 = { 12, NULL, NULL };
TreeNode n3 = { 19, NULL, NULL };
TreeNode n4 = { 10, &n1, &n2 };
TreeNode n5 = { 17, NULL, &n3 };
TreeNode n6 = { 15, &n4, &n5 };
TreeNode n7 = { 30, NULL, NULL };
TreeNode n8 = { 35, NULL, NULL };
TreeNode n9 = { 26, NULL, NULL };
TreeNode n10 = { 33, &n7, &n8 };
TreeNode n11 = { 28, &n9, &n10 };
TreeNode n12 = { 20, &n6, &n11 };
TreeNode* root = &n12;

void preorder_value(TreeNode* root, int value)
{
    if (root)
    {
        if (root->data < value) //입력값보다 작다면
            printf("%d보다 작은 노드 : %d\n", value, root->data); //노드 출력
        preorder_value(root->left, value); //왼쪽 서브 트리
        preorder_value(root->right, value); //오른쪽 서브 트리
    }
}

int main(void)
{
    int value = 0;
    printf("값을 입력하시오: ");
    scanf("%d", &value); //입력값을 받아온다

    preorder_value(root, value);
    return 0;
}
