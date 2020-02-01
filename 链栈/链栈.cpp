#include"LinkStack.h"
#include"CHAR.h"
#include<iostream>
using namespace std;
int In(char ch)//判断是否为数字
{
	if (ch >= '0' && ch <= '9')
	{
		return 1;
	}
	return 0;
}

char Precede(char a, char b)//比较字符优先级
{
	char c;
	if (a == '#' && b != '#') c = '<';
	if (a == '#' && b == '#') c = '=';
	else if ( a == '+' || a == '-')
	{
		if (b == '+' || b == '-' || b == ')' || b == '#')
		{
			c = '>';
		}
		else
		{
			c = '<';
		}
	}
	else if (a == '*' || a == '/')
	{
		if (b == '(')
		{
			c = '<';
		}
		else
		{
			c = '>';
		}
	}
	else if (a == '(')
	{
		if (b == ')')
		{
			c = '=';
		}
		else if (b == '+' || b == '-' || b == '*' || b == '/' || b == '(')
		{
			c = '<';
		}
	}
	else if (a == ')')
	{
		if (b == '+' || b == '-' || b == '*' || b == '/' || b == ')')
		{
			c = '>';
		}
	}
	return c;
}

int Operate(int a, char b, int c)//运算函数
{
	int sum = 0;
	switch (b)
	{
		case '+':
			sum = a + c;
			break;
		case '-':
			sum = a - c;
			break;
		case '*':
			sum = a * c;
			break;
		case '/':
			sum = a / c;
			break;
		default:
			break;
	}
	return sum;
	return 0;
}


int main()
{
	LinkStack OPND;
	CHAR OPTR;
	int num = 0;
	OPTR.Push('#');
	char theta;//运算符
	int a, b;//运算数
	char ch;//输入
	cin >> ch;
	while (ch != '#' || OPTR.GetTop() != '#') //while 循环
	{
		if (In(ch))//判断是否为字符
		{
			num = ((ch - '0') + num * 10);//因为数字是按字符单个读入的，所以先转换成数字。
			cin >> ch;
		}
		else
		{
			if (num != 0)//输入数字读取完毕，压入数字栈
			{
				OPND.Push(num);
				num = 0;//num 清零
			}
			switch (Precede(OPTR.GetTop(), ch))
			{
				case '<':
					OPTR.Push(ch);
					cin >> ch;
					break;
				case '>':
					theta = OPTR.Pop();
					b = OPND.Pop();
					a = OPND.Pop();
					OPND.Push(Operate(a, theta, b));
					break;
				case '=':
					OPTR.Pop();
					cin >> ch;
					break;
			}
		}
	}
	cout << OPND.GetTop();
	return 0;
}