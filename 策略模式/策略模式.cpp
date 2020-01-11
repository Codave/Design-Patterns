#include<iostream>
using namespace std;

class AbstractStrategy {
public:
	virtual void useWeapon() = 0;
};

class KnifeStrategy :public AbstractStrategy {
public:
	virtual void useWeapon() {
		cout << "ʹ��ذ�ף����н�ս����" << endl;
	}
};

class AkStrategy :public AbstractStrategy {
public:
	virtual void useWeapon() {
		cout << "ʹ��ak������Զ�̹���" << endl;
	}
};

class Hero {
public:
	Hero() {
		strategy = NULL;
	}
	void setStrategy(AbstractStrategy* strategy) {
		this->strategy = strategy;
	}
	void flight() {
		cout << "Ӣ�ۿ�ʼս����" << endl;
		this->strategy->useWeapon();
	}
private:
	AbstractStrategy* strategy;
};

int main() {

	AbstractStrategy* knife = new KnifeStrategy;
	AbstractStrategy* ak47 = new AkStrategy;

	Hero* hero = new Hero;

	cout << "Զ�̱����ˣ�����Զ�̹���" << endl;
	hero->setStrategy(ak47);
	hero->flight();

	cout << "��ս�����ˣ�������ս����" << endl;
	hero->setStrategy(knife);
	hero->flight();

	return 0;
}