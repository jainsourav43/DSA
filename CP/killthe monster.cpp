#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
	ll n,hit,t;
	cin>>n>>hit>>t;
	ll h[n],i,j=0,k,count1=0;
	for(i=0;i<n;i++)
	{
		cin>>h[i];
	}
	sort(h,h+n);
	for(i=0;i<t;i++)
	{
		h[j]=h[j]-hit;
		if(h[j]<=0)
		{
			j++;
			count1++;
		}

	}
	cout<<count1<<endl;
}
