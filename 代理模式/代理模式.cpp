////��̬�����
//#include<iostream>
//#include<string>
//using namespace std;
//
////��Ʒ
//class Item {
//public:
//	Item(string kind, bool fact) {
//		this->kind = kind;
//		this->fact = fact;
//	}
//	string getKind() {
//		return this->kind;
//	}
//	bool getFact() {
//		return this->fact;
//	}
//private:
//	string kind; //��Ʒ������
//	bool fact;	//��Ʒ�����
//};
//
////���﷽ʽ
//class Shopping {
//public:
//	virtual void buy(Item* it) = 0;
//};
//
//class KoreaShopping :public Shopping {
//public:
//	virtual void buy(Item* it) {
//		cout << "ȥ��������:" << it->getKind() << endl;
//	}
//};
//
//class USAShopping :public Shopping {
//public:
//	virtual void buy(Item* it) {
//		cout << "ȥ��������:" << it->getKind() << endl;
//	}
//};
//
//class UKShopping :public Shopping {
//public:
//	virtual void buy(Item* it) {
//		cout << "ȥӢ������:" << it->getKind() << endl;
//	}
//};
//
////����
//class OverseaProxy :public Shopping{
//public:
//	OverseaProxy(Shopping* shopping) {
//		this->shopping = shopping;
//	}
//	virtual void buy(Item* it) {
//		if (it->getFact()) {
//			cout << "������Ʒ������" << endl;
//			shopping->buy(it);
//			cout << "ͨ�����أ��������" << endl;
//		}
//		else {
//			cout << "���ּٻ������Ṻ��" << endl;
//		}
//	}
//private:
//	Shopping* shopping;
//};
//
//int main() {
//
//	/*Item it1("NIKE", true);
//	Shopping* koreashopping = new KoreaShopping;
//	if (it1.getFact()) {
//		cout << "������Ʒ������" << endl;
//		koreashopping->buy(&it1);
//		cout << "ͨ�����أ��������" << endl;
//	}
//	else {
//		cout << "���ּٻ������Ṻ��" << endl;
//	}*/
//
//	Item it1("NIKE", true);
//	Item it2("CET6", false);
//	Shopping* usashopping = new USAShopping;
//	Shopping* overseaproxy = new OverseaProxy(usashopping);
//	overseaproxy->buy(&it2);
//	overseaproxy->buy(&it1);
//
//	return 0;
//}