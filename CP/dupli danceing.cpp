#include<iostream>
#define ll long long
using namespace std;
ll binarySearch(ll arr[], ll l, ll r, ll x)
{
   while(r >= l)
   {
        ll mid = l + (r - l)/2;
         if (arr[mid] == x)  return mid;
         else if (arr[mid] > x) 
         {
         	r=mid-1;
		 }
		 else
		 {
		 	l=mid+1;
		 }
   }
   return -1;
}
int main()
{
	ll t;
	cin>>t;
while(t--)
{
	ll n,q;
	cin>>n>>q;
	ll i,j,l;
	ll a[n];ll b[q];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<q;i++)
	{
		cin>>b[i];
	}
	ll u,k;
	for(i=0;i<q;i++)
	{
		 u=-1,k=-1;
		k=binarySearch(a,0,n-1,b[i]);
		if(k>=0)
		cout<<"YES\n";
		else
		{
			u=binarySearch(b,0,i-1,b[i]);
			if(u>=0)
			{
				cout<<"YES\n";
			}
			else
			{
				cout<<"NO"<<endl;
			}
		}
	}
}
return 0;
}
