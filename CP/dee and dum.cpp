#include<iostream>
#define ll long long
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;string s;
		cin>>n;
		cin>>s;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		if(n==1)
		{
			if(a[0]%2==0)
			{
				if(s=="Dee")
				{
				  cout<<"Dee\n";
				}
				else
				{
					cout<<"Dum\n";
				}
			}
			else
			{
				cout<<"Dum\n";
			}
		}
		else
		{
			cout<<"Dum\n";
		}
		
	}
}
