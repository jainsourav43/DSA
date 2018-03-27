#include<iostream>
#include<algorithm>
#define d 2
#define null NULL
using namespace std;
typedef
struct bnode
{
	int key[2*d];
	bnode *ptr[2*d+1];
	int count;
	bnode *par;
}*bptr ;
struct queue
{
	int rear;
	int front;
	int size;
	bptr element[50];
};
void enque(queue &q,bptr e)
{
	if((q.rear+1)%q.size==q.front)
	{
		cout<<"overflow\n";
	}
	else
	{
		if(q.front==-1)
		{
			q.front=0;
		}
		q.rear=(q.rear+1)%q.size;
		q.element[q.rear]=e;
	}
}
bptr deque(queue &q)
{
	if(q.front==-1)
	{
		cout<<"Underflow\n";
	}
	else
	{
		int t=q.front;
		if(q.front==q.rear)
		{
			q.front=-1;
			q.rear=-1;
		}
		else
		{
			q.front=(q.front+1)%q.size;
		}
		return q.element[t];
		
	}
}
void printlevel(bptr t)
{
	queue q;
	q.front=-1;
	q.rear=-1;
	q.size=50;
	bptr t2;
	int i;
	enque(q,t);
	while(q.front!=-1)
	{
		t2=deque(q);
		for(i=0;i<=t2->count;i++)
		{
			cout<<t2->key[i]<<"  ";
		}
		cout<<endl;
		for(i=0;i<=t2->count+1;i++)
		{
			if(t2->ptr[i]!=null&&t2->ptr[1]!=null)
			enque(q,t2->ptr[i]);
		}
	}
}
void initialise(bptr &t)
{
	t->count=-1;
     for(int i=0;i<2*d+1;i++)
     {
     	t->ptr[i]=null;
     }
}
bptr search(bptr t,int k)
{
	if(t!=null)
	{
		if(t->key[0]>k)
		{
			if(t->ptr[0]!=null)
			{
				return search(t->ptr[0],k);
			}
			else
			{
				return t;
			}
		}
		else if(t->key[0]<k)
		{
			for(int i=0;i<=t->count;i++)
			{
				if(t->key[i]<k)
				{
					if(t->ptr[i+1]!=null&&i+1>=t->count&&t->key[i+1]>k)
					{
						return search(t->ptr[i+1],k);
					}
					else if(t->ptr[i+1]!=null&&i+1>=t->count&&t->key[i+1]<k&&i+2>=t->count+1&&t->ptr[i+2]!=null)
					{
						return search(t->ptr[i+2],k);
					}
					else if(t->ptr[i+1]!=null&&t->key[i+1]<k&&i+1<=t->count&&t->ptr[i+1]!=null)
					{
						continue;
					}
					else if(t->ptr[i+1]!=null)
					{
						return search(t->ptr[i+1],k);
					}
				}
				else if(t->key[i]>=k)
				{
					return search(t->ptr[i],k);
				}
				return t;
			}
		}
	}
}
//void print(bptr t)
//{
//	for()
//}
void printleaf(bptr t)
{
	while(t!=null)
	{
		for(int i=0;i<=t->count;i++)
		{
			cout<<t->key[i]<<"  ";
		}
		t=t->ptr[2*d];
	}
}
void printBplus(bptr t)
{
	while(t->ptr[0]!=null&&t->ptr[1]!=null)
	{
		t=t->ptr[0];
	}
	printleaf(t);
}
void overflow(bptr &t,bptr lc,bptr rc,int k,int a[])
{
	int i,j,l,b[2*d+1];
	if(t->par==null)
	{cout<<"OVERFLOW1\n";
		bptr t2=new bnode;
		bptr t3=new bnode;
		initialise(t2);
		initialise(t3);
		t2->par=t;
		t3->par=t;
		for(i=0;i<d;i++)
		{
			t2->key[i]=a[i];
			t2->count++;
		}
		if(t->ptr[1]==null)
		{
		for(i=0;i<=d;i++)
		{
			t3->key[i]=a[i+d];
			t3->count++;
		}
	  }
	  else
	  {
	  	for(i=0;i<d;i++)
		{
			t3->key[i]=a[i+d+1];
			t3->count++;
		}
	  }
		t->count=0;
		t->key[0]=a[d];
		int che=0,che1=0;
		bptr t4=t2,t5=t3;
		for(i=0;i<=d;i++)
		{
			if(t2->key[i]!=k)
			{
				if(che==1)
				{
					t2->ptr[i]=t->ptr[i-d+1];
					if(t2->ptr[i])
					{
						t2->ptr[i]->par=t4;
					}
				}
				else
				{
					t2->ptr[i]=t->ptr[i];
						if(t2->ptr[i])
					{
						t2->ptr[i]->par=t4;
					}
				}
				if(i==d-1&&t->key[i]!=k)
				{
					t2->ptr[i+1]=t->ptr[i+1];
					if(t2->ptr[i+1])
					{
						t2->ptr[i+1]->par=t4;
					}
					i++;
				}
			}
			else
			{
				che=1;
				t->ptr[i]=lc;
				if(t2->ptr[i])
		       {
					t2->ptr[i]->par=t4;
				}
				t2->ptr[i+1]=rc;
				if(t2->ptr[i+1])
				{
					t2->ptr[i+1]->par=t4;
				}
				i++;
			}
		}
		for(i=d;i<2*d;i++)
		{
			if(t3->count!=k)
			{
			if(che==0)
			{
				t3->ptr[i-d]=t->ptr[i+1];
				if(t3->ptr[i-d])
				t3->ptr[i-d]->par=t5;
			}
			else
			{
				t3->ptr[i-d]=t->ptr[i];
				if(t3->ptr[i-d])
				t3->ptr[i-d]->par=t5;
			}
			if(i==2*d-1&&t3->key[i]!=k)
			{
				t3->ptr[i+1-d]=t->ptr[i+1];
				if(t3->ptr[i-d+1])
				t3->ptr[i-d+1]->par=t5;
				i++;
			}
	     	}
	     	else
	     	{
	     		t3->ptr[i-d]=lc;
	     		if(t3->ptr[i-d])
				t3->ptr[i-d]->par=t5;
	     		t3->ptr[i-d+1]=rc;
	     		if(t3->ptr[i-d]+1)
				t3->ptr[i-d+1]->par=t5;
	     		i++;
	     	}
		}
		if(che==0&&che1==0)
		{
			t2->ptr[d]=lc;
			t3->ptr[0]=rc;
			for(i=d;i<2*d;i++)
			{
				t->ptr[i-d+1]=t->ptr[i+1];
			}
		}
		t->ptr[0]=t2;
		t->ptr[1]=t3;
		t->key[0]=a[d];
		if(t2->ptr[0]==null&&t3->ptr[1]==null)
		{
			t2->ptr[2*d]=t3;
			t3->ptr[0]=t2;
		}
	}
	else 
	{
		cout<<"OVERFLOW2\n";
		bptr t2=new bnode;
		bptr t3=new bnode;
		initialise(t2);
		initialise(t3);
		t2->par=t->par;
		t3->par=t->par;
		for(i=0;i<d;i++)
		{
			t2->key[i]=a[i];
			t2->count++;
		}
		
		if(t->ptr[1]==null)
		{
		for(i=0;i<=d;i++)
		{
			t3->key[i]=a[i+d];
			t3->count++;
		}
	   }
	  else
	  {
	  	for(i=0;i<d;i++)
		{
			t3->key[i]=a[i+d+1];
			t3->count++;
		}
	  }
	  bptr t4=t2,t5=t3;
	  int che=0,che1=0;
		for(i=0;i<=d;i++)
		{
			if(t2->key[i]!=k)
			{
				if(che==1)
				{
					t2->ptr[i]=t->ptr[i-d+1];
					if(t2->ptr[i])
					{
						t2->ptr[i]->par=t4;
					}
				}
				else
				{
					t2->ptr[i]=t->ptr[i];
					if(t2->ptr[i])
					{
						t2->ptr[i]->par=t4;
					}
				}
				if(i==d-1&&t2->key[i]!=k)
				{
					t2->ptr[i+1]=t->ptr[i+1];
					if(t2->ptr[i+1])
					{
						t2->ptr[i+1]->par=t4;
					}
					i++;
				}
			}
			else
			{
				che=1;
				t2->ptr[i]=lc;
				if(t2->ptr[i])
		       {
					t2->ptr[i]->par=t4;
				}
				t2->ptr[i+1]=rc;
				if(t2->ptr[i+1])
				{
					t2->ptr[i+1]->par=t4;
				}
				i++;
			}
		}cout<<"check 1\n";
		for(i=d;i<2*d;i++)
		{
			if(t3->count!=k)
			{
			if(che==0)
			{
				t3->ptr[i-d]=t->ptr[i+1];
				if(t3->ptr[i-d])
				t3->ptr[i-d]->par=t5;
			}
			else
			{
				t3->ptr[i-d]=t->ptr[i];
				if(t3->ptr[i-d])
				t3->ptr[i-d]->par=t5;
			}
			if(i==2*d-1&&t3->key[i]!=k)
			{
				t3->ptr[i+1-d]=t->ptr[i+1];
				if(t3->ptr[i-d+1])
				t3->ptr[i-d+1]->par=t5;
				i++;
			}
	     	}
	     	else
	     	{
	     		t3->ptr[i-d]=lc;
	     		if(t3->ptr[i-d])
				t3->ptr[i-d]->par=t5;
	     		t3->ptr[i-d+1]=rc;
	     		if(t3->ptr[i-d]+1)
				t3->ptr[i-d+1]->par=t5;
	     		i++;
	     	}
		}cout<<"check 2\n";
		if(t2->ptr[0])
		t->ptr[0]->ptr[2*d]=t2;
		t2->ptr[2*d]=t3;
		t3->ptr[0]=t2;cout<<"check 4\n";
		for(i=d+1;i<=2*d;i++)
		t->ptr[i]=null;
		if(t->par->count==2*d-1)
		{
			for(i=0;i<2*d;i++)
			{
				b[i]=t->par->key[i];
			}
			b[2*d]=a[d];
			sort(b,b+2*d+1);
			overflow(t->par,t2,t3,a[d],b);
		}
		else
		{
			for(i=t->par->count;i>=0;i--)
			{
				if(t->par->key[i]>a[d])
				{
					t->par->key[i+1]=t->par->key[i];
					t->par->ptr[i+2]=t->par->ptr[i+1];
				}
				else
				break;
			}
			t->par->key[i+1]=a[d];
			t->par->ptr[i+1]=t2;
			t->par->ptr[i+2]=t3;
			t->par->count++;cout<<"check 3\n";
		}
	}
	
}
void deleteit(bptr t,int k)
{
	int i;
	while(t->ptr[0]!=null&&t->ptr[1]!=null)
	{
		t=t->ptr[0];
	}
	while(t!=null)
	{
		for(i=0;i<=t->count;i++)
		{
			if(t->key[i]==k)
			{
				for(int j=i;j<t->count;j++)
				{
					t->key[j]=t->key[j+1];
				}
				 t->count--;
				 break;
			}
		}
		t=t->ptr[2*d];
	}
}
void searchleaf(bptr t,int k)
{
	int i,ans,j,check=0;
	while(t->ptr[0]!=null&&t->ptr[1]!=null)
	{
		t=t->ptr[0];
	}
	bptr t1=t,t4;
	cout<<"t->key[0]=  "<<t->key[0]<<endl;
	while(t!=null)
	{
		for(i=0;i<=t->count;i++)
		{
			if(t->key[i]==k)
			{
				ans=i;	
				check=1;
			}
		
		}
	    if(check==1)
	    {
	    t4=t;
		t=t->ptr[2*d];
			break;
		}else
		t=t->ptr[2*d];
	}
	bptr t3=t1;
	//cout<<"t->key[i]  = "<<t->key[i]<<endl;
	cout<<"t3 key = "<<t3->key[0]<<endl;
	cout<<"t4 = "<<t4->key[0]<<endl;
	while(t3!=t4)
	{
		for(i=0;i<=t3->count;i++)
		{
			cout<<t3->key[i]<<"  ";
		}
		t3=t3->ptr[2*d];
	}
	for(i=0;i<ans;i++)
	{
		cout<<t4->key[i]<<"  ";
	}
}
void add(bptr &t1,int k)
{
	bptr t=search(t1,k);
	int i,j,l,a[2*d+1];
	cout<<"t->key[0]"<<t->key[0]<<endl;
	if(t->count<2*d-1)
	{cout<<"if\n";                                               
		for(i=t->count;i>=0;i--)
		{
			if(t->key[i]>k)
			{
				t->key[i+1]=t->key[i];
				//if(t->ptr[1]!=null)
				t->ptr[i+2]=t->ptr[i+1];
			}
			else 
			break;
		}
		t->key[i+1]=k;
		t->count++;
	}
	else
	{
		cout<<"SEND\n";
		for(i=0;i<2*d;i++)
		{
			a[i]=t->key[i];
		}
		a[2*d]=k;
		sort(a,a+2*d+1);
		overflow(t,null,null,a[d],a);
	}
}
int main()
{
	int n,k;
	bptr t=new bnode;
	initialise(t);
	cout<<"Enter teh key to add\n";
	cin>>n;
	t->key[0]=n;
	t->count++;
	t->par=null;
	while(n!=-1)
	{
		cout<<"Enter the key to add \n";
		cin>>n;
		if(n!=-1)
		{
			add(t,n);
		}
		cout<<"Print\n";
			printBplus(t);cout<<endl;
		   printlevel(t);cout<<endl;
	}
	cout<<"Enter the key to search and print the content before it\n";
	cin>>k;
	searchleaf(t,k);
	cout<<"Enter the leaf node key without underflow\n";
	cin>>k;
	deleteit(t,k);
	cout<<"tree after delete\n";
	printBplus(t);cout<<endl;
	
}
