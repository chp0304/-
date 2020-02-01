#pragma once
#include<iostream>
#define OK 1
#define ERROR 0
using namespace std;
class CHAR
{
private:
	typedef struct StackNode
	{
		char data;
		struct StackNode *next;
	}*Stack;

public:
	Stack S = NULL;
	CHAR()
	{
		InitStack();
	}

	int InitStack()//初始化
	{
		S = NULL;
		return OK;
	}

	int Push(char e)//入栈
	{
		Stack p = new StackNode;
		p->data = e;
		p->next = S;
		S = p;
		return OK;
	}

	char Pop()//出栈
	{
		if (S == NULL) return ERROR;
		int e = S->data;
		Stack p = S;
		S = S->next;
		delete p;
		return e;
	}

	char GetTop()//获得栈顶元素
	{
		if (S == NULL) return ERROR;
		return S->data;
	}

	int StackEmpty()
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


};



