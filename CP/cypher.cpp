#include<iostream>
#include<cmath>
#define ll long long 
using namespace std;
int main()
{
ll t;
cin>>t;
while(t--)
{
ll l,r,k;
cin>>l>>r>>k;
ll i,j,m,n;ll sum=0;
for(i=l;i<=r;i++)
{ll a[40];
	if(i<pow(2,k))
	{
		continue;
	}
	else
	{n=i;m=0;
		while(n!=0)
		{
			a[m]=i%2;
			m++;
			n=n/2;
		}
		if(a[k-1]==1)
		{
			sum=sum+i;
		}
	}
}
cout<<sum<<endl;
}	
}
