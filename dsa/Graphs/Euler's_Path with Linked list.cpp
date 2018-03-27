#include<iostream>
#define null NULL
using namespace std;
struct queue
{
	int size;
	int element[50];
	int front;
	int rear;
};
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
void add_end(lptr l,int d)
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
void addbefore(lptr l,int d)
{
	lptr t,t2;
	t=l;int n;
	cout<<"Enter the data \n";
	cin>>n;
	while(t->next->data!=d)
	{
		t=t->next;
	}
	t2=t->next;
	t->next=new struct node;
	t=t->next;
	t->data=n;
	t->next=t2;
}

void display(lptr l)
{
	lptr t=l;
	while(t!=NULL)
	{
		cout<<t->data<<" ";	
		t=t->next;
	}cout<<endl;	
}
void create(lptr l)
{
	int d;lptr t;
//	t=l;
//	cout<<"Enter the first element or -1 to exit\n";
//	cin>>d;
//	if(d!=-1)
//	{
//		t->data=d;
//		t->next=NULL;
//	}
	while(d!=-1)
	{
	    cout<<"Enter the element or -1 to exit\n";
		cin>>d;
		if(d!=-1)
		add_end(l,d);
	}
}
void deleteend(lptr l)
{
lptr t;
t=l;
	while(t->next->next!=NULL)
	{
		t=t->next;
	}
	lptr t2;
	t2=t->next;
	t->next=NULL;
	delete(t2);
}
void deletebegin(lptr &l)
{
	lptr t;
	t=new struct node;
	t=l;
	l=l->next;
	delete t;
}
void deleteatpos(lptr l,int p)
{
	lptr t=l;int d;
	while(t->next->data!=p)
	t=t->next;
	lptr t2=t->next;
	t->next=t->next->next;
	delete t2;
}
void deleteafter(lptr l,int d)
{
	lptr t,t2;
	t=l;
	while(t->data!=d)
	{
		t=t->next;
	}
	t2=t->next;
	t->next=t->next->next;
	delete t2;
}
void deletebefore(lptr l,int p)
{
	lptr t,t2;
	t=l;
	while(t->next->next->data!=p)
	{
		t=t->next;
	}
	t2=t->next;
	t->next=t->next->next;
	delete t2;
}
void enque(queue &q,int x)
{
	if((q.rear+1)%q.size==q.front)
	{
		cout<<"Queue is overloaded\n";
	}
	else
	{
		if(q.front==-1)
		q.front=0;
		q.rear=(q.rear+1)%q.size;
		q.element[q.rear]=x;
	}
}
int deque(queue &q)
{
	int t;
	
	if(q.front==-1)
	{
		cout<<"Queue is Empty\n";
	}
	else
	{
		t=q.front;
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
int a[50][50]={0};
int in_degree(int n,int v)
{
	int dg=0;
	for(int i=1;i<=n;i++)
	{
		if(a[v][i]==1)
		{
			dg++;
		}
	}
	return dg;
}
int out_degree(int n,int v)
{
	int dg=0;
	for(int i=0;i<n;i++){
		if(a[v][i]==1)
		{
			dg++;
		}
	}
	return dg-1;
}
void print(int a[][50],int n)
{
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<"  ";
		}
		cout<<endl;
	}
} 
void addafter(lptr l,int d,int n)
{
	int i=0;
	lptr t;
	t=l;
	while(i<d-1)
	{
		t=t->next;
		i++;
	}
	lptr t2=t->next;
	t->next=new struct node;
	t=t->next;
	t->data= n;
	t->next=t2;
}
 int  temp[50],si=0;
 lptr final=null;
