#include<iostream>
#include<algorithm>
#define ll long long 
using namespace std;
#define ull unsigned long long 
 
ll n,k;
ull count1=0;
 
void func(ll a[],ll i,ull p)
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
