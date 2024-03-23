#define _CRT_SECURE_NO_WARNINGS

#include"student.h"

int Menu(void)
{
	int posy = 5;
	int option;
	int i, j;
	SetPosition(POS_X3, posy);
	printf("ѧ���ɼ�����ϵͳ\n");
	for (i = 0; i < 2; i++)
	{
		SetPosition(POS_X1, ++posy);
		for (j = 0; j < 55; j++)
		{
			printf("-");
		}
	}
	//���ϵͳ֧�ֵĹ��ܺͶ�Ӧ�Ĵ���
	SetPosition(POS_X1, ++posy);
	printf("1.����ѧ����Ϣ");
	SetPosition(POS_X4, posy);
	printf("2.����ѧ���ɼ�");
	SetPosition(POS_X1, posy+=2);
	printf("3.ɾ��ѧ����Ϣ");
	SetPosition(POS_X4, posy);
	printf("4.��ѧ�Ų��Ҽ�¼");
	SetPosition(POS_X1, posy+=2);
	printf("5.���������Ҽ�¼");
	SetPosition(POS_X4, posy);
	printf("6.�޸�ѧ����Ϣ");
	SetPosition(POS_X1, posy+=2);
	printf("7.����ѧ���ɼ�");
	SetPosition(POS_X4, posy);
	printf("8.����γ̳ɼ�");
	SetPosition(POS_X1, posy += 2);
	printf("9.��ѧ������");
	SetPosition(POS_X4, posy);
	printf("10.����������");
	SetPosition(POS_X1, posy+=2);
	printf("11.���ܳɼ���������");
	SetPosition(POS_X4, posy);
	printf("12.���ܳɼ���������");
	SetPosition(POS_X1, posy+=2);
	printf("13.ѧ���ɼ�ͳ��");
	SetPosition(POS_X4, posy);
	printf("14.��ӡѧ����¼");
	SetPosition(POS_X1, posy += 2);
	printf("15.ѧ����¼����");
	SetPosition(POS_X4, posy);
	printf("16.�Ӵ��̶�ȡѧ����¼");
	SetPosition(POS_X1, posy += 2);
	printf("0.�˳�");

	for (i = 0; i < 2;i++)
	{
		SetPosition(POS_X1, ++posy);
		for (j = 0; j < 55; j++)
		{
			printf("-");
		}
	}
	
	SetPosition(POS_X1, ++posy);
	printf("��ѡ������Ҫ���еĲ���[0~16]:[  ]\b\b\b");
	scanf("%d", &option);
	return option;
}


void SetPosition(int x, int y)
{
	HANDLE hOut;
	COORD pos;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut, pos);
}


void InputRecord(int& n, int& m,std::list<STU>& stu)
{
	int i, j;
	int posy = 6;
	STU ch;		//����ڵ�

	SetPosition(POS_X2, posy);
	printf("����ѧ��������n<%d��:", STU_NUM);
	scanf("%d", &n);

	SetPosition(POS_X2, posy += 2);
	printf("����γ�����(m<%d):", COURSE_NUM);
	scanf("%d", &m);
	
	for (i = 0; i < 2; i++)
	{
		SetPosition(POS_X1, ++posy);
		for (j = 0; j < 55; j++)
		{
			printf("-");
		}
	}

	SetPosition(POS_X2, ++posy);
	printf("����ѧ����ѧ�ţ������͸��ſγ̳ɼ���");
	for (i = 0; i < n; i++)
	{
		SetPosition(POS_X2, ++posy);
		printf("�����%d��ѧ����Ϣ��\t", i + 1);
		scanf("%ld%s", &ch.num, ch.name);
		for (j = 0; j < m; j++)
		{
			scanf("%f", &ch.score[j]);
		}
		stu.push_back(ch);
	}

	CalculateScoreOfStudent(n, m, stu);
}



void CalculateScoreOfStudent(int n, int m, std::list<STU>& stu)
{
	int i=0,j=0;
	printf("ÿ��ѧ�����ſγ̵��ֺܷ�ƽ����Ϊ��\n");
	for (std::list<STU>::iterator ch = stu.begin(); ch != stu.end(); ch++,i++)
	{
		ch->sum = 0;
		for (j = 0; j < m; j++)
		{
			ch->sum += ch->score[j];
		}
		ch->aver = ch->sum / m;
		printf("��%d��ѧ�����ܷ�=%.2f��ƽ����=%.2f\n", i + 1, ch->sum, ch->aver);
	}
}



