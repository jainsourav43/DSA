//program to create binary search tree iteratively and delete the node a/c to wish 
#include<iostream>
#define null NULL
using namespace std;
typedef
struct bstnode
{
	bstnode *lchild;
	int data ;
	bstnode *rchild;
} *bstptr;
void ldr(bstptr t)
{
	if(t!=null)
	{
		//cout<<" ldr   "<<endl;
		ldr(t->lchild);
		if(t->data!=0)
		cout<<t->data<<"   ";
		ldr(t->rchild);
	}
}
void dlr(bstptr t)
{
   // cout<<"CALLING\n";
	if(t!=null)
	{		
	    cout<<t->data<<"   ";
		dlr(t->lchild);
		dlr(t->rchild);
	}
}
int  findmin(bstptr t)
{
	while(t->lchild!=null)
	{
		t=t->lchild;
	}
	return t->data;
}
int  findmax(bstptr t)
{	
	while(t->rchild!=null)
	{
		t=t->rchild;
	}
	return t->data;
}
void create1(bstptr t)
{
	     bstptr t1,t2;int d=1;int k1,k2;
         while(d!=-1)
         {
          t1=t;t2=t;
          cout<<"Enter the data or -1 to exit\n";
          cin>>d;
          if(d!=-1)
          {
		  while(t2!=null)
		  {k1=0;k2=0;
		  	if(t1->data>d)
		  	{k1=1;
		  	if(t1->lchild!=null)
		  	t1=t1->lchild;	
		  	t2=t2->lchild;
			  }
			  else
			  {k2=1;
			    if(t1->rchild!=null)
			  	t1=t1->rchild;
			  	t2=t2->rchild;
			  }
			  
	      }
		  if(k1==1)
		  {	
		  t1->lchild=new bstnode;
	      t1=t1->lchild;
          t1->data=d;
       	  t1->lchild=null;
     	  t1->rchild=null;
	      }
	      else
	      {
	      	 t1->rchild=new bstnode;
	      t1=t1->rchild;
          t1->data=d;
       	  t1->lchild=null;
     	  t1->rchild=null;
		  }
		  	 
		}
}
}
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
bstptr findit(bstptr t,int k)
{
	if(t->data==k)
	{//cout<<t->data<<"\n";cout<<"IF\n";
	return t;
   }
	else
	{//cout<<"ELSE\n";
	   if(t!=null)
	   {
		if(t->data>k)
		{
			findit(t->lchild,k);
		}
		else
		{
			findit(t->rchild,k);
		}
	}
	}
}
int prec,suc;
void predanc(bstptr t,int k)
{
	if(t!=null)
	{
	
	if(t->data==k)
	{cout<<"1\n";
		bstptr temp=t->lchild;
		while(temp!=null&&temp->rchild!=null)
		{
			temp=temp->rchild;
		}
		if(temp)
		prec=temp->data;
		temp=t->rchild;
		while(temp&&t->lchild!=null)
		{
			temp=temp->lchild;
		}if(temp)
		suc=temp->data;
	}
	else if(t->data>k)
	{cout<<"2\n";
		prec=t->data;
		predanc(t->lchild,k);
	}
	else
	{cout<<"3\n";
		suc=t->data;
		predanc(t,k);
	}
}

}
void deleteas(bstptr &t,int k)
{
	bstptr t3;int m;
	if(t==null)
	{cout<<"return \n";
		return ;
	}
	 if(t->data>k) 
	{
		deleteas(t->lchild,k);
	}
	else if(t->data<k)
	{
		deleteas(t->rchild,k);
	}
	else
	{   
		if(t->lchild!=null&&t->rchild!=null)
		{
		  m=findmin(t->rchild);
		  t->data=m;
		  deleteas(t->rchild,m);
	     }
	     else if(t->lchild!=null)
	     {
	     	m=findmax(t->lchild);
	     	t->data=m;
	     	deleteas(t->lchild,m);
		 }
		 else if(t->rchild!=null)
		 {
		 		m=findmin(t->rchild);
		 		t->data=m;
		 		deleteas(t->rchild,m);
		 }
	    else
	   {
	   bstptr t2=t;
	   delete t2;
	   cout<<"ELSE 3\n";
	   t=null;
	  }
}
}
int main()
{   
    int d=1;
	bstptr t=new bstnode;
	cout<<"Enter the data\n";
    cin>>d;
	t->data=d;
	t->lchild=null;
	t->rchild=null;
	create1(t);
	ldr(t);
	cout<<"\n";
	dlr(t);
	cout<<endl;
	cout<<"Enter the key for pred and suc\n";
	int k;
	cin>>k;
	predanc(t,k); 
	cout<<"Pred = "<<prec<<" succ= "<<suc<<endl;
	findmax(t);
	findmin(t);
	cout<<"Enter the data to be delete\n";
	cin>>k;
	deleteas(t,k);
	ldr(t);
	return 0;
}
