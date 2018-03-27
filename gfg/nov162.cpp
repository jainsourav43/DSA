#include<iostream>
#define ll long long 
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll k,i,j;
		cin>>k;
		for(i=1;i<=k;i++)
		{
			for(j=1;j<=k;j++)
			{
			if(i==j)
			{
				cout<<k<<" ";
			}
			else if(i==1||j==k)
			{
				cout<<k-abs(i-j)<<" ";
			}
			else if(i<=k/2&&j>=k/2)
			{
				cout<<k-(j-i)<<" ";
			}	
			else if(i<=k/2&&j<=k/2)
			{
				if(i>=j)
				cout<<abs(j-i)<<" ";
				else
				cout<<k-abs(j-i)<<" ";
			}
			else if(i>=k/2&&j<=k/2)
			{
				cout<<i-j<<" ";
			}
			else if(i>=k/2&&j>=k/2)
			{
				if(j>=i)
				{
					cout<<k-abs(i-j)<<" ";
				}
				else
				cout<<abs(j-i)<<" ";
			}
			
			}cout<<endl;
		}
	}
	return 0;
} 
