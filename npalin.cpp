#include<iostream>
#define ll long long 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t1;
	cin>>t1;
	while(t1--)
	{
		int n,W;
		cin>>n>>W;
		ll t[n+1],c[n+1],p[n+1],i,j;
		for(i=1;i<=n;i++)
		{
			cin>>c[i]>>p[i]>>t[i];
		}
		ll dp[n+1][W+1];
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=W;j++)
			{
				if(i==0||j==0)
				{
					dp[i][j]=0;
				}
				else
				{
				//	cout<<"else\n";
				//	cout<<"j-t[i]=  "<<j-t[i]<<endl;
					if(j<t[i])
					dp[i][j]=dp[i-1][j];
					else
					dp[i][j]=max(dp[i-1][j],c[i]*p[i]+dp[i-1][j-t[i]]);
				}
			//	cout<<dp[i][j]<<" ";
			}
		//	cout<<endl;
		}
		
		cout<<dp[n][W]<<endl;
	}
}
