//#include<iostream>
//using namespace std;
//
//class Fruit {
//public:
//	virtual void getName() = 0;
//};
//
//class USAApple :public Fruit {
//public:
//	virtual void getName() {
//		cout << "����������ƻ��" << endl;
//	}
//};
//
//class USABanana :public Fruit {
//public:
//	virtual void getName() {
//		cout << "�����������㽶" << endl;
//	}
//};
//
//class ChinaApple :public Fruit {
//public:
//	virtual void getName() {
//		cout << "�����й���ƻ��" << endl;
//	}
//};
//
//class ChinaBanana :public Fruit {
//public:
//	virtual void getName() {
//		cout << "�����й����㽶" << endl;
//	}
//};
//
////����һ������Ĺ����������Ʒ��������
//class AbstractFactory {
//public:
//	virtual Fruit* createApple() = 0;
//	virtual Fruit* createBanana() = 0;
//};
//
////�����ľ��幤��
//class USAFactory :public AbstractFactory {
//public:
//	virtual Fruit* createApple() {
//		return new USAApple;
//	}
//	virtual Fruit* createBanana() {
//		return new USABanana;
//	}
//};
//
////�й��ľ��幤��
//class ChinaFactory :public AbstractFactory {
//public:
//	virtual Fruit* createApple() {
//		return new ChinaApple;
//	}
//	virtual Fruit* createBanana() {
//		return new ChinaBanana;
//	}
//};
//
//int main() {
//
//	AbstractFactory* chinaFactory = new ChinaFactory;
//	Fruit* chinaApple = chinaFactory->createApple();
//	chinaApple->getName();
//
//	return 0;
//}