#include"manager.h"
#include"globalFile.h"

//Ĭ�Ϲ���
Manager::Manager() {

}

//�вι���
Manager::Manager(string name, string pwd) {
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ������  ���һ�ȡ���ļ���ѧ������ʦ����Ϣ
	this->initVector();


	//��ʼ����������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;

	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum) {
		v_Com.push_back(com);
	}

	ifs.close();
}

//��ʾ�˵�
void Manager::operMenu() {
	cout << "��ӭ����Ա :" << this->m_Name << "��¼" << endl;
	cout << endl;
	cout << "\t\t------------------------------------------" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t|              1.   ����˺�             |" << endl;
	cout << "\t\t|              2.   ��ʾ�˺�             |" << endl;
	cout << "\t\t|              3. �鿴������Ϣ           |" << endl;
	cout << "\t\t|              4.   ȡ��ԤԼ             |" << endl;
	cout << "\t\t|              0.   ע����¼             |" << endl;
	cout << "\t\t|                                        |" << endl;
	cout << "\t\t------------------------------------------" << endl;
	cout << "����������ѡ��" << endl;
	
 }

//����ظ��˺�
bool Manager::checkRepeat(int id,int type) {
	if (type == 1) {
		//���ѧ��
		for (vector<Student>::iterator it = v_Stu.begin(); it != v_Stu.end(); it++) {
			if (id == it->m_Id) {
				return true;
			}
		}
	}
	else
	{
		//�����ʦ
		for (vector<Teacher>::iterator it = v_Tea.begin(); it != v_Tea.end(); it++) {
			if (id == it->m_EmpId) {
				return true;
			}
		}
	}
	return false;
}

//����˺�
void Manager::addPerson() {
	cout << "���������ѡ��" << endl;
	cout << "1.ѧ��" << endl;
	cout << "2.��ʦ" << endl;
	int select = 0;
	cin >> select;
	string fileName;
	string tip;
	string errorTip;
	while(true) {
		if (select == 1) {
			fileName = STUDENT_FILE;
			tip = "������ѧ����ѧ��";
			errorTip = "�ļ������ظ���ѧ�� ����������";
			break;
		}
		else if (select == 2) {
			fileName = TEACHER_FILE;
			tip = "�������ʦ��ְ�����";
			errorTip = "�ļ������ظ���ְ����� ����������";
			break;
		}
		else {
			cout << "������� ����������" << endl;
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
	
	cout << "��������" << endl;
	cin >> name;
	cout << "��������" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << endl;
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");

	ofs.close();

	//��ʼ������
	this->initVector();
}
//��ʼ������
void Manager::initVector(){
	//ȷ�������ǿյ�
	v_Stu.clear();
	v_Tea.clear();

	//��ȡѧ����Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
		v_Stu.push_back(s);
	}
	//cout << "��ǰѧ������ = " << v_Stu.size() << endl;
	ifs.close();

	//��ȡ��ʦ��Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd) {
		v_Tea.push_back(t);
	}
	//cout << "��ǰ��ʦ������ = " << v_Tea.size() << endl;
	ifs.close();
}

//��ӡѧ��
void printStudent(Student& s) {
	cout << "ѧ�� : " << s.m_Id << " ���� : " << s.m_Name << "  ���� : " << s.m_Pwd << endl;
}

//��ӡ��ʦ
void printTeacher(Teacher& t) {
	cout << "ְ����� : " << t.m_EmpId << " ���� : " << t.m_Name << "  ���� : " << t.m_Pwd << endl;
}



//��ʾ�˺�
void Manager::showPerson() {
	int select = 0;

	cout << "ѡ��Ҫ�鿴����Ϣ" << endl;
	cout << "1.ѧ���˺�" << endl;
	cout << "2.��ʦ�˺�" << endl;
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

//�鿴������Ϣ
void Manager::showCompture() {

	cout << "������Ϣ����" << endl;

	for (vector<ComputerRoom>::iterator it = v_Com.begin(); it != v_Com.end(); it++) {

		cout << "������� : " << it->m_ComId << " ������������ : " << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//ȡ��ԤԼ
void Manager::cleanFile() {

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc);
	ofs.close();
	cout << "��ճɹ�" << endl;

	system("pause");
	system("cls");
}