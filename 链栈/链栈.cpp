#include"LinkStack.h"
#include"CHAR.h"
#include<iostream>
using namespace std;
int In(char ch)//�ж��Ƿ�Ϊ����
{
	if (ch >= '0' && ch <= '9')
	{
		return 1;
	}
	return 0;
}

char Precede(char a, char b)//�Ƚ��ַ����ȼ�
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

int Operate(int a, char b, int c)//���㺯��
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
	char theta;//�����
	int a, b;//������
	char ch;//����
	cin >> ch;
	while (ch != '#' || OPTR.GetTop() != '#') //while ѭ��
	{
		if (In(ch))//�ж��Ƿ�Ϊ�ַ�
		{
			num = ((ch - '0') + num * 10);//��Ϊ�����ǰ��ַ���������ģ�������ת�������֡�
			cin >> ch;
		}
		else
		{
			if (num != 0)//�������ֶ�ȡ��ϣ�ѹ������ջ
			{
				OPND.Push(num);
				num = 0;//num ����
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