void CalculateScoreOfCourse(int n, int m, std::list<STU>& stu)
{
	int i = 0, j = 0;
	float sum[COURSE_NUM], aver[COURSE_NUM];
	int posy = 7;
	SetPosition(POS_X1, posy);
	printf("���ſγ̵��ֺܷ�ƽ���ֵļ�����Ϊ��\n");
	for (j = 0; j < m; j++)
	{
		sum[j] = 0;

		for (std::list<STU>::iterator ch = stu.begin(); ch != stu.end(); ch++, i++)
		{
			sum[j]+=ch->score[j];
		}
		aver[j] = sum[j] / n;
		SetPosition(POS_X1, ++posy);
		printf("��%d�ſγ̣��ܷ�=%.2f��ƽ����=%.2f\n", j + 1, sum[j], aver[j]);
	}
}

void WritetoFile(int n, int m, std::list<STU>& stu)
{
	int i, j;
	FILE* fp;
	if ((fp = fopen("student.txt", "w")) == NULL)
	{
		printf("�ļ�student.txt�޷������򿪣�");
		exit(0);
	}

	//�����ݰ�ָ����ʽд���ļ�������ѧ������n���γ�����m�Լ�ÿ��ѧ������Ϣ
	fprintf(fp, "%10d%10d\n", n, m);
	for (std::list<STU>::iterator ch = stu.begin(); ch != stu.end(); ch++)
	{
		fprintf(fp, "%10ld%10s", ch->num, ch->name);		//ɾ����һ�����з�			
		for (j = 0; j < m; j++)
		{
			fprintf(fp, "%10f", ch->score[j]);
		}
		fprintf(fp, "%10.f%10.f\n", ch->sum, ch->aver);			
	}
	fclose(fp);
	printf("������ϣ�\n");
}


int ReadfromFile(int& n, int& m, std::list<STU>& stu, int& first)
{
	FILE* fp;
	int i, j;
	int posy = 8;
	SetPosition(POS_X1, posy);
	//���ļ�
	if ((fp = fopen("student.txt", "r")) == NULL)
	{
		printf("�ļ�student.txt�޷������򿪣�");
		return 1;
	}
	//�����ݴӴ����ж���
	fscanf(fp, "%10d%10d", &n, &m);
	while(!feof(fp))
	{
		STU temp;		//������ʱ����ڴ�

		if (fscanf(fp, "%10ld%15s\n", &(temp.num), &(temp.name)) != 2)		//��10�ĳ�15
			break;
		for (j = 0; j < m; j++)
		{
			if(fscanf(fp, "%10f", &(temp.score[j]))!=1)
				break;
		}
		if (fscanf(fp, "%10f%10f\n", &temp.sum, &temp.aver) != 2)
		{
			//delete[] temp.score;
			break;
		}
		else
		{
			stu.push_back(temp);
		}
		
	}
	first = 0;	//�޸ı�־����

	fclose(fp);
	printf("���ݴӴ��̶�ȡ��ϣ�");

	return 0;
}


void SearchByNumber(int n, int m, std::list<STU>& stu)
{
	long id;
	int i, j;
	printf("��������Ҫ���ҵ�ѧ����ѧ�ţ�");
	scanf("%ld", &id);
	for (std::list<STU>::iterator ch = stu.begin();ch!=stu.end();ch++)
	{
		
		if (ch->num == id)
		{
			printf("�ҵ��ˣ���ѧ�Ŷ�Ӧ��ѧ����ϢΪ��\n");
			printf("%10ld%15s", ch->num, ch->name);
			for (j = 0; j < m; j++)
			{
				printf("%10.2f", ch->score[j]);
			}
			printf("%10.2f%10.2f", ch->sum, ch->aver);
			printf("\n");
			return;
		}
	}
	printf("δ�ҵ����ѧ�Ŷ�Ӧ��ѧ����¼\n");
	return;
}


