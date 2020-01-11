#include<iostream>
using namespace std;

//虚V5
class V5 {
public:
	virtual void useV5() = 0;
};

//目前只有v220的类，没有v5
class V220 {
public:
	void useV220() {
		cout << "使用了220V的电压" << endl;
	}
};

//适配器:手机充电器
class Adapter :public V5 {
public:
	Adapter(V220* v220) {
		this->v220 = v220;
	}
	~Adapter() {
		if (this->v220 != NULL) {
			delete this->v220;
		}
	}
	virtual void useV5() {
		v220->useV220();	//关键，重写了useV5
	}
private:
	V220* v220;
};

//iPhone只能用v5充电
class iPhone {
public:
	iPhone(V5* v5) {
		this->v5 = v5;
	}
	~iPhone() {
		if (this->v5 != NULL) {
			delete this->v5;
		}
	}
	void charge() {
		cout << "iPhone手机进行了充电" << endl;
		v5->useV5();
	}
private:
	V5* v5;
};


int main() {
	/*V5* v5 = new V5;
	iPhone* phone = new iPhone(v5);
	delete v5;*/
	iPhone* phone = new iPhone(new Adapter(new V220));
	phone->charge();

	return 0;
}