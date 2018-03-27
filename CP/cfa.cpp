#include<iostream>
#include <iomanip>      // std::setprecision
#include <math.h>       /* ceil*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
#include<iostream>
#include<cmath>
ll c[100001],w[100001],cost=0;
ll dpa[100001];
ll dp(ll pos,ll m,ll n)
{

	if(pos<n&&m-w[pos]>=0)
	{
		if(dpa[pos]==0)
		{
			dpa[pos]= max(c[pos]+dp(pos+1,m-w[pos],n),dp(pos+1,m,n));
			return dpa[pos];
		}
		else
		{
			return dpa[pos];
		}
	}

	else
	{
		return 0;
	}
}
int main()
{
	ll n,m,i,j;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>w[i]>>c[i];
	}
	cost=dp(0,m,n);
	for(i=0;i<n;i++)
	{
		dpa[i]=0;
	}
	cout<<cost<<endl;

}
