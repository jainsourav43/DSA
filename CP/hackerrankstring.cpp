#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
int n,k;
cin>>n;
  char str[n+1];
cin>>str;
cin>>k;
char ch='w';

ch=ch+9;

///cout<<"ch = "<<(int)ch<<endl;



for(int i=0;i<n;i++)
{
	cout<<int(str[i])<<endl;
	if((str[i]>=65&&str[i]<=91))
	{
		str[i]=(str[i])+(k%26);
	   //cout<<(int)str[i]<<endl;

		if(str[i]>91)
		{
			str[i]=str[i]-26;
		//		   cout<<"after = "<<(int)str[i]<<endl;

		}
	} 
	else if((str[i]>=97&&str[i]<=122))
	{
		//cout<<k%25<<endl;
		str[i]+=(k%26);
		
		
	//    cout<<int(str[i])<<endl;

		if(str[i]>122)
		{
		str[i]=96+(str[i]%122);
	//					   cout<<"after = "<<(int)str[i]<<endl;

           // cout<<int(str[i])<<endl;
		}
       //   cout<<(int)str[i]<<endl;

        
	}
}
	
	cout<<str<<endl;



}