int ve[50],first=0,siz=0,rem,second =0;
void dfs(int v,int n,int u)
{	
	int i,k,j;
	if(in_degree(n,v)>0)
	{	
	cout<<"v = "<<v<<"u  =  "<<u<<endl;
	temp[si++]=u;
	a[v][u]=0;
	a[u][v]=0;
	if(in_degree(n,u)>0)
	{
	for(i=1;i<=n;i++)
	{
		if(a[u][i]>0)
		{
			dfs(u,n,i);
		}
	}
   }
   else
   {
   cout<<"SPlicing\n";
   first++;
   	if(first==1)
    {
    	cout<<"If of splicing \n";
    	cout<<"temp array \n";
    	for(i=0;i<si;i++)
    	cout<<temp[i]<<"  ";cout<<endl;lptr final1;
   		for(i=0;i<si;i++)
   		{
   			if(i==0)
   			{
   				addbegin(final,temp[i]);
				final1=final;
			}
			   else
		     {
		     	addafter(final1,i,temp[i]);
		     	//cout<<"temp[i-1] "<<temp[i-1]<<"temp[i] = "<<temp[i]<<" \n ";
			 }
   			//final[i]=temp[i];
		}
		siz=si;
		cout<<"spliced  array \n"; final1=final;
		for(i=0;i<siz;i++)
		{
	    cout<<final1->data<<"  ";
	    final1=final1->next;
		}cout<<endl;
         final1=final;
		for(i=0;i<siz;i++)
		{
			if(in_degree(n,final1->data)>0)
			{
				for( j=1;j<=n;j++)
				{
					if(a[final1->data][j]>0)
					{
						break;
					}
				}
				si=0;rem =final1->data;
				temp[si++]=final1->data;
				dfs(final1->data,n,j);
				break;
			}
			final1=final1->next;
		}
        cout<<"si ="<<si<<endl;		
	}
	else
	{	
	    cout<<"Else  pf splicing \n";
    	cout<<"sz ="<<siz<<endl;
    	cout<<"si = "<<si<<endl;
    	cout<<"rem2  ="<<rem <<endl;
    	cout<<"temp array \n";cout<<"rem = "<<rem<<endl;
    	for(i=0;i<si;i++)
    	cout<<temp[i]<<"  ";cout<<endl;
    	second++;
    	int temp2[20];
    	    cout<<"Final array before splicing  array \n";
//				for(int l=0;l<siz;l++)
//				{
//					temp2[l]=final[l];
//					cout<<final[l]<<"  ";
//				}
lptr final1=final;int rem1=rem;
    	for(i=0;i<siz;i++)
		{
			if(final1->data==rem)
			{ 
			    cout<<"i  = "<<i<<endl;
				int m=0;
				for(j=0;j<si;j++)
				{
					if(j==0)
					{	
					siz++;
					}
					else
					{
					cout<<"i+j-1 = "<<i+j<<endl;
					addafter(final,i+j,temp[j]);
					siz++;
				   }
				}
				siz--;
				cout<<"spliced array \n";cout<<"size = "<<siz<<endl;
				break;
			}
		}
		si=0;int j1;final1=final;
    	for(i=0;i<siz;i++)
		{
			if(in_degree(n,final1->data)>0)
			{
				for( j1=1;j1<=n;j1++)
				{
					if(a[final1->data][j1]>0)
					break;
				}
				//cout<<"final ans ="<<final[i]<<endl;
//				if(in_degree(n,final1->data)==1&&in_degree(n,j1)==1)
//				{
//					rem=j1;
//					temp[si++]=j1;
//					dfs(j1,n,final1->data);
//					break;
//					
//				}
			//	else
				{
				rem=final1->data;
				temp[si++]=final1->data;
				dfs(final1->data,n,j1);
				break;
			    }
			}
			final1=final1->next;
		}cout<<"rem ="<<rem <<endl;
		
	}
   }
}
}
int main()
{
	int n,n1,i,ou,j;
	queue q;
	q.front=-1;
	q.rear=-1;
	q.size=50;
	cout<<"Enter the number of vertices\n";
	cin>>n;
	for(i=1;i<=n;i++)
	{
		ve[i]=0;
	}
	int in[n],u,v,i1;
	cout<<"Enter the number of edges\n";
	cin>>n1;
	for(i=0;i<n1;i++)
	{
	   cout<<"enter the u and v 'u->v' \n";
	   cin>>u>>v;
	   a[u][v]=1;
	   a[v][u]=1;
	}
	int s;
	cout<<"enter the starting vertex\n";
	cin>>s;
	for(i=1;i<=n;i++)
	{
		if(a[s][i]>0)
		{
			break;
		}
	}	
	    cout<<s<<" ";
		temp[si++]=s;
	    //si++;
		dfs(s,n,i);
		if(siz==0)
		{cout<<"Tmp\n";
			for(i=0;i<si;i++)
			{
				cout<<temp[i]<<"  ";
			}
		}
		else
		{cout<<"Final\n";
//		final[siz]=1;

		for(i=0;i<siz;i++)
		{
    cout<<final->data<<"  ";
    final=final->next;
    }
	    }
}
