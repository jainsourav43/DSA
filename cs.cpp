#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long 
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
		cout<<(-5)%2<<endl;
		cout<<setw(19)<<"h\n";
	    int n;
	    cin>>n;
	    int sum;
	    cin>>sum;
	    
	    int dp[n+1][sum+1];
	    int i,j,k;
	    dp[0][0]=1;
	    for(i=1;i<=n;i++)
	    {
	        dp[i][0]=1;
	    }
	    for(i=1;i<=sum;i++)
	    {
	        dp[0][i]=0;
	    }
	    int ans=0;
		for(i=1;i<=sum;i++)
		{
			for(j=1;j<=9;j++)
			if(j>=i)
			dp[1][i]=dp[0][i]+1;
			else
			dp[1][i]=0;
		}
	   for(i=2;i<=n;i++)
	   {
	       for(j=1;j<=sum;j++)
	       {
	       	   int ans=0;
	           for(k=0;k<=9;k++)
	           {
	              
	               if(j>k)
	               {
	                   ans+=dp[i-1][j-k];
	               }
	               
	               
	           }
	           dp[i][j]=ans;
	       }
	   }
	 
	    cout<<dp[n][sum]<<endl;
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	}
	return 0;
}
