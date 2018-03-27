#include<iostream>
using namespace std;
#define ll long long 
#include<bits/stdc++.h>
#include<map>
#include<limits.h>
ll n,q,r,uk,min1,max1,in;
void dfs(ll v,ll u,ll k,map< ll ,ll > &M,map< ll ,ll > &P)
{
	ll t1,i,temp1,temp2;
	if(v!=r)
	{
	temp1=P[v]^k;
	}	
	else
	{
	temp1=uk^k;
	u=-1;
	}
	if(temp1>max1)
	{
		max1=temp1;
	}
	else if(min1>temp1)
	{
		min1=temp1;
	}
	if(u!=-1)
	{
	dfs(M[v],u,k,M,P);
	}
}
int main()
{
	
	cin>>n>>q;
	map< ll ,ll > P; 
	map< ll,ll > M;
	cin>>r>>uk;
	ll i;
		ll tempu,tempv,tempk;
		char ch[20],ch1[20],ch2[20];
	for(i=0;i<n-1;i++)
	{
		cin>>tempu>>tempv>>tempk;
		P[tempu]=tempk;
		M[tempu]=tempv;
	}
	 in=n-1;
	ll la=0;
	ll t;
	ll u,v,k;
	for(i=0;i<q;i++)
	{
		cin>>t;
		t=t^la;
		if(t==0)
		{
			cin>>v>>u>>k;
			v=v^la;
			u=u^la;
			k=k^la;
		M[u]=v;
		P[u]=k;
		}
		else
		{
			cin>>v;
			cin>>k;
			v=v^la;
			k=k^la;
			min1=INT_MAX;
			max1=INT_MIN;
			dfs(v,1,k,M,P);
			cout<<min1<<" "<<max1<<endl;
			la=max1^min1;
		}
	}
	
	
}
