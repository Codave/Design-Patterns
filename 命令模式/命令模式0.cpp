//#include<iostream>
//using namespace std;
//
////ϵͳ��һ��������ģ��
//class Doctor {
//public:
//	//�����۾��ķ���
//	void treatEyes() {
//		cout << "ҽ���������۾�" << endl;
//	}
//	//�����۾��ķ���
//	void treatNose() {
//		cout << "ҽ�������˱���" << endl;
//	}
//};
//
////�����۾��Ĳ���
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
//	//����ִ�����Ƶ�ʱ��ʵ������ҽ������
//	void treat() {
//		doctor->treatEyes();
//	}
//private:
//	Doctor* doctor;
//};
//
////���Ʊ��ӵĲ���
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
//	//����ִ�����Ƶ�ʱ��ʵ������ҽ������
//	void treat() {
//		doctor->treatNose();
//	}
//private:
//	Doctor* doctor;
//};
//
////����
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