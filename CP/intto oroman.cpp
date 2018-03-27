#include<bits/stdc++.h>
using namespace std;
#include<iostream>
string myfun(int a)
{	
map<int,char>m;
m[1]='I';
m[5]='V';
m[10]='X';
m[50]='L';
m[100]='C';
m[500]='D';
m[1000]='M';
	string s;
	int mynum=a,tmp,j,i;
	map<int ,char> ::iterator it,it1;
	while(1)
	{
	if(mynum>=1000)
	{
		tmp=mynum/1000;
		for(j=0;j<tmp;j++)
		s=s+m[1000];
		mynum=mynum-tmp*1000;
	}
	else if(mynum>=500)
	{
		if(mynum<500+4*100)
		{
			s=s+m[500];
			mynum=mynum-500;
			
		}
		else
		{
			s=s+m[100];
			s=s+m[1000];
			mynum=mynum-(1000-100);
		}
	}
	else if(mynum>=100)
	{
		if(mynum<100+3*100)
		{
			tmp=mynum/100;
			for(j=0;j<tmp;j++)
			s=s+m[100];
			mynum=mynum-tmp*100;
		}
		else
		{
			s=s+m[100];
			s=s+m[500];
			mynum=mynum-(500-100);
		}
		
	}
	else if(mynum>=50)
	{
		if(mynum<50+4*10)
		{
			s=s+m[50];
			mynum=mynum-50;
		}
		else
		{
			s=s+m[10];
			s=s+m[100];
			mynum=mynum-(100-10);
		}
	}
	else if(mynum>=10)
	{
		if(mynum<10+3*10)
		{
			tmp=mynum/10;
			for(j=0;j<tmp;j++)
			s=s+m[10];
			mynum=mynum-tmp*10;
		}
		else
		{
			s=s+m[10];
			s=s+m[50];
			mynum=mynum-(50-10);
		}
	}
	else if(mynum>=5)
	{
		if(mynum<5+4*1)
		{
			s=s+m[5];
			mynum=mynum-5;
		}
		else
		{
			s=s+m[1];
			s=s+m[10];
			mynum=mynum-(10-1);
		}
	}
	else if(mynum>=1)
	{
		if(mynum<4)
		{
			for(i=0;i<mynum;i++)
			s=s+m[1];
			mynum=0;
		}
		else
		{
			s=s+m[1];
			s=s+m[5];
			mynum=mynum-(5-1);
		}
	}
		if(mynum<=0)
		break;
		}
	//cout<<s<<endl;
	return s;
	}
//

int main()
{
	int n;
	cin>>n;
	cout<<myfun(n);
}
