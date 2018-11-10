#include <stdio.h>
#include <iostream>

using namespace std;


struct Node
{
	int Data;
	struct Node *pNext;
};
typedef struct Node NODE;

struct List
{
	NODE *pHead;
	NODE *pTail;
};
typedef struct List LIST;

void Init(LIST &l)
{
	l.pHead = l.pTail = NULL;
}
NODE* GetNODE(int x)
{
	NODE *p = new NODE;
	if (p == NULL)
	{
		return NULL;
	}
	p->Data = x;
	p->pNext = NULL;
	return p;
}

void AddHead(LIST &l, NODE *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

void AddTail(LIST *l, NODE *p)
{
	if (l->pHead == NULL)
	{
		l->pHead = l->pTail = p;
	}
	else
	{
		l->pTail->pNext = p;
		l->pTail = p;
	}
}

int Length(LIST L)
{
	NODE *P = new NODE();
	P = L.pHead;
	int i = 0;
	while (P != NULL)
	{
		i++;
		P = P->pNext;
	}
	return i;
}

void removeHead(LIST &l)
{
	if (l.pHead == NULL)
	{
		cout << "List empty!";
	}
	else if (l.pHead == l.pTail)
	{
		delete(l.pHead);
		l.pHead = l.pTail = NULL;
	}
	else
	{
		NODE *temp = l.pHead;
		l.pHead = l.pHead->pNext;
		delete(temp);
	}
}

void removeTail(LIST &l)
{
	if (l.pHead == NULL)
	{
		cout << "List empty!";
	}
	else if (l.pHead == l.pTail)
	{
		delete(l.pHead);
		l.pHead = l.pTail = NULL;
	}
	else
	{
		NODE *temp = l.pHead;
		while (temp->pNext != l.pTail)
		{
			temp = temp->pNext;
		}
		delete(l.pTail);
		l.pTail = temp;
	}
}

void removeX(LIST &L, int x)
{
	NODE *p = L.pHead;
	while (p!=NULL)
	{
		if (p->Data == x)
		{
			NODE *q = new NODE();
			q = p;
			p = q->pNext;
			delete(q);
		}
		p = p->pNext;
	}
}



int Search(LIST L, int x)
{
	Node *P = L.pHead;
	int i = 1;
	while (P != NULL && P->Data != x) 
	{
		P = P->pNext;
		i++;
	}
	if (P != NULL) return i; 
	else return 0; 
}

void InPut(LIST &l, int n)
{
	Init(l);
	for (int i = 1; i <= n; i++)
	{
		int x;
		printf("\nNhap vào data: ");
		scanf("%d", &x);

		NODE *p = GetNODE(x);
		AddHead(l, p);
	}
}


void OutPut(LIST l)
{
	for (NODE *p = l.pHead; p != NULL; p = p->pNext)
	{
		printf("%4d", p->Data);
	}
}

int main()
{
	LIST l;
	int n;
	printf("\nBan mu?n nh?p bao nhiêu Node: ");
	scanf("%d", &n);
	InPut(l, n);
	OutPut(l);
}