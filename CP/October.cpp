#include<iostream>
using namespace std;
#define ll long long 
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll s,v;
		cin>>s>>v;
		cout.setf(ios::fixed);
		cout.precision(7);
		cout<<2*s/(3*v)<<endl;
	}
	return 0;
}
