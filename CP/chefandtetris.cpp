#include<iostream>
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n],b[n],i,j,sum=0,ans=-1;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		for(i=0;i<n;i++)
		{
			cin>>b[i];
			sum+=b[i];
		}
		if(sum%n)
		{
			cout<<-1<<endl;
		}
		else
		{
			ans=sum/n;
			vector<bool> v(n+1,false);
			if(n==1)
			{
				cout<<a[0]+b[0]<<endl;
				continue;
			}
			if(a[0]+b[0]==ans)
			{
				v[0]=true;
			}
			else if(a[0]+b[1]==ans)
			{
				v[1]=true;
			}
			else
			{
				cout<<-1<<endl;
				continue;
			}
			int check=0;
			for(i=1;i<n-1;i++)
			{
				
				if(a[i]==ans)
				{
					continue;
				}
				else if(v[i-1]==false&&a[i]+b[i-1]==ans)
				{
					v[i-1]=true;
					continue;
				}
				else if(v[i]==false&&a[i]+b[i]==ans)
				{
					v[i]=true;
				}
				else if(v[i+1]==false&&a[i]+b[i+1]==ans)
				{
					v[i+1]=false;
				}
				else
				{
					check=1;
					break;
				}
			}
			if(check==1)
			{
				cout<<-1<<endl;
				continue;
			}
			if(v[n-1]==false&&b[n-1]+a[n-1]==ans)
			{
				v[n-1]=true;
				cout<<ans<<endl;
			}
			else if(v[n-2]==false&&b[n-2]+a[n-1]==ans)
			{
				v[n-2]=true;
				cout<<ans<<endl;
			}
			else if(a[n-1]==ans)
			{
				cout<<ans<<endl;
			}
			else
			{
				cout<<-1<<endl;
			}
			
			
			
		}
	}
}
