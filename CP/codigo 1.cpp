#include<iostream>
#define ll long long
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,l,b,i,j,k,m;
		cin>>n>>l>>b;
		for(i=1;i<=n;i++)
		{
			if(l>b)
			{
				l=l-b;
			}
			else
			{
				b=b-l;
			}
		}
		if(l<=0||b<=0)
		{
			cout<<"No"<<endl;
		}
		else
		{
			cout<<"Yes"<<" "<<l*b<<endl;;
		}
	}
	return 0;
}
