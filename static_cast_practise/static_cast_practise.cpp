// static_cast_practise.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//˵��:static_cast ��������ʽת�� ��ֻ���ó���Ƚ���ʽת����˵����������ȷ
	int a = 1;
	float b = 2.0;
	//b = a;//��ʽת��
	b = static_cast<float>(a);//��������ʽת��ͬ�ȣ���ȷ���߱��ˣ�ת��Ϊfloat����
	std::cout << "b:" << b << std::endl;

	//2 ͬ��dynamic_cast
	//����ת����(����ȫ)
	cFather * father = new cFather;
	cSon* son = new cSon;
	//son = father;
	//son = static_cast<cSon*>(father); //������ʽת����������ȿ��Ա���ͨ�������ǲ���������ͼ�⣬��������벻ͨ��
	//dynamic_cast���Խ������ͼ�⣬�������ͼ������и�����ֵ��ת��ʧ�ܣ���sonΪnullptr,����ת���ɹ�
	son = dynamic_cast<cSon*>(father);
	if (son)
	{
		std::cout << "son��Ϊnullptr,ת���ɹ�" << std::endl;
	}
	else
	{
		std::cout << "ת��ʧ��" << std::endl;
	}

	//3 reinterpret_cast ��������ʾǿת������Ը� ��������ת�����ָ�Σ�յ�ת����ʽ
	son = reinterpret_cast<cSon*>(father);
	if (son)
	{
		std::cout << "son��Ϊnullptr,ת���ɹ�" << std::endl;
	}
	else
	{
		std::cout << "ת��ʧ��" << std::endl;
	}

	//4 const_cast
	//const_cast ֻ���ָ�룬���ã�thisָ�� Ŀ�ģ�ȥconst��
	const int n = 5;
	const std::string s = "Inception";
	std::string& test = const_cast<std::string&>(s);
	test = "123";
	std::cout << "s:" << s << std::endl;
	int * k = const_cast<int*>(&n);
	*k = 123;
	int tem = n;
	//���intû�иı䣬��string��ͬ����ʵn���ڴ��е�ֵ�Ѿ����123�ˣ����ǳ������Ǵ��������ű��ж�ȡn��ֵ�ģ����ű��е�nֵ����5
	std::cout << "tem:" << tem << std::endl;
	int& ref = const_cast<int&>(n);
	ref = 456;
	tem = n;
	std::cout << "tem:" << tem << std::endl;
	std::cin.get();
    return 0;
}

