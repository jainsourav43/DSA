#include<iostream>
#include<bits/stdc++.h>
#define  ll long long 
using namespace std;
struct st
{
	int ar;
	int ind;
};
bool comp(st s1,st s2)
{
	return s1.ar<s2.ar;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,q;
		cin>>n>>q;
		st s[n+1];
		ll ar[n+1],i,j;
		for(i=1;i<=n;i++)
		{
			cin>>ar[i];
			s[i].ar=ar[i];
			s[i].ind=i;
			
		}
		sort(s+1,s+n+1,comp);
		
		int a,b,c,d;
		int temp1[n+1],temp2[n+1];
		for(i=0;i<q;i++)
		{
			cin>>a>>b>>c>>d;
			if(a==c&&b==d)
			{
				cout<<"YES\n";
			}
			else
			{
			int count1=0,count2=0;
			
			for(j=1;j<=n;j++)
			{
				if(s[j].ind>=a&&s[j].ind<=b)
				temp1[count1++]=s[j].ar;
				if(s[j].ind>=c&&s[j].ind<=d)
				temp2[count2++]=s[j].ar;
			}
			int count3=0;
			for(j=0;j<count1;j++)
			{
				if(temp1[j]!=temp2[j])
				{
					count3++;
					if(count3>1) break;
				//	cout<<"YES\n";
				//	break;
				}
			}
			if(count3<=1)
			{
				cout<<"YES\n";
			}
			else
			{
				cout<<"NO\n";
			}
		}
	}
		
	}
} 
