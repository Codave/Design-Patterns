////��̬�����
//
//#include<iostream>
//#include<string>
//using namespace std;
//
//class Phone {
//public:
//	virtual void show() = 0;
//};
//
//class IPhone :public Phone {
//public:
//	virtual void show() {
//		cout << "�����IPhone" << endl;
//	}
//};
//
//class Mi :public Phone {
//public:
//	virtual void show() {
//		cout << "�����С��" << endl;
//	}
//};
//
////дһ��װ����,�ۺϰ�ʾ�������ڸ����ϴ��ڱȾֲ����ߵ�һ������
//class Decorator :public Phone{    //װ����Ҳ�Ǽ̳�
//public:
//	Decorator(Phone* phone) {
//		this->phone = phone;
//	}
//	virtual void show() = 0;
//protected:
//	Phone* phone;
//};
//
////������ֻ���Ĥװ����
//class MoDecorator :public Decorator {
//public:
//	MoDecorator(Phone* phone) :Decorator(phone) { }
//	virtual void show() {
//		this->phone->show();
//		this->mo();
//	}
//	//Ĥװ����������������ӵķ���
//	void mo() {
//		cout << "�ֻ�������Ĥ" << endl;
//	}
//};
//
////�����Ƥ��װ����
//class TaoDecorator :public Decorator {
//public:
//	TaoDecorator(Phone* phone) :Decorator(phone) { }
//	virtual void show() {
//		this->phone->show();
//		this->tao();
//	}
//	void tao() {
//		cout << "�ֻ�����Ƥ��" << endl;
//	}
//};
//
//int main() {
//
//	Phone* phone = new IPhone;
//	/*phone->show();
//	cout << "---------------" << endl;*/
//	Phone* mophone = new MoDecorator(phone);
//	/*mophone->show();
//	cout << "---------------" << endl;*/
//	Phone* taophone = new TaoDecorator(phone);
//	//taophone->show();
//	cout << "---------------" << endl;
//	Phone* motaophone = new TaoDecorator(mophone);
//	motaophone->show();
//
//	return 0;
//}