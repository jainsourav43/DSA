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
	    string s,ans="";
	    int i,j,k;
	    cin>>s>>k;
	    int n=s.length();
	    int idx=0;
	    for(i=0;i<k;i++)
	    {
	    	j=i;
	    	cout<<"Ans= "<<ans<<endl;
	    	while(j<n)
	    	{
	    			cout<<"J= "<<j<<endl;
	    			ans=ans+s[j];
	    			s[j]='-';
	    			if(j==n-1)
	    			{
	    			   j++;
					}
					else
	    			     if(j+1<n&&s[j+1]=='-')
	    			{
					
	    			while(j+1<n&&s[j+1]=='-')
	    			{
	    				j++;
					}
					j++;
					}
					else
					{
						cout<<"hii\n";
						j+=2*(k-2)+2-idx;
					}
			
			
			}
			idx+=2;
		}
	  cout<<ans<<endl;
	}
	
	
	
	return 0;
}
