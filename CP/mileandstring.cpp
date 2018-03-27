#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
	int m=INT_MAX,n,i,j,k;
	cin>>n;
	char c[51][51];
	for(i=0;i<n;i++)
	{ 
		cin>>c[i];
	}
	int count1[n]={0},lcount=0,lmax=0;
	int check=0,ans;
	for(i=0;i<n;i++)
	{
		lcount=0;
		lmax=0;
		check=0;
		for(j=0;j<n;j++)
		{
			
			for(k=0;k<strlen(c[i]);k++)
			{
				if(strcmp(c[i],c[j])==0)
				{
					check=1;
				break;		
				}
				else
				{
					char temp=c[i][strlen(c[i])-1];
					for(int l=strlen(c[i])-1;l>0;l--)
					{
						c[i][l]=c[i][l-1];
					}
					c[i][0]=temp;
					lcount++;
				}
			}
			if(lcount>lmax)
			{
				lmax=lcount;
			}
			
		}
		if(check==0)
		{
			ans=-1;
			break;
		}
		count1[i]=lmax;
	}
	if(ans==-1)
	{
		cout<<-1<<endl;
	}
	else
	{
	
	ans=*min_element(count1,count1+n);
	cout<<"ans ="<<ans<<endl;
	}
}
