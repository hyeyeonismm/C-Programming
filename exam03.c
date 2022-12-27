#include <stdio.h>
#include <math.h> //sqrt �Լ��� ����� �� ����
#pragma warning (disable:4996)

struct coordinate { //coordinate ����ü ����
	double x; //x,y��ǥ�� ����� ���´�.
	double y;
};

/* �Ÿ� ���ϴ� �Լ� ���� */
double distance(struct coordinate p1, struct coordinate p2)
{
	//�� �� ������ �Ÿ��� ���ϴ� ������ ������ �����ߴ�.
	int a, b; 
	a = p1.x - p2.x; 
	b = p1.y - p2.y;
	return sqrt(a * a + b * b);
}

int main()
{
	double result = 0; //����� ���� ���� �� �ʱ�ȭ
	struct coordinate p1, p2; //����ü ���� ����
	int i = 0; //�ݺ� Ƚ�� ���� ���� �� �ʱ�ȭ

	while (i<2) //i�� 2�� �ݺ��ϰ� while���� Ż���ϵ��� ��
	{
		scanf("%lf %lf", &p1.x, &p1.y); //p1��ǥ�� ���� �Է¹޴´�.
		scanf("%lf %lf", &p2.x, &p2.y); //p2��ǥ�� ���� �Է¹޴´�.

		result = distance(p1, p2); //��� �������� distance�Լ��� ��ȯ���� �����Ѵ�.
		
		printf("��(%.lf, %.lf)�� (%.lf, %.lf) ������ �Ÿ� = %.3lf\n", p1.x, p1.y, p2.x, p2.y, result);
		//p1, p2�� ���� �������̱� ������ �Ҽ����� �ȳ������� �����Ͽ���, ������� �Ҽ��� ��°�ڸ����� �������� �����Ͽ���.

		i++; //i�� 1�� ������Ų��.
	}

	return 0;
}