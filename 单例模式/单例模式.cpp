#include<iostream>
using namespace std;

class Printer {
public:
	static Printer* getInstance() {
		return instance;
	}
	void print(string text) {
		cout << text << endl;
		sequence++;
	}
	static int getCnt() {
		return sequence;
	}
private:
	Printer() {

	}
	class Garbo {
	public:
		~Garbo() {
			if (instance != NULL) {
				delete instance;
			}
		}
	};
	static Garbo garbo;
	static Printer* instance;
	static int sequence;
};

Printer* Printer::instance = new Printer;
int Printer::sequence = 0;
Printer::Garbo Printer::garbo;

int main() {

	Printer* p1 = Printer::getInstance();
	p1->print("一份简历");

	Printer* p2 = Printer::getInstance();
	p2->print("一份试卷");

	cout << p2->getCnt() << endl;

	return 0;
}