#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
bool check(ll a[],int x)
{
	for()
}
int main()
{
	ll n,c;
	cin>>n>>c;
	ll i,j;
	ll a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		m[a[i]]=true;
		
	}
	sort(a,a+n);
	int maxgap=INT_MIN,mingap=INT_MAX;
	for(i=1;i<n;i++)
	{
		if(a[i]-a[i-1]>maxgap)
		{
			maxgap=a[i]-a[i-1];
		}
		if(a[i]-a[i-1]<mingap)
		{
			mingap=a[i]-a[i-1];
		}
	}
	
	ll l=mingap,h=maxgap,mid;
	while(l<=h)
	{
		mid=(h+l)/2;
		if(check(a,mid))
		{
			ans=max(ans,mid);
			l=mid+1;
		}
		else
		{
			h=mid-1;
		}
	}
	
	
	
	
}
