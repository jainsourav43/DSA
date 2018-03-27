#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,i,j,k;
	cin>>n;
	char s[50][51];
	for(i=0;i<n;i++)
	{
		cin>>s[i];
	}
	int l[n];
	for(i=0;i<n;i++)
	{
		l[i]=0;
		for(j=0;j<n-1;j++)
		{
			if(s[i][j]=='.'&&s[i][j+1]=='.')
			{
				l[i]++;
			}
		}
	}
	//sort(l,l+n);
	for(i=1;i<n;i++)
	{
		if(l[i-1]+2<=l[i]&&l[i]>=[i+1]+2)
		k=1;
		else
		k=0;
	}
	if(k==1)
	cout<<l[n-1]/2<<endl;
	else
	cout<<0<<endl;
}
