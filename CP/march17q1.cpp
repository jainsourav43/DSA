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
		ll i,j,k;
		ll a[n],b[n],sum1=0,sum2=0,sum3=0,sum4=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
            if(i%2==0)
            {
            	sum1+=a[i];
			}
			else
			{
				sum2+=a[i];
			}
		}
		for(i=0;i<n;i++)
		{
			cin>>b[i];
			if(i%2==0)
			{
				sum3+=b[i];
			}
			else
			{
				sum4+=b[i];
			}
		}
		if((sum1+sum4)>(sum2+sum3))
		{
			cout<<sum2+sum3<<endl;
		}
		else
		{
			cout<<sum1+sum4<<endl;
		}
	}
}
