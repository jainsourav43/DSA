#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,p,q;
		cin>>n>>p>>q;
		ll i,j,k,l,a[n],c=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
	sort(a,a+n);
		if(q==0)
		{  
			for(i=0;i<n;i++)
			{
				if(p>=a[i])
				{
					p=p-a[i];
					c++;
				}
			}
			cout<<c<<endl;
		}
		else if(p==0)
		{c=0;
		for(i=0;i<n;i++)
		{
			if(q>=(a[i])/2&&(a[i]%2==0))
			{
				c++;
				q=q-(a[i]/2);
			}
		}
        cout<<c<<endl;
		}
		else if(p!=0&&q!=0)
		{
			c=0;
			for(i=0;i<n;i++)
			{
			 if(q>=a[i]/2&&a[i]%2==0)
				{
					q-=a[i]/2;
					c++;
				}
				else if(p>=a[i])
				{
					p-=a[i];
					c++;
				}
			  else if((p+2*q)>=a[i]&&p>0&&q>0)
				{
					a[i]=a[i]-2*q;
					q=q-a[i]/2;
					p=p-a[i];
					c++;
				}
				
				cout<<c<<endl;
			}
		}
	}
	return 0;
}

