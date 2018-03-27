#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct st
{
	int height;
	int infront;
};


bool comp(st s1,st s2) { return s1.height<s2.height;}
vector<int> t;

void build(int node,int s,int e)
{
	if(s==e)
	{
		t[node]=1;
		return ;
	}
	int mid=(s+e)/2;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);
	t[node]=t[2*node]+t[2*node+1];
}
void update(int node,int s,int e,int index,int val)
{
	if(s==e)
	{
		t[node]=0;
		return;
	}
	int mid=(s+e)/2;
	
	if(index>=s&&index<=mid)
	{
		update(2*node,s,mid,index,val);
	}
	else
	{
		update(2*node+1,s,mid+1,index,val);
	}
	t[node]=t[2*node]+t[2*node+1];
}


int query(int node,int s,int e,int l,int r)
{
	if(l>e||r<s||s>e)
	{
		return 0;
	}
	if(l<=s&&e<=r)
	{
		return t[node];
	}
	
	int mid=(l+r)/2;
	return query(2*node,s,mid,l,r)+query(2*node+1,mid+1,e,l,r);
}
int main()
{
	int n;
	
	cin>>n;
	int a[n];
	st s[n];
	t.assign(2*n+2,0);
	int i,ans[n];
	for(i=0;i<n;i++)
	{	
		cin>>s[i].height;
	}
	for(i=0;i<n;i++)
	{
		cin>>s[i].infront;
	}
	int count1=0,j;
	sort(s,s+n,comp);
	ans[0]=s[0].infront+1;
	vector<bool> v(n+1,false);
	vector<int> fans(n+1,0);
	v[s[0].infront+1]=true;
	for(i=1;i<n;i++)
	{
		count1=0;
	for(j=1;j<=n;j++)
	{
		if(v[j]==false)
		{
			count1++;
		}
		if(count1>s[i].infront)
		{
			break;
		}
	}
	ans[i]=j;
	v[j]=true;
	}
	for(i=0;i<n;i++)
	{
		cout<<ans[i]-1<<"  ";
		
		
		fans[ans[i]-1]=s[i].height;
	}
	for(i=0;i<n;i++)
	{
		cout<<fans[i]<<" ";
	}
	
	
}
