#include<iostream>
#include<algorithm>
#define ll long long 
#include<limits.h>

using namespace std;
bool check(ll p,ll a)
{
	if(p>a)
	{
			if(LONG_LONG_MAX/p>a)
			{
				return true;
			}
	}
	else
	{
			if(LONG_LONG_MAX/a>p)
			{
				return true;
			}
	}
	return false;

}
 int dig(ll n1)
 {
 	int ans=0;
 	while(n1)
 	{
 		n1/=10;
 		ans++;
	 }
	 //cout<<"ans= "<<ans<<endl;
	 return ans;
 }
ll n,k;
ll count1=0;
 
void func(ll a[],ll i,ll p)
{
	if(dig(p)+dig(a[i])<=20&&check(p,a[i]))
	{
	  p=p*a[i];
	// cout<<"p ="<<p<<endl;
	  if(p<=k&&p>0)
	  {
	  	count1++;
	  	for(ll j=i+1;j<n;j++)
	  	{
	  		
	  		func(a,j,p);
		}	  	
			p=p/a[i];
		}
	}
}

int main()
{
	
	cin>>n>>k;
	ll i,j,a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(i=0;i<n;i++)
	{
	if(k>=a[i])
	func(a,i,1);
	}
	cout<<count1<<endl;
	
} 
