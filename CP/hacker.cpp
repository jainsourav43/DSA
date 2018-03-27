#include<iostream>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
int prime(ll n){
    int i;

   if(n==1)
   return 0;
    if (n==2)
        return 1;

    if (n%2==0)
        return 0;

    for (i=3;i<=sqrt(n);i+=2)
        if (n%i==0)
            return 0;

    return 1;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,i,j,k;
		cin>>n;
		ll a[n];int maxe=-1;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<n;i++)
		{
			if(prime(a[i]))
			{
				if(a[i]>maxe)
				maxe=a[i];
			}
		}
	if(maxe>=0)
	{
		cout<<maxe*maxe<<endl;
	}
	else
	{
		cout<<maxe<<endl;
	}
	}

}
