#include"teacher.h"


//���캯��
Teacher::Teacher() {

}

//�вι���
Teacher::Teacher(int empid, string name, string pwd) {
	this->m_EmpId = empid;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//�˵�����
void Teacher::operMenu() {
	cout << "��ӭ��ʦ :" << this->m_Name << " ��¼" << endl;
	cout << endl;
	cout << "\t\t------------------------------------------" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|              1. �鿴����ԤԼ           |" << endl;
	cout << "\t\t|              2.   ���ԤԼ             |" << endl;
	cout << "\t\t|              0.   ע����¼             |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t------------------------------------------" << endl;
	cout << "����������ѡ��" << endl;
 }

//�鿴����ԤԼ
void Teacher::showAllOrder() {
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
		else if (of.m_orderData[i]["status"] == "2") {
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

//���ԤԼ
void Teacher::validOeder() {
	OrdeFile of;
	if (of.m_Size == 0) {
		cout << "��¼Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵�ԤԼ��¼����: " << endl;
	vector<int>v;
	int index = 0;
	for (int i = 0; i < of.m_Size; i++) {
		if (of.m_orderData[i]["status"] == "1") {
			v.push_back(i);
			cout << ++index << " . " << endl;
			cout << "ԤԼ����:  ��" << of.m_orderData[i]["data"] << " ";
			cout << "ʱ���: " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << " ";
			cout << "ѧ��: " << of.m_orderData[i]["stuId"] << " ";
			cout << "����: " << of.m_orderData[i]["stuName"] << " ";
			cout << "�������: " << of.m_orderData[i]["room"] << " ";
			string status = "״̬: �����";
			cout << status << endl;
		}
	}
	cout << "������Ҫ��˵�ԤԼ��¼ 0������" << endl;
	int select = 0;//ѡ�������
	int ret = 0;//ѡ��ͨ����ͨ��
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}
			else {
				cout << "��ѡ��ͨ����δͨ��" << endl;
				cout << "1.ͨ��" << endl;
				cout << "2.��ͨ��" << endl;
				cin >> ret;
				if (ret == 1) {
					of.m_orderData[v[select - 1]]["status"] = "2";
				}
				else if (ret == 2)
				{
					of.m_orderData[v[select - 1]]["status"] = "-1";
				}
				of.updateOrder();
				cout << "������" << endl;
				break;
			}

		}
		else {
			cout << "�������� ��������" << endl;
			break;
		}
	}
	system("pause");
	system("cls");
}