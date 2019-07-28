 ///
 /// @file    Computer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-23 11:44:54
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
	Computer(const char * brand, float price)
	: _brand(new char[strlen(brand)+ 1]())
	, _price(price)
	{
		strcpy(_brand, brand);
		cout << "Computer(const char*, float)" << endl;
	}

	//系统提供的拷贝构造函数不再满足需求
#if 0
	Computer(const Computer & rhs)
	: _brand(rhs._brand) //浅拷贝
	, _price(rhs._price)
	{
		cout << "Computer(const Computer &)" << endl;
	}
#endif

	//1. 拷贝构造函数的引用符号不可以删除;
	//	 如果删除会导致拷贝构造函数的无穷递归调用，直到栈溢出
	//2. 参数中的const 关键字不可以删除;
	//   如果删除，当传递过来的是一个右值时，就无法编译通过

	//Computer(const Computer  rhs)
	//Computer(Computer & rhs)
	Computer(const Computer & rhs)
	: _brand(new char[strlen(rhs._brand) + 1]()) //深拷贝
	, _price(rhs._price)
	{
		cout << "Computer(const Computer &)" << endl;
		strcpy(_brand, rhs._brand);
	}

	//系统提供的赋值函数不再满足需求
	//需要显式提供
#if 0
	Computer & operator=(const Computer & rhs)
	{
		_brand = rhs._brand;
		_price = rhs._price;

		cout << "Computer & operator=(const Computer &)" << endl;
		return *this;
	}
#endif

	//最容易出错
	Computer & operator=(const Computer & rhs)
	{
		if(this != &rhs) {//自复制
			cout << "Computer & operator=(const Computer &)" << endl;
			delete [] _brand;//回收左操作申请的空间

			//再进行深拷贝
			_brand = new char[strlen(rhs._brand) + 1]();
			strcpy(_brand, rhs._brand);
			_price = rhs._price;
		}
		return *this;
	}

	void print();

	//系统提供的不满足需求
	//~Computer(){}

	~Computer()
	{//析构函数的作用是用来清理对象开辟的资源
		if(_brand)
			delete [] _brand;

		cout << "~Computer()" << endl;
	}

private:
	char * _brand;
	float _price;
};
 

inline void Computer::print()
{
	printf("brand = %p\n", _brand);
	cout << "brand:" << _brand << endl
		 << "price:" << _price << endl;
}


//Computer gPc("Xiaomi", 7500);







void test3()
{
	Computer pc1("Thinkpad", 8888);
	Computer pc2("Xiaomi", 7500);

	pc2 = pc1;
	//pc2.operator=(pc1);
	cout << "执行赋值语句之后:" << endl;
	cout <<  "pc1 = ";
	pc1.print();
	cout <<  "pc2 = ";
	pc2.print();

	int a = 3, b = 4;
	a = (a = b);//自复制

}

int main(void)
{
	//test0();
	//test1();
	//test2();
	test3();

	return 0;
}
