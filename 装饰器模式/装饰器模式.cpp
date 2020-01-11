////动态的添加
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
//		cout << "秀出了IPhone" << endl;
//	}
//};
//
//class Mi :public Phone {
//public:
//	virtual void show() {
//		cout << "秀出了小米" << endl;
//	}
//};
//
////写一个装饰器,聚合暗示着整体在概念上处于比局部更高的一个级别
//class Decorator :public Phone{    //装饰器也是继承
//public:
//	Decorator(Phone* phone) {
//		this->phone = phone;
//	}
//	virtual void show() = 0;
//protected:
//	Phone* phone;
//};
//
////具体的手机贴膜装饰器
//class MoDecorator :public Decorator {
//public:
//	MoDecorator(Phone* phone) :Decorator(phone) { }
//	virtual void show() {
//		this->phone->show();
//		this->mo();
//	}
//	//膜装饰器，可以修饰添加的方法
//	void mo() {
//		cout << "手机有了贴膜" << endl;
//	}
//};
//
////具体的皮套装饰器
//class TaoDecorator :public Decorator {
//public:
//	TaoDecorator(Phone* phone) :Decorator(phone) { }
//	virtual void show() {
//		this->phone->show();
//		this->tao();
//	}
//	void tao() {
//		cout << "手机有了皮套" << endl;
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