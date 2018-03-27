#include<iostream>
using namespace std;
struct queue
{
	int size;
	int element[50];
	int front;
	int rear;
};
string  s;
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
int a[50][50]={0},count[50]={0};int ve[50],ad[5][5];
void alldfs1(int v,int n)
{   
	int i,check=0;
	if(ve[v]==0)
	{
		ve[v]=1;
		for(i=1;i<=n;i++)
		{
			if(ve[i]==0&&a[v][i]>0)
			{
				ad[v][++count[v]]=i;
				ad[i][++count[i]]=v;
				cout<<"i=="<<i<<endl;
				cout<<"Count[v]= "<<count[v]<<endl;
				check=1;
			}
	    }
		for(i=1;i<=count[v];i++)
		{
			if(check)
			{
				cout<<"Recursion== "<<ad[v][i]<<endl;
				alldfs1(ad[v][i],n);
		    }
	    }
	}
}
//void alldfs(int v,int n,int che)
//{
//	if(che==0)
//	{
//    int ad[n],i,vi[n];    
//	for(i=1;i<=n;i++)
//	{	
//		vi[i]=0;
//	}
//	cout<<v<<"  ";
//	for(i=1;i<=n;i++)
//	{
//	if(a[v][i]>0)
//	{
//		ad[count[i]]=i;
//		count[i]++;
//	}
//    }
//	for(i=1;i<=n;i++)
//	{	
//		if(a[v][i]>0&&vi[i]==0)
//		{
//			vi[v]=1;
//			alldfs(i,n,vi[i]);
//		}
//	}
//   }
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
int pcount[5]={0};
void print1(int a[][50],int v)
{
	int i,j;
	if(pcount[v]<=count[v])
	{
	for(i=1;i<=count[v];i++)
	{	
		if(ad[v][i]>v)
		{
		cout<<ad[v][i]<<"  ";
		pcount[v]++;
		print1(a,ad[v][i]);
	    }//cout<<endl;
	}
   }
   cout<<endl;	
}
//void print(int a[][50],int n)
//{
//	
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//		{
//			cout<<a[i][j]<<"  ";
//		}
//		cout<<endl;
//	}
//} 
//int count[50];
void dfs(int v,int n)
{
	int i;
	if(ve[v]==0)
	{
		ve[v]=1;
		cout<<v<<" ";
		for(i=1;i<=n;i++)
		{
			if(a[v][i]>0&&ve[i]==0)
			{
				dfs(i,n);
				for(int i=0;i<n;i++)
				{
							
				  v[i]=	                           
				}
				ve[v]=0;
			}
		}	
    }
}
bool check(int ans[][5],int j,int i)
{
	
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
	cout<<"enter the starting vertex \n";
	cin>>s;
	int  k=1,l;
	alldfs1(s,n);
	int ans[10][10];
	for(i=1;i<=n;i++)
	{
		int cj[5]={0};
		for(j=1;j<=count[i];j++)
		{	
		  cout<<ad[i][j]<<"  ";
		}
		cout<<endl;
	}
	for(i=1;i<=(n-1)*(n-1);i++)
	{
		for(j=1;j<=n;j++)
		{
			if(check(ans,ad[i][j],i))
		}
	}
//print1(a,s);
}
