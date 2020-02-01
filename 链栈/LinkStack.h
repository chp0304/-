#pragma once
#include<iostream>
#define OK 1
#define ERROR 0
using namespace std;
class LinkStack
{
	private :
		typedef struct StackNode
		{
			int data;
			struct StackNode *next;
		}*Stack;

	public :
		Stack S = NULL;
		LinkStack()
		{
			InitStack();
		}

		int InitStack()//初始化
		{
			S = NULL;
			return OK;
		}

		int Push(int e)//入栈
		{
			Stack p = new StackNode;
			p->data = e;
			p->next = S;
			S = p;
			return OK;
		}

		int Pop()//出栈
		{
			if (S == NULL) return ERROR;
			int e = S->data;
			Stack p = S;
			S = S->next;
			delete p;
			return e;
		}

		int GetTop()//获得栈顶元素
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

