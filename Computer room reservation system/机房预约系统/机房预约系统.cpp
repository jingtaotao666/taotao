#include<iostream>
using namespace std;
#include<string>
#include<fstream>
#include"identity.h"
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"

//教师的子菜单
void TeacherMenu(Identity*& teacher) {
	while (true) {
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		if (select == 1) {
			//显示所有预约
			tea->showAllOrder();
		}
		else if (select == 2) {
			//审核预约
			tea->validOeder();
		}
		else {
			cout << "注销成功" << endl;
			delete teacher;
			system("pause");
			system("cls");
			return;
		}
	}
}

//学生的子菜单
void studentMenu(Identity* & student) {
	while (true) {
		//调用学生的子菜单
		student->operMenu();

		//将父类的指针转为子类的指针
		Student* stu = (Student*)student;

		int select = 0;

		cin >> select;
		if (select == 1) {
			//申请预约
			stu->applyOrder();
		}
		else if (select == 2) {
			//查看我的预约
			stu->showMyOrder();
		}
		else if (select == 3) {
			//查看所有预约
			stu->showAllOrder();
		}
		else if (select == 4) {
			//取消预约
			stu->cencalOrder();
		}
		else {
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//管理员的子菜单
void managerMenu(Identity* & manager) {
	while (true) {
		//调用管理员的子菜单
		manager->operMenu();

		//将父类的指针强转为子类的指针  用以调用子类的独有属性
		Manager* man = (Manager*)manager;

		int select = 0;
		//接受用户的选择
		cin >> select;

		if (select == 1) {

			//添加账号
			//cout << "添加账号" << endl;

			man->addPerson();
		}
		else if (select == 2) {

			//查看账号
			

			//cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3) {

			//查看机房信息
			
			//cout << "查看机房信息" << endl;
			man->showCompture();
		}
		else if (select == 4) {

			//清空预约
			

			//cout << "清空预约" << endl;
			man->cleanFile();
		}
		else {
			delete manager;//销毁掉堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;

		}
	}



}


//登录页面     参数1 操作的文件名   参数2  操作身份的类型
void LoginIn(string fileName, int type) {

	//父类的指针指向子类的对象
	Identity* person = NULL;


	//打开文件
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
		ifs.close();
		return;
	}

	//准备参数接受用户输入的信息
	int id = 0;
	string name;
	string pwd;

	

	if (type == 1) {
		cout << "请输入学生的学号" << endl;
		cin >> id;
	}
	if (type == 2) {
		cout << "请输入教师的职工编号" << endl;

		cin >> id;
	}
	cout << "请输入用户名" << endl;
	cin >> name;

	cout << "请输入密码" << endl;
	cin >> pwd;

	if (type == 1) {
		//准备从文本文件中读取数据
		int fid;
		string fname;
		string fpwd;

		//学生身份验证
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (id == fid && name == fname && pwd == fpwd) {
				cout << "学生身份验证成功" << endl;
				
				system("pause");
				system("cls");

				person = new Student(id, name, pwd);

				//进入学生的子菜单
				studentMenu(person);
				return;

			}
			
		}
	}
	else if (type == 2) {
		//准备从文本文件中读取数据
		int fid;
		string fname;
		string fpwd;

		//教师身份验证
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (id == fid && name == fname && pwd == fpwd) {
				cout << "教师身份验证成功" << endl;
				
				system("pause");
				system("cls");

				person = new Teacher(id, name, pwd);

				//进入教师的子菜单
				TeacherMenu(person);
				return;
			}
			
		}
		
	}
	else if (type == 3) {
		//准备从文本文件中读取数据
		int fid;
		string fname;
		string fpwd;

		//管理员身份验证
		while ( ifs >> fname && ifs >> fpwd) {
			if ( name == fname && pwd == fpwd) {
				cout << "管理员身份验证成功" << endl;
				
				system("pause");
				system("cls");

				person = new Manager( name, pwd);

				//进入管理员的子菜单
				managerMenu(person);

				return;
			}
			
		}
	}
	cout << "身份验证失败" << endl;
	system("pause");
	system("cls");
	return;
}


int main() {
	int select = 0;

	while (true) {

		cout << "============================欢迎来到机房预约系统============================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t------------------------------------------" << endl;
		cout << "\t\t|                                        |" << endl;
		cout << "\t\t|              1.   学生代表             |" << endl;
		cout << "\t\t|              2.   老    师             |" << endl;
		cout << "\t\t|              3.   管 理 员             |" << endl;
		cout << "\t\t|              0.   退    出             |" << endl;
		cout << "\t\t|                                        |" << endl;
		cout << "\t\t------------------------------------------" << endl;
		cout << "请输入您的选择" << endl;
		cin >> select;

		switch (select)
		{
		case 1:  //学生代表
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:   //老师
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:   //管理员
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:   //退出
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误  请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}




	}
	system("pause");
	return 0;
}