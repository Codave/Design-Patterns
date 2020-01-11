#include<iostream>
#include<string>
using namespace std;

//美女类
class BeautyGirl {
public:
	virtual void MakeEyesWithMan() = 0;
	virtual void HappyWithMan() = 0;
};

class JinLian :public BeautyGirl {
public:
	virtual void MakeEyesWithMan() {
		cout << "潘金莲抛了一个媚眼" << endl;
	}
	virtual void HappyWithMan() {
		cout << "潘金莲跟你共度约会" << endl;
	}
};

//代理:王婆曾经也是美女
class WangPo :public BeautyGirl {
public:
	WangPo(BeautyGirl* girl) {
		this->girl = girl;
	}
	virtual void MakeEyesWithMan() {
		girl->MakeEyesWithMan();
	}
	virtual void HappyWithMan() {
		girl->HappyWithMan();
	}
private:
	BeautyGirl* girl;
};

//西门大官人
int main() {

	BeautyGirl* jinlian = new JinLian;
	WangPo* wangpo = new WangPo(jinlian);
	wangpo->MakeEyesWithMan();
	wangpo->HappyWithMan();
	
	return 0;
}