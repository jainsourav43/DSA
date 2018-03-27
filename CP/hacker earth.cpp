#include<iostream>
#define ll long long
using namespace std;
int main()
{
	ll n,k;
	cin>>n>>k;
	ll a[n];int i;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	ll c=0,j=0;ll sum[n][n];
	sum[n][n]={0};
	for(i=0;i<n;i++)
	{

    for(j=0;j<=i;j++)
    {
    	sum[j][i]=sum[j][i]+a[j];
	}
	if(sum[j][i]<k)
	{
		c++;
	}
	}
	cout<<c+n<<endl;
	return 0;
}
