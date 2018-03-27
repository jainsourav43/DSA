#include<bits/stdc++.h>
#define ll long long 
#include<vector>
#include<stack>
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,i;
		cin>>n;
		char s[2][n+1];
		cin>>s[0]>>s[1];
		int flag=0,flag2=0;
		for(i=0;i<n;i++)
		{
			if(s[0][i]=='*'&&s[1][i]=='*')
			{
				flag=1;
			}
		}
		ll ans=0;
		if(flag==1)
		{
			ans=1;
		}
		int prev[n+1];
		for(i=0;i<n;i++)
		prev[i]=0;
		prev[0]=1;
		int last0=0,last1=0,both=0,ans1=0;
		for(i=0;i<n;i++)
		{
			if(s[0][i]=='*'&&s[1][i]=='*')
			{
				///ans++;
				if(last1==1||last0==1||both==1)
				{
					prev[i]=1;
					ans++;
				}
				both=1;
				last1=1;
				last0=1;
			}
			else if(s[1][i]=='*')
			{
				//ans++;
				if(last1==1)
				{
					ans++;
					last0=0;
					both=0;
				}
				if(last0==1&&last1==0)
				{
					if(flag==0)
					{
						ans1++;
					}
				}
				last1=1;
				
				
			}
			else if(s[0][i]=='*')
			{
				if(last0==1)
				{
					ans++;
					last1=0;
					both=0;
				}
				else if(last1==1&&last0==0)
				{
					if(flag==0)
					{
						ans1++;
					}
				}
				last0=1;
				
			
			}
		}
		if(ans1>=1)
		{
			if(flag==0)
			{
				ans1=0;
				ans=ans+1;
				flag=1;
			}
		}
		cout<<ans<<endl;
		
	}
}
