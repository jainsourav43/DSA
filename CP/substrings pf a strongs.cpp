#include<iostream>
#include<string.h>
using namespace std;
int k=0,r=0;

int n,N,M;
void check(char *str,int i,int j)
{
	int count1=0;
	int count2=0;
	//cout<<"i= "<<i<<"   j= "<<j<<endl;
	for(int i1=i;i1<=j;i1++)
	{
		if(str[i1]=='K')
		{//cout<<"str[i] "<<str[i]<<endl;
			count1++;
		}
		else 
		{//cout<<"r\n";
			count2++;
		}
	}
	//cout<<"count1=  "<<count1<<"   count2=  "<<count2<<endl;
	if(count1==N)
	{//cout<<"++\n";
		k++;
	}
	if(count2==M)
	{
		r++;
	}
}
void func(char *str,int i,int j1)
{
//	cout<<"i="<<i<<endl;


	if(j1==i)
	for(int j=i+1;j<n;j++)
	{
//		cout<<"i= "<<i<<endl;
		check(str,i,j);
		func(str,j,i);
	}
}
int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		r=0;k=0;
	cin>>M>>N;
	
	char str[1000005];
	cin>>str;
	int l=strlen(str);
	n=l;int cr=0,ck=0;
//	cout<<"length= "<<l<<endl;
	for(int i=0;i<l;i++)
	{
		if(str[i]=='R')
		{
			cr++;
		}
		else 
		{
			ck++;
		}
	}
	if(M==1)
	{
		r+=cr;
	}
	if (N==1)
	{
		k+=ck;
	}
	for(int i=0;i<l;i++)
	{
		func(str,i,i);
	}
//	cout<<endl;
if(M==0&&N==0)
cout<<0<<" "<<0<<endl;
else if(M==0)
{
	cout<<0<<" "<<k<<endl;
}
else if(N==0)
{
	cout<<r<<" "<<0<<endl;
}
else

	cout<<r<<" "<<k<<endl;
	}

}
