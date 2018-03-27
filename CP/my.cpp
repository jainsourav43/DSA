#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//int dp[105][105];
string myfun(string s)
{
    
	int n=s.length(),i,j;
	vector<int> dp[n+1],d[n+1];
	for(i=0;i<=n;i++)
	{
	    dp[i].assign(n+1,0);
	    d[i].assign(n+1,false);
	    d[i][i]=true;
		dp[i][i]=1;
	}
	int k=0,ans=0,i1=0,j1=0,max1=0;
int low, high,maxLength=1;
int len=n,start=0;
 
    // One by one consider every character as center point of 
    // even and length palindromes
    for (int i = 1; i < len; ++i)
    {
        // Find the longest even length palindrome with center points
        // as i-1 and i.  
        low = i - 1;
        high = i;
        while (low >= 0 && high < len && s[low] == s[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
 
        // Find the longest odd length palindrome with center 
        // point as i
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && s[low] == s[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
    }
	//cout<<"i1,j1="<<i1<<" "<<j1<<endl;
	string s1="";
	for(i=start;i<start+maxLength;i++)
	{
	    s1=s1+s[i];
	}
	//cout<<s1<<endl;
	//cout<<max1<<endl;
	return s1;
}
string myf(string s)
{
	int len=s.length(),low,high,ma=0,start=0;
	int n=len;
	for(int i=1;i<=len;i++)
	{
		low=i-1;high=i;
		while(low>=0&&high<n&&s[low]==s[high])
		{
			if(high-low+1>ma)
			{
				start=low;
				ma=high-low+1;	
			}
			
			low--;
			high++;
		}
			low=i-1;high=i+1;
		while(low>=0&&high<n&&s[low]==s[high])
		{
			if(high-low+1>ma)
			{
				start=low;
				ma=high-low+1;	
			}
			
			low--;
			high++;
		}
	}
		string s1="";
	for(int i=start;i<start+ma;i++)
	{
	    s1=s1+s[i];
	}
	//cout<<s1<<endl;
	//cout<<max1<<endl;
	return s1;
}
int main()
{
    int t;
    cin>>t;while(t--){
	string s;
	int n;
//	cout<<"ENter\n";
	cin>>s;
	
cout<<	myf(s);
    }
}
