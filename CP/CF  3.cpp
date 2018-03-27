#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
	ll n;
	cin>>n;
	ll a[n],i,j,k,l,k1,k2;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	k=a[n/2];
	if(n%2!=0)
	{
	for(i=n/2+1,j=n/2-1;j>=0&&i<=n-1;j--,i++)
	{
		if(a[i]-k==k-a[j])
		{
			k1=0;
			continue;
		}
		else
		{
		k1=1;
		break;
		}
	}
   }
   else
   {
   	for(i=n/2+1,j=n/2-2;j>=0&&i<=n-1;j--,i++)
   	{
   			if(a[i]-k==k-a[j])
		{
			k1=0;
			continue;
		}
		else
		{
		k1=1;
		break;
		}
    }
   }
   if(k==1)
   cout<<"NO\n";
   else
   cout<<"YES\n";
} 
