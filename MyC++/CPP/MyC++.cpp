// MyC++.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <iostream>
#include <math.h>

float get_BMI(float tall, float weight);
void judge_health(float BMI);

using namespace std;

int main()
{
	float tall_m, weight_kg, BMI;

	cout << "请输入您的身高（单位：米）：" << endl;
	cin >> tall_m;
	cout << "请输入您的体重（单位：千克）：" << endl;
	cin >> weight_kg;

	BMI = get_BMI(tall_m, weight_kg);

	cout << "您的BMI指数为：" << BMI << endl;

	judge_health(BMI);
}

float get_BMI(float tall, float weight)
{
	return weight / pow(tall, 2);
}

void judge_health(float BMI)
{
	if (BMI <= 18.5)
		cout << "您的体重偏低" << endl;
	else if (BMI > 18.5 && BMI <= 24.0)
		cout << "您的体重正常" << endl;
	else if (BMI > 24.0 && BMI <= 28.0)
		cout << "您的体重偏重" << endl;
	else
		cout << "您的体重超重" << endl;
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
