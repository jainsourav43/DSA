#include<iostream>
#define ll long long 
using namespace std;
ll graph[21][21];
ll graph1[21][21];
ll n,e;
int indeg(int v)
{
	int count=0;
	for(int i=1;i<=n;i++)
	{
		if(graph[i][v]==1)
		{
			count++;
		}
	}
	return count;
}
int oudeg(int v)
{
	int count=0;
	for(int i=1;i<=n;i++)
	{
		if(graph[v][i]==1)
		{
			count++;
		}
	}
	return count;
}
int main()
{
	ll i,in,ou;
	cin>>n>>e;int u,v;
	for(i=1;i<=e;i++)
	{
		cin>>u>>v;
		graph[u][v]=1;
	}
	int check=0;ll j;
	if(e<n)
	{
		cout<<"NO\n";
	}
	else
	{
	for(i=1;i<=n;i++)
	{
		in=indeg(i);
		ou=oudeg(i);
		if(in+ou<2)
		{
			//cout<<"i = "<<i<<endl;
			cout<<"NO\n";
			check=1;
			break;
		}
		else
		{
			if(in>=2&&ou==0)
			{
				for(j=1;j<=n;j++)
				{
					if(graph[j][i]==1&&graph1[i][j]==0)
					{
						graph[j][i]=0;
						graph1[j][i]=1;
						graph[i][j]=1;
					}
				}
			}
			else if(in==0&&ou>=2)
			{
				for(j=1;j<=n;j++)
				{
					if(graph[i][j]==1&&graph1[j][i]==0)
					{
						graph[i][j]=0;
						graph1[i][j]=1;
						graph[j][i]=1;
					}
				}		
			}
		}
	}
	if(check==0)
	{
	    cout<<"YES\n";
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(graph[i][j]==1)
				{
					cout<<i<<" "<<j<<endl;
				}
			}
		}
	}
	}
}
