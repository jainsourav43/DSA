#include<iostream>
#define null NULL
using namespace std;
char red='r',black='b';
typedef 
struct rbnode
{
	int data;
	char color;
	rbnode* lchild;
	rbnode* rchild;
	rbnode* p;
}* rbptr;
void print(rbptr t)
{
	if(t==null)
	{
		return;
	}
	print(t->lchild);
	cout<<t->data<<" ";
	print(t->rchild);
}
void leftrotate(rbptr k1)
{
//	rbptr temp1,temp2;
//	temp1=k1->p;
cout<<"k1->data = "<<k1->data<<endl;

    cout<<"Left\n";
	rbptr k2=k1->rchild;
	k1->rchild=k2->lchild;
	cout<<"hii\n";
	if(k2->lchild)
	k2->lchild->p=k1;
	cout<<"bolo\n";
	if(!k1) cout<<"k1 null\n";
	if(!k2) cout<<"k2null\n";
	k2->p=k1->p;
	cout<<"bye\n";
	if(k1==k1->p->lchild)
	k1->p->lchild=k2;
	else
	{
		k1->p->rchild=k2;
	}
	cout<<"ch\n";
	k2->lchild=k1;
	k1->p=k2;
//	k1=k2;
	cout<<"BAck\n";
}
void rightrotate(rbptr k1)
{
	cout<<"Right\n";
	cout<<"k1->p->data= "<<k1->p->data<<endl;
		cout<<k1->p<<endl;
	rbptr k2=k1->lchild;
		cout<<k1->p<<endl;
	k1->lchild=k2->rchild;
		cout<<k1->p<<endl;
	cout<<"CHeck1\n";
	if(k2->rchild)
	{
	cout<<"k2->r->p ="<<k2->rchild->p->data<<endl;
	k2->rchild->p=k1;
    } 
	cout<<"Check2\n";
		cout<<"k1->data= "<<k1->data<<endl;

		cout<<k1->p<<endl;
		//cout<<"k` ="<<k1<<endl;
	k2->p=k1->p;
		cout<<k1->p<<endl;
				cout<<"k1->data= "<<k1->data<<endl;

	cout<<"check4\n";
	cout<<k1->p<<endl;
	if(k1&&k1->p&&k1==k1->p->lchild)
	{
		k1->p->lchild=k2;
	}
	else
	{
		k1->p->rchild=k2;
	}
	cout<<"CHeck3\n";
	k2->rchild=k1;
	k1->p=k2;
	cout<<"back\n";
}
void insertFix(rbptr t)
{
	cout<<"Fixing for "<<t->data<<endl;
	if(t->p==null)
	{
		cout<<"Root Check\n";
		if(t->color==red)
		{
			cout<<"Changing root Colour\n";
			t->color=black;
			return ;
		}
		else
		{
			return ;
		}
	}
	if(t->p->p==null)
	{
		cout<<"Return\n";
		return ;
	}
	if(t->p->color==red)
	{
		if(t->p==t->p->p->lchild)
		{
			if((t->p->p->rchild)&&t->p->p->rchild->color==red)
			{
				cout<<"CASE1\n";
				t->p->color=black;
				t->p->p->rchild->color=black;
				t->p->p->color=red;
			}
			else if(t==t->p->rchild)
			{
				cout<<"CASE2\n";
				t=t->p;
				cout<<"t->data"<<t->data<<endl; 
				leftrotate(t);
				cout<<"Printing in Emergency\n";
				print(t);
				cout<<endl;
				t->p->color=black;
				t->p->p->color=red;
				cout<<"t->p->p-> data= "<<t->p->p->data<<endl;
				rightrotate(t->p->p);
				
			}
			
		}
		else
		{
			if((t->p->p->lchild)&&t->p->p->lchild->color==red)
			{
				cout<<"CASE3\n";
				t->p->color=black;
				t->p->p->lchild->color=black;
				t->p->p->color=red;
			}
			else if(t==t->p->lchild)
			{
				cout<<"CASE4\n";
				t=t->p;
				rightrotate(t);
				t->p->color=black;
				t->p->p->color=red;
				leftrotate(t->p->p);
			}
		}
	}	
}
void Insert(rbptr &t,int key,rbptr par)
{
	if(t==null)
	{
		t=new rbnode;
		t->data=key;
		t->lchild=NULL;
		t->p=par;
		t->rchild=null;
		t->color=red;
		insertFix(t);
		cout<<"Back from Fix\n";
	}
	else  if(t->data>key)
	{
		Insert(t->lchild,key,t);
		cout<<"hii\n";
		insertFix(t);
	
	}
	else
	{
		Insert(t->rchild,key,t);
		cout<<"bye\n";
		insertFix(t);
	}
}

int main()
{
	cout<<"Welcome to the world of RED-BLACK Tree\n";
	rbptr t=null;
	int key;
	while(1)
	{
		cout<<"Enter the Key to Insert else -1\n";
		cin>>key;
		if(key==-1)
		{
			break;
		}
		Insert(t,key,null);
		cout<<"Currently Tree is \n";
		print(t);
		cout<<endl;
	}
}

