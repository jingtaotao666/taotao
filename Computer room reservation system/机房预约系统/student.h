#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
#include"identity.h"
#include"computerRoom.h"
#include"globalFile.h"


//�����������
class Student :public Identity {
public:

	//���캯��
	Student();
	
	//�вι���
	Student(int id, string name, string paw);
	
	//�˵�����
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴ԤԼ
	void showMyOrder();
	
	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cencalOrder();

	//ѧ��ѧ��
	int m_Id;

	//��������
	vector<ComputerRoom>v_Com;
};