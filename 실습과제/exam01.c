#include <stdio.h>
#pragma warning(disable:4996)

typedef struct TreeNode { //구조체로 노드 정의
	int data;
	struct TreeNode* left, * right;
}TreeNode;

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


//중위 순회
inorder(TreeNode* root) {
	if (root) {
		inorder(root->left); //왼쪽 서브트리 순회
		printf("%d ", root->data); //노드 방문
		inorder(root->right); //오른쪽 서브트리 순회
	}
}

//전위 순회
preorder(TreeNode* root) {
	if (root) {
		printf("%d ", root->data); //노드 방문
 		preorder(root->left); //왼쪽 서브트리 순회
		preorder(root->right); //오른쪽 서브트리 순회
	}
}

//후위 순회
postorder(TreeNode* root) {
	if (root) {
		postorder(root->left); //왼쪽 서브트리 순회
		postorder(root->right); //오른쪽 서브트리 순회
		printf("%d ", root->data); //노드 방문
	}
}


int main()
{
	printf("\n");
	
	printf(" 전위 순회= ");
	preorder(root);
	printf("\n\n");

	printf(" 후위 순회= ");
	postorder(root);
	printf("\n\n");

	printf(" 중위 순회= ");
	inorder(root);
	printf("\n\n");

	return 0;
}
