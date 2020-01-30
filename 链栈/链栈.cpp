#include<iostream>
#define OK 1
#define ERROR 0
using namespace std;

typedef struct StackNode
{
	int data;
	struct StackNode *next;
}*LinkStack;

int InitStack(LinkStack &S)//��ʼ��
{
	S = NULL;
	return OK;
}

int Push(LinkStack &S, int e)//��ջ
{
	LinkStack p = new StackNode;
	p->data = e;
	p->next = S;
	S = p;
	return OK;
}

int Pop(LinkStack &S)//��ջ
{
	if (S == NULL) return ERROR;
	int e = S->data;
	LinkStack p = S;
	S = S->next;
	delete p;
	return e;
}

int GetTop(LinkStack S)//���ջ��Ԫ��
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
	LinkStack S;//ʮ����ת�˽���
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