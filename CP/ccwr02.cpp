#include<iostream>
#include<algorithm>
#define ll long long 
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
	ll n;
	cin>>n;
	ll a[n];
	ll i,j,k,l,w,y;ll p=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cin>>w>>y;
	sort(a,a+n);
	if(w<y)
	{
	cout<<"Not Possible\n";
	}
	else
	{
		p=(w-y+1)*a[0];
		for(i=1;i<y;i++)
		{
		p=p+a[i];
		}
		cout<<p<<endl;
	}
	}
	return 0;
}
