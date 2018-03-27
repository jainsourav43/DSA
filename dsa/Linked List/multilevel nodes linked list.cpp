#include<iostream>
using namespace std;
int j=0;
typedef
struct mnode
{
	union u
	{
		char d;
		mnode *dptr;
	}data;
	int tag;
	struct mnode *next;
} *mptr;
void print(mptr m1)
{  
    //cout<<"###\n";
	mptr t1,t2;
	t1=m1;cout<<"(";
	while(t1->next!=NULL)
	{//cout<<"&&\n";
	if(t1->tag==-1)
	{
		return ;
	}
	else if(t1->tag==0)
	{
		cout<<t1->data.d;
	}
	else if(t1->tag==1)
	{
		print(t1->data.dptr);
	}
	t1=t1->next;
    }cout<<")";
}
void create(mptr &m1)
{
	mptr t1,t2;j=0;
    t1=m1;char n;
	while(t1->tag!=-1)
	{	j++;
	cout<<"Enter 0 for data and 1 for down pointer or -1 for ending the list\n";
	cin>>t1->tag;
	if(t1->tag==-1)
	{
    	return ;		
	}
	else if(t1->tag==0)
	{
		if(j==1)
		{
		cout<<"Enter the character\n";
//		cin>>n;
//		t1->data.d=n;
//		t1->next=NULL;
//		}
//		else
//		{
//		cout<<"Enter the character\n";
		cin>>n;
		t1->data.d=n;	
		t1->next=NULL;
		}
	}
	else if(t1->tag==1)
	{   
	   // print(m1);
	    //t1->next=new mnode;
	   // cout<<"AFTER PRINT\n";
		t1->data.dptr=new mnode;
		create(t1->data.dptr);
	}
	    t1->next=new mnode;
		t1=t1->next;
		t1->next=NULL;
    }
}
int main()
{
	mptr m1,m2;
	m1=new mnode;
	create(m1);
	print(m1);
	return 0;
}
