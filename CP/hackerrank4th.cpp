#include<iostream>
#include<bits/stdc++.h>
#define ll long long
struct str
{
	int index;
	char ch;
};
bool comp(str s1,str s2)
{
	return s1.index<s2.index;
}

using namespace std;
int main()
{
	ll n,i;
	cin>>n;
	char s1[n+1];
	cin>>s1;
	str s[n+1];
	for(i=0;i<n;i++)
	{
		s[i].ch=s1[i];
		s[i].index=i+1;
	}
	sort(s,s+n,comp);
	ll counta=0,countb=0,countc=0;

	for(i=0;i<n;i++) 
	{
		if(s[i].ch=='a')
		{
			counta++;
		}
		else if(s[i].ch=='b')
		{
			countb++;
		}
		else 
		{
			countc++;
		}
	}
		ll j1=countb+counta,k1=countb+counta+countc;
		cout<<"counta,countb,countc = "<<counta<<" "<<countb<<" "<<countc<<endl;
		cout<<"j1,k1"<< j1<<" "<<k1<<endl;
		for(i=0;i<n;i++) cout<<s[i].ch;cout<<endl;
		for(i=0;i<n;i++) cout<<s[i].index<<" ";
		ll count=0,j,k;
		for(i=0;i<counta;i++)
		{
			for(j=counta;j<j1;j++)
			{
				for(k=j1;k<k1;k++)
				{
		            if(((s[j].index)*(s[j].index)==(s[k].index)*(s[i].index)))
      				 {
       					count++;
					 }
				}
			}
		}
		cout<<count<<endl;
	
	

}
