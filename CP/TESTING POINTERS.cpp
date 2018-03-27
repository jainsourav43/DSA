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
	    string s;
	    cin>>s;
	    int i,len=s.length(),n=len,max1,st;
	    int po,minv;
	    vector<int> ans;
	    int x=1;
	    if(s[0]=='I')
	    {
	    	ans.push_back(1);
	    	ans.push_back(2);
	    	minv=3;
	    	po=1;
		}
		else
		{
			ans.push_back(2);
	    	ans.push_back(1);
	    	minv=3;
	    	po=0;
		}
	    for(i=1;i<len;i++)
	    {
	       if(s[i]=='I')
	       {
	       	ans.push_back(minv);
	       	minv++;
	       	po=i+1;
		   }
		   else
		   {
		   	ans.push_back(ans[i]);
		   	for(int j=po;j<=i;j++)
		   	{
		   		ans[j]++;
			}
			minv++;
		   }
	        
	    }
	        for(i=0;i<ans.size();i++)
	        {
	            cout<<ans[i];
	        }
	        cout<<endl;
	}
	return 0;
}
