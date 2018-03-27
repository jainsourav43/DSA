#include<iostream>
using namespace std;
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
void print(int a[][50],int n)
{
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<a[i][j]<<"  ";
		}
		cout<<endl;
	}
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
struct vertex
{
	int visit;
	int prev;
	int dist;
};
vertex ve[20];int check=0;
int dfs(int c,int g,int n)
{
	if(c!=g)
	{
		int i,j;
		v[c].visit=1;
		for(i=1;i<=n;i++)
		{
			if(v[i].visit==-1&&a[c][i]>0)
			{
				if(v[i].dist>v[c].dist+a[c][i])
				{
					v[i].dist=v[c].dist+a[c][i];
					v[i].prev=c;
				}
			}
		}
		int min=10000,in;
		for(i=1;i<=n;i++)
		{
			if(a[c][i]<min)
			{
				min=a[c][i];
				in=i;
			}
		}
		dikshtra(in,g,n);
	}
	else
	{
		return v[c].dist;
	}
}
int  dikshtra(int c,int g,int n)
{
	int i,j,min=10000,in;//cout<<"Dikshtre   "<<c<<endl;;
	if(c!=g)
	{
	ve[c].visit=1;
	for(i=1;i<=n;i++)
	{//cout<<"For\n";
		if(ve[i].visit==-1&&a[c][i]>0)
		{
			if(ve[i].dist>ve[c].dist+a[c][i])
			{
				ve[i].dist=ve[c].dist+a[c][i];
				ve[i].prev=c;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
	if(ve[i].visit==-1&&a[c][i]>0)
	{
		if(min>ve[i].dist)
		{
			min=ve[i].dist;
			in=i;
		}
	}
	}
//	check=1;
//	for(i=1;i<=n;i++)
//	{
//		if(ve[i].visit==1)
//		{
//			//check=1;
//			continue;
//		}
//		else 
//		{
//			check=0;
//			break;
//		}
//	}
	dikshtra(in,g,n);
   }
   else
   return ve[c].dist;	
}
void print1(int p,int s)
{
	if(ve[p].prev!=s)
	{
		print1(ve[p].prev,s);
		cout<<ve[p].prev<<"  ";
	}
}
int s,g,c;
int main()
{
	int n,n1,i;
	cout<<"Enter the number of vertices\n";
	cin>>n;
	for(i=1;i<=n;i++)
	{
		ve[i].prev=-1;
		ve[i].dist=10000;
		ve[i].visit=-1;
	}
	int in[n],u,v,i1;
	cout<<"Enter the number of edges\n";
	cin>>n1;int cost;
	for(i=1;i<=n1;i++)
	{
	   cout<<"enter the u and v 'u->v' \n";
	   cin>>u>>v;
	   cout<<"Enter the cost\n";
	   cin>>cost;
	   a[u][v]=cost;
	}
	print(a,n);
	cout<<"Enter the source\n";
	cin>>s;
	cout<<"Enter the goal\n";
	cin>>g;
	ve[s].dist=0;
	ve[s].prev=-1;
	c=s;
	int count,count1,check=0,ans;
	ans=dikshtra(s,g,n);
	cout<<"shortest length is \n";
	cout<<ans<<endl;
	int p=g;
	cout<<"Path is \n";
	cout<<s<<"  ";
	print1(g,s);
	cout<<g<<"  ";
	return 0;
}
