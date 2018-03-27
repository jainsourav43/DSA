#include<iostream>
#define ll long long
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m,f;
		cin>>n>>m>>f;
		ll s[n];bool v[n];
		ll i,j,k,l;ll ans=0,ans1=0,ans2;
		for(i=0;i<n;i++)
		{
			cin>>s[i];
			v[i]=true;
		}
		for(i=0;i<n;i++)
		{
			if(s[i]>0&&s[i]%m==0)
			{
				 v[i]=false;
				 ans++;
			}
		}
		for(i=0;i<n;i++)
		{
			if(s[i]>0&&v[i]==true&&s[i]%f==0)
			{
				v[i]=false;
				ans1++;
			}
		}
		ans2=ans1+ans;
		k=(ans2*100)/n;
		if(k>=70)
		{
			cout<<"Yes"<<endl;
			if(ans>ans1)
			{
				cout<<"Multan"<<endl;
			}
			else if(ans1>ans)
			{
				cout<<"Fultan"<<endl;
			}
			else
			{
				cout<<"Both"<<endl;
			}
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
}
