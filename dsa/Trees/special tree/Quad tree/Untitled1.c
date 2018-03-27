
#include<iostream>
#define null NULL
#include<string.h>
using namespace std;
struct trnode;
struct leafnode;
union un
{
	trnode **ptr1;
	leafnode *ptr2;
};
struct leafnode
{
	char key[50];
};
typedef
struct trnode
{
	union un ptr;
	int tag;
	int count;
} *trptr;
void create(trptr &tr,char str1[],char str[])
{
	leafnode *l1;int k=0,i,j;
	for(i=0;i<strlen(str);i++)
	{
		if(str1[i]==str[i])
		{
			break;
		}
	}
	if(tr->ptr.ptr1[i]->tag==0)
	{
		l1=tr->ptr.ptr1[i]->ptr.ptr2;
		for(j=0;(str1[j]==tr->ptr.ptr2->key[j])&&j<strlen(str1);j++)
		{
			k++;
			tr->ptr.ptr1[i]=new trnode;
			tr=tr->ptr.ptr1[i];
		    for(i=0;i<strlen(str);i++)
			{
				if(str1[k]==str[j])
				{
					break;
				}
			}
			i=j;
		}
	}
	else
	{
		leafnode *l;
		l=new leafnode;
		strcpy(l->key,str1);
		tr->ptr.ptr1[i]=new trnode;
		tr=tr->ptr.ptr1[i];
		tr->tag=0;
		tr->ptr.ptr2=l;
	}
}
void print(trptr tr,int n)
{
	if(tr!=null)
	{
	   for(int i=0;i<=n;i++)
	   {
	   	   if(tr->tag==1)
	   	   {
	   	   	print(tr->ptr.ptr1[i],n);
		   }
		   else if(tr->tag==0)
		   {
		   	cout<<tr->ptr.ptr2->key<<"    ";
		   }
	   }
    }
}
int main()
{
	trptr tr;
	leafnode *l;
	l=new leafnode;
	cout<<"Enter the no of characters u will be using \n";
	int n,i;
	cin>>n;
	cout<<"Enter the String\n";
	char str[27],str1[27];
	cin>>str;
	tr=new trnode;
	tr->ptr.ptr1=new trptr[n];
	tr->tag=1;
	for(i=0;i<=n;i++)
	{
		tr->ptr.ptr1[i]=null;
	}
	cout<<"Enter the input string \n";
	cin>>str1;
	for(i=0;i<strlen(str);i++)
	{
		if(str1[i]==str[i])
		{
			break;
		}
	}
	strcpy(l->key,str1);
	tr->ptr.ptr1[i]=new trnode;
	tr->ptr.ptr1[i]->tag=0;
	tr->ptr.ptr1[i]->ptr.ptr2=l;
	int ch=1;
	while(ch!=-1)
	{

		cout<<"enter 1 for continue else -1\n";
		cin>>ch;
		if(ch!=-1)
		{
		cout<<"Enter the string to input\n";
		cin>>str1;
		create(tr,str1,str);
	   }
	}
}
