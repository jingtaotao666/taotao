#pragma once
#include<iostream>
#include<vector>
using namespace std;
#include"identity.h"
#include"orderFile.h"

class Teacher :public Identity {

public:

	//���캯��
	Teacher();

	//�вι���
	Teacher(int empid, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOeder();



	int m_EmpId;//��ʦ���
};