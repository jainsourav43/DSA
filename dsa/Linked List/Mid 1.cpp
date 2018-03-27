#include<iostream>
#define null NULL
using namespace std;
typedef
struct bstnode
{
	int data;
	bstnode *lchild;
	bstnode *rchild;
}*bstptr;
typedef 
struct lnode
{
	lnode *next;
	bstptr tr;
	int data1;
}*lptr ;
void insert(bstptr &t,int k)
{
	if(t==null)
	{
	
		t=new bstnode;
		t->data=k;
		t->lchild=null;
		t->rchild=null;
	}
	else if(k<t->data)
	{
		insert(t->lchild,k);
	}
	else
	{
		insert(t->rchild,k);
	}
}
void ldr(bstptr t)
{
	if(t!=null)
	{
		ldr(t->lchild);
		cout<<t->data<<"   ";
		ldr(t->rchild);
	}
}
void addend(lptr l,int d)
{
	lptr t=l;int c=1;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=new struct lnode;
	t=t->next;
	t->data1=d;
	t->tr=null;
	while(c!=-1)
	{
	    cout<<"Enter the data to be entered in the tree else -1 \n";
	    cin>>c;
	    if(c!=-1)
		insert(t->tr,c);
	}
	t->next=NULL;
}

void create(lptr &l)
{
	int d=1;
	cout<<"Enter the first data to be entered in the linked list else -1\n";
	cin>>d;int c=1;
	l=new lnode;
	l->data1=d;
	l->tr=null;
	l->next=null;
	while(c!=-1)
	{
		cout<<"Enter the data to be entered in the tree else -1 \n";
	    cin>>c;
	    if(c!=-1)
	    insert(l->tr,c);
	}
	while(d!=-1)
	{
	cout<<"Enter the  data to be entered in the linked list else -1\n";
	cin>>d;
	if(d!=-1)
	{
		addend(l,d);
	}
	}
}
/*int f=0;
void print(lptr l)
{
	if(l!=null&&f==0)
	{cout<<"1enter \n";
		cout<<l->data1<<"  ";
		if(l->next!=null)
		cout<<l->next->data1<<":  ";f=1;
    }	
 	if(l!=null&&(l->tr!=null))
     {
	        cout<<"2wnetr\n";
	 		l->tr=l->tr->lchild;
	 		cout<<"a\n";
			print(l);cout<<"B\n";
			if(l->tr!=null)
			{
			cout<<l->tr->data<<"   ";cout<<"G\n";
	     	}
		cout<<"f\n";
		if(l->tr!=null)
			l->tr=l->tr->rchild;cout<<"c\n";
			print(l);cout<<"d\n";
			l=l->next;cout<<"e\n";
			f=0;	
     }
 }*/
 void print(lptr l,bstptr t)
 {
 	static int f=0;int k=0;
 	while(l)
 	{
 		if(f==0)
 		{
 			cout<<l->data1<<" - ";
			 if(l->next!=null)
			 {
			 	cout<<l->next->data1<<"  ";
			  } 
			  else 
			  cout<<"-";
			  f++; 
			  print(l,l->tr);
			  if(l->next!=null)
			  cout<<endl;
			  f=0;
		 }
		 else if(t!=null) 
		 {
		 	print(l,t->lchild);
		 	cout<<t->data<<"  ";
		 	k=1;
		 	print(l,t->rchild);//cout<<endl;
		 }
		  l=l->next;
		 if(k==1)
		 break;
		
	 }
	// if(f==0)
	  //cout<<endl;
 }
int search(lptr l,bstptr t,int k)
{
	if(l!=null)
	{
		if(l->next!=null&&l->data1<k&&l->next->data1>k||(l->next==null&&l->data1<k))
		{
		if(t!=null)
		{
			if(t->data>k)
			{//cout<<"Enter \n";
				return search(l,t->lchild,k);
			//	cout<<"RETURN \n";
			}
			else if(t->data<k)
			{//cout<<"2\n";
				return search(l,t->rchild,k);
			}
			else if(t->data==k)
			{//cout<<"3\n";
				return 1;
			}
		}
		}
		else if(l->next!=null&&l->data1<k&&l->next->data1<k)
		{//cout<<"4\n";
			return search(l->next,l->next->tr,k);
		}
		else if(l->data1>k)
		{//cout<<"5\n";
			return -1;
		}
	}
	return -1;
}
int main()
{
 lptr l=null;
 create(l);
// cout<<l->data1<<"  ";
//if(l->next!=null)
//cout<<l->next->data1<<":  ";
 print(l,l->tr);

int k,ans;
 int y=5;
 while(y--)
 { cout<<"Enter the key to search\n";
  cin>>k;
  ans=search(l,l->tr,k);
 cout<<"Ans = "<<ans<<endl;
}
}
