// MyC++.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

class account {
	string name;
	uint32_t number;
	uint32_t money;
public:
	account(const string& iptname, uint32_t iptnumber, uint32_t iptmoney)
	{
		name = iptname;
		number = iptnumber;
		money = iptmoney;
	}
	~account(void)
	{
		cout << "delet " << name << endl;
	}
	void showinfo(void)
	{
		cout << "name:" << name << endl;
		cout << "number:" << number << endl;
		cout << "money:" << money << endl;
	}
	void savemoney(uint32_t sm)
	{
		money += sm;
		showinfo();
	}
	void takemoney(uint32_t tm)
	{
		if (money >= tm)
		{
			money -= tm;
			showinfo();
		}
		else
			cout << "Your balance is insufficient!Your balance is :" << money << endl;
	}
};

int main()
{
	account bank("江戸川沢民", 10086, 50000);
	int cmd;
	uint32_t save, take;
	bool quit = false;
	while (!quit)
	{
		cout << "Welcome to bank!" << endl;
		cout << "Input 1 for save money;Input 2 for take money;Input 3 for show your account;Input 4 for quit" << endl;
		cin >> cmd;
		switch (cmd)
		{
		case 1:
			cout << "How much do you want to save?" << endl;
			cin >> save;
			bank.savemoney(save);
			break;
		case 2:
			cout << "How much do you want to take?" << endl;
			cin >> take;
			bank.takemoney(take);
			break;
		case 3:
			bank.showinfo();
			break;
		case 4:
			quit = true;
			break;
		}
		cout << endl;
	}
	bank.~account();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
