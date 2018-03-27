#include<iostream>
#include<string.h>
using namespace std;
int main()
{
int flag=0,j;
	while(flag==0)
	{	char s[101];int n,f,c,i;
		cin>>s;
		if(strlen(s)>36)
		{
			cout<<"Invalid"<<endl;
			continue;
		}
		else
		{  n=0;c=0;f=0;
			for(i=0;s[i]!='\0';i++)
			{
				if(s[i]>=47&&s[i]<=57)
				{
					n++;
				}
				else
				{
					c++;
				}
				for(j=i-1;j>=0;j--)
				if(s[i]==s[j])
				{
					f=1;
				}
			}
			if(n>=1&&c>=1&&f==0)
			{
				cout<<"Valid"<<endl;
				break;
			}
			else
			{
				cout<<"Invalid"<<endl;
			}
		
		}
	}
	return 0;
}
