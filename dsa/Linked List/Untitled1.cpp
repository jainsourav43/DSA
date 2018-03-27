#include<iostream>
#define ll long long
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,x;
		cin>>n>>x;
		if(n%x==0)
		{
			cout<<x<<endl;
		}
		else
		{
			cout<<n%x<<endl;
		}
	}
	return 0;
}
