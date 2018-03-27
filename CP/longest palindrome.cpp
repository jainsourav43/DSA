#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int lps(char *s,int i,int j)
{
	//cou/t<<"entering\n";

	if(i==j)
	{//cout<<"entering1\n";
	//cout<<"s[i],s[j] = "<<s[i]<<" "<<s[j]<<endl;
		return 1;
	}
	
	
	 if(s[i]==s[j]&&i+1==j)
	{//cout<<"entering1\n";
		return 2;
	}	
	
	 if(s[i]==s[j])
	{//cout<<"entering3\n";
		return lps(s,i+1,j-1)+2;
	}	
		return max(lps(s,i,j-1),lps(s,i+1,j));
}


int lpsdp(char *s)
{
	int n=strlen(s),i,j,cl;
	int l[n][n];
	for(i=0;i<n;i++)
	{
		l[i][i]=1;
	}
	
		for(cl=2;cl<=n;cl++)
		{
			for(i=0;i<n-cl+1;i++)
			{
				j=n-cl+1;
				if(s[i]==s[j]&&cl==2)
				{
					l[i][j]=2;
				}
				else if(s[i]==s[j])
				{
					l[i][j]=l[i+1][j-1]+2;
				}
				else
				{
					l[i][j]=max(l[i+1][j],l[i][j-1]);
				}
			}
		}
	return l[0][n-1];
}
int mindelete(char *s)
{
	int n=strlen(s);
	int i=lps(s,0,n-1);
	return n-i;
}
int main()
{
	char s[100];
	cout<<"Entee the Sring\n";
	cin>>s;
	int n=strlen(s);
	cout<<"max palindrome length is ="<< lps(s,0,n-1);
}
