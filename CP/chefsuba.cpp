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
	int a[2*100001],i,j;
	int c[2*100001],c1=1;
	int size=100000,size1=100000,ans=0;
	int temp,max1=0;
	for(i=size;i<size+n;i++)
	{
		cin>>a[i];
		if(a[i])
		ans++;
	}
	char s[p+1];
	cin>>s;int len=strlen(s);
	int count1=0,check=0;
	int l=size1;
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
					c[l]=count1;
				//	l++;
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
						{//	cout<<"IIIrd count = "<<count1<<" i = "<<i<<endl;
							max1=count1;
						}
						
					check++;	
					}
										
			    	//count1=0;
			    	//check=0;
			    	c[++l]=count1;
			    	c1++;
				}
			}
			ll maxcount=0;
			bool lm=false;
			for(i=size1;i<size1+c1;i++)
			{
				//cout<<"c[i] = "<<c[i]<<endl;
				if(c[i]==max1)
				{
					maxcount++;
				}
			}
			//cout<<"c[l]= "<<c[l]<<endl;
			if(c[l]==max1)
			{
				lm=true;
			}
		//	cout<<"maxcount= "<<maxcount<<endl;
		//	cout<<"lm  = "<<lm<<endl;
		//	cout<<"c1 = "<<c1<<endl;
	for(i=0;i<p;i++)
	{
		if(s[i]=='!')
		{
			a[size-1]=a[size+n-1];
			size--;
			size1--;
			if(a[size]==1&&a[size+k]==0)
			{
				c[size1]=c[size1+1]+1;
			}
			else if(a[size]==0&&a[size+k]==1)
			{
				c[size1]=c[size1+1]-1;
			}
			else
			{
				c[size1]=c[size1+1];
			}
			
			if(lm==true)
			{
				if(maxcount==1&&c[size1+c1-1]<max1)
				{
					//cout<<"rrr\n";
					max1=c[size1+c1-1];
					for(int h=size1;h<size1+c1-1;h++)
					if(max1==c[h]) maxcount++;
					
				}
				else  if(maxcount!=1)
				{
					if(c[size1+c1-1]==max1)
					{
						lm=true;
						maxcount--;
					}
					else 
					{
						lm=false;
						maxcount--;
					}
				}
			}
			
			if(c[size1]>=max1)
			{
				if(max1==c[size1])
				{
					maxcount++;
				}
				else if(c[size1]>max1)
				{
					max1=c[size1];
					maxcount=1;
					lm=false;
				}
			}
				if(c[size1+c1-1]==max1)
				{
					lm=true;
				}
			//	cout<<"c[speccial]= "<<c[size1]<<endl;
		}
		else
		{
			if(n>=k)
			cout<<max1<<endl;
			else
			{
				cout<<ans<<endl;
			}	
		}
	}
	
}
