#include<iostream>
using namespace std;
#define N NULL
int maxe,h=0;int c=0,k=0;
typedef
struct dnode
{
	dnode *left;
	int data;
	dnode *right;
} *dptr;
typedef
struct rnode
{
	dptr bktptr;
	rnode *next;
} *rptr;
typedef
struct node
{
	int data;
	struct node *next;
} *lptr;
void addbegin(lptr &l1,int d)
{
	lptr t;
	t=new struct node;
	t->data=d;
	t->next=l1;
	l1=t;	
}
void addbegin(dptr &d,int n)
{
	cout<<"Enter the data you want to enter\n";
	int d1;
//	cin>>d1;
	dptr t1,t2;
	t1=new dnode;
	t1->data=n;
	//cout<<"FUNCTION"<<t1->data<<endl;
	t1->left=NULL;
	t1->right=d;
	d=t1;	
}
void addend(dptr d,int n)
{
	dptr t1,t2;
	t1=d;
	while(t1->right!=NULL)
	{
		t1=t1->right;
	}
	t2=t1;
	t1->right=new dnode;
	t1=t1->right;
	t1->data=n;	//cout<<"FUNCTION"<<t1->data<<endl;

	t1->right=NULL;
	t1->left=t2;
}
void deleteend(dptr d)
{
	dptr t1,t2;
	t1=d;
	while(t1->right!=NULL)
	{
		t1=t1->right;
	}
	t1->left->right=NULL;
	t2=t1;
		delete(t2);
}
void deletebegin(dptr &d)
{
	dptr t1,t2;
	t1=d;
	d=d->right;
	d->left=NULL;
	delete(t1);
}
void deleteatpos(dptr d,int n)
{
	dptr t1,t2;
	t1=d;
	while(t1->data!=n)
	{
		t1=t1->right;
	}
	t2=t1;
	t1->left->right=t1->right;
	t1->right->left=t1->left;
	delete(t2);
}
void deletebefore(dptr d,int n)
{
	dptr t1,t2;
	t1=d;
	while(t1->data!=n)
	{
		t1=t1->right;
	}
	t2=t1->left;
	t1->left->left->right=t1;
	t1->left=t1->left->left;
	delete(t2);
}
void deleteafter(dptr d,int n)
{
	dptr t1,t2;
	t1=d;
	while(t1->data!=n)
	t1=t1->right;
	t2=t1->right;
	t1->right->right->left=t1;
	t1->right=t1->right->right;	
	delete(t2);
}
void addend(lptr l,int d)
{
	lptr t=l;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=new struct node;
	t=t->next;
	t->data=d;
	t->next=NULL;
}
void create(lptr l)
{
	int d;lptr t;
	t=l;
	cout<<"Enter the first element or -1 to exit\n";
	cin>>d;
	if(d!=-1)
	{
		t->data=d;
		t->next=NULL;
}
	while(d!=-1)
	{
	    cout<<"Enter the element or -1 to exit\n";
		cin>>d;
		if(d!=-1)
		addend(l,d);
	}
}
void display(lptr l)
{
	lptr t=l;
	while(t!=N)
	{
		cout<<t->data<<" ";	
		if(maxe<t->data)
		  maxe=t->data;
		t=t->next;
	}cout<<endl;	
}
int funcn(int n,int nd)
{
	int j,k1,l;
	for(j=1;j<nd;j++)
	{
		n=n/10;		
	}
	k1=n%10;
	return k1;
}
int number(int max)
{
	while(max!=0)
	{
		max=max/10;
		k++;
	}
}
void radixsort(lptr &l1,int h)
{
   //cout<<"***\n";
  c++;
  lptr t1;
  int j=0;
  int n=10;int i;
  static int m=maxe,hi=k;
  lptr l2,l3;rptr tr,tr1,tr2;
  t1=l1;int di;
  static int mi=k;
  rptr r1,r2;
  r1=new rnode;
  tr1=new rnode;
  r1->bktptr=N;
  tr=r1;
  for(i=0;i<9;i++)
  {
    tr->next=new rnode;
    tr=tr->next;
    tr->bktptr=N;	
  	tr->next=N;
  }
 // tr->next=N;
  while(t1!=N)
  {
  //cout<<"###\n";
    tr1=r1;
  	di=funcn(t1->data,h);
  //	cout<<"DI    "<<di<<endl;
  	for(i=0;i<di;i++)
  	{
	    //cout<<"&&&\n";
  		tr1=tr1->next;
	  }
    if(tr1->bktptr==N)
	{
		//addbegin(tr1->bktptr,t1->data);
		tr1->bktptr=new dnode;
		tr1->bktptr->data=t1->data;
		tr1->bktptr->right=N;
		tr1->bktptr->left=N;
		//tr1=r1;
	}
	else
	{
		addend(tr1->bktptr,t1->data);
	}
	t1=t1->next;
  }
 tr2=r1;
 l2=new node;
 t1=N;
//lptr t2=l2;  l3=l2;
for(int e=0;e<10;e++)
  {
   // cout<<tr2->bktptr->data<<"  &"<<endl;
  	j++;//cout<<"!!!\n";
	  //dptr tmp=r1->bktptr;	
  	while(tr2->bktptr!=N)
  	{
	    //cout<<"IF\n";
  		//tr2->bktptr=tr2->bktptr->right;
  		if(t1==N)
  		{
  		l2->data=tr2->bktptr->data;	
  		l2->next=N;
		tr2->bktptr=tr2->bktptr->right;
		t1=l2;
		//t2=l2;
  		//l2->next=new node;
  	    //l2=l2->next;
  	    //l2->next=N;
  	}//continue;  		
    else
    {//cout<<"ELSE\n";
    	addend(l2,tr2->bktptr->data);
    	tr2->bktptr=tr2->bktptr->right;

	}
  /*	while(tr2->bktptr->right!=N)
  	{
	    cout<<"@@@\n";
  		if(j==1)
  		addbegin(l2,tr2->bktptr->data);
  		else
  		addend(l2,tr2->bktptr->data);
  		tr2->bktptr=tr2->bktptr->right;
	}*/}
tr2=tr2->next;
  }//l2->next=N; 
  //l3=l2;
  //display(l2);
  hi--;h++;
  if(hi>=0)
  radixsort(l2,h);
  else
  {
  	display(l2);
  }
}
int main()
{
	lptr l;
	l=new node;
	create(l);
		cout<<"THE UNSORTED ARRAY IS :\n\n";
	display(l);
		number( maxe);
	cout<<"The maximum among the numbers is  : "<<maxe<<endl;
	cout<<"The no. of digits in maximum is/are : "<<k<<endl;
cout<<"THE SORTED ARRAY IS :\n\n";
	radixsort(l,h);
	
	return 0;
}
