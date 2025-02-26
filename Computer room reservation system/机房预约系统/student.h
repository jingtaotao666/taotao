#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
#include"identity.h"
#include"computerRoom.h"
#include"globalFile.h"


//抽象出派生类
class Student :public Identity {
public:

	//构造函数
	Student();
	
	//有参构造
	Student(int id, string name, string paw);
	
	//菜单界面
	virtual void operMenu();

	//申请预约
	void applyOrder();

	//查看预约
	void showMyOrder();
	
	//查看所有预约
	void showAllOrder();

	//取消预约
	void cencalOrder();

	//学生学号
	int m_Id;

	//机房容器
	vector<ComputerRoom>v_Com;
};