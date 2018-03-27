#include<iostream>
#include<limits.h>
#define ll long long
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,count=0;
		cin>>n;
		ll a[n],b[n],i,j,c[n],sum=0,min1=INT_MAX;
		for(i=0;i<n;i++)
		{	
			cin>>a[i];
			sum+=a[i];	
			if(a[i]<0) 
			{
				count++;
				sum=sum-a[i];
								
			}
		}
		if(count<=1)
		{
			cout<<sum<<endl;
		}
		else
		{
		ll sum1=0,msum=INT_MIN,min2=INT_MAX,count1=0;
		for(i=0;i<n;i++)
		{
			
			min2=min1;
			min1=min(min1,a[i]);
			if(a[i]<0&&mincount==0)
			{
			mincount++;
			sum1=sum1;
			}
			else 
			{
				mincount++;
				if(a[i]<0)
				{
						
				}
				else
				{
				sum1+=a[i];
				}
			}
					
			if(msum<sum1)
			{
				count1++;
				msum=sum1;
				if(msum-min1>msum&&count1>1)
				{
					count1--;
					msum=msum-min1;
				}
			}
			if(sum1<0)
			{
				sum1=0;
				min1=INT_MAX;
				count1=0;
			}
		}
		cout<<msum<<endl;
		}
	
	}
}
