#define _CRT_SECURE_NO_WARNINGS

#include"student.h"

int main()
{
	int n = 0;
	int m = 0;
	int i, j;
	char ch;
	int first = 1;
	std::list<STU> stu;		//����һ����Ϊstu���������ڴ洢ѧ������

	system("mode con cols = 200 ,lines = 60");
	system("color 0E");
	while (1)
	{
		system("cls");
		ch = Menu();
		switch (ch)
		{
		case 0:
			system("cls");
			printf("�˳�ϵͳ��\n");
			exit(0);
		case 1:
			system("cls");
			InputRecord(n, m, stu);
			first = 0;
			break;
		case 2:
			system("cls");
			if (first)
			{
				printf("ϵͳ������ѧ���ɼ���Ϣ���������룡\n");
				system("pause");
				break;
			}
			AppendRecord(n, m, stu);
			system("pause");
			break;
		case 3:
			system("cls");
			if (first)
			{
				printf("ϵͳ������ѧ���ɼ���Ϣ���������룡\n");
				system("pause");
				break;
			}
			DeleteRecord(n, m, stu);
			system("pause");
			break;
		case 4:
			system("cls");
			if (first)
			{
				printf("ϵͳ������ѧ���ɼ���Ϣ���������룡\n");
				system("pause");
				break;
			}
			SearchByNumber(n, m, stu);
			system("pause");
			break;
		case 5:
			system("cls");
			if (first)
			{
				printf("ϵͳ������ѧ���ɼ���Ϣ���������룡\n");
				system("pause");
				break;
			}
			SearchByName(n, m, stu);
			system("pause");
			break;
		case 6:
			system("cls");
			if (first)
			{
				printf("ϵͳ������ѧ���ɼ���Ϣ���������룡\n");
				system("pause");
				break;
			}
			ModifyRecord(n, m, stu);
			system("pause");
			break;
		case 7:
			system("cls");
			if (first)
			{
				cout << "ϵͳ������ѧ���ɼ���Ϣ���������룡\n";
				system("pause");
				break;
			}
			CalculateScoreOfStudent(n, m, stu);
			system("pause");
			break;
		case 8:
			system("cls");
			if (first)
			{
				cout << "ϵͳ������ѧ���ɼ���Ϣ���������룡\n";
				system("pause");
				break;
			}
			CalculateScoreOfCourse(n, m, stu);
			system("pause");
			break;
		case 9:
			system("cls");
			if (first)
			{
				SetPosition(POS_X3, POS_Y);
				printf("ϵͳ������ѧ����Ϣ���������룡\n");
				_getch();
				break;
			}
			SortbyNum(n, m, stu);
			_getch();
			break;
		case 10:
			system("cls");
			if (first)
			{
				SetPosition(POS_X3, POS_Y);
				printf("ϵͳ������ѧ����Ϣ���������룡\n");
				_getch();
				break;
			}
			SortbyName(n, m, stu);
			_getch();
			break;
		case 11:
			system("cls");
			if (first)
			{
				SetPosition(POS_X3, POS_Y);
				printf("ϵͳ������ѧ����Ϣ���������룡\n");
				_getch();
				break;
			}
			SortbyScore(m, n, stu);
			stu.reverse();
			_getch();
			break;
		case 12:
			system("cls");
			if (first)
			{
				SetPosition(POS_X3, POS_Y);
				printf("ϵͳ������ѧ����Ϣ���������룡\n");
				_getch();
				break;
			}
			SortbyScore(n, m, stu);
			_getch();
			break;
		case 13:
			system("cls");
			if (first)
			{
				SetPosition(POS_X3, POS_Y);
				printf("ϵͳ������ѧ����Ϣ���������룡\n");
				_getch();
				break;
			}
			StatisticAnalysis(n, m, stu);
			_getch();
			break;
		case 14:
			system("cls");
			if (first)
			{
				printf("ϵͳ������ѧ���ɼ���Ϣ���������룡\n");
				system("pause");
				break;
			}
			PrintRecord(n, m, stu);
			system("pause");
			break;
		case 15:
			system("cls");
			if (first)
			{
				SetPosition(POS_X3, POS_Y);
				printf("ϵͳ������ѧ����Ϣ���������룡\n");
				_getch();
				break;
			}
			WritetoFile(n, m, stu);
			_getch();
			break;
		case 16:
			system("cls");
			if (ReadfromFile(n, m, stu, first) || first)
			{
				SetPosition(POS_X1, 10);
				printf("��δ����ѧ����Ϣ���ļ���ʧ�ܣ����ȼ�飡\n");
				_getch();
				break;
			}
			_getch();
			break;
		default:
			system("cls");
			printf("�������������ѡ�������\n");
			system("pause");
			getchar();
			break;
		}
	}

	return 0;
}