void AppendRecord(int& n, int& m, std::list<STU>& stu)
{
	int i = 0, j = 0;
	STU ch;
	char input_str[5];
	printf("�����%d��ѧ����Ϣ������'q'�˳���\t", n + 1);

	while (scanf("%s", input_str) == 1)
	{
		if (input_str[0] == 'q') // ���������� 'q'�����˳�ѭ��
		{
			break;
		}

		// �����ַ���ת���س�������������Ϣ
		ch.num = atol(input_str);

		scanf("%s", ch.name);
		for (j = 0; j < m; j++)
		{
			scanf("%f", &ch.score[j]);
		}
		stu.push_back(ch);
		n++; // ѧ������ +1

		printf("�����%d��ѧ����Ϣ������'q'�˳���\t", n + 1);
	}
	printf("�����ϣ�\n");
	return;
}


void SearchByName(int& n, int& m, std::list<STU>& stu)
{
	int flag = 1;
	char name[NAME_LEN];
	int i, j;
	int k = 0;
	printf("��������Ҫ���ҵ�ѧ����������");
	scanf("%s", name);
	for (std::list<STU>::iterator ch = stu.begin(); ch != stu.end(); ch++)
	{

		if (strcmp(ch->name,name)==0)
		{
			printf("�ҵ��ˣ���%dѧ����Ӧ��ѧ����ϢΪ��\n", ++k);
			printf("%10ld%15s", ch->num, ch->name);
			for (j = 0; j < m; j++)
			{
				printf("%10.2f", ch->score[j]);
			}
			printf("%10.2f%10.2f\n", ch->sum, ch->aver);
			flag = 0;

		}
	}
	if (flag)
	{
		printf("δ�ҵ����������Ӧ��ѧ����¼\n");
	}
	return;
}


void DeleteRecord(int& n, int& m, std::list<STU>& stu)
{
	int i, j;
	long id;
	char yesorno;
	
	printf("��������Ҫɾ��ѧ����ѧ�ţ�");
	scanf("%ld", &id);
	for (std::list<STU>::iterator ch = stu.begin(); ch != stu.end(); ch++)
	{

		if (ch->num == id)
		{
			printf("�ҵ��˸�����¼����ϢΪ��\n");
			printf("%10ld%15s", ch->num, ch->name);
			for (j = 0; j < m; j++)
			{
				printf("%10.2f", ch->score[j]);
			}
			printf("%10.2f%10.2f", ch->sum, ch->aver);
			printf("��ȷ���Ƿ�Ҫɾ��������¼����Y/y��N/n����");
			getchar();
			scanf("%c", &yesorno);
			if (yesorno == 'Y' || yesorno == 'y')
			{
				stu.erase(ch);		//ɾ������ѧ����Ϣ
				printf("ɾ�����\n");
				return;
			}
			else if (yesorno == 'N' || yesorno == 'n')
			{
				printf("�ҵ���ѧ����¼������ɾ��\n");
				return;
			}
			else
			{
				printf("�������\n");
				return;
			}
		}
	}
	printf("δ�ҵ�������¼��\n");
	return;
}


void ModifyRecord(int& n, int& m, std::list<STU>& stu)
{
	long id;
	
	char yesorno;
	printf("��������Ҫ�޸���Ϣ����Ӧ��ѧ�ţ�");
	scanf("%ld", &id);

	for (std::list<STU>::iterator ch = stu.begin(); ch != stu.end(); ch++)
	{

		if (ch->num == id)
		{
			printf("�ҵ��˸�����¼����ϢΪ��\n");
			printf("%10ld%15s", ch->num, ch->name);
			for (int j = 0; j < m; j++)
			{
				printf("%10.2f", ch->score[j]);
			}
			printf("%10.2f%10.2f", ch->sum, ch->aver);
			printf("��ȷ���Ƿ�Ҫ�޸ģ���Y/y��N/n����");
			getchar();
			scanf("%c", &yesorno);
			if (yesorno == 'Y' || yesorno == 'y')
			{
				printf("������Ҫ�޸ĵ�ѧ����Ϣ��");
				scanf("%ld%s", &ch->num, ch->name);
				for (int i = 0; i < m; i++)
				{
					scanf("%f", &ch->score[i]);
				}

				printf("�޸����\n");
				return;
			}
			else if (yesorno == 'N' || yesorno == 'n')
			{
				printf("�ҵ���ѧ����¼�������޸�\n");
				return;
			}
			else
			{
				printf("�������\n");
				return;
			}
		}
	}
	printf("δ�ҵ�ѧ����¼��\n");
	return;
}



