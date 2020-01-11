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

class IntelCPU :public CPU {  //实现
public:
	virtual void caculate() {
		cout << "Intel cpu 开始工作了" << endl;
	}
};

class IntelCard :public Card { //实现
public:
	virtual void display() {
		cout << "Intel card开始显示了" << endl;
	}
};

class IntelMem :public Memory {  //实现
public:
	virtual void storage() {
		cout << "Intel Memery开始工作了" << endl;
	}
};

class NvidiaCPU :public CPU {  //实现
public:
	virtual void caculate() {
		cout << "Nvidia CPU开始工作了" << endl;
	}
};

class NvidiaCard :public Card {  //实现
public:
	virtual void display() {
		cout << "Nvidia card开始工作了" << endl;
	}
};

class NvidiaMem :public Memory {  //实现
public:
	virtual void storage() {
		cout << "Nvidia Memery开始工作了" << endl;
	}
};

class KinstonCPU :public CPU {  //实现
public:
	virtual void caculate() {
		cout << "Kinston CPU开始工作了" << endl;
	}
};

class KinstonCard :public Card {  //实现
	virtual void display() {
		cout << "Kinston Card开始工作了" << endl;
	}
};


class KinstonMem :public Memory {  //实现
public:
	virtual void storage() {
		cout << "Kinston Memery开始工作了" << endl;
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
	//1.组装一个Intel系列的电脑
	AbstractFactory* intelFactory = new IntelFactory;
	CPU* intelcpu = intelFactory->CreateCPU();
	Card* intelcard = intelFactory->CreateCard();
	Memory* intelmem = intelFactory->CreateMemory();

	Computer* com1 = new Computer(intelcpu, intelcard, intelmem);
	com1->work();

	//2.组装一个Intel cpu / Nvidia card /Kinston Memory 的电脑
	AbstractFactory* nvidiafactory = new NvidiaFactory;
	Card* nvidiacard = nvidiafactory->CreateCard();
	AbstractFactory* kinstonfactory = new KinstonFactory;
	Memory* kinstonmem = kinstonfactory->CreateMemory();

	Computer* com2 = new Computer(intelcpu, nvidiacard, kinstonmem);
	com2->work();

	return 0;
}