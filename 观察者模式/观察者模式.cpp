//#include<iostream>
//#include<string>
//#include<list>
//using namespace std;
//
////����Ĺ۲��� �������ߣ�
//class Listenner {
//public:
//	//��ʦ���ˣ��Ҹ���ô��
//	virtual void onTeacherComming() = 0;
//	//ѧ���ɻ�����
//	virtual void doBadthing() = 0;
//};
//
////����ı��۲��ߣ�֪ͨ�ߣ�
//class Notifier {
//public:
//	//��ӹ۲��ߵķ���
//	virtual void addListenner(Listenner* listenner) = 0;
//	//ɾ���۲��ߵķ���
//	virtual void notify(Listenner* listenner) = 0;
//	//֪ͨ���й۲��ߵķ���
//	virtual void notify() = 0;
//};
//
////����Ĺ۲��ߣ������ߣ�
//class Student :public Listenner {
//public:
//	Student(string name, string badthing) {
//		this->name = name;
//		this->badthing = badthing;
//	}
//	virtual void onTeacherComming() {
//		cout << "ѧ��" << name << "���ְ೤ʹ��ɫ��ֹͣ" << badthing << endl;
//	}
//	virtual void doBadthing() {
//		cout << "ѧ��" << name << "Ŀǰ����" << badthing << endl;
//	}
//private:
//	string name;
//	string badthing;
//};
//
////����ı��۲��ߣ�֪ͨ�ߣ�
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
//	Listenner* s1 = new Student("����", "����ҵ");
//	Listenner* s2 = new Student("����", "����Ϸ");
//	Listenner* s3 = new Student("����", "����Ϸ");
//
//	Notifier* bossXu = new Monitor;
//	bossXu->addListenner(s1);
//	bossXu->addListenner(s2);
//	bossXu->addListenner(s3);
//
//	cout << "����һƬ��г����ʦû����" << endl;
//	s1->doBadthing();
//	s2->doBadthing();
//	s3->doBadthing();
//
//	cout << "�೤ͻȻ������ʦ���ˣ���ѧ����ʹ��һ������" << endl;
//	bossXu->notify();
//
//	return 0;
//}