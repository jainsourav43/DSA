#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
int main()
{
	int r;
	cin>>r;
	while(r--)
	{
		int n,q;
		cin>>n>>q;
		int l[n],k[q],i,j;
		for(i=0;i<n;i++)
		{
			cin>>l[i];
		}
		for(i=0;i<q;i++)
		{
			cin>>k[i];
		}
		sort(l,l+n);
		int max1[n];
		for(i=0;i<n;i++)
		{
			if(i>=1)
			{
				if(max[i-1]>0)
			}
			else
			max1[i]=l[i]+i;
			
		}
		sort(max1,max1+n);
		int p;
		for(i=0;i<q;i++)
		{
			p=lower_bound(max1,max1+n,k[i])-max1;
			if(p==n)
			{
				cout<<0<<endl;
			}
			else
			cout<<n-p<<endl;
	
		}
		
		
	}
}
