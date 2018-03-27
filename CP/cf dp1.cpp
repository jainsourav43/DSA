#include<iostream>
#define ll long long
using namespace std;
int main()
{
	ll n,k,i,j;
	cin>>n>>k;
	ll a[n+1],sum=0,sum1=0,temp;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	if(n>1)
	{
	for(i=1;i<n;i++)
	{
		if(a[i]+a[i+1]<k)
		{
			temp=a[i+1];
			a[i+1]=k-a[i];
			sum1=sum1+a[i+1]-temp;
		}
	}
	cout<<sum1<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<a[i]<<"  ";
	}
   }
   else
   {
   	if(a[1]<k)
   	{
   		cout<<k-a[1]<<endl;
   		cout<<k<<endl;
	}
	else
	{
		cout<<0<<endl;
		cout<<a[1]<<endl;
	}
   }
}
