#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int ele;   //��������¥��
int st[10], end[10];   //�û���ʼ\Ŀ��¥�����

void sort(int a[], int b[])
{
	for (int i = 0; i < 9; i++) {
		for (int j = 9; j >i; --j) {
			if (a[j] > a[j - 1]) {
				int m1 = a[j];
				a[j] = a[j - 1];
				a[j - 1] =m1 ;
				int m2 = b[j];
				b[j] = b[j - 1];
				b[j - 1] = m2;
			}
		}
	}
}

int main()
{

	//��������
	printf("�������������¥�㣺\n");
	scanf("%d", &ele);
	printf("��������û���ʼ¥������ֹ¥��(����T��������\n");
	int n1 = -1;    //n1ͳ���û�������
	for (int i = 0; i < 10; i++) {
		char x = getchar();
		if (x == 'T') {
			break;   //�ֶ�����"T"ʱֹͣ����
		}
		scanf("%d %d", &st[i], &end[i]);
		n1++;
	}
	sort(st, end);   //����ʼ¥��Ӹߵ�������


    //������ʼ��   
	int t = 0, n2 = 0;   //t��¼ʱ�䣬n2��¼����������
	int dir;
	st[0] > ele ? dir = 1 : dir = -1;   //�жϵ��ݵĳ�ʼ���з���
	int top = -99;   //top��ǵ�������һ��ת��
	printf("���ݵ�����״������:\n");
	printf("¥�� ���� ʱ��\n");
	printf("%d %d %d\n", ele, 0, 0);
	
	//��������
	while (n1 > -1) {
	    
		//ȷ��topֵ
		for (int i = 0; i < 10; i++) {
			if ((st[i] > 0) && ((st[i] * dir > top * dir)||(top == -99))) {
				top = st[i];
			}
		}
		
		//�û�����
		int dw = -1, f2 = 99;
		for (int i = 0; i < 10; i++) {
			if ((ele == end[i]) && (st[i] == -1)) {
				dw = 1;
				f2 = i;
			}
		}
		if (dw == 1) {
			n2--;
			end[f2] = -1;   //���ݱ��
			printf("%d %d %d", ele, n2, t);
			printf("  ��������\n");
			n1--;
		}
		
		//�û�����
		int up = -1, f1 = 99;   //f1��¼�����û�����
		for (int i = 0; i < 10; i++) {   //�жϵ�ǰ�������û�������
			if (ele == st[i]) {
				up = 1;
				f1 = i;
			}
		}
		if (up == 1) {
			st[f1] = -1;   //���ݱ��
			n2++;
			if (end[f1] * dir > top * dir) {
				top = end[f1];   //�����û�Ŀ��¥�㳬��top����topֵ����
			}
			printf("%d %d %d", ele, n2, t);
			printf("  ��������\n");
		}
		
		//����ת��
		if (ele == top) {
			dir = -dir;
		}

		//��������
		ele += dir;
		t++;
	}
	return 0;
}