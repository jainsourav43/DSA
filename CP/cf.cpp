#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
void swap(char &a,char &b)
{
	char temp;
	temp=a;
	a=b;
	b=temp;
}
int main()
{
int  n,i,j,k,t,k1=0;
char s[1000];
cin>>s;
k=strlen(s);
//cout<<k<<"j"<<endl;
//sort(s,s+k);cout<<s<<endl;
for(i=0;i<k-1;i++)
{
	for(j=0;j<k-1-i;j++)
	{
		if(s[j]>s[j+1])
		{
			char temp=s[j];
			s[j]=s[j+1];
			s[j+1]=temp;
		}
	}
}
//cout<<s<<"  kk  "<<endl;
for(i=0;i<k-1;i++)
{
	if(s[i]==s[i+1])
	{
		continue;
	}
	else //if(s[i]!=s[i+1])
	{
		k1++;
	}
}
//cout<<<<endl;
if((k1+1)%2==0)
{
	cout<<"CHAT WITH HER!\n";
}
else
{
	cout<<"IGNORE HIM!\n";
}
return 0;
}
