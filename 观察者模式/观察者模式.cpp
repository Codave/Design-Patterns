//#include<iostream>
//#include<string>
//#include<list>
//using namespace std;
//
////抽象的观察者 （监听者）
//class Listenner {
//public:
//	//老师来了，我该怎么办
//	virtual void onTeacherComming() = 0;
//	//学生干坏事了
//	virtual void doBadthing() = 0;
//};
//
////抽象的被观察者（通知者）
//class Notifier {
//public:
//	//添加观察者的方法
//	virtual void addListenner(Listenner* listenner) = 0;
//	//删除观察者的方法
//	virtual void notify(Listenner* listenner) = 0;
//	//通知所有观察者的方法
//	virtual void notify() = 0;
//};
//
////具体的观察者（监听者）
//class Student :public Listenner {
//public:
//	Student(string name, string badthing) {
//		this->name = name;
//		this->badthing = badthing;
//	}
//	virtual void onTeacherComming() {
//		cout << "学生" << name << "发现班长使眼色，停止" << badthing << endl;
//	}
//	virtual void doBadthing() {
//		cout << "学生" << name << "目前正在" << badthing << endl;
//	}
//private:
//	string name;
//	string badthing;
//};
//
////具体的被观察者（通知者）
//class Monitor :public Notifier {
//public:
//	virtual void addListenner(Listenner* listenner) {
//		this->l_list.push_back(listenner);
//	}
//	virtual void notify(Listenner* listenner) {
//		this->l_list.remove(listenner);
//	}
//	virtual void notify() {
//		for (list<Listenner*>::iterator it = l_list.begin(); it != l_list.end(); it++) {
//			(*it)->onTeacherComming();
//		}
//	}
//private:
//	list<Listenner*> l_list;
//};
//
//int main() {
//
//	Listenner* s1 = new Student("张三", "抄作业");
//	Listenner* s2 = new Student("李四", "打游戏");
//	Listenner* s3 = new Student("王五", "打游戏");
//
//	Notifier* bossXu = new Monitor;
//	bossXu->addListenner(s1);
//	bossXu->addListenner(s2);
//	bossXu->addListenner(s3);
//
//	cout << "教室一片和谐，老师没有来" << endl;
//	s1->doBadthing();
//	s2->doBadthing();
//	s3->doBadthing();
//
//	cout << "班长突然发现老师来了，给学生们使了一个眼神" << endl;
//	bossXu->notify();
//
//	return 0;
//}