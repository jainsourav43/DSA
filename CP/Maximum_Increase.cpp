#include<iostream>
#define ll long long
using namespace std;
int main()
{
    long long int i;
	bool  dou,tri,rep;
	char s[200000+1];
	cin>>s;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]!=s[i+1])
		{
			strcat(str,s);
			//dou=true;
		}
		else if(dou==false&&s[i]==s[i+1])
		{
			dou=true;
			i+=1;
		}
		else if(dou==true&&s[i]==s[i]+1)
	}
	return 0;
}
