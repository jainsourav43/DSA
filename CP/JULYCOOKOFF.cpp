#include<bits/stdc++.h>
#define ll long long 
#include<iostream>
using namespace std;
int main()
{
	ll a,b;
	cin>>a>>b;
	ll sum=0,ans=0,x;
	for(x=1;x<=a;x++)
	{
			ll l=1,h=1000;
			bool check=0;
			if(b<(x+1)*(x+1)-x*x)continue;
		while(l<=h)
		{
			ll mid=(l+h)/2;	
			if((x+mid)*(x+mid)-x*x==b)
			{
				
				ans=mid;
				break;
			}
			else if((x+mid)*(x+mid)-x*x<b)
			{
				ans=mid;
				l=mid+1;
			}
			else
			{
			
				h=mid-1;
				ans=h;
			}
		}		
		sum=sum+(ans);
	}

	
	cout<<sum<<endl;
}
