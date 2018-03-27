#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<string> f;
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
		sum=c%10;
		carry=c/10;
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
		sum=c%10;
		carry=c/10;
		result=result+to_string(sum);
		i--;j--;
	}
	while(j>=0)
	{	
		c=(s2.at(j)-'0')+carry;
		sum=c%10;
		carry=c/10;
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
		sum=c%10;
		carry=c/10;
		result=result+to_string(sum);
		i--;j--;
	}
	while(i>=0)
	{	
		c=(s1.at(i)-'0')+carry;
		sum=c%10;
		carry=c/10;
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
void generate()
{
	f.push_back("0");
	f.push_back("1");
	int i=2;
	while(1)
	{
		f.push_back(addit(f[i-1],f[i-2]));
		if(f[i].size()>1000)
		{
			break;
		}
		i++;
	}
	
}
int main()
{
	int t;
	cin>>t;
	f.clear();
	generate();
	while(t--)
	{
		string s;
		cin>>s;
		int check=0;
		int h=f.size()-1,l=0,len=s.size();
		while(l<=h)
		{
			int mid=(l+h)/2;
			if(f[mid]==s)
			{
				check=1;
				cout<<"YES\n";
				break;
			}
			else if(f[mid].size()>len)
			{
				h=mid-1;
			}
			else if(f[mid].size()<len)
			{
				l=mid+1;
			}
			else if(f[mid].size()==len)
			{
				if(f[mid]>s)
				{
					h=mid-1;

				}
				else
				{
					l=mid+1;
				}
			}
		}
		if(!check)
		{
			cout<<"NO\n";
		}
	}
}
