#include<iostream>
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll dp[2097152],n,k,count1=0,t[22];
void calculate(ll pos,ll s,ll ans,ll a[])
{
	if(s<ans)
	{
		s=s+a[pos];
		if(ans==s)
		dp[count1++]=s;
		
	for(int i=pos+1;i<n;i++)
	{
		//t[i]=false;
		calculate(i,s,ans,a);
		//t[i]=true;		
	}
	s=s-a[pos];
	}
}
bool c;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		count1=0;
		cin>>n>>k;
		ll a[n],i,j,m=0,sum=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]>m) m=a[i];
			sum+=a[i];
		}
		ll ans=sum/k;
			int check=0;
			for(i=0;i<n-1;i++)
			{
				if(a[i]!=a[i+1])
				{
					check=1;
					break;
				}
			}
			sort(a,a+n);
		for(i=0;i<n;i++)
		calculate(i,0,ans,a);
	//	for(i=0;i<count1;i++) cout<<dp[i]<<" ";cout<<endl;
		if(k>n)
		{
			cout<<"no\n";
		}
		else if(sum%k)
		{
			cout<<"no\n";
		}
		else if(k==n)
		{
			if(check)
			cout<<"no\n";
			else
			cout<<"yes\n";
		}
		else
		{
			if(m>ans)
			{
				cout<<"no\n";
			}
			else
			{
			ll max=n-k+1,count2=0;
		
			if(count1>=k)
			{
				cout<<"yes\n";
			}
			else
			{
				cout<<"no\n";
			}
			}
		}
	
	}
}
