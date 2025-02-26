#include"manager.h"
#include"globalFile.h"

//默认构造
Manager::Manager() {

}

//有参构造
Manager::Manager(string name, string pwd) {
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化容器  并且获取到文件中学生和老师的信息
	this->initVector();


	//初始化机房的信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;

	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum) {
		v_Com.push_back(com);
	}

	ifs.close();
}

//显示菜单
void Manager::operMenu() {
	cout << "欢迎管理员 :" << this->m_Name << "登录" << endl;
	cout << endl;
	cout << "\t\t------------------------------------------" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|              1.   添加账号             |" << endl;
	cout << "\t\t|              2.   显示账号             |" << endl;
	cout << "\t\t|              3. 查看机房信息           |" << endl;
	cout << "\t\t|              4.   取消预约             |" << endl;
	cout << "\t\t|              0.   注销登录             |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t------------------------------------------" << endl;
	cout << "请输入您的选择" << endl;
	
 }

//检测重复账号
bool Manager::checkRepeat(int id,int type) {
	if (type == 1) {
		//检测学生
		for (vector<Student>::iterator it = v_Stu.begin(); it != v_Stu.end(); it++) {
			if (id == it->m_Id) {
				return true;
			}
		}
	}
	else
	{
		//检测老师
		for (vector<Teacher>::iterator it = v_Tea.begin(); it != v_Tea.end(); it++) {
			if (id == it->m_EmpId) {
				return true;
			}
		}
	}
	return false;
}

//添加账号
void Manager::addPerson() {
	cout << "请输入你的选择" << endl;
	cout << "1.学生" << endl;
	cout << "2.教师" << endl;
	int select = 0;
	cin >> select;
	string fileName;
	string tip;
	string errorTip;
	while(true) {
		if (select == 1) {
			fileName = STUDENT_FILE;
			tip = "请输入学生的学号";
			errorTip = "文件中有重复的学号 请重新输入";
			break;
		}
		else if (select == 2) {
			fileName = TEACHER_FILE;
			tip = "请输入教师的职工编号";
			errorTip = "文件中有重复的职工编号 请重新输入";
			break;
		}
		else {
			cout << "输入错误 请重新输入" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	ofstream ofs(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	while (true) {
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret) {
			cout << errorTip << endl;
		}
		else
		{
			break;
		}

	}
	
	cout << "输入姓名" << endl;
	cin >> name;
	cout << "输入密码" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << endl;
	cout << "添加成功" << endl;
	system("pause");
	system("cls");

	ofs.close();

	//初始化容器
	this->initVector();
}
//初始化容器
void Manager::initVector(){
	//确定容器是空的
	v_Stu.clear();
	v_Tea.clear();

	//读取学生信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}
	
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
		v_Stu.push_back(s);
	}
	//cout << "当前学生数量 = " << v_Stu.size() << endl;
	ifs.close();

	//读取老师信息
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd) {
		v_Tea.push_back(t);
	}
	//cout << "当前老师的数量 = " << v_Tea.size() << endl;
	ifs.close();
}

//打印学生
void printStudent(Student& s) {
	cout << "学号 : " << s.m_Id << " 姓名 : " << s.m_Name << "  密码 : " << s.m_Pwd << endl;
}

//打印老师
void printTeacher(Teacher& t) {
	cout << "职工编号 : " << t.m_EmpId << " 姓名 : " << t.m_Name << "  密码 : " << t.m_Pwd << endl;
}



//显示账号
void Manager::showPerson() {
	int select = 0;

	cout << "选择要查看的信息" << endl;
	cout << "1.学生账号" << endl;
	cout << "2.老师账号" << endl;
	cin >> select;
	if (select == 1) {
		for_each(v_Stu.begin(), v_Stu.end(), printStudent);
		cout << endl;
	}
	else
	{
		for_each(v_Tea.begin(), v_Tea.end(), printTeacher);
		cout << endl;
	}
	system("pause");
	system("cls");
}

//查看机房信息
void Manager::showCompture() {

	cout << "机房信息如下" << endl;

	for (vector<ComputerRoom>::iterator it = v_Com.begin(); it != v_Com.end(); it++) {

		cout << "机房编号 : " << it->m_ComId << " 机房电脑数量 : " << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//取消预约
void Manager::cleanFile() {

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc);
	ofs.close();
	cout << "清空成功" << endl;

	system("pause");
	system("cls");
}