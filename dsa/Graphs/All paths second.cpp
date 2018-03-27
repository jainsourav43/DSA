#include<iostream>
using namespace std;
struct info
{
	int visit;
	int ver;
};
struct queue
{
	int size;
	int  element[50];
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
int a[50][50]={0},count[50]={0};int ve[50];
//void alldfs1(int v,int n,queue q,info g[])
//{ 
//		int i,ad[5];
//    	enque(q,g[v]);
//		g[v].visit=1;	
//		if(q.rear-q.front==n-1)
//		{
//			while(q.front>-1)
//			{
//				cout<<deque(q).ver<<" ";
//			}
//			cout<<endl;
//		}
//		else
//		{//info gh=q.element[q.front];
//		for(i=1;i<=n;i++)
//		{
//			if(a[v][i]>0&&g[i].visit==0)
//			{
//			alldfs1(i,n,q,g);
//		    }
//	    }
//	     // cout<<"Exit\n";
//	
//	  }
//	  //cout<<"left = "<<v<<endl;
//	 // 	cout<<"deque(q)=  "<<deque(q).ver<<endl; 
//	    g[v].visit=0;
//}
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

//int count[50];

void dfs(int v,int n,queue q)
{   int i;
	ve[v]=1;
	enque(q,v);
	if(q.rear-q.front==n-1)
	{
		while(q.front!=-1)
		{
			cout<<deque(q)<<"  ";
		}cout<<endl;
	}
	else
	{
	for(i=1;i<=n;i++)
	{
		if(a[v][i]>0&&ve[i]==0)
		{
			dfs(i,n,q);
		}
	}
    }
    ve[v]=0;
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
		count[i] =0;
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
	info g[n+1];
	for(i=1;i<=n;i++)
	{
		g[i].visit=0;
		g[i].ver=i;
	}
	cout<<"enter the starting vertex\n";
	cin>>s;
//	alldfs1(s,n,q,g);
dfs(s,n,q);
}
