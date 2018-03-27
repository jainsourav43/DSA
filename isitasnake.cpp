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
		int onlydot=0,flag=0,ans=0,up=0,down=0,i,onlyup=0,onlydown=0;
		for(i=0;i<n;i++)
		{
			if(ch[0][i]=='#'&&ch[1][i]=='#')
			{
				if(onlydot==1||onlyup||onlydown)
				{
					ans=1;
					break;
				}
				flag=1;
				up=0;
				down=0;
			//	continue;
			}
			else if((ch[0][i]=='.'&&ch[1][i]=='#'))
			{
				if(onlydot==1)
				{
					ans=1;
					break;
				}
				
				if(flag==1)
				{
					if(i<n-1)
					{
						if(ch[0][i+1]=='#'&&ch[1][i+1]=='#')
						{
						//	continue;
						}
						else 
						{
							ans=1;
							break;
						}
					}
					else
					{
						ans=1;
						break;
						//continue;
					}
					down=0;
					up=1;
				}
				else if(flag==0)
				{
					up=1;
				}
				else //if(flag==0)
				{
					if(up==1)
					{
						onlyup=1;
						//continue;
					}
					else 
					{
						ans=1;
						break;
					}
					up=1;
				}
				flag=2;
			
			}
			else if((ch[1][i]=='.'&&ch[0][i]=='#'))
			{
				if(onlydot==1)
				{
					ans=1;
					break;
				}	
				if(flag==1)
				{
					if(i<n-1)
					{
						
						if(ch[0][i+1]=='#'&&ch[1][i+1]=='#')
						{
							//continue;
						}
						else 
						{
							ans=1;
							break;
						}
						down=1;
						up=0;
					}
					else
					{
					ans=1;
					break;
					down=1;
					up=0;
					}
					
					
				}
				else if(flag==0)
				{
					down=1;
				}
				else //if(flag==0)
				{
					if(down==1)
					{
						onlydown=1;
						//continue;
					}
					else 
					{
						ans=1;
						break;
					}
					up=0;
					down=1;
				}
				flag=2;
			}
			else if(ch[0][i]=='.'&&ch[1][i]=='.')
			{
				if(flag==0)
				{
					continue;
				}
				else if(i<n-1)
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
