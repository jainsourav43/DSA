#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<stdio.h>
using namespace std;
#define ll long long
int main()
{
	int n,k,p;
	//cin>>n>>k>>p;
	
	scanf("%d %d %d ",&n,&k,&p);
	int a[2*n],i,j;
	int temp,max1=0;
	for(i=n;i<2*n;i++)
	{
		//cin>>a[i];
		scanf("%d",&a[i]);
	}
	char s[p+1];
	int size=n;
	//cin>>s;
	scanf("%s",s);
	int sum[n]={0};
	int count1=0,check=0;
	int c[n],l=0;
	int len=strlen(s);
	for(j=size;j<size+n;j++)
	{
		if(check<k)
		{
			if(a[j]==1)
			{
				count1++;
				if(max1<count1)
				{
					max1=count1;
				}
			}
			check++;
			c[0]=count1;
	    }
	    else
	    {
	    	check--;
	    	if(a[j-k]==1)
	    	{
	    	count1--;
	    	if(a[j]==1)
			{
				count1++;
				if(max1<count1)
				{
						max1=count1;
				}
				
			}
			check++;
			}
			else 
			{
				if(a[j]==1)
				{
				count1++;		
				}	
				if(max1<count1)
				{
					max1=count1;
				}		
				check++;	
			}
	    	c[++l]=count1;
		}
	}
	for(i=0;i<len;i++)
	{
		if(s[i]=='!')
		{
			a[size-1]=a[size+n-1];
			size--;
			if(a[size]==1&&a[size+k]==0)
			{
				c[0]++;
			}
			else if(a[size]==0&&a[size+k]==1)
			{
				c[0]--;
			}
			if(max1<c[0])
			max1=c[0];
		}
		else
		{
		//	cout<<max1<<endl;
			printf("%d",max1);
			printf("\n");
		}
	}
	
} 
