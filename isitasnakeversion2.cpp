#include<iostream>
using namespace std;
int main()
{
	int t ;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		char ch[3][n+1];
		cin>>ch[0]>>ch[1];
		int onlydot=0,flag=0,ans=0,up=0,down=0,i,onlyup=0,onlydown=0,both=0,tenddown=0,tendup=0;
		for(i=0;i<n;i++)
		{
			if(ch[0][i]=='#'&&ch[1][i]=='#')
			{
				up=1;
				down=1;
				both=1;
				if(onlydot==1)
				{
					ans=1;
					break;
				}	
				if(tenddown==1)
				{
					tendup=1;
					tenddown=0;
				}
				else if(tendup==1)
				{
					tendup=0;
					tenddown=1;
				}
				flag=1;
				
			}
			else if(ch[0][i]=='.'&&ch[1][i]=='#')
			{
				if(onlydot==1)
				{
					ans=1;
					break;
				}	
				if(tendup==1)
				{
					ans=1;
					break;
				}
				if(both==1)
				{
					down=1;
					up=0;
					tenddown=1;
				}
				
				else if(up==1)
				{
					ans=1;
					break;
				}
				else
				{
					tenddown=1;
					down=1;
					up=0;
				}
				flag=1;
			}
			else if(ch[1][i]=='.'&&ch[0][i]=='#')
			{
				if(onlydot==1)
				{
					ans=1;
					break;
				}	
				if(tenddown==1)
				{
					ans=1;
					break;
				}
				if(both==1)
				{
					down=0;
					up=1;
					tendup=1;
				}
				else if(down==1)
				{
					
					ans=1;
					break;
				}	
				else
				{
					tendup=1;
					down=0;
					up=1;
				}
				flag=1;
			}
			else 
			{
				if(flag)
				{
					onlydot=1;
				}
			}
			
		}
		if(ans)
		{
			cout<<"no\n";
		}
		else{
			cout<<"yes\n";
		}
	}
	
}
