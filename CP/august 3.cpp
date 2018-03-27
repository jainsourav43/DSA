#include<iostream>
#define ll unsigned long long
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,i,j,k,l,ans=0,g;
		cin>>n;ll a[n+1];
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(i=1;i<=n;i++)
		{k=i;
			for(j=i;j<=n+i;j++)
			{
			g=j;
			if(g>n)
			{
				g=g-n;
			}
			k=k+a[g]+1;
			j=j+a[g ];
			if(k>n)
			{
			if(k-n==i)
			{ans++;
				break;
			}
			else if(k-n>i)
			{
				break;
			}
			}
	     	}
		}
		cout<<ans<<endl;
	}
	return 0;
}
