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
int ve[50];
int count[50];	
int s;
int number[20];
int ans=1;
int parent[20];
int child[20][20];
int noc[20]={0};
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
			child[v][noc[v]++]=i;
			//cout<<"v  ="<<v<<" i ="<<i<<endl;
			dfs(i,n);
		}
  }
   }
}
int lowv[20]={0},low[20];
void findlow(int v)
{
	if(lowv[v]==0){
	int i,j,min=1000,k,min2=1000,min3=1000;
	lowv[v]=1;//cout<<" v in low "<<v<<endl;
	for(i=0;i<noc[v];i++)
	{
		//cout<<"in ="<<i<<endl;
		if(lowv[i]==1)
		{
			if(min>low[child[v][i]])
			{
				min=low[child[v][i]];
  		    }		
		}
		else if(lowv[i]==0)
		{
			findlow(child[v][i]);
			k=low[child[v][i]];
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
    	if(i!=parent[v])
    	{
    		for(j=0;j<noc[v];j++)
    		{
    			if(i==child[v][j])
    			{
    				check=1;
				}
			}
		if(check==0)
		{
			if(min3>number[i])
			{
				min3=number[i];
			}
		}
		}
	
	  }
	}
////	cout<<"min "<<min<<"  min2 = "<<min2<<" min3 = "<<min3<<endl;
	low[v]=findmin(min,min2,min3); 
	//cout<<"low in fun = "<<low[v]<<endl;
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
		for(j=0;j<=noc[i];j++)
		{
			if(low[child[i][j]]>=number[i]&&i!=s)
			{
				cout<<i<<"   ";
				break;
			}
			else if(low[child[i][j]]>=number[i]&&i==s)
			{
				if(noc[i]>1)
				{
					cout<<i<<"   ";
					break;
				}
			}
		}
	}
}
