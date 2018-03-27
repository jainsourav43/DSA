#include<iostream>
#define mod 1000000007
using namespace std;
#define ll long long
ll pow(ll a,ll p)
{
	ll ans=1;
	while(p)
	{
		if(1&p)
		{
			ans=(ans*a)%mod;
		}
		a=(a*a)%mod;
		p>>=1;
	}
	return ans%mod;
}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		if(n==1||n==2)
		{
			cout<<0<<endl;
		}
		else
		cout<<(2*(pow(2,n-2)-1))%mod<<endl;
	}
}	
