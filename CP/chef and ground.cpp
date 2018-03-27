#include<iostream>
#define ll long long
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		ll a[n];
		ll i,j=0,k;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			j=j+a[i];
		}
		if((j+m)%n==0)
		{
			cout<<"Yes\n";
		}
		else
		cout<<"No\n";
	}
	return 0;
}

