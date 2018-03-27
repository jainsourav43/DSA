#include<iostream>
using namespace std;
#include<map>
#include<bits/stdc++.h>
struct st
{
	string str;
	int f;
	int p;
};
map<int,int> friends;
bool comp(st s1,st s2)
{
	if(friends.find(s1.f)!=friends.end()&&friends.find(s2.f)!=friends.end())
	{
		return  s1.p>s2.p;
	}
	else if(friends.find(s1.f)!=friends.end())
	{
		return 1;
	}
	else if(friends.find(s2.f)!=friends.end())
	{
		return 0;
	}
	else 
	{
		return s1.p>s2.p;
	}
}
int pow(int a,int p)
{
	int ans=1;
	while(p)
	{
		if(p&1)
		{
			ans=a*ans;
		}
		a=a*a;
		p>>=1;
	}
	return ans;
}
bool check(int n)
{
	int lo=log2(n);
	//cout<<"p1,p2= "<<
	if((n==pow(2,lo)-1)||(n==pow(2,lo+1)-1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{

int t;
cin>>t;
while(t--)
{
	int n;
	cin>>n;
	long long  a[n],i,j;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	long long p=a[0];
	int count1=1,max=1;
	//count++;
	for(i=1;i<n;i++)
	{
		cout<<"gcd= "<<__gcd(0LL,a[i])<<endl;
		if(__gcd(p,a[i])==1)
		{
			count1++;
			if(max<count1)
			{
				max=count1;
			}
			p=p*a[i];
		}
		else
		{
			count1=1;
			p=a[i];
		}
	}
	if(max==1)
	cout<<-1<<endl;
	else
	cout<<max<<endl;

}
}
