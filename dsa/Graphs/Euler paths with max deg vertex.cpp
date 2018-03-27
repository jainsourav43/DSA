#include<iostream>
using namespace std;
struct queue
{
	int size;
	int element[50];
	int front;
	int rear;
};
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
 int  temp[50],si=0;
int ve[50],final[50],first=0,siz=0,rem;
void dfs(int v,int n,int u)
{
	first++;
	int i,k,j;
	if(in_degree(n,v)>0)
	{
	cout<<u<<" ";
	temp[si++]=v;
	a[v][u]=0;
	a[u][v]=0;int max;
	int an;
	max=0;
	for(i=1;i<=n;i++)
	{	
		if(a[u][i]>0&&max<in_degree(n,i))
		{
			max=in_degree(n,i);
			an=i;
		}
	}
	dfs(u,n,an);
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
	int max=0,an;
	for(i=1;i<=n;i++)
	{
		if(a[s][i]>0&&max<in_degree(n,i))
		{
			max=in_degree(n,i);
			an=i;
		}
	}
	cout<<s<<" ";
		dfs(s,n,an);
		final[siz]=1;
//	for(i=0;i<=siz;i++)
//    cout<<final[i]<<"  ";
}
