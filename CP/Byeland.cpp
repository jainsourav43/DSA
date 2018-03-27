#include<iostream>
#include<string.h>
#define ll long long
using namespace std;
int main()
{
	ll t;
	cin>>t;
	char str[50];
	cin>>str;
	int a[27],i,k;
	for( i=0;i<26;i++)
	{
		a[i]=str[i];
	}
	while(t--)
	{
		char s[101];
		cin>>s;
		int b[102];
		for(i=0;i<strlen(s);i++)
		{
			b[i]=s[i];
			if(b[i]<=90&&b[i]>=65)
			{
			    k=b[i]-65;
				b[i]=a[k]-32;
				s[i]=char(b[i]);
			}
			else if(b[i]>=97&&b[i]<=122)
			{
				k=b[i]-97;
				b[i]=a[k];
				s[i]=char(b[i]);
			}
			else if(b[i]==95)
			{
				s[i]=' ';
			}
		}
		cout<<s<<endl;
		
	}
}
