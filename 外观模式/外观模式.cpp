#include<iostream>
using namespace std;

class Light {
	public:
		void On() {
			cout << "�ƴ���" << endl;
		}
		void Off() {
			cout << "�ƹر���" << endl;
		}
	};

class TV {
public:
	void On() {
		cout << "���Ӵ���" << endl;
	}
	void Off() {
		cout << "���ӹر���" << endl;
	}
};

class MikePhone {
public:
	void On() {
		cout << "��˷����" << endl;
	}
	void Off() {
		cout << "��˷�ر���" << endl;
	}
};

class Xbox {
public:
	void On() {
		cout << "Xbox����" << endl;
	}
	void Off() {
		cout << "Xbox�ر���" << endl;
	}
};

class DVD {
public:
	void On() {
		cout << "DVD����" << endl;
	}
	void Off() {
		cout << "DVD�ر���" << endl;
	}
};

class HomePlayer {
public:
	void doKTV() {
		light.On();
		mike.On();
	}
	void doGame() {
		xbox.On();
		dvd.On();
	}
	Light light;
	TV tv;
	MikePhone mike;
	Xbox xbox;
	DVD dvd;
};

int main() {

	HomePlayer hp;

	cout << "����ktvģʽ" << endl;
	hp.doKTV();

	cout << "������Ϸģʽ" << endl;
	hp.doGame();

	return 0;
}