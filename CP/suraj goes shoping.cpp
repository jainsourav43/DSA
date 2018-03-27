#include<iostream>
#include<algorithm>
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
		ll i,j,k,a[n+1],ans=0;
		for(i=1;i<=n;i++)
		{
		cin>>a[i];	
		}
		sort(a+1,a+n+1);
		//for(i=1;i<=n;i++)
		//{
		//	cout<<a[i]<<" ";
		//}
		for(j=n;j>=4;j=j-4)
		{
			ans=ans+a[j]+a[j-1];	
	    }	
	    if(n%4==0)
	    {
	    ans=ans+0;
		}
		else if(n%4==1)
		{
			ans=ans+a[1];
		}
		else if(n%4==2)
		{
			ans=ans+a[1]+a[2];
		}
		else
		{
			ans=ans+a[2]+a[3];
		}
		cout<<ans<<endl;
	}
}

