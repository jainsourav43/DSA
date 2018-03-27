#include<iostream>
#include<algorithm>
#include<string.h>
#define ll long long
using namespace std;
int main()
{
	ll t;
	cin>>t;
	t=1;
	while(t--)
	{
		ll n;
		cin>>n;
		int flag=0,sum=0,i,j,k,a[n],max=0;
		for(i=0;i<n;i++)
		cin>>a[i];
		for(i=0;i<n;i++)
		{
			cout<<"i\n";
			if(flag==0&&a[i]<0)
			continue;
			else 
			{
				flag=1;
				if(sum+a[i]>=0)
				{
					cout<<"in\n";
				sum+=a[i];
				if(max<sum)
				max=sum;
			    }
			    else if(sum+a[i]<0)
			    {
			    	sum=0;
				}
			}
		}
		cout<<max<<endl;
		
	}
}
