// static_cast_practise.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
class cFather
{
public:
	cFather() {}
	virtual ~cFather() {}

};

class cSon:public cFather
{
public:
	cSon() :cFather() {}
	
};

int main()
{
	//1
	//说明:static_cast 类似于隐式转换 ，只是让程序比较隐式转换来说看起来更明确
	int a = 1;
	float b = 2.0;
	//b = a;//隐式转换
	b = static_cast<float>(a);//和上面隐式转换同等，明确告诉别人，转换为float类型
	std::cout << "b:" << b << std::endl;

	//2 同比dynamic_cast
	//父类转子类(不安全)
	cFather * father = new cFather;
	cSon* son = new cSon;
	//son = father;
	//son = static_cast<cSon*>(father); //这种隐式转换和上面相比可以编译通过，但是不会进行类型检测，上面则编译不通过
	//dynamic_cast可以进行类型检测，所以类型检查就是有个返回值，转换失败，则son为nullptr,否则转换成功
	son = dynamic_cast<cSon*>(father);
	if (son)
	{
		std::cout << "son不为nullptr,转换成功" << std::endl;
	}
	else
	{
		std::cout << "转换失败" << std::endl;
	}

	//3 reinterpret_cast 类似于显示强转，后果自负 ，适用于转换各种高危险的转换方式
	son = reinterpret_cast<cSon*>(father);
	if (son)
	{
		std::cout << "son不为nullptr,转换成功" << std::endl;
	}
	else
	{
		std::cout << "转换失败" << std::endl;
	}

	//4 const_cast
	//const_cast 只针对指针，引用，this指针 目的：去const化
	const int n = 5;
	const std::string s = "Inception";
	std::string& test = const_cast<std::string&>(s);
	test = "123";
	std::cout << "s:" << s << std::endl;
	int * k = const_cast<int*>(&n);
	*k = 123;
	int tem = n;
	//这边int没有改变，和string不同，其实n在内存中的值已经变成123了，但是程序中是从数表（符号表）中读取n的值的，符号表中的n值还是5
	std::cout << "tem:" << tem << std::endl;
	int& ref = const_cast<int&>(n);
	ref = 456;
	tem = n;
	std::cout << "tem:" << tem << std::endl;
	std::cin.get();
    return 0;
}

