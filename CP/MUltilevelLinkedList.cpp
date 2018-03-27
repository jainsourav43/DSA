#include<iostream>
#include<string.h>
#define null NULL
using namespace std;
typedef struct mnode
{
	char data;
	mnode* dptr;
	mnode *next;
}*mptr;

struct multiarray
{
	char ch;
	mnode *list;
};
multiarray arr[50];
void print(mptr m)
{
	if(m!=null)
	{
		//cout<<"( ";
		cout<<m->data<<" ";
		if(m->dptr!=null)
		{
			cout<<"( ";
			print(m->dptr);
			cout<<"  ) ";
		}
		print(m->next);
		//cout<<" ) ";
		
	}
}
void create(mptr &m)
{
	char temp;
	if(m==null)
	{
		cout<<"Enter the Data to Enter other wise '.' \n";
		cin>>temp;
		if(temp=='.')
		return;
		m=new mnode;
		m->data=temp;
		m->dptr=null;
		m->next=null;
	
	cout<<" Starting a new subset after  "<<temp<<" otherwise u can press '.' \n";
	create(m->dptr);
	cout<<"Extending the same set after  "<<temp<<" otherwise u can press '.' \n";
	create(m->next);
	}
}
char str[50];
int no=0; char ch='B';
void createwith(mptr &m)
{
	static int i=1;
	if(m==null&&i<strlen(str))
	{
		m=new mnode;
		m->data=str[i];
		m->dptr=null;
		m->next=null;
		i++;
		if(str[i]=='(')
		{
			i++;
			
			createwith(m->dptr);
			arr[no].list=m->dptr;
			arr[no].ch=ch++;
			no++;
		}
		if(str[i]==')')
		{
		i++;
		return ;
		}
		createwith(m->next);
	}
}

int main()
{
	
	cout<<"Enter the String with proper brackets\n";
	cin>>str;
	mptr m=null;
	no=1;
	createwith(m);
	arr[0].list=m;
	arr[0].ch='A';
	cout<<"( ";
	print(m);
	cout<<" )";
	cout<<endl;
	for(int i=0;i<no;i++)
	{
		
		cout<<"set of the list   "<<arr[i].ch<<" is  \n";
		while(arr[i].list!=null)
		{
			cout<<arr[i].list->data<<"  ";
			arr[i].list=arr[i].list->next;
		}
		cout<<endl;
	}
}
