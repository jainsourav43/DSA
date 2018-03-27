#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char s[100];
	int i,j,flag=0,k;
	while(flag==0)
	{
		cin>>s;
		int f=0;
		for(i=0;s[i]!='\0';i++)
		{k=0;
		for(j=i-1;j>=0;j--)
		{
			if(s[j]==s[i])
			{
				k=1;
				break;
			}
			
		}
			if((s[i]>=48&&s[i]<=57)&&k==0&&strlen(s)!=1&&f>=1)
			{
			  cout<<"Valid"<<endl;
				flag=1;
	 			break;
			}
			else
			{
				f++;
			}
		}
		if(flag==0||strlen(s)==1)
		cout<<"Invalid"<<endl;
	}
	return 0;
}
