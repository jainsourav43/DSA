#include<iostream>
using namespace std;
#define ll long long
bool search(ll a[],ll l,ll r,long long int k)
{
	 ll m=l+(r-l)/2;
	if(k==a[m])
	{
		return true;
	}
	else if(k>a[m])
	{
		if(l<=m-1)
		return search(a,l,m-1,k);
	}
	else if(k<a[m])
	{
		if(m+1<=r)
		return search(a,m+1,r,k);
	}
	else 
    return false;
}

int main()
{
	ll n,d;
	cin>>n>>d;
	ll i,j;
	bool check1,check2;
	ll a[n];
	for(i=0;i<n;i++)
	cin>>a[i];ll count=0;
	for(i=0;i<n;i++)
	{
		check1=false;
		check2=false;
		check1=search(a,i+1,n-1,a[i]+d);
		check2=search(a,i+2,n-1,a[i]+2*d);
		if(check1&&check2)
		{
			//cout<<" a[i] = "<<a[i]<<" ";
			count++;
		}
	}//cout<<endl;
	cout<<count<<endl;
	return 0;
}
