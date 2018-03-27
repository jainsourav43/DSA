#include<iostream>
#include<bits/stdc++.h>
#define  ll long long 
using namespace std;
bool comp(ll a,ll b)
{
	return a>b;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n],i,j,j1=0;ll ans=0;
		for(i=0;i<n;i++)
		{
		//	cin>>a[i];	
			scanf("%lld",&a[i]);
		}		
		sort(a,a+n,comp);
		ll sum=0,maxsum=INT_MIN,curr[n];
		for(i=0;i<n;i++)
		{
			if(a[i]>=0)
			sum=sum+a[i];
			else 
			break;
		}
		if(i<n)
		{
			
			for(j=i;j<n;j++)
			{
				if((sum+a[j])*(j+1)>(sum*(j)+a[j]))
				{
				//	cout<<"j1=n";
					sum=sum+a[j];
				}
				else
				{
					break;
				}
			}
			if(j==n)
			ans=sum*(j);
			else
			ans=sum*(j);
			for(j1=j;j1<n;j1++)
			{
				ans=ans+a[j1];
			}
			cout<<ans<<endl;
		}
		else
		{
			cout<<sum*n<<endl;
		}
		
		
		
	
		
	}
	
}
