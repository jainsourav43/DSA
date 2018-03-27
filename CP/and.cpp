#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll n;
	cin>>n;
	ll a[n],i,j,sum=0,check=0,count=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>1)
		{
			check=1;
		}
		else if(a[i]==1)
		count++;
	}
	sort(a,a+n);
	if(check==0)
	{
	sum=count*(count-1)/2;	
	}
	else
	{	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			sum=sum+(a[i]&a[j]);
			//cout<<(a[i]&a[j])<<endl;
		}
	}
	}
	cout<<sum<<endl;
}
