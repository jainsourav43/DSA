#include<iostream>
#define ll long long
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;ll ans=0,flag=0;
		ll i,j;ll a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<n;i++)
		{ans=0;
			for(j=i;j<n;j++)
			{
				if(a[j]%2==0)
				{
					ans++;
				}
				if(ans==k)
				{flag=1;
					break;
				}
			}
			if(flag==1)
			{
				break;
			}
		}
		if(flag==1)
		{
			cout<<"YES\n";
		}
		else
		cout<<"NO\n";
	}
	return 0;
}
