#include<iostream>
#include<bits/stdc++.h>
#define  ll long long 
using namespace std;
map<ll,ll>ma[100000];
ll a[100001],n;
void findprime()
{
	int i;
	for(i=0;i<n;i++)
	{
		int temp=a[i];
		while(temp%2==0)
		{
			ma[i][2]++;
			temp=temp/2;
		}
		for(int j=3;j*j<=temp&&temp>0;j+=2)
		{
			while(temp%j==0)
			{
				ma[i][j]++;
				temp=temp/j;
			}
		}
		if(temp>2)
		{
			ma[i][temp]++;
		}
		
	}
}

int main()
{

		cin>>n;	
		ll i;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		findprime();
		ll q;
		cin>>q;
		ll l,r,x,y;
		map<ll,ll> :: iterator it1,it2;
		for(i=0;i<q;i++)
		{
			cin>>l>>r>>x>>y;
			ll ans=0;
			for(int j=l-1;j<r;j++)
			{
				it1=ma[j].lower_bound(x);
				it2=ma[j].upper_bound(y);
				for(;it1!=ma[j].end()&&it1!=it2;it1++)
				{
					ans=ans+it1->second;
				}
				
			}
			cout<<ans<<endl;
			
		}
		
}
