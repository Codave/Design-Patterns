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
//		cout << "我是美国的苹果" << endl;
//	}
//};
//
//class USABanana :public Fruit {
//public:
//	virtual void getName() {
//		cout << "我是美国的香蕉" << endl;
//	}
//};
//
//class ChinaApple :public Fruit {
//public:
//	virtual void getName() {
//		cout << "我是中国的苹果" << endl;
//	}
//};
//
//class ChinaBanana :public Fruit {
//public:
//	virtual void getName() {
//		cout << "我是中国的香蕉" << endl;
//	}
//};
//
////定义一个抽象的工厂，面向产品进行生产
//class AbstractFactory {
//public:
//	virtual Fruit* createApple() = 0;
//	virtual Fruit* createBanana() = 0;
//};
//
////美国的具体工厂
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
////中国的具体工厂
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