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
//			else if(i==1||j==k)
//			{
//				cout<<k-abs(i-j)<<" ";
//			}
			else if(i<=k/2&&j>=k/2)
			{
				if(k-(j-i)==1)
				cout<<k/2<<" ";
				else if(k-(j-i)==k/2)
				cout<<1<<" ";
				else
				cout<<k-(j-i)<<" ";
			}	
			else if(i<=k/2&&j<=k/2)
			{
				if(i>=j)
				{
				if(abs(j-i)==1)
				cout<<k/2<<" ";
				else if(abs(j-i)==k/2)
				cout<<1<<" ";
				else
				cout<<abs(j-i)<<" ";
				}
				else
				{
				if(k-abs(j-i)==1)
				cout<<k/2<<" ";
				else if(k-abs(j-i)==k/2)
				cout<<1<<" ";
				else
				cout<<k-abs(j-i)<<" ";
				}
			}
			else if(i>=k/2&&j<=k/2)
			{
				if(i-j==1)
				cout<<k/2<<" ";
				else if(i-j==k/2)
				cout<<1<<" ";
				else
				cout<<i-j<<" ";
			}
			else if(i>=k/2&&j>=k/2)
			{
				if(j>=i)
				{
				if(k-abs(i-j)==1)
				cout<<k/2<<" ";
				else if(k-abs(i-j)==k/2)
				cout<<1<<" ";
				else
					cout<<k-abs(i-j)<<" ";
				}
				else
				{
				if(abs(i-j)==1)
				cout<<k/2<<" ";
				else if(abs(i-j)==k/2)
				cout<<1<<" ";
				else
				cout<<abs(j-i)<<" ";
				}
			}
			
			}cout<<endl;
		}
	}
	return 0;
} 

 
