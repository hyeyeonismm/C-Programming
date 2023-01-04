#include <stdio.h>
#pragma warning(disable:4996)

typedef struct TreeNode { //����ü�� ��� ����
	int data;
	struct TreeNode* left, * right;
}TreeNode;

// 			     20
//	      15             28
//	   10     17       26    33
//   4   12     19         30   35

TreeNode n1 = { 4, NULL, NULL }; //������ ��� ����
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


//���� ��ȸ
inorder(TreeNode* root) {
	if (root) {
		inorder(root->left); //���� ����Ʈ�� ��ȸ
		printf("%d ", root->data); //��� �湮
		inorder(root->right); //������ ����Ʈ�� ��ȸ
	}
}

//���� ��ȸ
preorder(TreeNode* root) {
	if (root) {
		printf("%d ", root->data); //��� �湮
 		preorder(root->left); //���� ����Ʈ�� ��ȸ
		preorder(root->right); //������ ����Ʈ�� ��ȸ
	}
}

//���� ��ȸ
postorder(TreeNode* root) {
	if (root) {
		postorder(root->left); //���� ����Ʈ�� ��ȸ
		postorder(root->right); //������ ����Ʈ�� ��ȸ
		printf("%d ", root->data); //��� �湮
	}
}


int main()
{
	printf("\n");
	
	printf(" ���� ��ȸ= ");
	preorder(root);
	printf("\n\n");

	printf(" ���� ��ȸ= ");
	postorder(root);
	printf("\n\n");

	printf(" ���� ��ȸ= ");
	inorder(root);
	printf("\n\n");

	return 0;
}
