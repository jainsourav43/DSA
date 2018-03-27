#include<iostream>
#include<algorithm>
#include<vector>
#define ll unsigned long long
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,q;
		cin>>n>>q;
		ll a[n],i,j,k;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		ll l[q],r[q];
		for(i=0;i<q;i++)
		{
			cin>>l[i]>>r[i];
		}
		//ll g;
	//	g=(n*(n-1))/2+n;
	//k=0;//ll sum[g];k=0;
	    vector <ll> sum;
		for(i=0;i<n;i++)
		{	ll c;
		    c=a[i];//sum[k]=a[i];
		    sum.push_back(a[i]);
			for(j=i+1;j<n;j++)
			{
				c=c+a[j];
				sum.push_back(c);
			}
		}
		ll u,v;
		sort(sum.begin(),sum.end());ll s;
		for(j=0;j<q;j++)
		{s=0;
			for(u=l[j]-1;u<=r[j]-1;u++)
			{
				s=s+sum[u];
			}
			cout<<s<<" ";
		}
		
	}
		return 0;	

}
