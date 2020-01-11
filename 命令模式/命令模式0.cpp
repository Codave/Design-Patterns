//#include<iostream>
//using namespace std;
//
////系统的一个核心类模块
//class Doctor {
//public:
//	//治疗眼睛的方法
//	void treatEyes() {
//		cout << "医生治疗了眼睛" << endl;
//	}
//	//治疗眼睛的方法
//	void treatNose() {
//		cout << "医生治疗了鼻子" << endl;
//	}
//};
//
////治疗眼睛的病单
//class CommandEyes {
//public:
//	CommandEyes(Doctor* doctor) {
//		this->doctor = doctor;
//	}
//	~CommandEyes() {
//		if (this->doctor != NULL) {
//			delete this->doctor;
//			this->doctor = NULL;
//		}
//	}
//	//病单执行治疗的时候，实际上让医生治疗
//	void treat() {
//		doctor->treatEyes();
//	}
//private:
//	Doctor* doctor;
//};
//
////治疗鼻子的病单
//class CommandNose {
//public:
//	CommandNose(Doctor* doctor) {
//		this->doctor = doctor;
//	}
//	~CommandNose() {
//		if (this->doctor != NULL) {
//			delete this->doctor;
//			this->doctor = NULL;
//		}
//	}
//	//病单执行治疗的时候，实际上让医生治疗
//	void treat() {
//		doctor->treatNose();
//	}
//private:
//	Doctor* doctor;
//};
//
////病人
//int main() {
//
//	/*Doctor* doctor = new Doctor;
//	doctor->treatEyes();
//	doctor->treatNose();*/
//
//	CommandEyes* cmdeyes = new CommandEyes(new Doctor);
//	cmdeyes->treat();
//
//	CommandNose* cmdnose = new CommandNose(new Doctor);
//	cmdnose->treat();
//
//	return 0;
//}