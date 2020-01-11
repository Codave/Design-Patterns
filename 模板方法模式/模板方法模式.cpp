#include<iostream>
using namespace std;

class MakeDrink {
public:
	//1.��ˮ��
	virtual void boil() {
		cout << "��ˮ��" << endl;
	}
	//2.��ĳ��
	virtual void brew() = 0;
	//3.�Ӵ󱭵���С��
	virtual void putInCup() {
		cout << "�ѳ��ݺõ����ϣ��Ӵ󱭵���С��" << endl;
	}
	//4.��һЩ����
	virtual void addThings() = 0;

	//���Ӻ���
	virtual bool CustomWantAddThings() {
		return true;
	}

	//ҵ����߼���ͳһģ��
	void make() {
		boil();
		brew();
		putInCup();
		if (CustomWantAddThings() == true) {
			addThings();
		}
	}
};

class MakeCoffee :public MakeDrink {
public:
	MakeCoffee(bool isAdd) {
		this->isAdd = isAdd;
	}
	////1.��ˮ��
	//virtual void boil() {
	//	cout << "��ˮ��" << endl;
	//}
	//2.��ĳ��
	virtual void brew() {
		cout << "���ݿ��ȶ�" << endl;
	}
	////3.�Ӵ󱭵���С��
	//virtual void putInCup() {
	//	cout << "�ѳ��ݺõ����ϣ��Ӵ󱭵���С��" << endl;
	//}
	//4.��һЩ����
	virtual void addThings() {
		cout << "����Ǻ�ţ��" << endl;
	}
	virtual bool CustomWantAddThings() {
		return isAdd;
	}
private:
	bool isAdd;
};

class MakeTea :public MakeDrink {
public:
	MakeTea(bool isAdd) {
		this->isAdd = isAdd;
	}
	//2.��ĳ��
	virtual void brew() {
		cout << "���ݲ�Ҷ" << endl;
	}
	//4.��һЩ����
	virtual void addThings() {
		cout << "�������" << endl;
	}
	virtual bool CustomWantAddThings() {
		return isAdd;
	}
private:
	bool isAdd;
};

int main() {

	MakeDrink* makecoffee = new MakeCoffee(true);
	makecoffee->make();
	cout << "------------------------" << endl;
	MakeDrink* maketea = new MakeTea(false);
	maketea->make();

	return 0;
}