#include<iostream>
#define null NULL
#include<cmath>
using namespace std;
typedef 
struct avlnode
{
	int data;
	avlnode *lchild;
	avlnode *rchild;
	int height;
}*avlptr;
int getHeight1(avlptr t)
{
	if(t==null)
	{
		return -1;
	}
	else
	{
		return (max(getHeight1(t->lchild),getHeight1(t->rchild))+1);
	}
}
void inOrder(avlptr t)
{
	if(t==null)
	return ;
	inOrder(t->lchild);
	cout<<t->data<<"  ";
//	cout<<"  h= "<<t->height<<" ";
	inOrder(t->rchild);
}
void preOrder(avlptr t)
{
	if(t==null)
	return ;
	cout<<t->data<<"  ";
	preOrder(t->lchild);
	preOrder(t->rchild);
}
void postOrede(avlptr t)
{
	if(t==null)
	return ;
	postOrede(t->lchild);
	postOrede(t->rchild);
	cout<<t->data<<" ";
}
int getHeight(avlptr t)
{
	if(t==null) return -1;
	return t->height;
}
void rightRotation(avlptr &k1)
{
	cout<<"RightRotation\n";
	avlptr k2=k1->lchild;
//	cout<<"k1->height= "<<k1->height<<endl;
//	cout<<"k2->height= "<<k2->height<<endl;
	k1->lchild=k2->rchild;
	k2->rchild=k1;
	k1->height=max(getHeight(k1->rchild),getHeight(k1->lchild))+1;
	
	k2->height=max(getHeight(k2->rchild),getHeight(k1))+1;
	k1=k2;
	
}
void leftRotation(avlptr &k1)
{
	cout<<"LeftRotation\n";
	avlptr k2=k1->rchild;
	k1->rchild=k2->lchild;
	k2->lchild=k1;
	k1->height=max(getHeight(k1->lchild),getHeight(k1->rchild))+1;
	k2->height=max(getHeight(k2->rchild),getHeight(k1))+1;
	k1=k2;
}
void doubleright(avlptr &k1)
{
	leftRotation(k1->lchild);
	rightRotation(k1);
}
void doubleleft(avlptr &k1)
{
	rightRotation(k1->rchild);
	leftRotation(k1);
}
void insert(avlptr &t,int key)
{
	if(t==null)
	{
		t=new avlnode;
		t->data=key;
		t->rchild=null;
		t->lchild=null;
		t->height=0;
	}
	else if(t->data>key)
	{
		insert(t->lchild,key);
		t->height=max(getHeight(t->rchild),getHeight(t->lchild))+1;
		if(abs(getHeight(t->lchild)-getHeight(t->rchild))>=2)
		{
			if(key<t->lchild->data)
			{
				rightRotation(t);
			}
			else
			{//cout<<"calling = "<<t->data<<endl;
				doubleright(t);
			}
		}		
	}
	else
	{
		insert(t->rchild,key);
		t->height=max(getHeight(t->rchild),getHeight(t->lchild))+1;
		if(abs(getHeight(t->lchild)-getHeight(t->rchild))>=2)
		{
			if(key>t->rchild->data)
			{
			cout<<"caling  data = "<<t->data<<endl;
				leftRotation(t);
			}
			else
			{cout<<"doublt\n";
				doubleleft(t);
			}
		}
	}
}


int main()
{
	avlptr t=null;
	int temp=1;
	while(1)
	{
		cout<<"Enter the key to insert \n";
		cin>>temp;
		if(temp==-1)
		{
			break;
		}
		insert(t,temp);
	}
	cout<<"InOrder Traversal is \n";
	inOrder(t);
	cout<<"\n PreOrder traversal is \n";
	preOrder(t);
	cout<<"\n PostOrder traversal is \n";
	postOrede(t);
}
