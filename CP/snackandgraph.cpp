#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> g[100001];
int n,m;
struct  degree
{
	int v;
	int deg;
};
degree degre[100001];
bool comp(degree d1,degree d2)
{
	return d1.deg<d2.deg;
}
int binary(int key)
{
	int low=1,high=n+1;
	int mid;
	while(low<high)
	{
		mid=(high+low)/2;
		
		if(key>=degre[mid].deg)
		{
			low=mid+1;
		}
		else 
		{
			high=mid;
		}
	
	}
	return low;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			g[i].clear();
		}
		int i,j,x,y;
		for(i=0;i<m;i++)
		{
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		for(i=1;i<=n;i++)
		{
			degre[i].v=i;
			degre[i].deg=g[i].size();
		}
		int p;
		sort(degre+1,degre+n+1,comp);
//		for(i=1;i<=n;i++) 
//		cout<<degre[i].deg<<"  ";
		for(i=0;i<n;i++)
		{
			p=binary(i);
			cout<<"p= "<<p<<endl;
			
			//if(degre[v])
			cout<<p-1<<"  ";
		}
		cout<<endl;
		
		
		
		
	}
}
