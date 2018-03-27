#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long 
int main()
{
	ll t;
	t=1;
	while(t--)
	{
			//cout<<"mod"<<mod<<endl;
		ll n;
		cin>>n;
		ll c;
		cin>>c;
		ll a[n];
		int i;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
	
		int j,k,k1,xo,ans=0;
		for(i=0;i<c;i++)
		{
			ans=0;
			ll l,r;
			cin>>l>>r;
			l=l-1;
			r=r-1;
			for(j=l;j<=r;j++)
			{
				xo=0;
				for(k=l;k<=r;k++)
				{
					xo=(xo^a[k])%mod;
//					for(k1=j;k1<=k;k1++)
//					{
//						xo=(xo^a[k1])%mod;
//					}
					ans=(ans^xo)%mod;
				}
			}
				cout<<ans<<endl;
		}
	
		
		
	
	}
}
