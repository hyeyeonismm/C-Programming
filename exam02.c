#include <stdio.h>
#pragma warning (disable:4996)

struct person { //person ����ü ����
	char name[10]; //���� �迭�� �� �̸� ����(���� �ڷ����� ũ��� ó�����ǿ� ���� 10���� ����)
	int age; //����� ���̸� ��Ÿ���� �������� ����
	double money; //������ ������ ��Ÿ���� �Ǽ����� ����
};

int main()
{
	struct person hong;
	struct person* pHong; //����ü person�� ����Ű�� ������ ���� pHong ����

	pHong = &hong; //����ü ���� hong�� �ּҰ� �����

	/* �� �Է¹ޱ� */
	printf("\n �̸��� �Է����ּ���: ");
	scanf("%s", &pHong->name); //ȭ��ǥ �����ڴ� ����ü �����ͷ� ����ü�� ����� ������ �� �ְ� ���ش�.
	printf(" ���̸� �Է����ּ���: ");
	scanf("%d", &pHong->age);
	printf(" ������ �Է����ּ���: ");
	scanf("%lf", &pHong->money);

	printf("================================\n");

	printf(" �̸�: %s\n", (*pHong).name); //����ü ������ pHong�� �Է��ؼ� ����ü ���� hong�� ������� �����Ѵ�.
	/*** (*pHong).name�� hong.name�� ���� �ǹ̶�� ���� �� ***/
	printf(" ����: %d\n", (*pHong).age);
	printf(" ����: %.2lf\n", (*pHong).money); //�ǽ��� ���ȭ�鿡 �Ҽ��� ��°�ڸ����� ǥ��Ǿ��ֱ� ������ .2lf�� ����Ѵ�.

	return 0;
}
