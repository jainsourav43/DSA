#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void next(string s)
{
	int l=s.length();
//	string s1=s;
	int i,j;
//	cout<<next_permutation(s1.begin(),s1.end())<<endl;
//	cout<<s1<<endl;
	string :: iterator it=s.end();
	it--;
	for(i=l-1;i>=0;i--)
	{
		if(s[i]<s[l-1])
		{
			break;
		}
		it--;
	}
//	cout<<"i= "<<i<<*it<<endl;
	if(i==-1)
	{
		cout<<"NOT \n";
	}
	else
	{
		swap(s[i],s[l-1]);
	}
	sort(it+1,s.end());
	
	cout<<s<<endl;
}
int main()
{
	string s;
	cin>>s;
	next(s);
}
