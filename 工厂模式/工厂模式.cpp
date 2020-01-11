#include<iostream>
using namespace std;

//抽象的水果类
class Fruit {
public:
	virtual void getName() = 0;
};

class Apple :public Fruit {
public:
	virtual void getName() {
		cout << "我是苹果" << endl;
	}
};

class Banana :public Fruit {
public:
	virtual void getName() {
		cout << "我是香蕉" << endl;
	}
};

//添加一个梨
class Pear :public Fruit {
public:
	virtual void getName() {
		cout << "我是鸭梨" << endl;
	}
};


//抽象的工厂类
class AbstractFactory {
public:
	//抽象的水果生产器
	virtual Fruit* createFruit() = 0; 
};

//抽象的苹果工厂
class AppleFactory : public AbstractFactory {
public:
	virtual Fruit* createFruit() {
		return new Apple;
	}
};

//抽象的香蕉工厂
class BananaFactory :public AbstractFactory {
public:
	virtual Fruit* createFruit() {
		return new Banana;
	}
};

//抽象的鸭梨工厂
class PearFactory :public AbstractFactory {
public:
	virtual Fruit* createFruit() {
		return new Pear;
	}
};

int main() {
	
	//给我来一个香蕉的工厂
	AbstractFactory* bananaFactory = new BananaFactory;
	//给我来一个水果
	Fruit* banana = bananaFactory->createFruit();
	banana->getName();

	delete bananaFactory;
	delete banana;

	AbstractFactory* appleFactory = new AppleFactory;
	Fruit* apple = appleFactory->createFruit();
	apple->getName();

	AbstractFactory* pearFactory = new PearFactory;
	Fruit* pear = pearFactory->createFruit();
	pear->getName();

	return 0;
}