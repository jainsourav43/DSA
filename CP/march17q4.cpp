#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
int main()
{
	ll n,i,j;
	cin>>n;
	for(i=0;i<n;i++)
	{
		ll a[n];
		for(j=0;j<n;j++)
		{
			cin>>a[j];
		}
		if(i%2==0)
		sort(a,a+n, std::greater<int>());
		else
		{
			sort(a,a+n);
		}
		for(j=0;j<n;j++)
		{
			cout<<a[j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
