#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
#include<map>
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
	int l=0;
	
	map<int,int> c;
	typeof(c.begin()) it;
			for(j=size;j<size+n;j++)
			{
				if(check<k)
				{
					if(a[j]==1)
					{
						count1++;
					}
					c[0]=count1;
					check++;
			    }
			    else
			    {
			    	if(a[j-k]==1)
			    	{
			    		count1--;
			    	if(a[j]==1)
					{
						count1++;
					}
					
					}
					else 
					{
						if(a[j]==1)
						{
						count1++;							
						}				
					}
			    	c[++l]=count1;
				}
			}
			cout<<l<<endl;
		//	cout<<max1<<endl;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='!')
		{
			a[size-1]=a[size+n-1];
			size--;
			for(j=l;j>0;j--)
			{
				c[j]=c[j-1];
			}
			if(a[size]==0&&a[size+k]==1)
			{
				c[0]--;
			}
			else if(a[size]==1&&a[size+k]==0)
			{//cout<<"increasing\n";
				c[0]++;
			}
		}
		else
		{
			it=c.end();
			cout<<it->second<<endl;
		}
	}
	}

