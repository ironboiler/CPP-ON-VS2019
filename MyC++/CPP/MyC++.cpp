// MyC++.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <ctime>
#include "Vector.h"

using namespace std;
using namespace VECTOR;

int main()
{
	ofstream outfile;
	outfile.open("record.txt");
	//
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		outfile << "Target Distance: " << target << ", Step Size: " << dstep << endl;
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep,direction,Vector::POL);
			result = result + step;
			outfile << steps << ": " << result << endl;
			steps++;
		}
		outfile << "After " << steps << " steps,the subject has the following location:" << endl;
		outfile << result << endl;
		result.polar_mode();
		outfile << " or" <<endl<<result <<endl;
		outfile << "Average outward distance per step = " << result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0,0.0);
		cout << endl<< "Record had Generated " << endl; 
		cout << endl << "Enter target distance (q to quit): ";
	}
	cout << "Bye!" << endl;
	outfile.close();
	cin.clear();
	while (cin.get() != '\n')
		continue;
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
