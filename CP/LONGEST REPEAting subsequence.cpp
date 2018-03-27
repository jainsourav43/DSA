#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int max(int a,int b,int c)
{
	if(a>=b&&a>=c)
	{
		return a;
	}
	if(b>=a&&b>=c)
	{
		return b;
	}
	return c;
}
int lon(string s)
{
	int i,j;
	int len=s.length();
	int l[len+1][len+1];
	for(i=0;i<=len;i++)
	{
		for(j=0;j<=len;j++)
		{
			l[i][j]=0;
		}
	}
	for(i=1;i<=len;i++)
	{
		for(j=i+1;j<=len;j++)
		{
			if(s[i-1]==s[j-1])
			{
				l[i][j]=l[i-1][j-1]+1;
			}
		}
	}

	for(i=1;i<=len;i++)
	{
		for(j=1;j<=len;j++)
		{
		//	cout<<"i,j="<<i<<" "<<j<<endl;
			if(i!=j&&s[i-1]==s[j-1]&&j>i)
			{
				l[i][j]=l[i-1][j-1]+1;
			}
			else
			{
				l[i][j]=max(l[i][j-1],l[i-1][j]);
			}
		}
	}	
	for(i=0;i<=len;i++)
	{
		for(j=0;j<=len;j++)
		{
			cout<<l[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return l[len][len];
	
	
	
	
}
int main()
{
	string s;
	cin>>s;
	cout<<lon(s);
}
