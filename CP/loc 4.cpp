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
		ll n,i,j,k=0,l,m,z;
		cin>>n;
		ll sum=0;ll a[n];
		bool v[n];
	
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			sum=sum+a[i];
			v[i]=false;
		}
    	sort(a,a+n);ll flag,fi,fii,f;
    	if(a[0]==0)
		{
			z=1;
		}
    	if(sum%3==0&&z==1)
    	{
    		for(j=0;j<n;j++)
    		{
    			k=k*10+a[i];
			}
		}
		else if(sum%3==1&&z==1)
		{flag=0;
			for(i=0;i<n;i++)
			{
				if(a[i]%3==1)
				{   
				    flag=1;
					v[i]=true;
					break;
				}
			}
			if(flag==1)
			{
			for(i=n-1;i>=0;i--)
			{
				if(v[i]==false)
				k=k*10+a[i];
			}
		   }
			else
			{f=0;
				for(i=0;i<n&&f<2;i++)
				{
					if(a[i]%3==2)
					{
						v[i]=true;
						f++;
					}
				}
				for(i=n-1;i>=0;i--)
				{
				   if(v[i]==false)
					k=k*10+a[i];
				}
				cout<<k<<endl;
			}
		}
		else if(sum%3==0&&z==1)
		{fi=0;
			for(i=0;i<n;i++)
			{
				if(a[i]%3==2)
				{
				    fi++;
					v[i]=false;
					break;
				}
			}
			if(fi==1)
			{
				for(i=n;i>=0;i--)
				{
					if(v[i]==false)
					k=k*10+a[i];
				}
			}
			else{
				fii=0;
				for(i=0;i<n&&fi<2;i++)
				{
					if(a[i]%3==1)
					{
						fii++;
						v[i]=true;
					}
				}
				for(i=0;i<n;i++)
				{
					if(v[i]==false)
					{
						k=k*10+a[i];
					}
				}
			}
			
		}
    	cout<<k<<endl;
	}
}
