#define _CRT_SECURE_NO_WARNINGS

#include"student.h"

int Menu(void)
{
	int posy = 5;
	int option;
	int i, j;
	SetPosition(POS_X3, posy);
	printf("学生成绩管理系统\n");
	for (i = 0; i < 2; i++)
	{
		SetPosition(POS_X1, ++posy);
		for (j = 0; j < 55; j++)
		{
			printf("-");
		}
	}
	//输出系统支持的功能和对应的代号
	SetPosition(POS_X1, ++posy);
	printf("1.输入学生信息");
	SetPosition(POS_X4, posy);
	printf("2.增加学生成绩");
	SetPosition(POS_X1, posy+=2);
	printf("3.删除学生信息");
	SetPosition(POS_X4, posy);
	printf("4.按学号查找记录");
	SetPosition(POS_X1, posy+=2);
	printf("5.按姓名查找记录");
	SetPosition(POS_X4, posy);
	printf("6.修改学生信息");
	SetPosition(POS_X1, posy+=2);
	printf("7.计算学生成绩");
	SetPosition(POS_X4, posy);
	printf("8.计算课程成绩");
	SetPosition(POS_X1, posy += 2);
	printf("9.按学号排序");
	SetPosition(POS_X4, posy);
	printf("10.按姓名排序");
	SetPosition(POS_X1, posy+=2);
	printf("11.按总成绩降序排序");
	SetPosition(POS_X4, posy);
	printf("12.按总成绩升序排序");
	SetPosition(POS_X1, posy+=2);
	printf("13.学生成绩统计");
	SetPosition(POS_X4, posy);
	printf("14.打印学生记录");
	SetPosition(POS_X1, posy += 2);
	printf("15.学生记录存盘");
	SetPosition(POS_X4, posy);
	printf("16.从磁盘读取学生记录");
	SetPosition(POS_X1, posy += 2);
	printf("0.退出");

	for (i = 0; i < 2;i++)
	{
		SetPosition(POS_X1, ++posy);
		for (j = 0; j < 55; j++)
		{
			printf("-");
		}
	}
	
	SetPosition(POS_X1, ++posy);
	printf("请选择你想要进行的操作[0~16]:[  ]\b\b\b");
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
	STU ch;		//链表节点

	SetPosition(POS_X2, posy);
	printf("输入学生人数（n<%d）:", STU_NUM);
	scanf("%d", &n);

	SetPosition(POS_X2, posy += 2);
	printf("输入课程门数(m<%d):", COURSE_NUM);
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
	printf("输入学生的学号，姓名和各门课程成绩：");
	for (i = 0; i < n; i++)
	{
		SetPosition(POS_X2, ++posy);
		printf("输入第%d个学生信息：\t", i + 1);
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
	printf("每个学生各门课程的总分和平均分为：\n");
	for (std::list<STU>::iterator ch = stu.begin(); ch != stu.end(); ch++,i++)
	{
		ch->sum = 0;
		for (j = 0; j < m; j++)
		{
			ch->sum += ch->score[j];
		}
		ch->aver = ch->sum / m;
		printf("第%d个学生：总分=%.2f，平均分=%.2f\n", i + 1, ch->sum, ch->aver);
	}
}



void CalculateScoreOfCourse(int n, int m, std::list<STU>& stu)
{
	int i = 0, j = 0;
	float sum[COURSE_NUM], aver[COURSE_NUM];
	int posy = 7;
	SetPosition(POS_X1, posy);
	printf("各门课程的总分和平均分的计算结果为：\n");
	for (j = 0; j < m; j++)
	{
		sum[j] = 0;

		for (std::list<STU>::iterator ch = stu.begin(); ch != stu.end(); ch++, i++)
		{
			sum[j]+=ch->score[j];
		}
		aver[j] = sum[j] / n;
		SetPosition(POS_X1, ++posy);
		printf("第%d门课程：总分=%.2f，平均分=%.2f\n", j + 1, sum[j], aver[j]);
	}
}

void WritetoFile(int n, int m, std::list<STU>& stu)
{
	int i, j;
	FILE* fp;
	if ((fp = fopen("student.txt", "w")) == NULL)
	{
		printf("文件student.txt无法正常打开！");
		exit(0);
	}

	//将数据按指定格式写入文件，包括学生人数n，课程人数m以及每个学生的信息
	fprintf(fp, "%10d%10d\n", n, m);
	for (std::list<STU>::iterator ch = stu.begin(); ch != stu.end(); ch++)
	{
		fprintf(fp, "%10ld%10s", ch->num, ch->name);		//删除了一个换行符			
		for (j = 0; j < m; j++)
		{
			fprintf(fp, "%10f", ch->score[j]);
		}
		fprintf(fp, "%10.f%10.f\n", ch->sum, ch->aver);			
	}
	fclose(fp);
	printf("存盘完毕！\n");
}


int ReadfromFile(int& n, int& m, std::list<STU>& stu, int& first)
{
	FILE* fp;
	int i, j;
	int posy = 8;
	SetPosition(POS_X1, posy);
	//打开文件
	if ((fp = fopen("student.txt", "r")) == NULL)
	{
		printf("文件student.txt无法正常打开！");
		return 1;
	}
	//将数据从磁盘中读出
	fscanf(fp, "%10d%10d", &n, &m);
	while(!feof(fp))
	{
		STU temp;		//数据暂时存放在此

		if (fscanf(fp, "%10ld%15s\n", &(temp.num), &(temp.name)) != 2)		//把10改成15
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
	first = 0;	//修改标志变量

	fclose(fp);
	printf("数据从磁盘读取完毕！");

	return 0;
}


void SearchByNumber(int n, int m, std::list<STU>& stu)
{
	long id;
	int i, j;
	printf("请输入你要查找的学生的学号：");
	scanf("%ld", &id);
	for (std::list<STU>::iterator ch = stu.begin();ch!=stu.end();ch++)
	{
		
		if (ch->num == id)
		{
			printf("找到了，该学号对应的学生信息为：\n");
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
	printf("未找到这个学号对应的学生记录\n");
	return;
}


void AppendRecord(int& n, int& m, std::list<STU>& stu)
{
	int i = 0, j = 0;
	STU ch;
	char input_str[5];
	printf("输入第%d个学生信息或输入'q'退出：\t", n + 1);

	while (scanf("%s", input_str) == 1)
	{
		if (input_str[0] == 'q') // 如果输入的是 'q'，则退出循环
		{
			break;
		}

		// 将从字符串转换回长整数和其他信息
		ch.num = atol(input_str);

		scanf("%s", ch.name);
		for (j = 0; j < m; j++)
		{
			scanf("%f", &ch.score[j]);
		}
		stu.push_back(ch);
		n++; // 学生人数 +1

		printf("输入第%d个学生信息或输入'q'退出：\t", n + 1);
	}
	printf("添加完毕！\n");
	return;
}


void SearchByName(int& n, int& m, std::list<STU>& stu)
{
	int flag = 1;
	char name[NAME_LEN];
	int i, j;
	int k = 0;
	printf("请输入你要查找的学生的姓名：");
	scanf("%s", name);
	for (std::list<STU>::iterator ch = stu.begin(); ch != stu.end(); ch++)
	{

		if (strcmp(ch->name,name)==0)
		{
			printf("找到了，第%d学生对应的学生信息为：\n", ++k);
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
		printf("未找到这个姓名对应的学生记录\n");
	}
	return;
}


void DeleteRecord(int& n, int& m, std::list<STU>& stu)
{
	int i, j;
	long id;
	char yesorno;
	
	printf("请输入你要删除学生的学号：");
	scanf("%ld", &id);
	for (std::list<STU>::iterator ch = stu.begin(); ch != stu.end(); ch++)
	{

		if (ch->num == id)
		{
			printf("找到了该生记录，信息为：\n");
			printf("%10ld%15s", ch->num, ch->name);
			for (j = 0; j < m; j++)
			{
				printf("%10.2f", ch->score[j]);
			}
			printf("%10.2f%10.2f", ch->sum, ch->aver);
			printf("请确认是否要删除这条记录？（Y/y或N/n）：");
			getchar();
			scanf("%c", &yesorno);
			if (yesorno == 'Y' || yesorno == 'y')
			{
				stu.erase(ch);		//删除这条学生信息
				printf("删除完毕\n");
				return;
			}
			else if (yesorno == 'N' || yesorno == 'n')
			{
				printf("找到了学生记录，但不删除\n");
				return;
			}
			else
			{
				printf("输入出错！\n");
				return;
			}
		}
	}
	printf("未找到该生记录！\n");
	return;
}


void ModifyRecord(int& n, int& m, std::list<STU>& stu)
{
	long id;
	
	char yesorno;
	printf("请输入需要修改信息所对应的学号：");
	scanf("%ld", &id);

	for (std::list<STU>::iterator ch = stu.begin(); ch != stu.end(); ch++)
	{

		if (ch->num == id)
		{
			printf("找到了该生记录，信息为：\n");
			printf("%10ld%15s", ch->num, ch->name);
			for (int j = 0; j < m; j++)
			{
				printf("%10.2f", ch->score[j]);
			}
			printf("%10.2f%10.2f", ch->sum, ch->aver);
			printf("请确认是否要修改？（Y/y或N/n）：");
			getchar();
			scanf("%c", &yesorno);
			if (yesorno == 'Y' || yesorno == 'y')
			{
				printf("请输入要修改的学生信息：");
				scanf("%ld%s", &ch->num, ch->name);
				for (int i = 0; i < m; i++)
				{
					scanf("%f", &ch->score[i]);
				}

				printf("修改完毕\n");
				return;
			}
			else if (yesorno == 'N' || yesorno == 'n')
			{
				printf("找到了学生记录，但不修改\n");
				return;
			}
			else
			{
				printf("输入出错！\n");
				return;
			}
		}
	}
	printf("未找到学生记录！\n");
	return;
}



void PrintRecord(int n, int m, std::list<STU> stu)
{
	printf("学号\t\t姓名\t\t");
	for (int i = 0; i < m; i++)
	{
		printf("课程%d\t\t",i+1);
	}
	printf("总分\t\t平均分\n");
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

	printf("按姓名字典对学生记录排序完毕");
	return;
}


void SortbyNum(int& n, int& m, std::list<STU>& stu)
{
	stu.sort([](const STU& a, const STU& b)
		{
			return a.num< b.num ;
		});

	printf("按学号从小到大对学生记录排序完毕");
	return;
}


void SortbyScore(int& n, int& m, std::list<STU>& stu)
{
	stu.sort([](const STU& a, const STU& b)
		{
			return a.sum< b.sum;
		});

	printf("按学生成绩总分对学生记录排序完毕");
	return;
	
}



void StatisticAnalysis(int n, int m, std::list<STU>& stu)
{
	int t[6] = {0};
	for (int j = 0; j < m; j++)
	{
		printf("课程%d成绩统计结果为：\n", j + 1);
		printf("分数段\t人数\t占比\n");
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

	printf("\n学生成绩平均分统计结果为：\n");
	printf("分数段\t人数\t占比\n");
	memset(t, 0, sizeof(t));		//待研究
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