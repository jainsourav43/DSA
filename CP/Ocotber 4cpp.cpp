#include<iostream>
#include<string.h>
#include<cmath>
#define ll long long
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		char a[100001],b[100001];
		cin>>a>>b;int check1=0;
		ll count=0,ans1=0,i;
		for(i=0;i<strlen(a)-2&&strlen(a)>=2;i++)
		{
			if(a[i]=='2'&&a[i+1]=='1'&&b[i+1]=='1')
			{
				ans1=1;
				break;
			}
			else if(a[i]=='1'&&a[i+1]=='2'&&b[i]=='1'&&b[i+1]=='2'&&b[i+2]=='1')
			{
				//ans1=1;
				//break;
				if(i==strlen(a)-3)
				check1=1;
				count+=2;
				i+=2;
			}
			else if(a[i]=='1'&&a[i+1]=='2'&&b[i]=='1')
			{
				ans1=1;
				break;
			}
			else if(b[i]=='1'&&b[i+1]=='2'&&a[i]=='1'&&a[i+1]=='1'&&a[i+2]=='2'&&b[i+2]=='1')
			{
				//ans1 =1;
				//break;
				if(i==strlen(a)-3)
				check1=1;
				count+=2;
				i+=2;
			}
			else if(b[i]=='1'&&b[i+1]=='2'&&a[i]=='1'&&a[i+1]=='1')
			{
				ans1=1;break;
			}
			else if(b[i]=='2'&&b[i+1]=='1'&&a[i+1]=='1')
			{
				ans1=1;
				break;
			}
			else if((a[i]=='1'&&a[i+1]=='1'&&b[i]=='2'&&b[i+1]=='2'&&b[i+2]!='2')||b[i]=='1'&&b[i+1]=='1'&&a[i]=='2'&&a[i+1]=='2'&&a[i+2]!='2')
			{
				count++;i++;
			}
			else if((a[i]=='1'&&a[i+1]=='1'&&b[i]=='2'&&b[i+1]=='2'&&b[i+2]=='2')||b[i]=='1'&&b[i+1]=='1'&&a[i]=='2'&&a[i+1]=='2'&&a[i+2]=='2')
			{
				ans1=1;
				break;
			}
			else if(a[i]=='2')
			{
				if((a[i+1]=='1'&&(b[i]=='2'&&b[i+1]=='2'&&a[i+2]!='2'&&b[i+2]!='2'))||(a[i+1]=='1'&&b[i]=='1'&&b[i+1]=='2'&&a[i+2]!='2'&&b[i+2]!='2'))
				{
				count+=2;
				i+=2;
				}				
			}
			else if(b[i]=='2')
			{
		         if((b[i+1]=='2'&&(a[i]=='2'&&a[i+1]=='2'&&b[i+2]!='2'&&a[i+1]!='2'))||(b[i+1]=='1'&&a[i]=='1'&&a[i+1]=='2'&&b[i+2]!='2'&&a[i+2]!='2'))
				{
					count+=2;
					i+=2;
				}
			}
			else if(a[i]=='2')
			{
				if((a[i+1]=='1'&&(b[i]=='2'&&b[i+1]=='2'&&a[i+2]=='2'))||(a[i+1]=='1'&&b[i]=='1'&&b[i+1]=='2'&&a[i+2]=='2'))
				{
				ans1=1;
				break;
				i++;
				}				
			}
		    else if(b[i]=='2')
			{
		         if((b[i+1]=='1'&&(a[i]=='2'&&a[i+1]=='2'&&b[i+2]=='2'))||(b[i+1]=='1'&&a[i]=='1'&&a[i+1]=='2'&&b[i+2]=='2'))
				{
					ans1=1;break;
					i++;
				}
			}
		
			else if(a[i]=='1'&&b[i]=='1'&&a[i+1]=='1'&&b[i+1]=='1')
			{
				count++;
				//i++;
				
			}
		}
		if(strlen(a)>=2)
		{	
		i=strlen(a)-2;
		if(a[i]=='1'&&b[i]=='1'&&a[i+1]=='1'&&b[i+1]=='1')
		{
			count+=2;
		}
	     if((a[i]=='1'&&b[i]=='2'&&a[i+1]=='1'&&b[i+1]=='2')||(a[i]=='2'&&b[i]=='1'&&a[i+1]=='2'&&b[i+1]=='1'))
		{
			count+=1;
		}
			else if((a[i]=='2'&&b[i]=='2'&&a[i+1]=='1'&&b[i+1]=='2')||(a[i]=='2'&&b[i]=='2'&&a[i+1]=='2'&&b[i+1]=='1'))
		{
			ans1=1;
		}
	   }
	   if(strlen(a)==1)
	   cout<<2<<endl;
		else if(ans1==1)
		cout<<0<<endl;
		else
		cout<<pow(2,count)<<endl;
	}
}

