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
	for(int i=0;i<n;i++)
	{
		if(a[i][v]==1)
		{
			dg++;
		}
	}
	return dg-1;
}
int out_degree(int n,int v)
{
	int dg=0;
	for(int i=0;i<n;i++)
	{
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
int main()
{
	int n,n1,i,ou,j;
	queue q;
	q.front=-1;
	q.rear=-1;
	q.size=50;
	cout<<"Enter the number of vertices\n";
	cin>>n;
	int in[n],u,v,i1;
	cout<<"Enter the number of edges\n";
	cin>>n1;
	for(i=0;i<n1;i++)
	{
	   cout<<"enter the u and v 'u->v' \n";
	   cin>>u>>v;
	   a[u-1][v-1]=1;
	}
	for(i=0;i<n;i++)
	{
		a[i][i]=1;
	}
	 for(i=0;i<n;i++)
     if(in_degree(n,i)==0)
     {
     	enque(q,i);
	 }//print(a,n);
	 int count=0;
	  while(q.front!=-1)
	  { 
	  if(count==n)
	  break;
	  	ou=deque(q);
	  	count++;
	  	cout<<ou+1<<"  ";
	  	for(i=0;i<n;i++)
	  	{
	  		if(a[ou][i]==1)
	  		{
	  			a[ou][i]--;
			}
		}
		
		cout<<endl;//print(a,n);
		for(j=0;j<n;j++)
		{
			//cout<<"In degree after "<<in_degree(n,j)<<"  ";
			if(in_degree(n,j)==0)
			{
				enque(q,j);
				break;
			}
		}
		
	  }
}
