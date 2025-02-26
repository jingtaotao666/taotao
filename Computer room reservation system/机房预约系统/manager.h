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

	//默认构造
	Manager();

	//有参构造
	Manager(string name, string pwd);

	//显示菜单
	virtual void operMenu();

	//添加账号
	void addPerson();

	//检测重复账号
	bool checkRepeat(int id, int type);

	//显示账号
	void showPerson();

	//查看机房信息
	void showCompture();

	//取消预约
	void cleanFile();

	//初始化容器
	void initVector();

	//学生容器
	vector<Student>v_Stu;

	//教师容器
	vector<Teacher>v_Tea;

	//机房容器
	vector<ComputerRoom>v_Com;
};