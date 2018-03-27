#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
#define ll long long
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
	cin>>s;int sum[n]={0};
	int count1=0,check=0;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='!')
		{
//			temp=a[n-1];
//			
//			for(j=n-1;j>0;j--)
//			{
//				a[j]=a[j-1];
//			}
//			a[0]=temp;
			if(size>0)
			{
			a[size-1]=a[size+n-1];
			size--;
			}else
			{
			temp=a[n-1];	
			for(j=n-1;j>0;j--)
			{
				a[j]=a[j-1];
			}
			a[0]=temp;	
			}
		}
		else
		{
		//	cout<<"s ="<<s[i]<<endl;
			count1=0;
			check=0;
			max1=0;
			for(j=size;j<size+n;j++)
			{
				if(check<k)
				{
					if(a[j]==1)
					{
						count1++;
						if(max1<count1)
						{
							//cout<<"ist count = "<<count1<<"i ="<<i<<endl;
							max1=count1;
						}
					}
					check++;
			    }
			    else
			    {
			    	//check--;
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
				//	check++;
					}
					else 
					{
						if(a[j]==1)
						{
						count1++;		
						}	
						if(max1<count1)
						{//	cout<<"IIIrd count = "<<count1<<" i = "<<i<<endl;
							max1=count1;
						}
						
					//check++;	
					}
										
			    	//count1=0;
			    	//check=0;
				}
			}
			cout<<max1<<endl;
		}
	}
	
} 
