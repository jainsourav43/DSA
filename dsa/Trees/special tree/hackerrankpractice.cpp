#include<iostream>
using namespace std;
#include<cmath>
#define ll long long
int search(ll a[],ll l,ll r,long long int k)
{
	 ll m=l+(r-l)/2;
 cout<<"m= "<<m<<" k = "<<k<<endl;
	if(k==a[m])
	{//
	cout<<"one\n";
		return m;
	}
	else if(k<a[m])
	{	cout<<"two\n";
		if(l<=m-1)
		return search(a,l,m-1,k);
	}
	else if(k>a[m])
	{	cout<<"three\n";
		if(m+1<=r)
		return search(a,m+1,r,k);
	}
//	else
//	{
//		cout<<"four\n"; 
    return -1;
    
//	}
}

int main()
{
	ll n,d;
	cin>>n;
	ll i,j;
	int  check1,check2;
	ll a[n];
	for(i=0;i<n;i++)
	cin>>a[i];ll count=0,min=1000000000;
	for(i=0;i<n;i++)
	{
		check1=search(a,i+1,n-1,a[i]);
		if(check1!=-1)
		{
			cout<<"dis= "<<abs(i-check1)<<endl;
			if(min>=abs(i-check1)&&abs(i-check1)!=0)
			{
				min=abs(i-check1);
			}
		}
		
	}
	if(min!=1000000000)
	cout<<min<<endl;
	else
	cout<<-1<<endl;
	return 0;
}
