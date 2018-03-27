#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#define ll long long
using namespace std;
int main()
{
	ll n,k,p;
	cin>>n>>k>>p;
	ll a[2*n],i,j;
	int temp,max1=0;
	for(i=n;i<2*n;i++)
	{
		cin>>a[i];
	}
	char s[p+1];
	int size=n;
	cin>>s;
	int sum[n]={0};
	int count1=0,check=0;
	int c[n],l=0;
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
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='!')
		{
			a[size-1]=a[size+n-1];
			size--;
			
			for(int o=1;o<=l;o++)
			c[o]=c[o-1];	
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
			cout<<max1<<endl;
		}
	}
	
}
