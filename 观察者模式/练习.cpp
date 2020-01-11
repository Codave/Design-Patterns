#include<iostream>
#include<string>
#include<list>
using namespace std;

//前置声明notifier
class Notifier;

class Listenner {
public:
	virtual void onFriendBeFight(Listenner* one, Listenner* another, Notifier* baixiao) = 0;
	virtual void fighting(Listenner* another, Notifier* notifier) = 0;
	virtual string getName() = 0;
	virtual string getParty() = 0;
};

class Notifier {
public:
	virtual void addListenner(Listenner* listenner) = 0;
	virtual void delListenner(Listenner* listenner) = 0;
	virtual void notify(Listenner* one, Listenner* another) = 0;
};

class Hero :public Listenner {
public:
	Hero(string name, string party) {
		this->name = name;
		this->party = party;
	}
	//当我发现一个消息之后我该怎么办
	virtual void onFriendBeFight(Listenner* one, Listenner* another, Notifier* baixiao) {
		if (another->getName() != this->name && one->getName() != this->name) {
			//如果是当事人，什么都不做
			//如果不是当事人，需要判断打人的party和被打的party是不是我自己哥们
			if (one->getParty() == this->party) {
				//自己人把别人揍了 
				cout << name << "发现自己人把别人揍了，笑了，拍手叫好" << endl;
			}
			else if (another->getParty() == this->party) {
				cout << name << "发现自己人被别人揍了，出手相助" << endl;
				this->fighting(one, baixiao);
			}
		}
		else {
			//如果是当事人，什么都不干
		}
	}
	//揍人
	virtual void fighting(Listenner* another, Notifier* notifier) {
		cout << name << "[" << this->party << "]" << "把" << another->getName() << "[" << another->getParty() << "]"  << "给揍了\n";
		//揍完之后，这个事件应该让百晓生知道
		//应该调用百晓生的notify方法
		notifier->notify(this, another);
	}

	string getName() {  //加不加virtual都一样，可以省略
		return this->name;
	}
	string getParty() {
		return this->party;
	}
private:
	string name;
	string party;
};

class Baixiao :public Notifier {
public:
	//添加观察者的方法
	virtual void addListenner(Listenner* listenner) {
		this->l_list.push_back(listenner);
	}
	//删除观察者的方法
	virtual void delListenner(Listenner* listenner) {
		this->l_list.remove(listenner);
	}
	//通知所有观察者的方法
	virtual void notify(Listenner* one, Listenner* another) {
		for (list<Listenner*>::iterator it = l_list.begin(); it != l_list.end(); it++) {
			(*it)->onFriendBeFight(one, another, this);
		}
	}
private:
	list<Listenner*> l_list;
};

int main() {

	Listenner* hong7 = new Hero("洪七公", "丐帮");
	Listenner* hr = new Hero("黄蓉", "丐帮");
	Listenner* wuyazi = new Hero("无崖子", "逍遥派");
	Listenner* tonglao = new Hero("天山童姥", "逍遥派");

	Notifier* baixiao = new Baixiao;
	baixiao->addListenner(hong7);
	baixiao->addListenner(hr);
	baixiao->addListenner(wuyazi);
	baixiao->addListenner(tonglao);

	hong7->fighting(wuyazi, baixiao);
	cout << "--------------------------" << endl;
	//tonglao->fighting(hong7, baixiao);

	return 0;
}