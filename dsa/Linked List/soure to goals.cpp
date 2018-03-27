#include<iostream>
using namespace std;
int j=0,a[50],t=0;
typedef
struct gnode
{
	int data;
	gnode *nx1;
	gnode *nx2;
	gnode *nx3;
} *gptr;
struct stack
{
	int size;
	int top;
    int ele[50];
};
void push(stack &s1,int x )
{
	if(s1.top==s1.size-1)
	{
		cout<<"Overflow of stack\n";
	}
	else
	{
		s1.top++;
		s1.ele[s1.top]=x;
	}
}
int  pop(stack &s1)
{
	if(s1.top==-1)
	{
		cout<<"Underflow\n";
	}
	else
	{	
	return (s1.ele[s1.top--]);
	}
}
/*void transverse(gptr g1)
{
    //cout<<"***\n";
	gptr t1,t2;
	t1=g1;
	if(t1->nx1!=NULL)
	{
		cout<<t1->data<<" ";
		t1=t1->nx1;//cout<<" 1 IF\n";
		if(t1->nx1!=NULL)
		transverse(t1);
	
	}
if(t1->nx2!=NULL)
	{
			cout<<t1->data<<" ";
		t1=t1->nx1;	
		if(t1->nx2!=NULL)
		transverse(t1);
	
	}
	 if(t1->nx3!=NULL)
	{
		cout<<t1->data;
			t1=t1->nx3;//	cout<<" 3 IF\n";
			if(t1->nx3!=NULL)
			transverse(t1);
	}
	else
	{
		return ;
	}
}*/
void transverse(gptr g,int i)
{
	gptr t;static int a[40];
	t=g;
if(g!=null)
{
a[i]=g->data;
i++;
//	cout<<t->data<<"   ";
	transverse(t->nx1,i);
	if(g->nx1==null&&g->nx2==null&&g->nx3==null)
	{
		for(int j=0;j<i;j++)
		{
			cout<<a[i]<<"  ";
		}
	}
	transverse(t->nx2,i);
	/*if(g->nx1==null&&g->nx2==null&&g->nx3==null)
	{
		for(int j=0;j<i;j++)
		{
			cout<<a[i]<<"  ";
		}
	}*/
	transverse(t->nx3,i);
}
}
void findit(gptr g1,int k,stack &s1)
{
	gptr t;
	t=g1;
//	if(t->data==k)
//	{
//		  push(s1,t->data);
//	}
	if(t==NULL)
	{
		return;
	}
	if(s1.ele[s1.top]!=k)
    push(s1,t->data);
	transverse(t->nx1,k,s1);
	if(s1.ele[s1.top]==k)
	{
      //pop(s1);
	transverse(t->nx2,k,s1);
	//pop(s1);
	transverse(t->nx3,k,s1);
	}
	else
	{
	pop(s1);
	transverse(t->nx2,k,s1);
	pop(s1);
	transverse(t->nx3,k,s1);
}
	//cout<<t->data<<"   ";
}
void create(gptr &g1)
{
    cout<<"#\n";
	int i,k,l;
	j++;
	gptr t1,t2,t3;
	t1=g1;
	int n1,n;//t1=new gnode;
	cout<<"enter  1 for added in first list 2 for second list and  3 for third list\n";
	cin>>n1;
	cout<<"Enter the data if link is present else enter 0\n";
	cin>>n;
    if(n==0)	
    {
		return;
	}	
	if(n1==1&&n!=0)
	{
		if(j==1)
		{
		t1->data=n;
		t1->nx2=NULL;
		t1->nx3=NULL;
       	t1->nx1=NULL;	
		create(t1);
	   }
	else 
	{
		t1->nx1=new gnode;
		t1=t1->nx1;
		t1->data=n;
		t1->nx2=NULL;
		t1->nx3=NULL;
       	t1->nx1=NULL;	
		create(t1);
	}
	}
	cout<<"return \n";
	cout<<"enter  1 for added in first list 2 for second list and  3 for third list\n";
	cin>>n1;	
	if(n1==0)
	return ;
    if(n1==2)
	{
	cout<<"Enter the data if link is present else enter 0\n";
	cin>>n;
	if(n!=0)
	{
	    t1->nx2=new gnode;
	    t1=t1->nx2;
	    t1->nx1=NULL;
	    t1->nx3=NULL;
		t1->data=n;
		t1->nx2=NULL;
		create(t1);

    }
	}	
	cout<<"return 2\n";
	cout<<"enter  1 for added in first list 2 for second list and  3 for third list\n";
	cin>>n1;
	if(n1==0)
	return ;
	if(n1==3)
	{
	cout<<"Enter the data if link is present else enter 0\n";
	cin>>n;
	if(n!=0)
	{
	    t1->nx3=new gnode;
	    t1=t1->nx3;
	    t1->nx2=NULL;
	    t1->nx1=NULL;
		t1->data=n;
		t1->nx3=NULL;
		create(t1);
    }
	}	
	cout<<"return3 \n";

}
int main()
{
	gptr g1,g2;
	stack s1;
	s1.top=-1;
	s1.size=50;
	g1=new gnode;
	create(g1);int k;int i=0;
	cout<<"Enter the key to be searched\n";
	cin>>k;
	transverse(g1,i);
	//cout<<k<<"  ";
	findit(g1,k,s1);
	//for(i=s1.top;i>0;i--)
	//{
	//	cout<<pop(s1)<<"  ";
	//}
	cout<<k<<"  ";
	return 0;
}
