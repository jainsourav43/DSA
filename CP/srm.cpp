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
		cin>>n>>k;
		ll i,j,l,a[n];ll flag=0;ll sum=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(j=0;j<n;j++)
		{
			sum=sum+a[j];
			if(sum>=k)
			{flag=1;
				cout<<"YES"<<endl;
				break;
			}
		}
		if(flag==0)
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
