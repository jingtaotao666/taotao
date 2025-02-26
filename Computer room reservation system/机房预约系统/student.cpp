#include"student.h"
#include"orderFile.h"

//构造函数
Student::Student() {

}

//有参构造
Student::Student(int id, string name, string pwd) {
	this->m_Name = name;
	this->m_Id = id;
	this->m_Pwd = pwd;

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;

	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum) {
		v_Com.push_back(com);
	}
	ifs.close();

}

//菜单界面
void Student::operMenu() {
	cout << "欢迎学生 :" << this->m_Name << " 登录" << endl;
	cout << endl;
	cout << "\t\t------------------------------------------" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|              1.   申请预约             |" << endl;
	cout << "\t\t|              2. 查看我的预约           |" << endl;
	cout << "\t\t|              3. 查看所有预约           |" << endl;
	cout << "\t\t|              4.   取消预约             |" << endl;
	cout << "\t\t|              0.   注销登录             |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t------------------------------------------" << endl;
	cout << "请输入您的选择" << endl;
}

//申请预约
void Student::applyOrder() {
	cout << "机房开放的时间为周一至周五" << endl;
	cout << "请输入预约的时间" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;

	int data = 0;
	int interval = 0;
	int room = 0;

	while (true) {
		cin >> data;
		if (data >= 1 && data <= 5) {
			break;
		}
		cout << "输入有误请重新输入" << endl;
	}

	cout << "请选择预约的时间段" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	
	while (true) {
		cin >> interval;
		if (interval >= 1 && interval <= 2) {
			break;
		}
		cout << "输入有误请重新输入" << endl;
	}
	cout << "请选择机房" << endl;
	cout << "1. 1号机房  电脑数量" << v_Com[0].m_MaxNum << endl;
	cout << "2. 2号机房  电脑数量" << v_Com[1].m_MaxNum << endl;
	cout << "3. 3号机房  电脑数量" << v_Com[2].m_MaxNum << endl;
	
	while (true) {
		cin >> room;
		if (room >= 1 && room <= 3) {
			break;
		}
		cout << "输入有误请重新输入" << endl;
	}
	cout << "预约成功! 审核中" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::app);
	ofs << "data:" << data <<" "
		<<"interval:" << interval << " "
		<< "room:" << room << " "
		<< "stuId:" << this->m_Id << " "
		<< "stuName:" << this->m_Name << " "
		<<"status:"<< 1 << endl;
	ofs.close();
	system("pause");
	system("cls");
}

//查看自身预约
void Student::showMyOrder() {
	OrdeFile of;
	if (of.m_Size == 0) {
		cout << "预约记录为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++) {

		//string 转 int
		//string 利用 .c_str() 转为 const char *
		//再利用 atoi( const char * ) 转为 int
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str())) {
			cout << "预约日期:  周" << of.m_orderData[i]["data"];
			cout << " 时间段: " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房号: " << of.m_orderData[i]["room"];
			string status = "状态: ";

			//1.审核中   2 已预约  -1 预约失败    0 取消
			if (of.m_orderData[i]["status"] == "1") {
				status += "审核中";
			}
			else if (of.m_orderData[i]["status"] == "2") {
				status += "预约成功";
			}
			else if (of.m_orderData[i]["status"] == "-1") {
				status += "预约失败";
			}
			else {
				status += "预约取消";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}

//查看所有预约
void Student::showAllOrder() {
	OrdeFile of;
	if (of.m_Size == 0) {
		cout << "记录为空" << endl;
		system("Pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++) {
		cout << "第" << i + 1 << "条数据如下: " << endl;
		cout << "预约日期:  周" << of.m_orderData[i]["data"] << " ";
		cout << "时间段: " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
		cout << "学号: " << of.m_orderData[i]["stuId"] << " ";
		cout << "姓名: " << of.m_orderData[i]["stuName"] << " ";
		cout << "机房编号: " << of.m_orderData[i]["room"] << " ";
		string status = "审核状态: ";
		if (of.m_orderData[i]["status"] == "1") {
			status += "审核中!";
		}
		else if(of.m_orderData[i]["status"]=="2") {
			status += "预约成功!";
		}
		else if (of.m_orderData[i]["status"] == "-1") {
			status += "预约失败!";
		}
		else {
			status += "预约已取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");

}

// 取消预约
void Student::cencalOrder() {
	OrdeFile of;
	if (of.m_Size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "取消掉的只能是审核成功或者审核中的记录" << endl;
	int index = 1;
	vector<int> v;
	for (int i = 0; i < of.m_Size; i++) {
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str())) {
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2") {
				v.push_back(i);
				cout << "第" << index << "条信息: " << endl;
				cout << "预约日期:  周" << of.m_orderData[i]["data"] << " ";
				cout << "时间段: " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
				cout << "机房编号: " << of.m_orderData[i]["room"] << " ";
				string status = "审核状态: ";
				if (of.m_orderData[i]["status"] == "1") {
					status += "审核中";
				}
				else if (of.m_orderData[i]["status"] == "2") {
					status += "审核成功";
				}
				cout << status << endl;
				index++;
			}
		}
	}
	int select = 0;
	cout << "请输入要取消掉的记录,0代表返回" << endl;

	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}
			else {
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.updateOrder();  // 确保更新文件

				cout << "已取消预约" << endl;
				break;
			}
		}
		else {
			cout << "输入有误 请重新输入" << endl;
		}
	}
	system("pause");
	system("cls");
}