#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	ll t;
	t=1;
	while(t--)
	{
		ll n;
		cin>>n;
		ll c;
		cin>>c;int i;
		ll a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		ll left[2*n+2];
		ll choice,x,y,l,r;
		left[0]=a[0];
		for(i=1;i<n;i++)
		{
			left[i]=a[i];
		}
		
		for(i=n;i<2*n;i++)
		{
			left[i]=left[i-n];
		}
		int start=0,end=n-1;
		for(i=0;i<c;i++)
		{
			cin>>choice;
			if(choice==1)
			{
				cin>>x;
				
				x=x%n;
				start=start-x;
				end=end-x;
				if(start<0)
				{
					start=start+n;
					end=end+n;
				}
			
			}
			else if(choice==2)
			{
				cin>>y;
				y=y%n;
				start=start+y;
				end=(end+y);
				if(start>=n)
				{
					start=start-n;
					end=end-n;
				}
				
			}
			else
			{
				ll sum=0;
				cin>>l>>r;
				//cout<<start<<endl;
				
				for(int i1=l;i1<=r;i1++)
				{
					sum+=left[start+i1];
				//	cout<<"Left= "<<left[start+i1]<<" ";
				}
				//cout<<endl;
				cout<<sum<<endl;
			
				
			}
		}
		
	}
}
