#include<iostream>
#include<bits/stdc++.h>
#define ll long long 

void build(int a[],int n)
{
	int i,j;
	for(i=n-1;i>0;i--)
	{
		a[i]=a[2*i]+a[2*i+1];
	}
}


using namespace std;
int main()
{
	ll n,k,p;
	cin>>n>>k>>p;
	ll a[2*n],i,j;
	for(i=n;i<2*n;i++)
	{
		cin>>a[i];
	}
	build(a,n);
	
	
}
