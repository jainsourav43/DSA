#include<iostream>
#define ll long long
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n;
		ll i,j,k,l;ll a[n];ll c=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		cin>>m;
		ll b[m];bool v[m];
		for(i=0;i<m;i++)
		{
			cin>>b[i];
			v[i]=true;
		}
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(b[i]==a[j]&&(v[i]==true))
				{
					c++;
					v[i]=false;
				}
			}
		}
		cout<<c<<endl;	
	}
}

