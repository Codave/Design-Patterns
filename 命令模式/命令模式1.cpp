#include<iostream>
#include<list>
using namespace std;

//ϵͳ��һ��������ģ��
class Doctor {
public:
	//�����۾��ķ���
	void treatEyes() {
		cout << "ҽ���������۾�" << endl;
	}
	//�����۾��ķ���
	void treatNose() {
		cout << "ҽ�������˱���" << endl;
	}
};

//����һ������Ĳ���
class Command {
public:
	Command(Doctor* doctor) {
		this->doctor = doctor;
	}
	~Command() {
		if (this->doctor != NULL) {
			delete this->doctor;
			this->doctor = NULL;
		}
	}
	//����ִ�����Ƶ�ʱ��ʵ������ҽ������
	virtual void treat() = 0;
private:
	Doctor* doctor;
};

//�����۾��Ĳ���
class CommandEyes :public Command{
public:
	CommandEyes(Doctor* doctor) :Command(doctor) { }
	//����ִ�����Ƶ�ʱ��ʵ������ҽ������
	virtual void treat() {
		doctor->treatEyes();
	}
private:
	Doctor* doctor;
};

//���Ʊ��ӵĲ���
class CommandNose :public Command{
public:
	CommandNose(Doctor* doctor) :Command(doctor) { }
	//����ִ�����Ƶ�ʱ��ʵ������ҽ������
	virtual void treat() {
		doctor->treatNose();
	}
private:
	Doctor* doctor;
};

////��ʿ��
//class Nurse {
//public:
//	Nurse(Command* cmd) {
//		this->cmd = cmd;
//	}
//	~Nurse() {
//		if (this->cmd != cmd) {
//			delete this->cmd;
//		}
//	}
//	//�·������ķ���
//	void notify() {
//		this->cmd->treat();
//	}
//private:
//	Command* cmd;
//};

//��ʿ����
class NurseBoss {
public:
	NurseBoss() {
		m_list.clear();
	}
	~NurseBoss() {
		m_list.clear();
	}
	//��ʿ����Ӳ����ķ���
	void setCmd(Command* cmd) {
		this->m_list.push_back(cmd);
	}
	//�·��������в�����ָ��
	void notify() {
		for (list<Command*>::iterator iter = m_list.begin(); iter != m_list.end(); iter++) {
			(*iter)->treat();
		}
	}

private:
	list<Command*> m_list;
};

//����
int main() {

	/*Nurse* nurse = new Nurse(new CommandEyes(new Doctor));
	nurse->notify();
	Nurse* nurse2 = new Nurse(new CommandNose(new Doctor));
	nurse2->notify();*/

	NurseBoss* woman = new NurseBoss;
	Command* cmd1 = new CommandEyes(new Doctor);
	Command* cmd2 = new CommandNose(new Doctor);

	woman->setCmd(cmd1);
	woman->setCmd(cmd2);

	woman->notify();

	return 0;
}