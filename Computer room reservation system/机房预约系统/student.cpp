#include"student.h"
#include"orderFile.h"

//���캯��
Student::Student() {

}

//�вι���
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

//�˵�����
void Student::operMenu() {
	cout << "��ӭѧ�� :" << this->m_Name << " ��¼" << endl;
	cout << endl;
	cout << "\t\t------------------------------------------" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|              1.   ����ԤԼ             |" << endl;
	cout << "\t\t|              2. �鿴�ҵ�ԤԼ           |" << endl;
	cout << "\t\t|              3. �鿴����ԤԼ           |" << endl;
	cout << "\t\t|              4.   ȡ��ԤԼ             |" << endl;
	cout << "\t\t|              0.   ע����¼             |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t------------------------------------------" << endl;
	cout << "����������ѡ��" << endl;
}

//����ԤԼ
void Student::applyOrder() {
	cout << "�������ŵ�ʱ��Ϊ��һ������" << endl;
	cout << "������ԤԼ��ʱ��" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;

	int data = 0;
	int interval = 0;
	int room = 0;

	while (true) {
		cin >> data;
		if (data >= 1 && data <= 5) {
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "��ѡ��ԤԼ��ʱ���" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
	
	while (true) {
		cin >> interval;
		if (interval >= 1 && interval <= 2) {
			break;
		}
		cout << "������������������" << endl;
	}
	cout << "��ѡ�����" << endl;
	cout << "1. 1�Ż���  ��������" << v_Com[0].m_MaxNum << endl;
	cout << "2. 2�Ż���  ��������" << v_Com[1].m_MaxNum << endl;
	cout << "3. 3�Ż���  ��������" << v_Com[2].m_MaxNum << endl;
	
	while (true) {
		cin >> room;
		if (room >= 1 && room <= 3) {
			break;
		}
		cout << "������������������" << endl;
	}
	cout << "ԤԼ�ɹ�! �����" << endl;

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

//�鿴����ԤԼ
void Student::showMyOrder() {
	OrdeFile of;
	if (of.m_Size == 0) {
		cout << "ԤԼ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++) {

		//string ת int
		//string ���� .c_str() תΪ const char *
		//������ atoi( const char * ) תΪ int
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str())) {
			cout << "ԤԼ����:  ��" << of.m_orderData[i]["data"];
			cout << " ʱ���: " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << " ������: " << of.m_orderData[i]["room"];
			string status = "״̬: ";

			//1.�����   2 ��ԤԼ  -1 ԤԼʧ��    0 ȡ��
			if (of.m_orderData[i]["status"] == "1") {
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2") {
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_orderData[i]["status"] == "-1") {
				status += "ԤԼʧ��";
			}
			else {
				status += "ԤԼȡ��";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::showAllOrder() {
	OrdeFile of;
	if (of.m_Size == 0) {
		cout << "��¼Ϊ��" << endl;
		system("Pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++) {
		cout << "��" << i + 1 << "����������: " << endl;
		cout << "ԤԼ����:  ��" << of.m_orderData[i]["data"] << " ";
		cout << "ʱ���: " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << " ";
		cout << "ѧ��: " << of.m_orderData[i]["stuId"] << " ";
		cout << "����: " << of.m_orderData[i]["stuName"] << " ";
		cout << "�������: " << of.m_orderData[i]["room"] << " ";
		string status = "���״̬: ";
		if (of.m_orderData[i]["status"] == "1") {
			status += "�����!";
		}
		else if(of.m_orderData[i]["status"]=="2") {
			status += "ԤԼ�ɹ�!";
		}
		else if (of.m_orderData[i]["status"] == "-1") {
			status += "ԤԼʧ��!";
		}
		else {
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");

}

// ȡ��ԤԼ
void Student::cencalOrder() {
	OrdeFile of;
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "ȡ������ֻ������˳ɹ���������еļ�¼" << endl;
	int index = 1;
	vector<int> v;
	for (int i = 0; i < of.m_Size; i++) {
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str())) {
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2") {
				v.push_back(i);
				cout << "��" << index << "����Ϣ: " << endl;
				cout << "ԤԼ����:  ��" << of.m_orderData[i]["data"] << " ";
				cout << "ʱ���: " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << " ";
				cout << "�������: " << of.m_orderData[i]["room"] << " ";
				string status = "���״̬: ";
				if (of.m_orderData[i]["status"] == "1") {
					status += "�����";
				}
				else if (of.m_orderData[i]["status"] == "2") {
					status += "��˳ɹ�";
				}
				cout << status << endl;
				index++;
			}
		}
	}
	int select = 0;
	cout << "������Ҫȡ�����ļ�¼,0������" << endl;

	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}
			else {
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.updateOrder();  // ȷ�������ļ�

				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}
		else {
			cout << "�������� ����������" << endl;
		}
	}
	system("pause");
	system("cls");
}