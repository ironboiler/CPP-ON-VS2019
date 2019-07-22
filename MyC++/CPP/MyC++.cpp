// MyC++.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <math.h>
#include <iomanip>

float get_tex(int money);
bool tex_fun(void);
using namespace std;

int main()
{
	while (1)
	{
		if (tex_fun() == false)
			break;
	}
}

float get_tex(int money)
{
	if (money > 35000)
		return (money - 35000) * 0.2 + 4000;
	else if (money > 15000)
		return (money - 15000) * 0.15 + 1000;
	else if (money > 5000)
		return (money - 5000) * 0.1;
	else
		return 0;
}

bool tex_fun(void)
{
	char income[20];
	cout << "Please input your income" << endl;
	cin >> income;
	int charnum = 0, moneysum = 0, count = 0;
	float tex = 0;
	for (charnum = 0; income[charnum] != '\0'; charnum++)
	{
		if (income[charnum]<'0' || income[charnum]>'9')
		{
			cout << "Illegal input" << endl;
			return false;
		}
	}
	charnum--;
	for (count = 0; charnum >= 0; charnum--)
		moneysum += (income[count++] - '0') * pow(10, charnum);
	cout << "moneysum:" << moneysum << endl;
	tex = get_tex(moneysum);
	cout << "Your tex is " << fixed << setprecision(1) << tex << endl;
	return true;
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
