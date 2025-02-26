#include<iostream>
using namespace std;
#include<string>
#include<fstream>
#include"identity.h"
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"

//��ʦ���Ӳ˵�
void TeacherMenu(Identity*& teacher) {
	while (true) {
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		if (select == 1) {
			//��ʾ����ԤԼ
			tea->showAllOrder();
		}
		else if (select == 2) {
			//���ԤԼ
			tea->validOeder();
		}
		else {
			cout << "ע���ɹ�" << endl;
			delete teacher;
			system("pause");
			system("cls");
			return;
		}
	}
}

//ѧ�����Ӳ˵�
void studentMenu(Identity* & student) {
	while (true) {
		//����ѧ�����Ӳ˵�
		student->operMenu();

		//�������ָ��תΪ�����ָ��
		Student* stu = (Student*)student;

		int select = 0;

		cin >> select;
		if (select == 1) {
			//����ԤԼ
			stu->applyOrder();
		}
		else if (select == 2) {
			//�鿴�ҵ�ԤԼ
			stu->showMyOrder();
		}
		else if (select == 3) {
			//�鿴����ԤԼ
			stu->showAllOrder();
		}
		else if (select == 4) {
			//ȡ��ԤԼ
			stu->cencalOrder();
		}
		else {
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//����Ա���Ӳ˵�
void managerMenu(Identity* & manager) {
	while (true) {
		//���ù���Ա���Ӳ˵�
		manager->operMenu();

		//�������ָ��ǿתΪ�����ָ��  ���Ե�������Ķ�������
		Manager* man = (Manager*)manager;

		int select = 0;
		//�����û���ѡ��
		cin >> select;

		if (select == 1) {

			//����˺�
			//cout << "����˺�" << endl;

			man->addPerson();
		}
		else if (select == 2) {

			//�鿴�˺�
			

			//cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3) {

			//�鿴������Ϣ
			
			//cout << "�鿴������Ϣ" << endl;
			man->showCompture();
		}
		else if (select == 4) {

			//���ԤԼ
			

			//cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else {
			delete manager;//���ٵ���������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;

		}
	}



}


//��¼ҳ��     ����1 �������ļ���   ����2  ������ݵ�����
void LoginIn(string fileName, int type) {

	//�����ָ��ָ������Ķ���
	Identity* person = NULL;


	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
		ifs.close();
		return;
	}

	//׼�����������û��������Ϣ
	int id = 0;
	string name;
	string pwd;

	

	if (type == 1) {
		cout << "������ѧ����ѧ��" << endl;
		cin >> id;
	}
	if (type == 2) {
		cout << "�������ʦ��ְ�����" << endl;

		cin >> id;
	}
	cout << "�������û���" << endl;
	cin >> name;

	cout << "����������" << endl;
	cin >> pwd;

	if (type == 1) {
		//׼�����ı��ļ��ж�ȡ����
		int fid;
		string fname;
		string fpwd;

		//ѧ�������֤
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (id == fid && name == fname && pwd == fpwd) {
				cout << "ѧ�������֤�ɹ�" << endl;
				
				system("pause");
				system("cls");

				person = new Student(id, name, pwd);

				//����ѧ�����Ӳ˵�
				studentMenu(person);
				return;

			}
			
		}
	}
	else if (type == 2) {
		//׼�����ı��ļ��ж�ȡ����
		int fid;
		string fname;
		string fpwd;

		//��ʦ�����֤
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (id == fid && name == fname && pwd == fpwd) {
				cout << "��ʦ�����֤�ɹ�" << endl;
				
				system("pause");
				system("cls");

				person = new Teacher(id, name, pwd);

				//�����ʦ���Ӳ˵�
				TeacherMenu(person);
				return;
			}
			
		}
		
	}
	else if (type == 3) {
		//׼�����ı��ļ��ж�ȡ����
		int fid;
		string fname;
		string fpwd;

		//����Ա�����֤
		while ( ifs >> fname && ifs >> fpwd) {
			if ( name == fname && pwd == fpwd) {
				cout << "����Ա�����֤�ɹ�" << endl;
				
				system("pause");
				system("cls");

				person = new Manager( name, pwd);

				//�������Ա���Ӳ˵�
				managerMenu(person);

				return;
			}
			
		}
	}
	cout << "�����֤ʧ��" << endl;
	system("pause");
	system("cls");
	return;
}


int main() {
	int select = 0;

	while (true) {

		cout << "============================��ӭ��������ԤԼϵͳ============================" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t------------------------------------------" << endl;
		cout << "\t\t|                                        |" << endl;
		cout << "\t\t|              1.   ѧ������             |" << endl;
		cout << "\t\t|              2.   ��    ʦ             |" << endl;
		cout << "\t\t|              3.   �� �� Ա             |" << endl;
		cout << "\t\t|              0.   ��    ��             |" << endl;
		cout << "\t\t|                                        |" << endl;
		cout << "\t\t------------------------------------------" << endl;
		cout << "����������ѡ��" << endl;
		cin >> select;

		switch (select)
		{
		case 1:  //ѧ������
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:   //��ʦ
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:   //����Ա
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:   //�˳�
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������  ����������" << endl;
			system("pause");
			system("cls");
			break;
		}




	}
	system("pause");
	return 0;
}