#include<bits/stdc++.h>
bool v[100001];
#define ll long long 
using namespace std;
bool cancut(ll time,ll h[],ll r[],ll l,ll n,ll w)
{
	ll sum=0,i;
	for(i=0;i<n;i++)
	{
		if(time>=(l-h[i])/r[i])
		{
			sum=sum+h[i]+r[i]*time;
			if(sum>=w)
			return true;
		}
	}
	return false;

}
struct st
{
	ll height;
	ll rate;
};
bool comp(st s1,st s2)
{
	return s1.rate<s2.rate;
}
int main()
{
	ll n,w,l,ans;
	cin>>n>>w>>l;
	ll h[n],r[n],i,j,h1[n],r1[n],l1[n],sr[n];
	st s[n];
	for(i=0;i<n;i++)
	{
		cin>>h[i]>>r[i];
//		st[i].height=h[i];
//		st[i].rate=r[i];
	}
	ll max1=*max_element(r,r+n),max2=*max_element(h,h+n);
		ll low=0, high=1000000000000000001,mid;
		
	
		while(high-low>1)
		{
			mid=(low+high)/2;
			//ll su=cancut(mid,h,r,l,n);
			if(cancut(mid,h,r,l,n,w))
			{
			high=mid;
			}
			else 
			{
				low=mid;
			}
			
		}
		cout<<mid<<endl;
}
