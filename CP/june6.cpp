#include<iostream>
#include<bits/stdc++.h>
#define  ll long long 
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,q;
		cin>>n>>q;
		
		ll ar[n+1],i,j;
		for(i=1;i<=n;i++)
		{
			cin>>ar[i];
		}
		int a,b,c,d;
		int temp1[n+1],temp2[n+1];
		for(i=0;i<q;i++)
		{
			cin>>a>>b>>c>>d;
			int count1=0,count2=0;
			for(j=a;j<=b;j++)
			{
				temp1[count1++]=ar[j];
			}
			int count3=0;
			for(j=c;j<=d;j++)
			{
				temp2[count2++]=ar[j];
			}
			sort(temp1,temp1+count1);
			sort(temp2,temp2+count2);
			for(j=0;j<count1;j++)
			{
				if(temp1[j]!=temp2[j])
				{
					count3++;
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
