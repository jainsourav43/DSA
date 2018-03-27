#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
	while(1)
	{
		ll n;
		cin>>n;
		if(n==0)
		break;
		double ans;
		if(n==1)
		cout<<0<<endl;
		else if(n==3||n==2) cout<<1<<endl;
		else
		{
			ans=(-1+sqrt(1+8*n))/2;
					
			cout<<ceil(ans)<<endl;
		}
	
	}
}
