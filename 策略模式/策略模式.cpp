#include<iostream>
using namespace std;

class AbstractStrategy {
public:
	virtual void useWeapon() = 0;
};

class KnifeStrategy :public AbstractStrategy {
public:
	virtual void useWeapon() {
		cout << "使用匕首，进行近战攻击" << endl;
	}
};

class AkStrategy :public AbstractStrategy {
public:
	virtual void useWeapon() {
		cout << "使用ak，进行远程攻击" << endl;
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
		cout << "英雄开始战斗了" << endl;
		this->strategy->useWeapon();
	}
private:
	AbstractStrategy* strategy;
};

int main() {

	AbstractStrategy* knife = new KnifeStrategy;
	AbstractStrategy* ak47 = new AkStrategy;

	Hero* hero = new Hero;

	cout << "远程兵来了，更换远程攻击" << endl;
	hero->setStrategy(ak47);
	hero->flight();

	cout << "近战兵来了，更换近战攻击" << endl;
	hero->setStrategy(knife);
	hero->flight();

	return 0;
}