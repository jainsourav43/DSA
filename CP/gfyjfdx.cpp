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
    cout<<"###\n";
	mptr t1,t2;
	t1=m1;
	while(t1->next!=NULL)
	{cout<<"&&\n";
	if(t1->tag==-1)
	{
		return ;
	}
	else if(t1->tag==0)
	{
		cout<<t1->data.d<<endl;
	}
	else if(t1->tag==1)
	{
		print(t1->data.dptr);
	}
	t1=t1->next;
    }
}
void create(mptr m1)
{
    cout<<"***\n";
	mptr t1,t2;j=0;
t1=m1;char n;
	cout<<"Enter 0 for data and 1 for down pointer or -1 for ending the list\n";
	cin>>t1->tag;
	while(t1->tag!=-1)
	{	j++;
	if(t1->tag==-1)
	{
    	return ;		
	}
	else if(t1->tag==0)
	{
		if(j==1)
		{cout<<"1\n";
		cout<<"Enter the character\n";
		cin>>n;
		t1->data.d=n;
		t1->next=NULL;
		}
		else
		{cout<<"2\n";
		cout<<"Enter the character\n";
		cin>>n;
		t1->data.d=n;	
		t1->next=NULL;
		}
	}
	else if(t1->tag==1)
	{   
	    print(m1);
	    //t1->next=new mnode;
	    cout<<"AFTER PRINT\n";
		t1->data.dptr=new mnode;
		create(t1->data.dptr);
	}
	cout<<"Enter 0 for data and 1 for down pointer or -1 for ending the list\n";
	cin>>t1->tag;
	if(t1->tag!=-1)
	{
	    t1->next=new mnode;
		t1=t1->next;
    }
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
