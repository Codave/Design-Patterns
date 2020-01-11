#include<iostream>
#include<list>
using namespace std;

//系统的一个核心类模块
class Doctor {
public:
	//治疗眼睛的方法
	void treatEyes() {
		cout << "医生治疗了眼睛" << endl;
	}
	//治疗眼睛的方法
	void treatNose() {
		cout << "医生治疗了鼻子" << endl;
	}
};

//定义一个抽象的病单
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
	//病单执行治疗的时候，实际上让医生治疗
	virtual void treat() = 0;
private:
	Doctor* doctor;
};

//治疗眼睛的病单
class CommandEyes :public Command{
public:
	CommandEyes(Doctor* doctor) :Command(doctor) { }
	//病单执行治疗的时候，实际上让医生治疗
	virtual void treat() {
		doctor->treatEyes();
	}
private:
	Doctor* doctor;
};

//治疗鼻子的病单
class CommandNose :public Command{
public:
	CommandNose(Doctor* doctor) :Command(doctor) { }
	//病单执行治疗的时候，实际上让医生治疗
	virtual void treat() {
		doctor->treatNose();
	}
private:
	Doctor* doctor;
};

////护士类
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
//	//下发病单的方法
//	void notify() {
//		this->cmd->treat();
//	}
//private:
//	Command* cmd;
//};

//护士长类
class NurseBoss {
public:
	NurseBoss() {
		m_list.clear();
	}
	~NurseBoss() {
		m_list.clear();
	}
	//护士长添加病单的方法
	void setCmd(Command* cmd) {
		this->m_list.push_back(cmd);
	}
	//下发手里所有病单的指令
	void notify() {
		for (list<Command*>::iterator iter = m_list.begin(); iter != m_list.end(); iter++) {
			(*iter)->treat();
		}
	}

private:
	list<Command*> m_list;
};

//病人
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