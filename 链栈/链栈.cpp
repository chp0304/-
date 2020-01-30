#include<iostream>
#define OK 1
#define ERROR 0
using namespace std;

typedef struct StackNode
{
	int data;
	struct StackNode *next;
}*LinkStack;

int InitStack(LinkStack &S)//初始化
{
	S = NULL;
	return OK;
}

int Push(LinkStack &S, int e)//入栈
{
	LinkStack p = new StackNode;
	p->data = e;
	p->next = S;
	S = p;
	return OK;
}

int Pop(LinkStack &S)//出栈
{
	if (S == NULL) return ERROR;
	int e = S->data;
	LinkStack p = S;
	S = S->next;
	delete p;
	return e;
}

int GetTop(LinkStack S)//获得栈顶元素
{
	if (S == NULL) return ERROR;
	return S->data;
}

int StackEmpty(LinkStack S)
{
	if (S == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main()
{
	LinkStack S;//十进制转八进制
	InitStack(S);
	int n;
	cin >> n;
	while (n)
	{
		Push(S, n % 8);
		n /= 8;
	}
	while (StackEmpty(S))
	{
		cout << Pop(S);
	}
	cout << endl;
	return 0;
}