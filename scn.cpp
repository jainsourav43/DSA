#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int k,a,b;
		cin>>k>>a>>b;
		if(a>b)
		swap(a,b);
		int a1=b-a-1;
		int a2=k-(a1)-2;
		if(a1==a2)
		{
			cout<<0<<endl;
		}
		else
		{
			cout<<min(a2,a1)<<endl;
		}
	}
}
