#include<algorithm>
#include<iostream>
#define maxv 100
#define INF 100000
using namespace std;
int graph[maxv][maxv],d[maxv][maxv]; 
void floydwarshall(int n)
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
				cout<<"j,k = "<<j<<" "<<k<<endl;
				if(d[j][k]>d[j][i]+d[i][k])
				{
					d[j][k]=d[j][i]+d[i][k];
				}
			}
		}
	}
}
void print(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(d[i][j]==INF)
			{
				cout<<"INF  ";
			}
			else
			{
				cout<<d[i][j]<<"    ";
			}
		}
		cout<<endl;
	}
}

int main()
{
	int n;int i,j,u,v,c,e;
	cout<<"Enter thr number of vertices and edges\n";
	cin>>n>>e;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			graph[i][j]=INF;
		}
	}
	for(i=1;i<=n;i++) graph[i][i]=0;
	for( i=0;i<e;i++)
	{
		cout<<"enter the vertex u -> v to add in the graph\n";
		cin>>u>>v;
		cout<<"Please enter the cost\n";
		cin>>c;
		graph[u][v]=c;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		d[i][j]=graph[i][j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(graph[i][j]==INF)
			{
				cout<<"INF ";
			}
			else
			{
				cout<<graph[i][j]<<"   ";
			}
		}
		cout<<endl;
	}
	floydwarshall(n);
	print(n);

}
