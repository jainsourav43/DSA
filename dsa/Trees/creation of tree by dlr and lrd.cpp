#include<iostream>
#include<string.h>
#define null NULL
using namespace std;
int size1,size2,sd=0,ld,y=0;
bool v[50];
char ldr1[50],lrd1[50];
typedef
struct btnode
{
	btnode *lchild;
	char data ;
	btnode *rchild;
} *btptr;
void ldr(btptr t)
{
   // cout<<"CALLING\n";
	if(t!=null)
	{
		ldr(t->lchild);
		cout<<t->data<<"   ";
		ldr(t->rchild);
	}
}
void dlr(btptr t)
{
   // cout<<"CALLING\n";
	if(t!=null)
	{
		
		cout<<t->data<<"   ";
		dlr(t->lchild);
		dlr(t->rchild);
	}
}
void create(btptr &t,int sl,int ll)
{   
if(sl<=ll)
{
//cout<<"CAlling\n";
    int j=sl,i;
	if(t==null&&sd>=0)
	{
		t=new btnode;
		t->data=lrd1[sd];
		t->lchild=null;
		t->rchild=null;
		sd--;
	}
	for(i=sl;i<=ll;i++)
	{
		if(lrd1[sd+1]!=ldr1[i])
		j++;
		else
		{//cout<<"BREAK\n";
		break;
		}//cout<<"FOR \n";
	}//cout<<"J   "<<j;
	v[j]=true;
	if(j+1<=size2&&v[j+1]==false)
	create(t->rchild,j+1,ll);
	if(j-1>=0&&v[j-1]==false)
    create(t->lchild,sl,j-1);
	/*j=0;
	for(i=sl;i<=ll;i++)
	{
		if(dlr1[sd-1]!=lrd1[i])
		j++;
		else
		break;cout<<"FOR 2\n";
	}
	v[j]=true;*/
	
}
}
int main()
{

	btptr t=null;int s1=0;int s2=0;
	cout<<"Enter the ldr string \n";
	cin>>ldr1;
	cout<<"Enter the LRD string \n";
	cin>>lrd1;
	size2=strlen(ldr1);//cout<<"SIZE2  "<<size2;
	size1=strlen(lrd1);	
	sd=size1-1;
	cout<<"sd\n"<<sd;
	for(int y=0;y<size2;y++)
      v[y]=false;
	create(t,s2,size2-1);
	ldr(t);cout<<"\n";
	dlr(t);
	return 0;
}
