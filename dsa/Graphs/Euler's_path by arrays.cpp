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
int ve[50],final[50],first=0,siz=0,rem,second =0;
void dfs(int v,int n,int u)
{
	
	int i,k,j;
	//cout<<"v = "<<v<<"u  =  "<<u<<endl;
	if(in_degree(n,v)>0)
	{	cout<<"v = "<<v<<"u  =  "<<u<<endl;
	//ve[v]=1;
	//cout<<u<<" ";
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
    	cout<<temp[i]<<"  ";cout<<endl;
   		for(i=0;i<si;i++)
   		{
   			final[i]=temp[i];
		}
		siz=si;
		cout<<"spliced  array \n";
		for(i=0;i<siz;i++)
	    cout<<final[i]<<"  ";cout<<endl;
		for(i=0;i<siz;i++)
		{
			if(in_degree(n,final[i])>0)
			{
				for( j=1;j<=n;j++)
				{
					if(a[final[i]][j]>0)
					{
						break;
					}
				}
				si=0;rem =final[i];
				temp[si++]=final[i];
				dfs(final[i],n,j);
				break;
			}
		}
        cout<<"si ="<<si<<endl;		
	}
	else
	{	cout<<"Else  pf splicing \n";
    	cout<<"sz ="<<siz<<endl;
    	cout<<"si = "<<si<<endl;
    	cout<<"rem2  ="<<rem <<endl;
    	cout<<"temp array \n";cout<<"rem = "<<rem<<endl;
    	for(i=0;i<si;i++)
    	cout<<temp[i]<<"  ";cout<<endl;
    	second++;
    	int temp2[20];
    	    cout<<"Final array before splicing  array \n";
				for(int l=0;l<siz;l++)
				{
					temp2[l]=final[l];
					cout<<final[l]<<"  ";
				}
    	for(i=0;i<siz;i++)
		{
			if(final[i]==rem)
			{
			    cout<<"i  = "<<i<<endl;
				for(k=i;k<siz-1;k++)
				{
					cout<<"si+k = "<<si+k<<" k+1 = "<<k+1<<endl;
					final[si+k]=temp2[k+1];
				}
				int m=0;
				for(j=i;j<si+i;j++)
				{
					final[j]=temp[m];
					siz++;
					m++;
				}
				siz--;
				cout<<"spliced array \n";cout<<"size = "<<siz<<endl;
				for(int l=0;l<siz;l++)
				{
					cout<<final[l]<<"  ";
				}
				break;
			}
		}
		si=0;int j1;
    	for(i=0;i<siz;i++)
		{
			if(in_degree(n,final[i])>0)
			{
				for( j1=1;j1<=n;j1++)
				{
					if(a[final[i]][j1]>0)
					break;
				}
				cout<<"final ans ="<<final[i]<<endl;
				rem=final[i];
				temp[si++]=final[i];
				dfs(final[i],n,j1);
			}
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
	    cout<<s<<" ";temp[si++]=s;
	    dfs(s,n,i);
		if(siz==0)
		{
		    cout<<"Temp\n";
			for(i=0;i<si;i++)
			{
				cout<<temp[i]<<"  ";
			}
		}
		else
		{cout<<"Final\n";
		//final[siz]=1;
		for(i=0;i<siz;i++)
	    cout<<final[i]<<"  ";
	    }
}
