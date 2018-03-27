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
		sort(s,s+count3,comp);
		sort(s1,s1+count4,comp1);
		for(i=0;i<count3;i++)
		{
			
		}
		cout<<"Pritings \n";
		for(i=0;i<count3;i++)
		{
			cout<<"s1 "<<s[i].row<<" "<<s[i].col<<endl;
			cout<<"s2 "<<s1[i].row<<" "<<s1[i].col<<endl;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(a[i][j]!=max)
				{
					p1=binary1(i,j);
					p2=binary2(j,i);
					cout<<"For I,J= "<<i<<"  "<<j<<endl;
					cout<<"P1,p2= "<<p1<<" "<<p2<<endl;
					cout<<"s1 "<<s[p1].row<<" "<<s[p1].col<<endl;
					cout<<"s2 "<<s1[p2].row<<" "<<s1[p2].col<<endl;
					cost2=INT_MAX;
					cost1=INT_MAX;
					if(p1<count3)
					cost1=maximum(abs(s[p1].row-i),abs(s[p1].col-j));
					p1--;
					if(p1>=0)
					cost2=maximum(abs(s[p1].row-i),abs(s[p1].col-j));
					fcost1=min(cost1,cost2);
					cost2=INT_MAX;
					cost1=INT_MAX;
					if(p2<count3)
					cost1=maximum(abs(s1[p2].row-i),abs(s1[p2].col-j));
					p2--;
					if(p2>=0)
					{
						cost2=maximum(abs(s1[p2].row-i),abs(s1[p2].col-j));
					}
					fcost2=min(cost1,cost2);
					cout<<"f= "<<fcost1<<"  "<<fcost2<<endl;
					fcost=min(fcost1,fcost2);
					hours=maximum(hours,fcost);
				}
			}
		}
		cout<<hours<<endl;
	//	hour++;
		}
	//	lower_bound()
	
} 
