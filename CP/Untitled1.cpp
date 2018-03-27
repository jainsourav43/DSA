#include<iostream>
#include<stdio.h>
#define ll long long
using namespace std;
int main()
{
	ll t;
	//cin>>t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n;
	//	cin>>n;
		scanf("%lld",&n);
		ll p[n+1],i,v[n],u[n],j,p1[n+1],k,a[n+1];
		ll max1=0,in1=0;
		for(i=1;i<=n;i++)
		{
		//	cin>>p[i];
			scanf("%lld",&p[i]);
		}
		for(i=1;i<n;i++)
		{
		//	cin>>v[i]>>u[i];
			scanf("%lld %lld",&v[i],&u[i]);
		}
	
		int check;
		for(i=1;i<=n;i++)
		{	
			ll max=0,in=0;
			for(k=1;k<=n;k++)
			{
				p1[k]=p[k];
			}
			p1[i]=0;
		    for(j=1;j<=n-1;j++)
		    {
		    	if(u[j]==i)
		    	{
		    		p1[v[j]]=0;
				}
				if(v[j]==i)
				{
					p1[u[j]]=0;
				}
			}
			for(k=1;k<=n;k++)
			{
				if(max<p1[k])
				{
					max=p1[k];
					in=k;
				}
			}
			a[i]=in;
	
		}
		for(i=1;i<=n;i++)
		{
		printf("%lld",a[i]);
		printf("\n");
		}
		}
} 
