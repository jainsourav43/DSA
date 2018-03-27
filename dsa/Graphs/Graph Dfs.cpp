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
void dfs(int v,int n)
{
	int i;static int ans=1;
	ve[v]=1;
	cout<<v<<" ";
	for(i=1;i<=n;i++)
	{
		if(a[v][i]>0&&ve[i]==0)
		{
			dfs(i,n);
			//cout<<"v    my love = "<<v<<endl;
			
		}
	}
//	number[v]=ans++;
//for(i=1;i<=n;i++)
//{
//	int j=in_degree(n,v);
////	cout<<"v  ="<<v<<"   count[v] = "<<count[v]<<"  j =  "<<j<<endl;
//	if(count[v]<j)
//	{
////	cout<<"Entering\n";
//	//cout<<"v  ="<<v<<"count[v] = "<<count[v]<<"  j  =  "<<j<<endl;
//	ve[v]=0;
//	cout<<endl;
//	
//	count[s]++;
//	dfs(s,n);
//	break;
//    }
//}
}
int main()
{
	int n,n1,i,ou,j;
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
	dfs(s,n);cout<<endl;
//	
//	check=0;
//	while(check==0)
//	{
//	for(i=1;i<=n;i++)
//	{
//		if(ve[i]==0)
//		{
//			dfs(i,n);
//			cout<<endl;
//		}
//	}
//	for(j=1;j<=n;j++)
//	{
//		if(ve[j]==1)
//		{
//			check=1;
//		}
//		else if(ve[j]==0)
//		{
//			check=0;
//			break;
//		}
//	}
//   }
//   check=0;
//   cout<<"Numbered array\n";
//   for(i=1;i<=n;i++)
//   {
//   	cout<<number[i]<<"   ";
//   }cout<<endl;int ans;
//	for(i=1;i<=n;i++)
//	{
//		for(j=1;j<=n;j++)
//		{
//			a[i][j]=0;
//		}
//	}
//	for(i=1;i<=n;i++)
//	{
//		ve[i]=0;
//	}
//	for(i=0;i<n1;i++)
//	{
//		a[vn[i]][un[i]]=1;
//	}	
//	for(i=1;i<=n;i++)
//	{
//		a[i][i]=1;
//	}
//	max=0;
//	cout<<"After \n";
//	ans=1;
//	while(check==0)
//	{max=0;
//	cout<<"{";
//	for(i=1;i<=n;i++)
//	{
//		if(max<number[i]&&ve[i]==0)
//		{
//		max=number[i];
//		ans =i;
//	    }
//	}
//	  dfs(ans,n);
//	  cout<<"}";cout<<endl;
//	  for(j=1;j<=n;j++)
//	  {
//	  	if(ve[j]==1)
//	  	{
//	  		check=1;
//		}
//		else
//		{
//			check=0;
//			break;
//		}
//	  }
//   }
//	
}
