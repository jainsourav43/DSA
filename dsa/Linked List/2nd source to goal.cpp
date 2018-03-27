#include<iostream>
using namespace std;
typedef
struct gnode
{
	int data;
	int count;
	gnode **next;
} *gptr;
void create(gptr &g)
{
  cout<<"***\n";
  int n1,i,j=0;
  gptr t1;
  t1=g;
  t1=new gnode;
  cout<<"Enter the no of pointer\n";
  cin>>n1;
  t1->count=n1;
  cout<<"Enter the data\n";
  cin>>i;
  t1->data=i;
  t1->next=new (gnode*)*n1;
  while(j!=t1->count)
  {
    cout<<"&&&\n";
  	create(g->next[j]);
  	j++;
  }
}
void print(gptr g)
{
	gptr t1,t2;
	t1=g;int j=0;
	if(t1->next[j]==NULL)
	{
		return ;
	}
	cout<<t1->data<<"   ";
	while(t1->count--)
	{
	print(t1->next[j]);
	j++;
    }
}
int main()
{
	gptr g;
	int i,c,n;
	create(g);
	print(g);
	return 0;
}
