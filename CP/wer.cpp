#include<iostream>
#define ll long long 
#include<stdio.h>
using namespace std;
int main()
{
	ll t;
	//cin>>t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n,m,i;
		//cin>>n>>m;
		scanf("%lld %lld",&n,&m);
		ll a[n+1];
		for( i=1;i<=n;i++)
		{
			//cin>>a[i];
			scanf("%lld",&a[i]);
		}
		ll q,x,y,l,r,pro=1,count=0,j,ans=0,check=0;
		for( j=0;j<m;j++)
		{
			//cin>>q;
			scanf("%lld",&q);
			if(q==1)
			{
				//cin>>l>>r>>x;
				scanf("%lld %lld %lld",&l,&r,&x);
				for(i=l;i<=r;i++)
				{
					a[i]=a[i]*x;
				}
			}
			else if(q==2)
			{
				//cin>>l>>r>>y;
					scanf("%lld %lld %lld",&l,&r,&y);
				for(i=l;i<=r;i++)
				{
					a[i]=(i-l+1)*y;
				}
			}
			else if(q==3)
			{
				//cin>>l>>r;
				scanf("%lld %lld",&l,&r );
			     pro=1;count=0;
				for(i=l;i<=r;i++)
				{
					if(a[i]%5==0||a[i]%2==0)
					pro=pro*a[i];
					while(pro%10==0)
					{
						count++;
						pro=pro/10;
					}
				}
				ans=ans+count;
			}
		}
		printf("%lld" ,ans);
    	cout<<endl;
	}
	return 0;
}
