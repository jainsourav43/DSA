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
		ll i,j;
		i=n-1;
		j=m-1;
		if((i+j)%2==0)
		{
			cout<<"No"<<endl;
		}
		else
		{
			cout<<"Yes"<<endl;
		}
	}
	return 0;
}
