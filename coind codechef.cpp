#include<map>
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#include<map>
using namespace std;

ll max(ll a,ll b)
{
	if(a>b)
	return a;
	return b;
}
 map<ll,ll>dp;
ll solveit(ll n)
{
//	cout<<dp[0]<<endl;
if(dp.find(n)==dp.end())
{//	cout<<"n ="<<n<<endl;

	dp[n]=max(solveit(n/2)+solveit(n/3)+solveit(n/4),n);
}
return dp[n];
}
 
 
 
int main()
{
	ll n;
	while(cin>>n)
	{
		ll ans=solveit( n);
		cout<<ans<<endl;
	}
} 
