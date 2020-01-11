#include<iostream>
using namespace std;

//����Ӣ����
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

//�����Ӣ��װ����
//�ۺϰ�ʾ�������ڸ����ϴ��ڱȾֲ����ߵ�һ������
class Decorator :public Hero {
public:
	Decorator(Hero* hero) {
		this->hero = hero;
	}
	virtual void status() = 0;
protected:
	Hero* hero;
};

class Dp1Decorator :public Decorator { //װ��1
public:
	Dp1Decorator(Hero* hero) :Decorator(hero) { }
	virtual void status() {
		this->hero->status();
		cout << "HP+10000" << endl;
	}
};

class Dp2Decorator :public Decorator {	//װ��2
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

	cout << "װ��1֮��" << endl;
	Hero* dp1akali = new Dp1Decorator(akali);
	dp1akali->status();

	cout << "װ��2֮��" << endl;
	Hero* dp2akali = new Dp2Decorator(dp1akali);
	dp2akali->status();

	return 0;
}