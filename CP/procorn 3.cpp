#include<iostream>
#define ll  long long 
using namespace std;
ll powe(ll a,ll b)
{
	ll i,j,k,t=1;
	while(b>0)
	{
		if(b&&1)
		{
			t=t*a;
		}
		a=a*a;
		b>>=1;
	}
	return t;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;ll sum=0,i;
		for(i=1;i<=n;i++)
		{cout<<"powe()"<<powe(2,i)<<endl;
			if((powe(2,i)+1)%3==0)
			{
				sum=sum+i;
			}
		}
		cout<<sum<<endl;
	}
}
