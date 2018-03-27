#include<iostream>
#define ll long long 
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m,i;
		cin>>n>>m;
		ll a[n+1];
		for( i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		ll q,x,y,l,r,pro=1,count=0,j;
		for( j=0;j<m;j++)
		{
			cin>>q;
			if(q==1)
			{
				cin>>l>>r>>x;
				for(i=l;i<=r;i++)
				{
					a[i]=a[i]*x;
				}
			}
			else if(q==2)
			{
				cin>>l>>r>>y;
				for(i=l;i<=r;i++)
				{
					a[i]=(i-l+1)*y;
				}
			}
			else if(q==3)
			{
				cin>>l>>r;
			     pro=1;
				for(i=l;i<=r;i++)
				{
					pro=pro*a[i];
					if(pro%10==0)
					{
						count++;
						pro=pro%10;
					}
				}
				cout<<"coutn ="<<count<<endl;
			}
		}
			cout<<count<<endl;
	}
	return 0;
}
