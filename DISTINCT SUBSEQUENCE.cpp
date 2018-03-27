#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int ans=0;
void solve(string s,string t,int pos,int n,int m,string temp)
{
//	cout<<"Calling\n";

	if(temp==t)
	{
		ans++;
	}
	int i;
	string prev;
	for(i=pos;i<n;i++)
	{
	//	cout<<"for = ";
     	prev=temp;
		temp=temp+s[i];
		cout<<"Temp ="<<temp<<endl;
		solve(s,t,i+1,n,m,temp);
		temp=prev;
	}
	
	
}
void myfun(string s,string t)
{
	int n=s.length(),m=t.length(),i,j;
	int dp[n+1][m+1];
	dp[0][0]=1;
	for(i=1;i<=m;i++)
	{
		dp[0][i]=0;
	}
	for(i=1;i<=n;i++)
	{
		dp[i][0]=1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(s[i-1]==t[j-1])
			{
				dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	cout<<dp[n][m]<<endl;
}
int main()
{
	string s,t,temp="";
	cin>>s>>t;
	
	int n=s.length(),m=t.length();
//	solve(s,t,0,n,m,temp);
	myfun(s,t);
	cout<<ans<<endl;
	
}
