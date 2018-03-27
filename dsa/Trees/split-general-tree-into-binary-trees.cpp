#include<iostream>
using namespace std;

typedef struct gtnode{
	char key;
	int count;
	struct gtnode* parent;
	struct gtnode** next;
} *GTPTR;

typedef struct btnode{
	char key;
	struct btnode* lchild;
	struct btnode* rchild;
} *BTPTR;

void createTree(GTPTR &T,char ch)
{
	T->key = ch;
	cout<<"\nEnter number of children for "<<T->key<<": ";
	cin>>T->count;
	T->next = new struct gtnode* [T->count];
	for(int i=0;i<T->count;i++)
	{
		T->next[i] = NULL;
		cout<<"\nEnter child "<<i+1<<" for "<<T->key<<": ";
		cin>>ch;
		if(ch!='-')
		{
			T->next[i] = new struct gtnode;
			T->next[i]->parent = T;
			T->next[i]->key = ch;
			createTree(T->next[i],ch);
		}
	}
}

void printGT(GTPTR T)
{
	cout<<T->key<<" ";
	for(int i=0;i<T->count;i++)
	{
		printGT(T->next[i]);
	}
}

void insertBT(BTPTR &BT, GTPTR P, GTPTR C)
{
	if(BT->key == P->key)
	{
		if(BT->lchild==NULL)
		{
			BT->lchild = new struct btnode;
			BT->lchild->key = C->key;
			BT->lchild->lchild = NULL;
			BT->lchild->rchild = NULL;
		}
		else
		{
			BT->rchild = new struct btnode;
			BT->rchild->key = C->key;
			BT->rchild->lchild = NULL;
			BT->rchild->rchild = NULL;
		}
		return;
	}
	if(BT->lchild)
	insertBT(BT->lchild,P,C);
	if(BT->rchild)
	insertBT(BT->rchild,P,C);
}

bool allNextNull(GTPTR T)
{
	for(int i=0;i<T->count;i++)
	{
		if(T->next[i])
			return false;
	}
	return true;
}

int findChild(GTPTR P,GTPTR C)
{
	for(int i=0;i<P->count;i++)
	{
		if(P->next[i]==C)
			return i;
	}
	cout<<"\nERROR: Child Not Found";
	exit(0);
}

void split(GTPTR &T,BTPTR &BT)
{
	int f=0; 
	if(allNextNull(T))
	{
		if(T->parent == T)
		{
			T = NULL;
			return;
		}
		int i = findChild(T->parent,T);
		T->parent->next[i] = NULL;
	}
	else
	{
	for(int i=0;i<T->count;i++)
	{
		if(T->next[i])
		{
			insertBT(BT,T,T->next[i]);
			split(T->next[i],BT);
			f++;
			if(f==2)
			break;	
		}
	}
	if(allNextNull(T))
	{
		if(T->parent == T)
		{
			T = NULL;
			return;
		}
		int i = findChild(T->parent,T);
		T->parent->next[i] = NULL;
	}
	}
}

void printBT(BTPTR T)
{
	if(T->lchild)
	printBT(T->lchild);
	cout<<T->key<<" ";
	if(T->rchild)
	printBT(T->rchild);
}

int main()
{
	GTPTR T;
	T = new struct gtnode;
	T->parent = T;
	char data;
	cout<<"Enter data: ";
	cin>>data;
	createTree(T,data);
	printGT(T);
	cout<<endl;
	while(T)
	{
		BTPTR BT = new struct btnode;
		BT->key = T->key;
		BT->lchild = NULL;
		BT->rchild = NULL;

		split(T,BT);
		cout<<"Binary Tree: ";
		printBT(BT);
		cout<<endl;
	}
	
	return 0;
}
