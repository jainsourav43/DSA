#include<iostream>
#include<string.h>
#define ll long long 
using namespace std;
int main()
{
	ll n;
	cin>>n;
	ll i,j,k,l,m,ka=0,ki=0,o;
	char s[n][101];
	while(n--)
	{
		int a[n];
	for(o=0;o<n;o++)
	for(i=0;i<a[n];i++)
	{
		cin>>s[i];
		l=strlen(s[i]);
		if(s[i][l-1]=='a'&&s[i][l-2]=='k')
		{
			ka++;
		}
		else if(s[i][l-1]=='i'&&s[i][l-2]=='k')
		{
			ki++;
		}
	}
	if(ki<ka)
	{
		cout<<ki<<endl;
	}
	else
	{
		cout<<ka<<endl;
	}
}
	return 0;
}
