#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[50][50];
int myfun(string s)
{
	int n=s.length(),i,j;
	for(i=0;i<=n;i++)
	{
		dp[i][i]=0;
	}
	int k=0;
	for(k=2;k<=n;k++)
	{
		
		for(i=0;i<n-k+1;i++)
		{
			j=k+i-1;
			if(s.at(i)==s.at(j))
			{
				dp[i][j]=dp[i+1][j-1];
						//	cout<<"Dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<endl;

			}
			else
			{
				dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
			//	cout<<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<endl;
			}
		}
	}
//	int m=*min_element(dp[0],dp[0]+n);
	int in=0,min1=INT_MAX;
	for(j=1;j<n;j++)
	{
		if(min1>=dp[0][j]&&dp[0][j]==0)
		{
			min1=dp[0][j];
			in=j;
		}
	}
//	cout<<in<<endl;
	cout<<n-in-1<<endl;
}
int main()
{
	string s;
	int n;
//	cout<<"ENter\n";
	cin>>s;
	
	myfun(s);
	
}
