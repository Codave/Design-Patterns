#include<iostream>
using namespace std;

class Light {
	public:
		void On() {
			cout << "灯打开了" << endl;
		}
		void Off() {
			cout << "灯关闭了" << endl;
		}
	};

class TV {
public:
	void On() {
		cout << "电视打开了" << endl;
	}
	void Off() {
		cout << "电视关闭了" << endl;
	}
};

class MikePhone {
public:
	void On() {
		cout << "麦克风打开了" << endl;
	}
	void Off() {
		cout << "麦克风关闭了" << endl;
	}
};

class Xbox {
public:
	void On() {
		cout << "Xbox打开了" << endl;
	}
	void Off() {
		cout << "Xbox关闭了" << endl;
	}
};

class DVD {
public:
	void On() {
		cout << "DVD打开了" << endl;
	}
	void Off() {
		cout << "DVD关闭了" << endl;
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

	cout << "进入ktv模式" << endl;
	hp.doKTV();

	cout << "进入游戏模式" << endl;
	hp.doGame();

	return 0;
}