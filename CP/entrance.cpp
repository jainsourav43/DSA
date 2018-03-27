#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{ll n;
	cin>>n;
		ll a[n];
		ll i,j,k;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		//cin>>a[0]>>a[1]>>a[2];
		sort(a,a+n);
		cout<<a[0]+a[1]<<endl;
	}
	return 0;
}
