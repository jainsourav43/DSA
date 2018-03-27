#include<iostream>
#include<algorithm>
#include<string.h>
#define ll long long
using namespace std;
int main()
{
	ll n;
	cin>>n;ll i,j,k,l,m,l1,l2,ans=0;
	string str[n];
	bool v[n];
	for(i=0;i<n;i++)
	{
		cin>>str[i];
	}
	sort(str,str+n);
	for(i=0;i<n;i++)
	{
	v[i]=false;
	}
	for(j=0;j<n;j++)
	{   //l1=strlen(str[j]);
	for(l1=0;str[j][l1]!='\0';l1++);
 ll flag;
	for(i=j+1;i<n;i++)
     {flag=0;
    	//l2=strlen(str[i]);
    	for(l2=0;str[i][l2]!='\0';l2++);
    	if(l1==l2&&v[i]==false&&v[j]==false)
    	{
    	for(k=0;k<l1-1;k++)
    	{
    		if(str[j][k]!=str[i][k])
			{
				flag=1;
			}
		}
	if(flag==0&&str[j][l1-1]=='a'&&str[i][l2-1]=='i')
	{
		ans++;
		v[i]=true;
		v[j]=true;
	}
		}
	}
}
cout<<ans<<endl;
return 0;
}
