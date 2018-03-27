#include<iostream>
using namespace std;
struct queue
{
	int size;
	int element[50];
	int front;
	int rear;
};
struct stack
{
	int top;
	int size;
	int ele[5];
};
int a[50][50]={0},n;
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
int ve[50],count[50],s,number[20],ans=1,parent[20];
int findmin(int a,int b,int c)
{
	if(a<=b&&a<=c)
	return a;
	else if(b<=a&&b<=c)
	return b;
	else
	return c;
}
void dfs(int v,int n)
{
	int i;static int ans=1;
	if(ve[v]==0)
	{
	ve[v]=1;
	number[v]=ans++;
	cout<<v<<" ";
	for(i=1;i<=n;i++)
	{
		if(a[v][i]>0&&ve[i]==0)
		{
			count[i]++;
			parent[i]=v;
			dfs(i,n);
		}
  }
   }
}
int lowv[20]={0},low[20];
void findlow(int v)
{
	if(lowv[v]==0)
	{
	int i,j,min=1000,k,min2=1000,min3=1000;
	lowv[v]=1;
	for(i=1;i<=n;i++)
	{
		if(lowv[i]==1&&v==parent[i])
		{
			if(min>low[i])
			{
				min=low[i];
  		    }		
		}
		else if(lowv[i]==0&&v==parent[i])
		{
			findlow(i);
			k=low[i];
			if(min>k)
			min=k;
		}
	}
	min2=number[v];
	int check=0;
    for(i=1;i<=n;i++)
    {
    	if(a[v][i]>0)
    	{
    	if(i!=parent[v]&&v!=parent[i])
    	{
    		if(min3>number[i])
    		{
    			min3=number[i];
			}
		}
	
	  }
	}
	low[v]=findmin(min,min2,min3); 
 }
}
int main()
{
	int n1,i,ou,j;
	queue q;
	q.front=-1;
	q.rear=-1;
	q.size=50;
	cout<<"Enter the number of vertices\n";
	cin>>n;int check,max;
	for(i=1;i<=n;i++)
	{
		ve[i]=0;
		count[i] =0;
	}
	int in[n],u,v,i1;
	cout<<"Enter the number of edges\n";
	cin>>n1;int un[n1],vn[n1];
	for(i=0;i<n1;i++)
	{
	   cout<<"enter the u and v 'u->v' \n";
	   cin>>u>>v;
	   un[i]=u;vn[i]=v;
	   a[u][v]=1;
//	   count[u]++;
//	   count[v]++:
	   a[v][u]=1;
    }
	for(i=1;i<=n;i++)
	{
		a[i][i]=1;
	}
	cout<<"enter the starting vertex\n";
	cin>>s;
	count[s]++;
	parent[s]=-1;
	cout<<"\nDFS is \n";
	dfs(s,n);cout<<endl;
//	for(i=1;i<=n;i++)
//	{//cout<<"num "<<i<<"  = "<<number[i]<<endl;
//		cout<<"par of   "<<i<<"    = "<<parent[i]<<endl;
//		for(j=0;j<noc[i];j++)
//		{
//			cout<<"child of "<<i<<"    = "<<child[i][j]<<"  ";
//		 } cout<<endl;
//	}
	for(i=n;i>0;i--)
	{
		if(lowv[i]==0)
		findlow(i);
    }
//    for(i=1;i<=n;i++)
//    {
//    	cout<<"low  "<<i<<"  "<<low[i]<<"  ";
//	}
	cout<<"\nArticulation Points are \n";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(parent[j]==i&&i!=s)
			{
				if(low[j]>=number[i])
				{
					cout<<i<<"  ";
					break;
				}
			}
			else if(parent[j]==i&&i==s)
			{
			    int count=0;
				for(int k=1;k<=n;k++)
				{
					if(parent[k]==i)
					{
						count++;
					}
				}
				if(count>1&&low[j]>=number[i])
				{
					cout<<i<<"  ";
					break;
				}
			}
		}
	}
	return 0;
}
