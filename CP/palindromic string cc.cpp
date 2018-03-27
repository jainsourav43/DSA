#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char s1[1002],s2[1002];
		cin>>s1>>s2;int n1,n2;
		n1=strlen(s1);
		n2=strlen(s2);
		sort(s1,s1+n1);
		sort(s2,s2+n2);
		if(s1[0]==s2[0])
		{
			cout<<"Yes\n";
		}
		else
		{
			cout<<"No\n";
		}
		
	}
	return 0;
}
