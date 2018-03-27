#include<bits/stdc++.h>
using namespace std;
struct tree
{
	int id;
	int child;
};
tree st[32];
int count1=0,total=0,sum1[32];
int func(int id,int prev,int sum)
{
	int i,j;int ans1,ans2;
	cout<<"id = "<<id<<endl;
	if(st[id].child==0&&sum==total)
	{
		return st[id].id;
	}
	else
	{
	
	for(int i=st[id].child,j=0;i>st[id].child/2;i--,j++)
	{
		cout<<"i,j,id,prev = "<<i<<" "<<j<<" "<<id<<" "<<prev<<endl;
		
		if(i!=id&&i!=prev)
		ans1=func(i,id,sum);
		if(j!=id&&j!=prev)
		ans2=func(j,id,sum);
		cout<<"ans1 ,ans2 = "<<ans1<<"  "<<ans2<<endl;
		if(ans1+ans2==st[id].child)
		return 1;
	
	}
	return 0;
	}
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		total=0;
		count1=0;
		int n,i,j;
		cin>>n;
		int id1;
		for(i=0;i<n;i++)
		{
			cin>>id1;
			st[id1].id=id1;
			cin>>st[id1].child;
			total+=st[id1].child;
		}
		int ans;
		for(i=1;i<=n;i++)
		{
			cout<<"CALLING-----------------------------------------------------------------------\n";
			ans=func(st[i].id,-1,0);
			if(ans)
			{
				sum1[count1++]=st[i].id;
				cout<<sum1[count1-1]<<" ";
			}	
		}
		cout<<endl;
	}
}
