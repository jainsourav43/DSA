#include<iostream>
#define ll long long 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll g;
		cin>>g;
		while(g--)
		{
			ll i,n,q;
			cin>>i>>n>>q;
			if(i==1)
			{
				if(n%2==0)
				{
					cout<<n/2<<endl;
				}
				else
				{
					if(q==1)
					{
						cout<<n/2<<endl;
					}
					else
					{
						cout<<n/2+1<<endl;
					}
				}
			}
			else
			{
				if(n%2==0)
				{
					cout<<n/2<<endl;
				}
				else
				{
					if(q==1)
					{
						cout<<n/2+1<<endl;
					}
					else
					{
						cout<<n/2<<endl;
					}
				}
			}
		}
	}
}
