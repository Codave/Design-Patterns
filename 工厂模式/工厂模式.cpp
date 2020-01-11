#include<iostream>
using namespace std;

//�����ˮ����
class Fruit {
public:
	virtual void getName() = 0;
};

class Apple :public Fruit {
public:
	virtual void getName() {
		cout << "����ƻ��" << endl;
	}
};

class Banana :public Fruit {
public:
	virtual void getName() {
		cout << "�����㽶" << endl;
	}
};

//���һ����
class Pear :public Fruit {
public:
	virtual void getName() {
		cout << "����Ѽ��" << endl;
	}
};


//����Ĺ�����
class AbstractFactory {
public:
	//�����ˮ��������
	virtual Fruit* createFruit() = 0; 
};

//�����ƻ������
class AppleFactory : public AbstractFactory {
public:
	virtual Fruit* createFruit() {
		return new Apple;
	}
};

//������㽶����
class BananaFactory :public AbstractFactory {
public:
	virtual Fruit* createFruit() {
		return new Banana;
	}
};

//�����Ѽ�湤��
class PearFactory :public AbstractFactory {
public:
	virtual Fruit* createFruit() {
		return new Pear;
	}
};

int main() {
	
	//������һ���㽶�Ĺ���
	AbstractFactory* bananaFactory = new BananaFactory;
	//������һ��ˮ��
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