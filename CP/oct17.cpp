#include<iostream>
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll ans=INT_MIN;
		int i,j;
		vector< vector<int> > a;
		for(i=0;i<n;i++)
		{
			ll m;
			cin>>m;
			vector<int> cur;
			for(j=0;j<m;j++)
			{
				int temp;
				cin>>temp;
				cur.push_back(temp);
			}
			a.push_back(cur);
			
		}
		int ma[n],mi[n];
		for(i=0;i<n;i++)
		{
			ma[i]=*max_element(a[i].begin(),a[i].end());
			mi[i]=*min_element(a[i].begin(),a[i].end());
		}
	}
}
