#include<iostream>
#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 1000000006
#define ll long long 
using namespace std;
ll a[100001],b[100001],c[100001];
ll prea[100001],preb[100001],prec[100001];
bool comp(ll a,ll b)
{
	return a>b;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll p,q,r,i,j,k;
		
		scanf("%lld %lld %lld ",&p,&q,&r);
	//	cout<<p<<q<<r;
	//	cin>>p>>q>>r;
		for(i=0;i<p;i++)
		{
			scanf("%lld",&a[i]);
			//cin>>a[i];
		}
		for(j=0;j<q;j++)
		{
			scanf("%lld",&b[j]);
		//	cin>>b[j];
		}
		for(i=0;i<r;i++)
		{
			scanf("%lld",&c[i]);
		//	cin>>c[i];
		}
		sort(a,a+p);
		sort(b,b+q,comp);
		sort(c,c+r);
		ll sum=0,count=0;
		
		 prea[0]=a[0];
		 preb[0]=b[0];
		 prec[0]=c[0];
		 for(i=1;i<p;i++)
		 {
		 	prea[i]=(prea[i-1]+a[i]);
		 	if(prea[i]>mod2)
		 	prea[i]=prea[i]%mod;
		 }
		 for(i=1;i<r;i++)
		 {
		 	prec[i]=prec[i-1]+c[i];
		 	if(prec[i]>mod2)
		 	prec[i]=prec[i]%mod;
		 }
		 ll p1,p2,p3,a1,b1,c1,d1,e1,f1,g1;
		 i=0;
	 	//p1=upper_bound(a,a+p,b[0])-a;
	//	p2=upper_bound(c,c+r,b[0])-c;
		 while(b[i]>=c[r-1]&&b[i]>=a[p-1]&&i<q)
		 {
		 	 a1=prea[p-1];
			 b1=p*b[i];
			 c1=prec[r-1];
			 d1=r*b[i];
			 if(b1>mod2)
			 b1=b1%mod;
			 if(d1>mod2)
			 d1=d1%mod;
			 e1=a1+b1;
			 f1=c1+d1;
			 if(e1>mod2)
			 e1=e1%mod;
			 if(f1>mod2)
			 f1=f1%mod;
			 g1=e1*f1;
			 if(g1>mod2)
			 g1=g1%mod;	
			 sum=sum+g1;
			 if(sum>mod2)
			 sum=sum%mod;
		 //	sum=(sum+((((prea[p-1]+(p*b[i])%mod)%mod)*((prec[r-1]+(r*b[i])%mod)%mod))%mod))%mod;
		 	i++;
		 }
		 int i1=i;
		 
		// cout<<i1<<endl;
		for(i=i1;i<q;i++)
		{
			p1=upper_bound(a,a+p,b[i])-a;
			p2=upper_bound(c,c+r,b[i])-c;
			if(p1>0&&p2>0)
			{
			 a1=prea[p1-1];
			 b1=p1*b[i];
			 c1=prec[p2-1];
			 d1=p2*b[i];
			 if(b1>mod2)
			 b1=b1%mod;
			 if(d1>mod2)
			 d1=d1%mod;
			 e1=a1+b1;
			 f1=c1+d1;
			 if(e1>mod2)
			 e1=e1%mod;
			 if(f1>mod2)
			 f1=f1%mod;
			 g1=e1*f1;
			 if(g1>mod2)
			 g1=g1%mod;	
			 sum=sum+g1;
			 if(sum>mod2)
			 sum=sum%mod;	
			}
			else
			break;
		}
		cout<<sum<<endl;
	}
}
