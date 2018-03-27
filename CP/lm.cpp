#include<iostream>
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		ll x,y;
		int temp;
		int t1[10000],t2[10000];
		for(int i=0;i<100;i++)
		{
			temp++;
		}
		cin>>x>>y;
		ll a=0,b=0;
		ll len=s.length();
		int j;
		string ans="";
		ll i;
		for(i=0;i<len;i++)
		{
			if(s[i]=='a')
			{
				a++;
			}
			else
			{
				b++;
			}
		}
		
		if(a==b)
		{
			for(i=0;i<len;i++)
			{
				if(i%2==0)
				{
					ans.push_back('a');
				}
				else
				{
					ans.push_back('b');
				}
			}
			cout<<ans<<endl;
				int temp;
		for(int i=0;i<100;i++)
		{
			temp++;
		}
		}
		else if(a>b)
		{
			int neededa;
//			cout<<"a,b =  "<<a<<" "<<b<<endl;
			if(a%x==0)
			{
				neededa=a/x-1;
			}
			else
			{
				neededa=a/x;
			}
			
			string s="";
			int extras;
//			cout<<"Needed,b= "<<neededa<<" "<<b<<endl;
			if(b>=neededa)
			{
				
				while(b>neededa)
				{
//				cout<<"Needed,b= "<<neededa<<" "<<b<<endl;
				extras=b-neededa;
				for(i=0;i<extras;i++)
				{
					ans.push_back('a');
					ans.push_back('b');
				}
				a=a-extras;
				b=b-extras;
					if(a%x==0)
					{
						neededa=a/x-1;
					}
					else
					{
						neededa=a/x;
					}
				
			}
				while(a>=x)
				{
					for(j=0;j<=x-1;j++)
					{
						ans.push_back('a');	
					}
					
					
					a=a-x;
					if(b>0)
					{
						ans.push_back('b');
					}	
					b--;					
			    }
			    if(a>0)
			    {
			    	while(a)
			    	{
			    		ans.push_back('a');
			    		a--;
					}
				}
					for(int i=0;i<100;i++)
		{
			temp++;
		}
			}
			else
			{
				int kiwi=neededa-b;
				int k1=0;
				while(a>=x)
				{
					for(j=0;j<=x-1;j++)
					{
						ans.push_back('a');	
					}
					a=a-x;	
					if(1)
					{
						ans.push_back('*');
						k1++;
						if(k1==kiwi)
						{
							break;
						}
					}					
			    }
				while(a>=x&&b>0)
				{
					for(j=0;j<=x-1;j++)
					{
						ans.push_back('a');	
					}
					ans.push_back('b');
					b--;
					a=a-x;
					if(b==0)
					{
						break;
					}						
			    }
//			    while(a>=x)
//				{
//					for(j=0;j<=x-1;j++)
//					{
//						ans.push_back('a');	
//					}
//					a=a-x;	
//					if(a>0)
//					{
//						ans.push_back('*');
//					}					
//			    }
			    while(a>0)
			    {
			    	ans.push_back('a');
			    	a--;
				}
			    
			    
			}
			
			cout<<ans<<endl;
		}
		else
		{
			x=y;
			int neededb;
			if(b%x==0)
			{
				neededb=b/x-1;
			}
			else
			{
				neededb=b/x;
			}
		
			string s="";
			int extras;
			if(a>=neededb)
			{
				while(a>neededb)
				{
				extras=a-neededb;
				for(i=0;i<extras;i++)
				{
					ans.push_back('b');
					ans.push_back('a');
				}
				b=b-extras;
				a=a-extras;
					if(b%x==0)
					{
						neededb=b/x-1;
					}
					else
					{
						neededb=b/x;
					}
				}
				while(b>=x)
				{
					for(j=0;j<=x-1;j++)
					{
						ans.push_back('b');	
					}
						b=b-x;	
					if(a>0)
					ans.push_back('a');
					a--;
									
			    }
			    if(b>0)
			    {
			    	while(b)
			    	{
			    		ans.push_back('b');
			    		b--;
					}
				}
					for(int i=0;i<100;i++)
		{
			temp++;
		}
			}
			else
			{
				int kiwi=neededb-a;
				int k1=0;
				while(b>=x)
				{
					for(j=0;j<=x-1;j++)
					{
						ans.push_back('b');	
					}
					
					b=b-x;
					if(1)
					{
						k1++;
						ans.push_back('*');
						if(k1==kiwi)
						{
							break;
						}
					}	
						for(int i=0;i<100;i++)
		{
			temp++;
		}					
			    }
			    
				while(b>=x&&a>0)
				{
					for(j=0;j<=x-1;j++)
					{
						ans.push_back('b');	
					}
					ans.push_back('a');
					a--;
					b=b-x;
					if(a==0)
					{
						break;
					}						
			    }
			  
			    while(b>0)
			    {
			    	ans.push_back('b');
			    	b--;
				}
		for(int i=0;i<100;i++)
		{
			temp++;
		}
			    
			}
			cout<<ans<<endl;
				for(int i=0;i<100;i++)
		{
			temp++;
		}
		}
		
	}
}
