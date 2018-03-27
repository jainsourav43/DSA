#include<iostream>
#define null NULL
#define m 3
using namespace std;
typedef
struct mstnode
{
	int key[m];
	mstnode *ptr[m+1];
	int count;
}*mstptr;
void print(mstptr t)
{
	if(t!=null)
	{
		for(int i=0;i<=t->count;i++)
		{
			if(t->ptr[i]!=null)
			{
				print(t->ptr[i]);
			}
			if(i<t->count)
			cout<<t->key[i]<<"   ";
		}
	}
}
void insert(mstptr &t,int f)
{
	int i,k;int temp,temp1;
	if(t==null||t->count<m)
	{
		if(t!=null)
		{		t->count=t->count+1;

		for(i=0;i<t->count;i++)
		{
			if(t->key[i]>f)
			{
				t->key[0]=f; temp=t->key[0];
				for(int j=i;j<=t->count-1;j++)
				{
					t->key[j+1]=temp;
				}print(t);cout<<endl;
			}
			else
			{
				for(i=0;i<t->count;i++)
				{
					if(t->key[i]>f)
					{
						k=i;
					}
					else
					{
					temp=t->key[k+1];	t->key[k+1]=f;
						for(i=k+1;i<t->count-1;i++)
						{	temp1=t->key[i+1];
						t->key[i+1]	=temp;
						temp=temp1;
						}print(t);cout<<endl;
					}
				}
			}
		}
	}
	else
	{
	t=new mstnode;
	t->count=0;
	t->key[0]=f;
	for(int i=0;i<=m;i++)
	{
		t->ptr[i]=null;
	}	
	}	
	}
	else //if(t->key[0]<f||t->key[m-1]>f)
	{
			if(t->key[0]>f)
			{
			insert(t->ptr[0],f);print(t);cout<<endl;
			}
			else if(t->key[m-1]<f)
			{
				insert(t->ptr[m],f);print(t);cout<<endl;
			}
			for(i=0;i<t->count-1;i++)
		if(t->key[i]<f&&t->key[i+1]>f)
		{
			insert(t->ptr[i],f);print(t);cout<<endl;
		}
	}
}

int main()
{
	mstptr t;
	int f;
	cout<<"Enter the data to insert\n";
	cin>>f;
	t=new mstnode;
	t->count=0;
	t->key[0]=f;
	for(int i=0;i<=m;i++)
	t->ptr[i]=null;
	t->count=t->count+1;
	while(f!=-1)
	{
	cout<<"Enter the data to insert\n";
	cin>>f;
	if(f!=-1)
	{
		insert(t,f);
	}
    }
    print(t);
}

