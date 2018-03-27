#include<iostream>
#include<cmath>
using namespace std;
#define ll long long
int main()
{
	ll a[5],b[5],i,j,sum=0;
	for(i=0;i<5;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<5;i++)
	{
		cin>>b[i];
	}
	for(i=0;i<5;i++)
	{
		j=min(abs(b[i]-a[i]),abs(a[i]+10-b[i]));
		sum=sum+j;
	}
	cout<<sum<<endl;
	return 0;
}

