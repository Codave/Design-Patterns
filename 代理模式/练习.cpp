#include<iostream>
#include<string>
using namespace std;

//��Ů��
class BeautyGirl {
public:
	virtual void MakeEyesWithMan() = 0;
	virtual void HappyWithMan() = 0;
};

class JinLian :public BeautyGirl {
public:
	virtual void MakeEyesWithMan() {
		cout << "�˽�������һ������" << endl;
	}
	virtual void HappyWithMan() {
		cout << "�˽������㹲��Լ��" << endl;
	}
};

//����:��������Ҳ����Ů
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

//���Ŵ����
int main() {

	BeautyGirl* jinlian = new JinLian;
	WangPo* wangpo = new WangPo(jinlian);
	wangpo->MakeEyesWithMan();
	wangpo->HappyWithMan();
	
	return 0;
}