void PrintRecord(int n, int m, std::list<STU> stu)
{
	printf("ѧ��\t\t����\t\t");
	for (int i = 0; i < m; i++)
	{
		printf("�γ�%d\t\t",i+1);
	}
	printf("�ܷ�\t\tƽ����\n");
	for (std::list<STU>::iterator ch = stu.begin(); ch != stu.end(); ch++)
	{
		printf("%-16ld%-16s", ch->num, ch->name);
		for (int j = 0; j < m; j++)
		{
			printf("%-16.1lf", ch->score[j]);
		}
		printf("%-16.1lf%-16.1lf\n", ch->sum, ch->aver);
	}
	return;
}



void SortbyName(int& n, int& m, std::list<STU>& stu)
{
	stu.sort([](const STU& a, const STU& b)
		{
			return strcmp(a.name , b.name)<0;
		});

	printf("�������ֵ��ѧ����¼�������");
	return;
}


void SortbyNum(int& n, int& m, std::list<STU>& stu)
{
	stu.sort([](const STU& a, const STU& b)
		{
			return a.num< b.num ;
		});

	printf("��ѧ�Ŵ�С�����ѧ����¼�������");
	return;
}


void SortbyScore(int& n, int& m, std::list<STU>& stu)
{
	stu.sort([](const STU& a, const STU& b)
		{
			return a.sum< b.sum;
		});

	printf("��ѧ���ɼ��ֶܷ�ѧ����¼�������");
	return;
	
}



void StatisticAnalysis(int n, int m, std::list<STU>& stu)
{
	int t[6] = {0};
	for (int j = 0; j < m; j++)
	{
		printf("�γ�%d�ɼ�ͳ�ƽ��Ϊ��\n", j + 1);
		printf("������\t����\tռ��\n");
		for (std::list<STU>::iterator ch = stu.begin(); ch != stu.end(); ch++)
		{
			if (ch->score[j ]>= 0 && ch->score[j] < 60)
				t[0]++;
			else if (ch->score[j] < 70)
				t[1]++;
			else if (ch->score[j] < 80)
				t[2]++;
			else if (ch->score[j] < 90)
				t[3]++;
			else if (ch->score[j] <100)
				t[4]++;
			else if (ch->score[j] ==100)
				t[5]++;
		}

		for (int i = 0; i < 6; i++)
		{
			if (i == 0)
				printf("<60\t%d\t%.2f%%\n", t[i], (float)t[i] / n * 100);
			else if (i == 5)
				printf("100\t%d\t%.2f%%\n", t[i], (float)t[i] / n * 100);
			else
				printf("%d-%d\t%d\t%.2f%%\n", (i + 5) * 10, (i + 5) * 10 + 9, t[i], (float)t[i] / n * 100);
		}
	}

	printf("\nѧ���ɼ�ƽ����ͳ�ƽ��Ϊ��\n");
	printf("������\t����\tռ��\n");
	memset(t, 0, sizeof(t));		//���о�
	for (std::list<STU>::iterator ch = stu.begin(); ch != stu.end(); ch++)
	{
		if (ch->aver >= 0 && ch->aver < 60)
			t[0]++;
		else if (ch->aver < 70)
			t[1]++;
		else if (ch->aver < 80)
			t[2]++;
		else if (ch->aver < 90)
			t[3]++;
		else if (ch->aver < 100)
			t[4]++;
		else if (ch->aver == 100)
			t[5]++;
	}
	for (int i = 0; i < 6; i++)
	{
		if (i == 0)
			printf("<60\t%d\t%.2f%%\n", t[i], (float)t[i] / n * 100);
		else if (i == 5)
			printf("100\t%d\t%.2f%%\n", t[i], (float)t[i] / n * 100);
		else
			printf("%d-%d\t%d\t%.2f%%\n", (i + 5) * 10, (i + 5) * 10 + 9, t[i], (float)t[i] / n * 100);
	}

}