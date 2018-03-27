#include<iostream>
#include<stack>
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
		ll a[n];
	stack<ll> 
	s[n];int d;
		ll i,j,k,sum=0;
		for(i=0;i<n;i++)
		{
		    cin>>a[i];
			sum=sum+a[i];
			for(j=0;j<a[i];j++)
			{
			cin>>d;
			s[i].push(d);
			}
		}
		ll s1[sum];
		for(i=0;i<sum;i++)
		{
			cin>>s1[i];
		}
		     int c=0;
				for(k=0;k<sum;k++)
				{
					for(i=0;i<n;i++)
					{
						if(!s[i].empty()&&s[i].top()==s1[k])
						{
							if(!s[i].empty())
							s[i].pop();
							c++;
							break;
							
						}
					}
				}
		if(c==sum)
		{
			cout<<"Yes\n";
		}
		else 
		cout<<"No\n";
	}
}
