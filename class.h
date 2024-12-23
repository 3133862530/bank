#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

extern int OpeningHour;
extern int OpeningMintue;
extern int MAXTIME;

class client {
private:
	string Name; // 姓名
	int Phone[11]; // 电话号码
	bool Kind; // 0是普通业务，1是特殊业务
	string Id; // 身份证号
	int Arrtime; // 到达时间
	int Reqtime; // 所需时长
public:
	client() {}
	client(string name, int* phone, bool kind, string id, int arrtime, int reqtime);
	client(const client& c);
	~client() {}
	void infomation(client& c);
	void getName(string& n);
	void getPhone(int* p);
	void getKind(bool& k);
	void getId(string& i);
	void getArrtime(int& a);
	void getReqtime(int& r);

	friend class queue;
	friend class node;
};

class windows :public client {
private:
	int Number; // 窗口编号
	bool Kind; // 0是普通业务，1是特殊业务
	bool Available; // 0为空闲，1为正在办理
	client Customer; // 正在办理业务的客户
public:
	windows() :Available(false) {}
	windows(int number, bool kind);
	~windows() {}
	void conduct(const client& c);
};

class node :public client {
public:
	client C;
	node* Next;
	node() :Next(nullptr) {}
	node(const client& c);
	node(const client& c, node* next);
	~node() {}
};

class queue :public node {
public:
	node* Head;
	node* Tail;
	queue() :Head(nullptr), Tail(nullptr) {}
	~queue();
	void init();
	bool empty();
	void enqueue(const client& c);
	void dequeue(client& c);
	void writeToFile(const string& filename);
	void readFromFile(const string& filename);
};

#endif
