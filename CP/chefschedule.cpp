#include<iostream>
#include<bits/stdc++.h>
#define  ll long long
using namespace std;

ll cons[1000001];
ll findbin(ll top[],ll low ,ll high,ll key)
{
	//cout<<"key\"
	ll mid=(low+high)/2,ans=high+1;
	while(low<=high)
	{
		mid=(high+low)/2;
	//	cout<<"MId= "<<mid<<endl;
		if(top[mid]>key)
		{
			ans=mid;
			high=mid-1;
		}
		else if(top[mid]<=key)
		{
			low=mid+1;
		}
		
	}
	return ans;
}
//ll pow(ll a,ll p)
//{
//	ll ans=1;
//	while(p)
//	{
//		if(p&1)
//		{
//			ans=ans*a;
//		}
//		a=a*a;
//		p>>=1;
//	}
//	return ans;
//}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,k,i;ll ans=0;
		cin>>n>>k;
		ll a[n],top[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<n;i++)
		{
		//	cout<<"log  ="<<log2(a[i])<<" "<<log2(k)<<endl;
			ll lo=log2(a[i])/log2(k);
		//	cout<<"lpg  ="<<lo<<endl;
		//	cout<<"po= "<<pow(k,lo)<<"  "<<pow(k,lo+1)<<endl;
			if(pow(k,lo)==a[i]||pow(k,lo+1)==a[i])
			{
				ans++;
			}
			
		}
		cout<<ans<<endl;
	}
}
