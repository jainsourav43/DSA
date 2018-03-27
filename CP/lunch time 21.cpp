#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char s[30];
	cin>>s;
	int n;
	cin>>n;
	char w[n][13];
	int i,j,k,l,m,c;
	for( i=0;i<n;i++)
	{
		cin>>w[i];
	}
		for(j=0;j<n;j++)
		{c=0;
			for(k=0;k<strlen(w[j]);k++)
			{
				for(i=0;i<strlen(s);i++)
             	{
	              if(w[j][k]==s[i])
	              {
	              	c++;
	              	break;
				  }
	             }
			}
			 if(strlen(w[j])==c)
	             {
	             	cout<<"Yes\n";
				 }
				 else
				 {
				 	cout<<"No\n";
				 }
		}
	
}
