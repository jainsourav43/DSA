#include<iostream>
#define ll long long 
#include<string.h>
#include<algorithm>
#include<vector>
struct mat
{
	char ch;
	int index;
	int sortedindex;
};
using namespace std;
int main()
{
	ll n;
	cin>>n;
	char s[n+1],str[n+1];
	ll a[26],b[26],j;
	for(j=0;j<26;j++)
	{
		a[j]=0;
		b[j]=0;
	}
	for(int j=0;j<26;j++)
	{
		a[j]=0;
		b[j]=0;
	}
	ll q,q1,x;
	char c;
	cin>>q;
	cin>>s;
	ll i;
	strcpy(str,s);
	for(i=0;i<strlen(s);i++)
	{
		a[(int)s[i]-65]++;
	}
//	cout<<"LKJHH\n";
//	for(i=0;i<26;i++)
//	{
//		cout<<a[i]<<"  ";
//	}cout<<endl;
	for(i=0;i<q;i++)
	{
		cin>>q1;
		if(q1==1)
		{
			cin>>x;
			cin>>c;
			a[(int)s[x-1]-65]--;
			s[x-1]=c;
			a[(int)c-65]++;
//			cout<<"NHUHUU  ="<<(int)c-65<<endl;
//			for(int k=0;k<26;k++)
//	{
//		cout<<a[k]<<"  ";
//	}cout<<endl;
		}
		else
		{
			cin>>x;
			j=0;ll sum=0;
		    while(sum<x)
		    {
		    	sum+=a[j];
		    	j++;
			}
			char ch1;
		//	cout<<"J = "<<j<<endl;
			//if(x==sum)
			//ch1=j+65;
		////	else
		//{
				ch1=65+j-1;
			//}
			
			cout<<ch1<<endl;
		}
	}
}
