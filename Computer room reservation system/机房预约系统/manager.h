#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
#include"identity.h"
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"

class Manager :public Identity {
public:

	//Ĭ�Ϲ���
	Manager();

	//�вι���
	Manager(string name, string pwd);

	//��ʾ�˵�
	virtual void operMenu();

	//����˺�
	void addPerson();

	//����ظ��˺�
	bool checkRepeat(int id, int type);

	//��ʾ�˺�
	void showPerson();

	//�鿴������Ϣ
	void showCompture();

	//ȡ��ԤԼ
	void cleanFile();

	//��ʼ������
	void initVector();

	//ѧ������
	vector<Student>v_Stu;

	//��ʦ����
	vector<Teacher>v_Tea;

	//��������
	vector<ComputerRoom>v_Com;
};