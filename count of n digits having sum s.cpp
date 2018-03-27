// A memoization based recursive program to count 
// numbers with sum of n as given 'sum'
#include<bits/stdc++.h>
using namespace std;

// A lookup table used for memoization
unsigned long long int lookup[101][50001];

// Memoizatiob based implementation of recursive
// function
unsigned long long int countRec(int n, int sum)
{
	// Base case
	if (n == 0)
	return sum == 0;

	// If this subproblem is already evaluated,
	// return the evaluated value
	if (lookup[n][sum] != -1)
	return lookup[n][sum];

	// Initialize answer
	unsigned long long int ans = 0;

	// Traverse through every digit and
	// recursively count numbers beginning
	// with it
	for (int i=0; i<10; i++)
	if (sum-i >= 0)
		ans += countRec(n-1, sum-i);

	return lookup[n][sum] = ans;
}

// This is mainly a wrapper over countRec. It
// explicitly handles leading digit and calls
// countRec() for remaining n.
unsigned long long int finalCount(int n, int sum)
{
	// Initialize all entries of lookup table
	memset(lookup, -1, sizeof lookup);

	// Initialize final answer
	unsigned long long int ans = 0;

	// Traverse through every digit from 1 to
	// 9 and count numbers beginning with it
	for (int i = 1; i <= 9; i++)
	if (sum-i >= 0)
		ans += countRec(n-1, sum-i);
	return ans;
}

// Driver program
int main()
{
	int n = 5, sum = 15;
	cout << finalCount(n, sum);
	return 0;
}
//---------------------------------------------------Bottom UP ----------------------------------------
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
