#include<iostream>
#include<algorithm>
#include<map>
#define ll long long
using namespace std;
bool comp(ll x,ll y)
{
	return x>y;
}
//map<ll,ll>m;
int  sum[100000001];
bool v[1000001];
int main()
{
	ll n,k;
	cin>>n>>k;
	ll a[n],i,j;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	long long  diff[n],count=0;
	sort(a,a+n,comp);
//	v[0]=true;
	for(i=0;i<n;i++)
	{
//	map[a[i]]++;
	if(i-1<0)
	sum[a[i]]=sum[a[i]]+1;
	else
	sum[a[i]]=sum[a[i-1]]+1;
	v[a[i]]=true;
	}
	int m=*max_element(a,a+n);
	for(i=m;i>=0;i--)
	{
		if(!v[i])
		{
			sum[i]=sum[i+1];
		}
	}
	
	ll ans=0;
//	for(i=0;i<=m;i++) cout<<sum[i]<<" ";cout<<endl;
	for(i=0;i<n;i++)
	{
	  ans=ans+sum[k+a[i]];
	}
	
	cout<<ans<<endl;
	
}
