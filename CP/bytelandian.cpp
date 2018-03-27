#include<iostream>
#include<bits/stdc++.h>
#define ll long long
ll max(ll a,ll b)
{
	if(a>b)
	return a;
	return b;
}
ll solveit(ll n)
{
	ll tmp=n/12;
	ll tmp1=n%12;
	if(n==0)
	return 0;
	if(tmp1==0)
	{
		return n/2+n/3+n/4;
	}
	else if (n<12)
	{
		return n;
	}
	else
	{
	
			return max(solveit(n/2)+solveit(n/3)+solveit(n/4),n);
	}
}



using namespace std;
int main()
{
	ll n;
	while(cin>>n)
	{
		ll ans=solveit( n);
		cout<<ans<<endl;
	}
}
