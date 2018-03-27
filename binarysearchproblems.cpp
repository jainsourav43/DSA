#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long 
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
	long long n;
	cin>>n;
	ll low=0,hi=n,mid=((hi+low)/2);
	while(low<=hi)
	{
		mid=((hi+low)/2);
		if(mid*(mid+1)/2<=n&&((mid+1)*(mid+2))/2>n)
		{
			cout<<mid<<endl;
			break;
		}
		else if(mid*(mid+1)/2<n)
		{
			low=mid+1;
		}
		else if(mid*(mid+1)/2>n)
		{
			hi=mid-1;
		}
	}
	
	
	}
}
