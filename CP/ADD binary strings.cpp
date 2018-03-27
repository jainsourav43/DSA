#include<iostream>
using namespace std;
#include<bits/stdc++.h>
string addit(string s1,string s2)
{
	string result="";
	int l1=s1.size(),l2=s2.size();
	int l=min(l1,l2),i,j;
	int carry=0,c=0,sum=0;
	if(l1==l2)
	{
	
	for(i=l-1;i>=0;i--)
	{
		int c=(s1.at(i)-'0')+(s2.at(i)-'0')+carry;
		sum=c%2;
		carry=c/2;
		result=result+to_string(sum);
	}
	if(carry)
	{
		result=result+to_string(carry);
	}
	}
 else if(l2>l1)
 {
 	int i=l1-1;j=l2-1;
 	while(i>=0)
 	{
 		
 		int c=(s1.at(i)-'0')+(s2.at(j)-'0')+carry;
		sum=c%2;
		carry=c/2;
		result=result+to_string(sum);
		i--;j--;
	}
	while(j>=0)
	{	
		c=(s2.at(j)-'0')+carry;
		sum=c%2;
		carry=c/2;
		result=result+to_string(sum);
		j--;
	}
	if(carry)
	{
		result=result+to_string(carry);
	}
 }
 else
 {
   int i=l1-1;j=l2-1;
 	while(j>=0)
 	{
 		int c=(s1.at(i)-'0')+(s2.at(j)-'0')+carry;
		sum=c%2;
		carry=c/2;
		result=result+to_string(sum);
		i--;j--;
	}
	while(i>=0)
	{	
		c=(s1.at(i)-'0')+carry;
		sum=c%2;
		carry=c/2;
		result=result+to_string(sum);
		i--;
	}
		if(carry)
	{
		result=result+to_string(carry);
	}	
 }
	reverse(result.begin(),result.end());
	return result;
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	cout<<addit(s1,s2);
}
