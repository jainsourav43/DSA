#include<iostream>
#include<algorithm>
#include<string.h>
#define ll long long
using namespace std;
int main()
{
	ll n;
	cin>>n;
	ll i,j;
	ll a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
     ll	x=a[0]^a[1];
	for(i=1;i<n-1;i++)
	{
		x=x^a[i+1];
	}
	cout<<x<<endl;
}
