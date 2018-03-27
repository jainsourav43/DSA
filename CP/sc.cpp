#include <stdio.h>
#include<iostream>
using namespace std;
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n],i,j,sum=0;
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	        sum=sum+a[i];
	    }
	    if(sum%2)
	    {
	        cout<<"NO\n";
	    }
	    else
	    {
	        bool dp[n+1][sum+1];
	        int j;
	        for(i=0;i<=n;i++)
	        {
	            dp[0][i]=true;
	        }
	        for(i=1;i<=sum;i++)
	        {
	            dp[i][0]=false;
	        }
	        for(i=1;i<=sum;i++)
	        {
	            for(j=1;j<=n;j++)
	            {
	                dp[i][j]=dp[i][j-1];
	                if(i>=a[j-1])
	                {
	                    dp[i][j]=dp[i][j]||dp[i-a[j-1]][j-1];
	                }
	            }
	        }
	        if(dp[sum][n])
	        {
	            cout<<"YES\n";
	        }
	        else
	        {
	            cout<<"NO\n";
	        }
	        
	    }
	    
	}
	return 0;
}
