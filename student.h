#define _CRT_SECURE_NO_WARNINGS
#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<conio.h>
#include<windows.h>
#include<list>

using namespace std;

const int STU_NUM = 1000;		//教学班学生人数上限
const int COURSE_NUM = 10;	//课程门数上限
const int NAME_LEN =15;		//学生姓名最大长度
const int POS_X1 = 35;		//菜单页，第一列所有功能输出起始位置的x坐标值
const int POS_X2 = 40;		//输入模块提示语句出现的x坐标值
const int POS_X3 = 50;		//
const int POS_X4 = 65;		//
const int POS_Y = 3;		//排序之后输出提示起点的y坐标值

typedef struct student
{
	long num;					//学号
	char name[NAME_LEN];		//学生姓名
	float score[COURSE_NUM];	//各门课程成绩
	float sum;					//各门课程总分
	float aver;					//各门课程平均分
}STU;

//函数声明
int Menu(void);																		//操作菜单
void SetPosition(int x, int y);														//设置输出内容在控制台窗口中的起始位置
void InputRecord(int& n, int& m, std::list<STU>& stu);								//输入学生信息	
void AppendRecord(int& n, int& m, std::list<STU>& stu);								//增加学生信息
void DeleteRecord(int& n, int& m, std::list<STU>& stu);								//删除学生信息
void SearchByNumber(int n, int m, std::list<STU>& stu);								//按学号查询学生信息
void SearchByName(int& n, int& m, std::list<STU>& stu);								//按姓名查询学生信息
void ModifyRecord(int& n, int& m, std::list<STU>& stu);								//修改学生信息
void CalculateScoreOfStudent(int n, int m, std::list<STU>& stu);					//计算学生的总分和平均分
void CalculateScoreOfCourse(int n, int m, std::list<STU>& stu);						//计算某门课程的总分和平均分
void SortbyNum(int& n, int& m, std::list<STU>& stu); 								//按学号排序
void SortbyName(int& n, int& m, std::list<STU>& stu);								//按姓名排序
void SortbyScore(int& n, int& m, std::list<STU>& stu);								//按每个学生平均分排序
void StatisticAnalysis(int n, int m, std::list<STU>& stu);							//统计并输出各个分数段学生人数及占比
void PrintRecord(int n, int m, std::list<STU> stu);									//打印学生成绩
void WritetoFile(int n, int m, std::list<STU>& stu);								//将学生信息保存至文件中
int ReadfromFile(int& n, int& m, std::list<STU>& stu, int& first);					//将学生信息从文件中读出，存入内存，方便对学生信息进行处理		

#endif
