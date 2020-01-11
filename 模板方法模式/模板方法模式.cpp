#include<iostream>
using namespace std;

class MakeDrink {
public:
	//1.把水煮开
	virtual void boil() {
		cout << "把水煮开" << endl;
	}
	//2.冲某物
	virtual void brew() = 0;
	//3.从大杯倒入小杯
	virtual void putInCup() {
		cout << "把冲泡好的饮料，从大杯倒入小杯" << endl;
	}
	//4.加一些酌料
	virtual void addThings() = 0;

	//钩子函数
	virtual bool CustomWantAddThings() {
		return true;
	}

	//业务的逻辑的统一模板
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
	////1.把水煮开
	//virtual void boil() {
	//	cout << "把水煮开" << endl;
	//}
	//2.冲某物
	virtual void brew() {
		cout << "冲泡咖啡豆" << endl;
	}
	////3.从大杯倒入小杯
	//virtual void putInCup() {
	//	cout << "把冲泡好的饮料，从大杯倒入小杯" << endl;
	//}
	//4.加一些酌料
	virtual void addThings() {
		cout << "添加糖和牛奶" << endl;
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
	//2.冲某物
	virtual void brew() {
		cout << "冲泡茶叶" << endl;
	}
	//4.加一些酌料
	virtual void addThings() {
		cout << "添加柠檬" << endl;
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