#pragma once
#include<iostream>
#include<vector>
using namespace std;
#include"identity.h"
#include"orderFile.h"

class Teacher :public Identity {

public:

	//构造函数
	Teacher();

	//有参构造
	Teacher(int empid, string name, string pwd);

	//菜单界面
	virtual void operMenu();

	//查看所有预约
	void showAllOrder();

	//审核预约
	void validOeder();



	int m_EmpId;//教师编号
};