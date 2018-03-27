#include<bits/stdc++.h>
#define ll long long 
#include<vector>
#include<stack>
#include<stdio.h>
struct st
{
	int row;
	int col;
	
};
int  maximum(int  a,int  b)
{
	if(a>b)
	return a;
	return b;
}
bool v[501][501],v1[501][501];
int n,m,count3=0,count4=0;
bool anyfalse()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(!v[i][j])
			{
				return true;
			}
		}
	}
	return false;
}
using namespace std;
st s[250005],s1[250005];
int binary1(int key,int j)
{
	int low=0,high=count3;
	int mid;
	int prev=(high+low)/2;
	while(low<high)
	{
		mid=(high+low)/2;
		
		if((s[mid].row)>=key)
		{
			
			//ans=mid;
			high=mid;
			//return mid;
		}
		else 
		{
			low=mid+1;
		}
	
	}
	return low;
}
int binary2(int key,int i)
{
	int low=0,high=count3;
	int mid;
	int cost;
	int prevcost=INT_MAX;
	while(low<high)
	{
		mid=(high+low)/2;
		if((s1[mid].col)>=key)
		{
			//ans=mid;
			high=mid;
			//return mid;
		}
		else 
		{
			low=mid+1;
		}
	}
	return low;
	
}

bool comp(st s1,st s2)
{
//	if(s2.row==s2.row)
//	return s1.col<s2.col;
	return (s1.row)<(s2.row);
}
bool comp1(st s1,st s2)
{
//	if(s1.col==s2.col)
//	return s1.row<s2.row;
	return s1.col<s2.col;
}
int main()
{
	int t;
	//scanf("%d",&t);
	cin>>t;
	while(t--)
	{
			int hour=0;
	//	scanf("%d %d",&n,&m);
		cin>>n>>m;
		
		int a[n+1][m+1];
	
		int i,j,k,max=0;
		count3=0;count4=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cin>>a[i][j];
				//scanf("%d", &a[i][j]);
				v[i][j]=false;
				if(a[i][j]>max)
				{
					max=a[i][j];
				}
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(a[i][j]==max)
				{
					v[i][j]=true;
					s[count3].row=i;
					s[count3].col=j;
					s1[count4].row=i;
					s1[count4].col=j;
					count3++;
					count4++;
				}
			}
		}
		int lower,p2,u,cost,tempcost,hours=0,cost1=INT_MAX,tempp,p1,fcost1,fcost2,fcost,cost2;
	//	sort(s,s+count3,comp);
		//sort(s1,s1+count4,comp1);
//		cout<<"Pritings \n";
//		for(i=0;i<count3;i++)
//		{
//			cout<<"s1 "<<s[i].row<<" "<<s[i].col<<endl;
//			cout<<"s2 "<<s1[i].row<<" "<<s1[i].col<<endl;
//		}
		int dist=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(a[i][j]!=max)
				{
					dist=INT_MAX;
					for(k=0;k<count3;k++)
					{
						if(dist>maximum(abs(s[k].row-i),abs(s[k].col-j)))
						{
							dist=maximum(abs((s[k].row-i)),abs(s[k].col-j));
						}
					}
					hours=maximum(hours,dist);
				}
				
			}
		}
		cout<<hours<<endl;
	//	hour++;
		}
	//	lower_bound()
	
} 
