#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		
		int k;
		int n;
		cin>>n>>k;
		int i;
		map<int,int> m;
		long long a[n];
		
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			m[a[i]]++;
		}
		cout<<pow(2,k)-1-m.size()<<endl;
		
	}
}
