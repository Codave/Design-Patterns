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
	virtual void getName() {
		cout << "�����㽶" << endl;
	}
};

//���һ����ƷѼ��
class Pear :public Fruit {
public:
	virtual void getName() {
		cout << "����Ѽ��" << endl;
	}
};



//����
class Factory {
public:
	//ˮ��������
	Fruit* createFruit(string kind) {
		Fruit* fruit = NULL;
		if (kind == "apple") {
			fruit = new Apple;
		}
		else if (kind == "banana") {
			fruit = new Banana;
		}
		//�����һ��Ѽ�棬�޸��˹����ķ�����Υ���˿���ԭ��
		else if (kind == "Pear") {
			fruit = new Pear;
		}
		return fruit;
	}
};

int main() {
	//�����Ǹ������򽻵�
	Factory* factory = new Factory;

	//��һ��ƻ��
	Fruit* apple = factory->createFruit("apple");
	apple->getName();

	//��һ���㽶
	Fruit* banana = factory->createFruit("banana");
	banana->getName();

	return 0;
}