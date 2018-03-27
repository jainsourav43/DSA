#include<iostream>
#include<cmath>
#define ll long long
using namespace std;
int main()
{
	ll n,k;
	cin>>n>>k;
	ll i,j,l,c=0,a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j+=4)
		{
		   if(abs(a[i]-a[j])>=k)
		   {
		   	c++;
		   }
		   if(abs(a[i]-a[j+1])>=k&&j+1<n)
		   {
		   	c++;
		   }
		   if(abs(a[i]-a[j+2])>=k&&j+2<n)
		   {
		   	c++;
		   }
		    if(abs(a[i]-a[j+3])>=k&&j+3<n)
		   {
		   	c++;
		   }
		}
	}
	cout<<c<<endl;
	return 0;
} 
