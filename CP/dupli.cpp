#include<iostream>
#define ll  long long 
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;ll sum=0,i,k;
		if(n%2==0)
		k=n/2;
		else
		k=(n/2)+1;
		cout<<k*k<<endl;
	}
}
