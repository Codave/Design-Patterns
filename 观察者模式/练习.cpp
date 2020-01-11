#include<iostream>
#include<string>
#include<list>
using namespace std;

//ǰ������notifier
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
	//���ҷ���һ����Ϣ֮���Ҹ���ô��
	virtual void onFriendBeFight(Listenner* one, Listenner* another, Notifier* baixiao) {
		if (another->getName() != this->name && one->getName() != this->name) {
			//����ǵ����ˣ�ʲô������
			//������ǵ����ˣ���Ҫ�жϴ��˵�party�ͱ����party�ǲ������Լ�����
			if (one->getParty() == this->party) {
				//�Լ��˰ѱ������� 
				cout << name << "�����Լ��˰ѱ������ˣ�Ц�ˣ����ֽк�" << endl;
			}
			else if (another->getParty() == this->party) {
				cout << name << "�����Լ��˱��������ˣ���������" << endl;
				this->fighting(one, baixiao);
			}
		}
		else {
			//����ǵ����ˣ�ʲô������
		}
	}
	//����
	virtual void fighting(Listenner* another, Notifier* notifier) {
		cout << name << "[" << this->party << "]" << "��" << another->getName() << "[" << another->getParty() << "]"  << "������\n";
		//����֮������¼�Ӧ���ð�����֪��
		//Ӧ�õ��ð�������notify����
		notifier->notify(this, another);
	}

	string getName() {  //�Ӳ���virtual��һ��������ʡ��
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
	//��ӹ۲��ߵķ���
	virtual void addListenner(Listenner* listenner) {
		this->l_list.push_back(listenner);
	}
	//ɾ���۲��ߵķ���
	virtual void delListenner(Listenner* listenner) {
		this->l_list.remove(listenner);
	}
	//֪ͨ���й۲��ߵķ���
	virtual void notify(Listenner* one, Listenner* another) {
		for (list<Listenner*>::iterator it = l_list.begin(); it != l_list.end(); it++) {
			(*it)->onFriendBeFight(one, another, this);
		}
	}
private:
	list<Listenner*> l_list;
};

int main() {

	Listenner* hong7 = new Hero("���߹�", "ؤ��");
	Listenner* hr = new Hero("����", "ؤ��");
	Listenner* wuyazi = new Hero("������", "��ң��");
	Listenner* tonglao = new Hero("��ɽͯ��", "��ң��");

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