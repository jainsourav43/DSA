#include<iostream>
#include<string.h>
#define ll long long 
using namespace std;
int main()
{
	ll n;
	cin>>n;
	ll i,j,k,l,m,ka=0,ki=0;
	int s[n][101];
	for(i=0;i<n;i++)
	{
		cin>>s[i];
		l=strlen(s[i]);
		if(s[i][l-1]==97&&s[i][l-2]==107)
		{
			ka++;
		}
		else if(s[i][l-1]==105&&s[i][l-2]==107)
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
	return 0;
} 
