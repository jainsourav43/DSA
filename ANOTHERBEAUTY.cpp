#include<iostream>
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
vector<bool> prime(1000001,true);
void generate()
{
	ll p=2,i,j;
	prime[1]=false;
	for(p=2;p*p<=1000000;p++)
	{
		if(prime[p]==true)
		{
			for(j=2*p;j<=1000000;j+=p)
			{
				prime[j]=false;
			}
		}
	}
}
ll primefactor(ll n)
{
	ll i,res=1,count=0;
	while(n%2==0)
	{
		n=n/2;
		count++;
	}
	res=res*(count+1);
	for(i=3;i*i<=n;i+=2)
	{
		count=0;
		while(n%i==0)
		{
			n=n/i;
			count++;
		}
		res=res*(count+1);
	}
	
	if(n>2)
	{
		res=res*2;
	}
	return res;
}
	ll rem[1000001],cnt[1000001];
int main()
{
	ll t;
	cin>>t;
	generate();
	while(t--)
	{
		ll l,r,i,p,ans,j;
		cin>>l>>r;
		for(i=l;i<=r;i++)
		{
			cnt[i-l]=1;
			rem[i-l]=i;
		}
		for(i=1;i<=1000000;i++)
		{
			if(prime[i])
			{
				for(j=((l-1)/i+1)*ij<=r;j+=i)
				{
					ll x=j-l;
					ll c=0;
					while(rem[x]%i==0)
					{
						rem[x]/=i;
						++c;
					}
					cnt[x]*=(c+1);
				}
			}
		}
			for (int i = 0; i <= r - l; ++i) {
			if (rem[i] > 1) {
				cnt[i] *= 2;
			}
			if (prime[cnt[i]]) {
				++ans;
			}
		}
		cout<<ans<<endl;
	}
}
