#include<iostream>
#include<cmath>
#define ll long long 
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,p;
		cin>>n>>p;
		ll a[n],i,j;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		ll sum=0,count=0,max=0;
		for(i=0;i<n;i++)
		{
			if(max<(a[i]%p))
			{
				max=a[i]%p;
				count=1;
			}
			else if (max==a[i])
			{
				count++;
			}
		}
		int flag=0;
		for(i=0;i<n;i++)
		{
			if(1)
			{
				sum=sum+a[i];
				//sum=sum%p;
				if(max<sum%p)
				{
					max=sum%p;
					count=1;
					flag=1;
				}
				else if(flag||sum%p==max)
				{
					count++;
				}
			
			}
		
		}
		cout<<max<<" "<<count<<endl;
	}
}
