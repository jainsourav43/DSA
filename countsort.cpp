#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int range=*max_element(a,a+n);
	int *count=new int[range+1];
	for(int i=0;i<=range;i++)
	{
		count[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		count[a[i]]++;
	}
	for(int i=0;i<=range;i++)
	{
		while(count[i]!=0)
		{
			cout<<i<<" ";
			count[i]--;
		}
	}
}
