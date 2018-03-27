#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x11,y11,x12,y12,x21,y21,x22,y22;
		cin>>x11>>y11>>x12>>y12>>x21>>y21>>x22>>y22;
		if(y11==y12&&y21==y22)
		{
			if((y11!=y21))
			{
				cout<<"no\n";
			}
			else
			{
			
			if(x11>x12)
			{
				swap(x11,x12);
			}
			if(x21>x22)
			{
				swap(x21,x22);
			}
			if((x11>=x21&&x11<=x22)||(x12>=x21&&x12<=x22)||(x21>=x11&&x21<=x12)||(x22>=x11&&x22<=x12))
			{
				cout<<"yes\n";
			}
			else
			{
				cout<<"no\n";
			}
			}
		}
		else if(x11==x12&&x21==x22) 
		{
			if(x11!=x21)
			{
				cout<<"no\n";
			}
			else
			{
			if(y11>y12)
			{
				swap(y11,y12);
			}
			if(y21>y22)
			{
				swap(y21,y22);
			}
			if((y11>=y21&&y11<=y22)||(y12>=y21&&y12<=y22)||(y21>=y11&&y21<=y12)||(y22>=y11&&y22<=y12))
			{
				cout<<"yes\n";
			}
			else
			{
				cout<<"no\n";
			}
			
			
			}
		}
		else
		{
			if(y11==y12)
			{
				
				if(x11>x12)
				{
					swap(x11,x12);
				}
			
				if((y12==y21||y12==y22)&&(x22==x11||x22==x12))
				{
					cout<<"yes\n";
				}
				else
				{
					cout<<"no\n";
				}
				
			}
			else
			{
				if(x21>x22)
				{
					swap(x21,x22);
					
				}
				if(y11>y12)
				{
					swap(y11,y12);
				}
				if((y22==y11||y22==y12)&&(x11==x21||x11==x22))
				{
					cout<<"yes\n";
				}
				else
				{
					cout<<"no\n";
				}
					
			}
		}
	}
}
