#include<iostream>
#include <string>
using namespace std;

typedef struct student
{
	int number;
	string name;
	float chinesewrite;
	float maths;
	float English;
	student* next;
};

void menu(),examine(), remove(), change(), seek();
void add();
student* head = new student;

int main()
{
	cout << "      欢迎进入新生管理系统。" <<endl<<endl<<"\t\t\t\t\t[ENTER]";
	cin.get();
	menu();
	return 0;
}

void menu()
{
	int yourNumber;
	cout << endl<<"1.查看学生信息\t\t2.添加名单上的学生\t3.移除名单上的学生" << endl<<endl;
	cout << "4.修改学生信息\t\t5.按要求查找学生\t6.退出系统" << endl<<endl;
	cout <<  "请输入数字并回车执行相应的功能:" << endl;
	(cin >> yourNumber).get();
	cout << endl;
	switch (yourNumber)
	{
	case 1:
		examine();
		break;
	case 2:
		add();
		break;
	case 3:
		remove();
		break;
	case 4:
		change();
		break;
	case 5:
		seek();
		break;
	case 6:
		cout << "系统已成功退出。\n\n";
		break;
	}
}
void examine()
{
	student* p = head;
	p = p->next;
	cout << "\t学号\t姓名\t中文写作\t高等数学\t大学英语";
	while (p->number != 0) {
		cout << "\n\t"<<p->number<<"\t"<<p->name<<"\t"<<p->chinesewrite<<"\t"<<p->maths<<"\t"<<p->English;
		p = p->next;
	}
	cout << "\n将返回菜单（请按回车）";
	cin.get();
	menu();
}

void add() {
	cout << "\t学号\t姓名\t中文写作\t高等数学\t大学英语" << "(请按此顺序依次输入学生信息，统计完成时全部用0代替）" << endl;
	student* p1 = head;
	student* p2 = new student;
	int n = 0;
	while (p2->number != 0)
	{
		n++;
		cout << "第" <<n <<"位:";
		p2 = new student;
		cin >> p2->number >> p2->name >> p2->chinesewrite >> p2->maths >> p2->English;
		cin.get();
		p2->next = NULL;
		p1->next = p2;
		p1 = p2;
	}
	cout << "\n将返回菜单（请按回车）";
	cin.get();
	menu();
}

void remove() {
	cout << "请输入学号：";
	int twoNumber = 0;
	(cin >> twoNumber).get();
	student* p = head;
	student* p1;
	p1 = p;
	p = p->next;
	bool search = true;
	while (p->number) {
		if (p->number == twoNumber)
		{
			cout << "\n已找到该生:\t" << p->number << "\t" << p->name << "\t" << p->chinesewrite << "\t" << p->maths << "\t" << p->English << endl;
			search = 0;
			p1->next = p->next;
			cout << "\n已经成功移除!\n";
			p = p->next;
		}
		p1 = p;
	}
	if (search) {
		cout << "\n抱歉没有找到该生。";
	}
	cout << "\n将返回菜单（请按回车）";
	cin.get();
	menu();
}

void change() {
	cout << "\n请输入学号：";
	int twoNumber = 0;
	(cin >> twoNumber).get();
	student* p = head;
	p = p->next;
	bool search = true;
	while (p->number) {
		if (p->number == twoNumber)
		{
			cout << "\n已找到该生:\t" << p->number << "\t" << p->name << "\t" << p->chinesewrite <<"\t" << p->maths << "\t" << p->English << endl<<"请选择将要修改的内容\n";
			cout<< "\t\t1.学号 2.姓名 3.中文写作成绩 4.高等数学成绩 5.大学英语成绩\n请输入修改后的内容：";
			int options = 0;
			(cin >> options).get();
			switch (options)
			{
			case 1:
				cin >> p->number;
				break;
			case 2:
				cin >> p->name;
				break;
			case 3:
				cin >> p->chinesewrite;
				break;
			case 4:
				cin >> p->maths;
				break;
			case 5:
				cin >> p->English;
				break;
			}
			cout << "\n修改成功！\n";
			search = false;
		}
		p = p->next;
	}
	if (search) {
		cout << "\n抱歉没有找到该生。";
	}
	cout << "\n将返回菜单（请按回车）";
	cin.get();
	menu();
}

void seek() {
	cout << "请确定查找标准（1.按学号查找 2.按姓名查找）:"<<endl;
	int n = 0;
	cin >> n;
	if (n == 1) {
		cout << "\n请输入学号：";
		int twoNumber = 0;
		(cin >> twoNumber).get();
		student* p = head;
		p = p->next;
		while (p->number) {
			if (p->number == twoNumber)
			{
				cout<<"\n已找到该生:\t"<<p->number << "\t" << p->name << "\t" << p->chinesewrite << "\t" << p->maths << "\t" << p->English<<endl;
				n = 0;
			}
			p = p->next;
		}
		if (n == 1) {
			cout << "\n抱歉没有找到该生。";
		}
	}
	else if (n == 2) {
		cout << "\n请输入姓名：";
		string twoName ;
		cin >> twoName;
		student* p = head;
		p = p->next;
		while (p->number) {
			if (p->name == twoName)
			{
				cout << "\n已找到该生:\t" << p->number << "\t" << p->name << "\t" << p->chinesewrite << "\t" << p->maths << "\t" << p->English << endl;
				n = 0;
			}
			p = p->next;
		}
		if (n == 2) {
			cout << "\n抱歉没有找到该生。";
		}
	}
	cout << "\n将返回菜单（请按回车）";
	cin.get();
	menu();
}
