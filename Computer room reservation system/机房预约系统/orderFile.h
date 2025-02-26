#pragma once
#include<iostream>
using namespace std;
#include<map>
#include<fstream>
#include<string>
#include"globalFile.h"

class OrdeFile {
public:
	//构造函数
	OrdeFile();

	//更新预约记录
	void updateOrder();

	//记录预约的个数
	int m_Size;

	//记录所有预约的容器
	map<int, map<string, string>>m_orderData;
};