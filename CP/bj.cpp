#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
int main()
{

int t;
cin>>t;
while(t--)
{
	int n;
	cin>>n;
	int a[n],i;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	long long ans=0,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if((a[i]|a[j])<=max(a[i],a[j]))
			{
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
}
