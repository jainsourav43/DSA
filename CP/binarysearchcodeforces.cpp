#include<iostream>
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
struct st
{
	int ind;
	int val;
};
bool comp(st s1,st s2)
{
	return s1.val<s2.val;
}
int main()
{
	ll n,s;
	cin>>n>>s;
	ll a[n],i,j;
	st s1[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		s1[i].val=a[i];
		s1[i].ind=i+1;
	}
	sort(s1,s1+n,comp);
	
	ll sum[n],sumi[n];
	sum[0]=s1[0].val;
	sumi[0]=s1[0].ind;
	for(i=1;i<n;i++)
	{
		sum[i]=s1[i].val+sum[i-1];
	}
	for(i=1;i<n;i++)
	{
		sumi[i]=s1[i].ind+sumi[i-1];
	}
	if((sum[n-1]+(n*n*(n+1)/2)<s))
	{
		cout<<n<<" "<<sum[n-1]+(n*n*(n+1)/2)<<endl;
	}
	else
	{
		///while(s>0)
		
			ll l=0,r=n-1,mid;
			while(l<=r)
			{
				mid=(l+r)/2;
		//	cout<<"mid ="<<(l+r)/2<<endl;
				if((sumi[mid]*(mid+1))+sum[mid]<=s)
				{
					l=mid+1;
		//		cout<<"mid,low  ="<<mid<<" "<<l<<endl;
				}
				else
				{
					r=mid-1;
				}
			}
			if(l>0)
			cout<<l<<"  "<<(sum[l-1]+sumi[l-1]*l)<<endl;
			else
			cout<<0<<" "<<0<<endl;
	}
	
}
