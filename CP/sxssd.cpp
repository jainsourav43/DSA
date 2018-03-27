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
	for(i=0;i<n-1;i++)
	{
	if(h[i]+h[i+1]<k)
	{
		c+=(i+1);
	}
	else
	{
		break;
	}
	}
	int co,ci=0,cu;co=1;
	for(j=i+2;j<n;j++)
	{
		if(h[i+1]==h[j])
		{
			co++;
		}
	}
	//cout<<"  i+1  "<<i+1<<"  ";
	for(j=i-1;j>=0;j--)
	{
		if(h[j]+h[i+1]<k)
		{
			ci++;
		}
	}
	cu=ci*co;
	c=c+cu;
	cout<<c<<endl;
	return 0;
} 
