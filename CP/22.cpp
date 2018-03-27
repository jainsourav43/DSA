#include<iostream>
#include<algorithm>
#define ll long long 
using namespace std;
 
ll n,k;
ll count1=0;

void func(ll a[],ll i,ll p)
{
	 	 p=p*a[i];
	  if(p<=k&&p>0)
	  {
	  	count1++;
	  	for(ll j=i+1;j<n;j++)
	  	{
	  		if(p*a[j]<=k)
	  		func(a,j,p);
		}	  	
			p=p/a[i];
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
