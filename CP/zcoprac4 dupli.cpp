#include<iostream>
#include<algorithm>
#define ll long long 
using namespace std;
int main()
{
	ll n,k;
	cin>>n>>k;
	ll h[n],i;
	for(i=0;i<n;i++)
	{
		cin>>h[i];
	}
	sort(h,h+n);
	ll j,m;ll c=0;
/*	for(j=0;j<n-1;j++)
	{
		for(m=j+1;m<n;m++)
		{
			if(h[j]+h[m]<k)
			{
				c++;
			}
		}
	}*/
	for(i=0;i<n-1&&h[i]+h[i+1]<=(k/2)+1;i++)
	{
		for(j=i+1;j<n&&h[j]<=k;j++)
		{
			if(h[i]+h[j]<k)
			{
				c++;
			}
		}
	}
	cout<<c<<endl;
	return 0;
}
