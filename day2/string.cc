 ///
 /// @file    string.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-23 09:59:36
 ///
 
#include <string.h>

#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

void test0()
{
	//字符数组
	char str1[] = "hello";//栈上
	char str2[] = "world";
	//
	//C风格字符串
	const char * pstr = "hello,world";//文字常量区
	//*pstr = 'x';//error
	
	//str1 = 0x1000;//数组名是一个常量，不能进行修改
	//++str1;
	cout << "sizeof(str1) = " << sizeof(str1) << endl;
	
	char * ptmp = (char *)malloc(sizeof(str1) + sizeof(str2));
	strcpy(ptmp, str1);
	strcat(ptmp, str2);
	
	printf("ptmp = %s\n", ptmp);

	//获取字符串长度
	printf("strlen(ptmp) = %ld\n", strlen(ptmp));
	

	free(ptmp);
}


void test1()
{
	//C++风格字符串
	string s1 = "hello";//将C风格字符串转换成C++风格字符串	
	string s2 = "world";

	string s3 = s1 + 'x' + "wangdao" + s2;
	cout << "s3 = " << s3 << endl;
	s1.append(s2);//后面接s2
	cout << "s1 = " << s1 << endl;

	cout << "s1.size() = " << s1.size() << endl;
	cout << "s1.length() = " << s1.length() << endl;

	//对C++的字符串进行遍历
	for(size_t idx = 0; idx != s1.size(); ++idx)
		cout << s1[idx] << endl;
	cout << endl;

	size_t pos = s3.find("world");
	string s4 = s3.substr(pos, 4);//pos 往后后面4个字符
	cout << "s4 = " << s4 << endl;
	
	//将C++风格字符串转换成C风格字符串
	const char * pstr = s4.c_str();
	const char * pstr2 = s4.data();
	printf("pstr = %p\n", pstr);
	printf("pstr2 = %p\n", pstr2);
	cout << "pstr = " << pstr << endl;
	cout << "pstr2 = " << pstr2 << endl;
}

 
int main(void)
{
	//test0();
	test1();
	return 0;
}
