#include<iostream>
#define ll long long
using namespace std;
ll gcd(ll x,ll y)
{
	ll r;r=x%y;
	while(r!=0)
	{
		x=y;
		y=r;
		r=x%y;
	}
	return y;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,l ,k;
		cin>>n>>k>>l;ll i,j,a[n];ll le=n-1,ans=0,g;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				g=gcd(a[i],a[j]);ll flag=0;
				for(k=0;k<n;k++)
				{
					if(g==a[k])
					{
						flag=1;
				    }
				}
				if(flag==0)
				{
				//	a[++le]=g;
					ans++;
				}
			}
		}
		if(ans==0)
		{
			cout<<1<<endl;
		}
		else
		cout<<ans<<endl;
	}
}
