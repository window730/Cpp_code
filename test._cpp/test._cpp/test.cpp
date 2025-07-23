#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <stdlib.h>
//
// //定义命名空间 wnadou
//namespace wandou
//{
//    int rand = 10;
//    int Add(int left, int right)
//    {
//        return left + right;
//    }
//    struct Node
//    {
//        Node* next;
//        int val;
//    };
//}
//
//int main()
//{
//    printf("%p\n", rand); // 默认访问的是全局的rand
//    printf("%d\n", wandou::rand); // 指定访问 wandou 命名空间中的 rand
//    return 0;
//}
//
//namespace wandou
//{
//    namespace wd
//    {
//        int rand = 1;
//        int Add(int left, int right)
//        {
//            return left + right;
//        }
//    }
//}
//
//#include <iostream>
//
//int main()
//{
//    std::cout << "Hello, World!" << std::endl;  // 输出字符串
//    int a = 10;
//    std::cout << "a = " << a << std::endl;  // 输出变量值
//    double b = 3.14;
//    std::cout << "b = " << b << std::endl;  // 输出浮点数值
//    return 0;
//}
//
//#include <iostream>
//
//int main()
//{
//    int a;
//    std::cout << "请输入一个整数: ";
//    std::cin >> a;  // 从标准输入读取一个整数并存储到变量a中
//    std::cout << "你输入的整数是: " << a << std::endl;
//
//    double b;
//    std::cout << "请输入一个浮点数: ";
//    std::cin >> b;  // 从标准输入读取一个浮点数并存储到变量b中
//    std::cout << "你输入的浮点数是: " << b << std::endl;
//
//    return 0;
//}
//
//#include <iostream>
//
//void Print(int x = 10, int y = 20)
//{
//    std::cout << "x = " << x << ", y = " << y << std::endl;
//}
//
//int main()
//{
//    Print();            // 调用 Print()，使用默认值 x=10, y=20
//    Print(5);           // 调用 Print(5)，使用默认值 y=20
//    Print(5, 15);       // 调用 Print(5, 15)，不使用默认值
//
//    return 0;
//}


//
//#include <iostream>
//
//// 定义多个重载函数
//void Print(int x)
//{
//    
//    std::cout << "Print int: " << x << std::endl;
//}
//void Print(double x)
//{
//    std::cout << "Print double: " << x << std::endl;
//}
//
//void Print(int x, double y)
//{
//    std::cout << "Print int and double: " << x << ", " << y << std::endl;
//}
//
//int main()
//{
//    Print(5);           // 调用 Print(int)
//    Print(5.5);         // 调用 Print(double)
//    Print(5, 5.5);      // 调用 Print(int, double)
//
//    return 0;
//}

#include <iostream>
using namespace std;

class Date
{
public:
	//构造函数
	Date(int year = 1, int mouth = 1, int day = 1,const char* time = "00:00")
	{
		_year = year;
		_mouth = mouth;
		_day = day;
		_time = (char*)malloc(sizeof(char) * 6);
		memcpy(_time, time, 6);
	}

	//拷贝构造函数
	Date(const Date& d)
	{
		_year = d._year;
		_mouth = d._mouth;
		_day = d._day;
		_time = (char*)malloc(sizeof(char) * 6);
		memcpy(_time, d._time, 6);
	}

	//析构函数
	~Date()
	{
		free(_time);
		_time = nullptr;
		_year = 0;
		_mouth = 0;
		_day = 0;
		cout << "日期类已销毁" << endl;
	}

	void Print()
	{
		cout << _year << "年" << _mouth << "月" << _day << "日 北京时间" << _time << endl;
	}
private:
	int _year;
	int _mouth;
	int _day;
	char* _time;
};
int main()
{
	Date d1;
	Date d2(2025, 7, 17, "19:06");
	Date d3 = d2;

	d1.Print();
	d2.Print();
	d3.Print();
	return 0;
}

