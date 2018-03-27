#include<iostream>
#define ll long long
using namespace std;
int main()
{
ll t;
cin>>t;
while(t--)
{
	ll n,k;
	cin>>n>>k;
	ll a[n+1],i;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	ll h,j;
	h=n;ll sum=0;ll c;
     for(j=1;j<=n;j++)
     {c=0;
	for(i=1;i<=n;i++)
	{
	 if(a[i]==j)
	 {
	 	c++;
	 }
	}
	if(c>=k&&a[j]!=j)
	{
		sum++;
	}
  }
  cout<<sum<<endl;
}
}

