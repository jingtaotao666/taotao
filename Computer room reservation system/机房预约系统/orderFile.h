#pragma once
#include<iostream>
using namespace std;
#include<map>
#include<fstream>
#include<string>
#include"globalFile.h"

class OrdeFile {
public:
	//���캯��
	OrdeFile();

	//����ԤԼ��¼
	void updateOrder();

	//��¼ԤԼ�ĸ���
	int m_Size;

	//��¼����ԤԼ������
	map<int, map<string, string>>m_orderData;
};