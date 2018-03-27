#include<iostream>
#define null NULL
using namespace std;
typedef
struct gnode
{
	int data;
	gnode **next;
	int count;
} *gptr;
void create(gptr &g)
{
	int c,i,d,j,k;
	cout<<"\nEnter the data otherwise -1\n";
	cin>>d;
	if(d==-1)
	{
		return ;
	}
	cout<<"\nEnter the number of nodes\n";
	cin>>c;
	if(g==null)
	{
	g=new gnode;
	g->data=d;
	g->count=c;
	g->next=new gnode*[(g->count)];
    for(int h=0;h<g->count;h++)
    g->next[h]=null;
	} 
	for(int f=0;f<g->count;f++)
	{
		create(g->next[f]);
		cout<<"\n Your Current location is \n  "<<g->data;
     }
}
void transverse(gptr g,int i)
{
gptr t;static int a[40];
t=g;
if(g!=null)
{
a[i]=g->data;
i++;
//	cout<<t->data<<"   ";
	transverse(t->next[0],i);
	cout<<endl;
	if(g->count==0)
	{
		for(int j=0;j<i;j++)
		{
		cout<<" "<<a[j]<<"  ";
		}cout<<endl;
	}
	if(g->count>1)
	transverse(t->next[1],i);
//	cout<<endl;
    if(g->count>2)
	transverse(t->next[2],i);
}
}
int main()
{
	gptr g=null;
	create(g);
	int i=0;
	transverse(g,i);
}
