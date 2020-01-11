////静态的添加
//#include<iostream>
//#include<string>
//using namespace std;
//
////商品
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
//	string kind; //商品的种类
//	bool fact;	//商品的真假
//};
//
////购物方式
//class Shopping {
//public:
//	virtual void buy(Item* it) = 0;
//};
//
//class KoreaShopping :public Shopping {
//public:
//	virtual void buy(Item* it) {
//		cout << "去韩国买了:" << it->getKind() << endl;
//	}
//};
//
//class USAShopping :public Shopping {
//public:
//	virtual void buy(Item* it) {
//		cout << "去美国买了:" << it->getKind() << endl;
//	}
//};
//
//class UKShopping :public Shopping {
//public:
//	virtual void buy(Item* it) {
//		cout << "去英国买了:" << it->getKind() << endl;
//	}
//};
//
////代理
//class OverseaProxy :public Shopping{
//public:
//	OverseaProxy(Shopping* shopping) {
//		this->shopping = shopping;
//	}
//	virtual void buy(Item* it) {
//		if (it->getFact()) {
//			cout << "发现正品，购买" << endl;
//			shopping->buy(it);
//			cout << "通过海关，带回祖国" << endl;
//		}
//		else {
//			cout << "发现假货，不会购买" << endl;
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
//		cout << "发现正品，购买" << endl;
//		koreashopping->buy(&it1);
//		cout << "通过海关，带回祖国" << endl;
//	}
//	else {
//		cout << "发现假货，不会购买" << endl;
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