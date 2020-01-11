#include<iostream>
using namespace std;

class CPU {
public:
	virtual void caculate() = 0;
};

class Card {
public:
	virtual void display() = 0;
};

class Memory {
public:
	virtual void storage() = 0;
};

class IntelCPU :public CPU {  //ʵ��
public:
	virtual void caculate() {
		cout << "Intel cpu ��ʼ������" << endl;
	}
};

class IntelCard :public Card { //ʵ��
public:
	virtual void display() {
		cout << "Intel card��ʼ��ʾ��" << endl;
	}
};

class IntelMem :public Memory {  //ʵ��
public:
	virtual void storage() {
		cout << "Intel Memery��ʼ������" << endl;
	}
};

class NvidiaCPU :public CPU {  //ʵ��
public:
	virtual void caculate() {
		cout << "Nvidia CPU��ʼ������" << endl;
	}
};

class NvidiaCard :public Card {  //ʵ��
public:
	virtual void display() {
		cout << "Nvidia card��ʼ������" << endl;
	}
};

class NvidiaMem :public Memory {  //ʵ��
public:
	virtual void storage() {
		cout << "Nvidia Memery��ʼ������" << endl;
	}
};

class KinstonCPU :public CPU {  //ʵ��
public:
	virtual void caculate() {
		cout << "Kinston CPU��ʼ������" << endl;
	}
};

class KinstonCard :public Card {  //ʵ��
	virtual void display() {
		cout << "Kinston Card��ʼ������" << endl;
	}
};


class KinstonMem :public Memory {  //ʵ��
public:
	virtual void storage() {
		cout << "Kinston Memery��ʼ������" << endl;
	}
};


class AbstractFactory {
public:
	virtual CPU* CreateCPU() = 0;
	virtual Card* CreateCard() = 0;
	virtual Memory* CreateMemory() = 0;
};

class IntelFactory :public AbstractFactory{
public:
	virtual CPU* CreateCPU() {
		return new IntelCPU;
	}
	virtual Card* CreateCard() {
		return new IntelCard;
	}
	virtual Memory* CreateMemory() {
		return new IntelMem;
	}
};

class NvidiaFactory :public AbstractFactory {
public:
	virtual CPU* CreateCPU() {
		return new NvidiaCPU;
	}
	virtual Card* CreateCard() {
		return new NvidiaCard;
	}
	virtual Memory* CreateMemory() {
		return new NvidiaMem;
	}
};

class KinstonFactory :public AbstractFactory {
public:
	virtual CPU* CreateCPU() {
		return new KinstonCPU;
	}
	virtual Card* CreateCard() {
		return new KinstonCard;
	}
	virtual Memory* CreateMemory() {
		return new KinstonMem;
	}
};

class Computer {
public:
	Computer(CPU* cpu, Card* card, Memory* mem) {
		this->cpu = cpu;
		this->card = card;
		this->mem = mem;
	}
	void work() {
		this->cpu->caculate();
		this->card->display();
		this->mem->storage();
	}
private:
	CPU* cpu;
	Card* card;
	Memory* mem;
};

int main() {
	//1.��װһ��Intelϵ�еĵ���
	AbstractFactory* intelFactory = new IntelFactory;
	CPU* intelcpu = intelFactory->CreateCPU();
	Card* intelcard = intelFactory->CreateCard();
	Memory* intelmem = intelFactory->CreateMemory();

	Computer* com1 = new Computer(intelcpu, intelcard, intelmem);
	com1->work();

	//2.��װһ��Intel cpu / Nvidia card /Kinston Memory �ĵ���
	AbstractFactory* nvidiafactory = new NvidiaFactory;
	Card* nvidiacard = nvidiafactory->CreateCard();
	AbstractFactory* kinstonfactory = new KinstonFactory;
	Memory* kinstonmem = kinstonfactory->CreateMemory();

	Computer* com2 = new Computer(intelcpu, nvidiacard, kinstonmem);
	com2->work();

	return 0;
}