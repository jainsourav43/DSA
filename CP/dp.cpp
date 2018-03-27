#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int dp[16]={-1};
void initialize()
{
	for(int i=0;i<=15;i++)
	dp[i]=-1;
}
int calculate(string str,int pos,char c,int len,int prev)
{
	cout<<"c= "<<c<<endl;
	cout<<"dp= "<<dp[pos]<<"   pos,prev "<<pos<<" "<<prev<<endl;
	if(dp[pos]!=-1)
	{
		return dp[pos];
	}
	else if(pos==len-1)
	{
		dp[pos]= (pos-prev)*(pos-prev);
	}
	else
	{
		if(str.at(pos)==c)
		{
			dp[pos]=(pos-prev)*(pos-prev);
		}
		char mychar ;
		if(c=='R')
		{
			mychar='G';
		}
		else if(c=='G')
		{
			mychar='B';
		}
		else 
		{
			mychar='R';
		}
		for(int i=pos;i<len;i++)
		{
			if(str.at(i)==c)
			{
				dp[pos]=min((i-pos)*(i-pos)+calculate(str,i+1,mychar,len,i),calculate(str,i,c,len,pos));
			}
		}	
	}
	return dp[pos];
}
int getMin(string str)
{
	
	int len=str.length();
	initialize();
	dp[0]=0;
	if(str[1]=='G')
	{
		dp[1]=1;
	}
	else
	{
		dp[1]=INT_MAX;
	}
	int ans=calculate(str,1,'G',len,0);
	return ans;
}
int main()
{
	string st;
	cin>>st;
	cout<<getMin(st)<<endl;
	for(int i=0;i<=st.length();i++)
	cout<<dp[i]<<" ";cout<<endl;
}
