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

const int STU_NUM = 1000;		//��ѧ��ѧ����������
const int COURSE_NUM = 10;	//�γ���������
const int NAME_LEN =15;		//ѧ��������󳤶�
const int POS_X1 = 35;		//�˵�ҳ����һ�����й��������ʼλ�õ�x����ֵ
const int POS_X2 = 40;		//����ģ����ʾ�����ֵ�x����ֵ
const int POS_X3 = 50;		//
const int POS_X4 = 65;		//
const int POS_Y = 3;		//����֮�������ʾ����y����ֵ

typedef struct student
{
	long num;					//ѧ��
	char name[NAME_LEN];		//ѧ������
	float score[COURSE_NUM];	//���ſγ̳ɼ�
	float sum;					//���ſγ��ܷ�
	float aver;					//���ſγ�ƽ����
}STU;

//��������
int Menu(void);																		//�����˵�
void SetPosition(int x, int y);														//������������ڿ���̨�����е���ʼλ��
void InputRecord(int& n, int& m, std::list<STU>& stu);								//����ѧ����Ϣ	
void AppendRecord(int& n, int& m, std::list<STU>& stu);								//����ѧ����Ϣ
void DeleteRecord(int& n, int& m, std::list<STU>& stu);								//ɾ��ѧ����Ϣ
void SearchByNumber(int n, int m, std::list<STU>& stu);								//��ѧ�Ų�ѯѧ����Ϣ
void SearchByName(int& n, int& m, std::list<STU>& stu);								//��������ѯѧ����Ϣ
void ModifyRecord(int& n, int& m, std::list<STU>& stu);								//�޸�ѧ����Ϣ
void CalculateScoreOfStudent(int n, int m, std::list<STU>& stu);					//����ѧ�����ֺܷ�ƽ����
void CalculateScoreOfCourse(int n, int m, std::list<STU>& stu);						//����ĳ�ſγ̵��ֺܷ�ƽ����
void SortbyNum(int& n, int& m, std::list<STU>& stu); 								//��ѧ������
void SortbyName(int& n, int& m, std::list<STU>& stu);								//����������
void SortbyScore(int& n, int& m, std::list<STU>& stu);								//��ÿ��ѧ��ƽ��������
void StatisticAnalysis(int n, int m, std::list<STU>& stu);							//ͳ�Ʋ��������������ѧ��������ռ��
void PrintRecord(int n, int m, std::list<STU> stu);									//��ӡѧ���ɼ�
void WritetoFile(int n, int m, std::list<STU>& stu);								//��ѧ����Ϣ�������ļ���
int ReadfromFile(int& n, int& m, std::list<STU>& stu, int& first);					//��ѧ����Ϣ���ļ��ж����������ڴ棬�����ѧ����Ϣ���д���		

#endif
