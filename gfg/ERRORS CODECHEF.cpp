#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
///	cin>>t;
	while(t--)
	{
			string s,temp;
			cin>>s;
			int ans=0;
			int len=s.length();
			if(s.find("010")<len||s.find("101")<len)
			cout<<"Good"<<endl;
			else
			{
				cout<<"Bad\n";
			}
			
	}
}
