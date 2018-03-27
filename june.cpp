#include<iostream>
#include<bits/stdc++.h>
#define  ll long long 
using namespace std;
//set<ll>ma[100];
ll a[2501][2501],len[2501];bool ch[2501];
ll n,k;
bool check(ll i,ll j)
{
	ll i1,j1;	
	for(i1=1;i1<=k;i1++)
	ch[i1]=false;
	
//	cout<<"array 1=\n";

    int c=1;i1=0;j1=0;
	for(;i1<len[i]&&j1<len[j];)
	{
		if(a[i][i1]==c&&a[j][j1]==c)
		{
			i1++;j1++;
			c++;
				if(c==k+1)
				return true;
			
		}	
		else if(a[i][i1]==c)
		{
			i1++;
			c++;
			if(c==k+1)
			return true;
		}
		else if(a[j][j1]==c)
		{
			j1++;
			c++;
			if(c==k+1)
			return true;
		}
		else
		{
			return false;
		}
	}
		while(i1<len[i])
		{
			if(a[i][i1]==c)
			{
				c++;
				i1++;
				if(c==k+1)
				return true;
			}
			else
			{
				return false;
			}
		}
		while(j1<len[j])
		{
			if(a[j][j1]==c)
			{
				c++;
				j1++;
				if(c==k+1)
				{
					return true;
				}
			}
			else
			{
				return false;
			}
		}
		return false;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		ll i,j;
		ll count=0;
		for(i=0;i<n;i++)
		{
			cin>>len[i];
			for(j=0;j<len[i];j++)
			{
				scanf("%lld",&a[i][j]);
			//	ma[i].insert(a[i][j]);
			}
			sort(a[i],a[i]+len[i]);
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(len[i]==k||len[j]==k)
				{
					count++;
					
				}
				else if(len[i]+len[j]>=k)
				{
						if(check(i,j))
					     count++;
				}
			}
		}
		cout<<count<<endl;
		
		
	}
}
