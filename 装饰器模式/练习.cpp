#include<iostream>
using namespace std;

//抽象英雄类
class Hero {
public:
	virtual void status() = 0;
};

class Akali :public Hero {
public:
	virtual void status() {
		cout << "HP:10000" << endl;
		cout << "AP:500" << endl;
		cout << "AD:50" << endl;
	}
};

//抽象的英雄装饰器
//聚合暗示着整体在概念上处于比局部更高的一个级别
class Decorator :public Hero {
public:
	Decorator(Hero* hero) {
		this->hero = hero;
	}
	virtual void status() = 0;
protected:
	Hero* hero;
};

class Dp1Decorator :public Decorator { //装备1
public:
	Dp1Decorator(Hero* hero) :Decorator(hero) { }
	virtual void status() {
		this->hero->status();
		cout << "HP+10000" << endl;
	}
};

class Dp2Decorator :public Decorator {	//装备2
public:
	Dp2Decorator(Hero* hero) :Decorator(hero) { }
	virtual void status() {
		this->hero->status();
		cout << "AP+5000" << endl;
	}
};

int main() {

	Hero* akali = new Akali;
	akali->status();

	cout << "装备1之后" << endl;
	Hero* dp1akali = new Dp1Decorator(akali);
	dp1akali->status();

	cout << "装备2之后" << endl;
	Hero* dp2akali = new Dp2Decorator(dp1akali);
	dp2akali->status();

	return 0;
}