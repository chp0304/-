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

		int InitStack()//��ʼ��
		{
			S = NULL;
			return OK;
		}

		int Push(int e)//��ջ
		{
			Stack p = new StackNode;
			p->data = e;
			p->next = S;
			S = p;
			return OK;
		}

		int Pop()//��ջ
		{
			if (S == NULL) return ERROR;
			int e = S->data;
			Stack p = S;
			S = S->next;
			delete p;
			return e;
		}

		int GetTop()//���ջ��Ԫ��
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

