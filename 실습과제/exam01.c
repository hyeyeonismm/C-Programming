#include <stdio.h>
#pragma warning (disable : 4996)

int findLength(char* pStr); //���ڿ��� ���� ���ϴ� �Լ� ����
int main()
{
	char str[100]; //���ڿ��� 100�� �̸����� �Է¹��� �� �ֵ��� ������ �����Ѵ�. 

	/* �ǽ� ȭ��� �����ϰ� ��µǵ��� printf�Լ��� ����Ͽ� ���� */
	printf("\n ������ : ���ڿ��� ���� ��� :\n");
	printf("---------------------------------------\n");
	printf(" ���ڿ� �Է� : ");
	scanf("%s", str);  //���ڿ��� �Է¹���

	int strLen = findLength(str); //�Է¹��� ���ڿ��� ���̴� findLength�Լ��� ����Ͽ� ����Ѵ�.


	printf(" �Է¹��� ���ڿ� ���� : %d\n", strLen); //strLen �� ���

	return 0;
}

int findLength(char* pStr) //���ڿ� ���̸� üũ�� �޸��� ���� �ּ�
{
	int length = 0; //���ڿ��� ���̸� ������ ���� ����

	while (*pStr++ != 0) //pStr�� �޸� ���� NULL�� �ش��ϴ� 0�� �ƴ� ������ �ݺ��� ����
		length++; //pStr�� ���� NULL�� �ƴ϶�� ���ڿ��� ���̸� ������ ������ 1�� �����Ѵ�.

	return length; //�ݺ������� Ż���ϸ� length���� ����ϵ��� �Ѵ�.
}