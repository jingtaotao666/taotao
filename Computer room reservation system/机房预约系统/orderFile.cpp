#include"orderFile.h"

//构造函数
OrdeFile::OrdeFile() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string data;
	string interval;
	string stuId;
	string stuName;
	string room;
	string status;

	this->m_Size = 0;

	while (ifs >> data && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> room && ifs >> status) {
		/*cout << data << endl;
		cout << interval << endl;
		cout << stuId << endl;
		cout << stuName << endl;
		cout << room << endl;
		cout << status << endl;*/

		string key;
		string value;
		map<string, string>m;

		//截取时间
		int pos = data.find(":");
		if (pos != -1) {
			key = data.substr(0, pos);
			value = data.substr(pos + 1, data.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		//截取时间段
		pos = interval.find(":");
		if (pos != -1) {
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		//截取学号
		pos = stuId.find(":");
		if (pos != -1) {
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		//截取姓名
		pos = stuName.find(":");
		if (pos != -1) {
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		//截取机房
		pos = room.find(":");
		if (pos != -1) {
			key = room.substr(0, pos);
			value = room.substr(pos + 1, room.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		//截取审核状态
		pos = status.find(":");
		if (pos != -1) {
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		//将小map容器装入大map容器
		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}
	ifs.close();

	//测试
	/*for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++) {
		cout << "条数 = " << it->first << " value = " << endl;
		for (map<string, string>::iterator dit = it->second.begin(); dit != it->second.end(); dit++) {
			cout << "key = " << dit->first << " value = " << dit->second << endl;
		}
		cout << endl;
	}*/

}

// 更新预约记录
void OrdeFile::updateOrder() {
	if (this->m_Size == 0) {
		return;
	}
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);

	for (int i = 0; i < this->m_Size; i++) {
		ofs << "data:" << this->m_orderData[i]["data"] << " "
			<< "interval:" << this->m_orderData[i]["interval"] << " "
			<< "stuId:" << this->m_orderData[i]["stuId"] << " "
			<< "stuName:" << this->m_orderData[i]["stuName"] << " "
			<< "room:" << this->m_orderData[i]["room"] << " "
			<< "status:" << this->m_orderData[i]["status"] << endl;
	}
	ofs.close();
}
