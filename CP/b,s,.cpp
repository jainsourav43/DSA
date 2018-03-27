#include<iostream>
#define ll long long 
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll k,i,j;
		cin>>k;
		for(i=1;i<=k;i++)
		{
			for(j=1;j<=k;j++)
			{
				cout<<k-abs(i-j)<<" ";
			}cout<<endl;
		}
	}
	return 0;
}
