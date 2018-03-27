#include<iostream>
#include<string.h>
#include<bitset>
#define ll long long
using namespace std;
int main()
{
	  ll t;
	  cin>>t;
	    while(t--)
	    {  
		char l1[1001],l2[1001],l3[1001];
		ll n,ans2=0,ans3=0,ans;
		cin>>l1>>l2>>l3;
		cin>>n;
		int c=0,count1=0,count2=0,count3=0,check=0,ans1=0,i,j,length=0;
		for(i=strlen(l3)-1;i>=0;i--)
		{
			if(l3[i]=='1')
			{
				c++;
				check=1;
				continue;
			}
			else
			{
				
			//	cout<<"coem";
				ans1=1;
				break;
		        
			}
		}
	//	cout<<"I  ="<<i<<endl;
       	for(j=strlen(l2);j>=0;j--)
	  	{
	  		if(l2[j]=='1')
	  		{
	  			length++;
			  }
		  }
		if(ans1==1)
		{
			for(j=i;j>=0;j--)
			{
				if(l3[j]=='1')
				count1++;
			}
		}
		if(ans1==1)
		{
		for(j=0;j<strlen(l2);j++)
		{
			if(l2[j]=='1')
			{
				count2++;
			}
		}
	  }
	  else
	  {
	  	for(i=strlen(l2)-1;i>=0;i--)
	  	{
	  		if(l2[i]=='1')
	  		{
	  			continue;
			  }
			  else
			  {
			  ans2=1;
			  break;
		     }
		}
	  }
	  if(ans2==1)
	  {
	  	for(j=i;j>=0;j--)
	  	{
	  		if(l2[j]=='1')
	  		{
	  			count2++;
			  }
		  }
	  }
	  if(ans1==1||ans2==1)
	  {
		for(j=0;j<strlen(l1);j++)
		{
			if(l1[j]=='1')
			{
				count3++;
			}
		}
	}
	else
	{
		for(i=strlen(l1)-1;i>=0;i--)
		{
			if(l1[i]=='1')
			{
				continue;
			}
			else
			{
				ans3=1;
				break;
			}
		}
	}
		
		if(ans3==1)
		{
			for(j=i;j>=0;j--)
			{
				if(l1[j]=='1')
				{
					count3++;
				}
			}
		}
	//	cout<<"counts ="<<count1<<" "<<count2<<" "<<count3<<endl;
	     if(ans2==1)
		ans=count1+count2+length*(n-1)+count3+1;
		else
		ans=count1+count2*n+count3+1;
		cout<<ans<<endl;
	}
		
}
