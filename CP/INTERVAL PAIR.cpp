#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct st
{
	int height;
	int infront;
};


bool comp(st s1,st s2) { return s1.height<s2.height;}
vector<pair<int ,int > > t;

void build(int node,int s,int e)
{
	if(s==e)
	{
	//	cout<<"s= ----------------------------"<<s<<endl;
				t[node]=make_pair(1,e);

	//	cout<<"t["<<node<<"]"<<t[node].first<<endl;
		return ;
	}
	int mid=(e+s)/2;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);
	t[node]=make_pair(t[2*node].first+t[2*node+1].first,max(t[2*node].second,t[2*node+1].second));
}
void update(int node,int s,int e,int index,int val)
{
	//cout<<"s,e ="<<s<<" "<<e<<endl;
	//cout<<"INdex="<<index<<endl;
	if(s==e)
	{
		cout<<"updating---------------------="<<node<<endl;
		t[node]=make_pair(val,INT_MIN);
		return;
	}
	int mid=(e+s)/2;
	
	if(index>=s&&index<=mid)
	{
		update(2*node,s,mid,index,val);
	}
	else
	{
		update(2*node+1,mid+1,e,index,val);
	}
	t[node]=make_pair(t[2*node].first+t[2*node+1].first,max(t[2*node].second,t[2*node+1].second));
}

int maxn;
int query(int node,int s,int e,int l,int r,int val)
{

	cout<<"Val =  "<<val<<endl;
	if(t[node].first==val)
	{
		return node;
	}
	else
	{
		cout<<"Node = "<<node<<endl;
		cout<<"node->first,node->Second= "<<t[node].first<<" "<<t[node].second<<endl;
		int mid=(s+e)/2;
		cout<<"node->first,node->Second= "<<t[2*node].first<<" "<<t[2*node].second<<endl;
		if(t[2*node].first>val)
		{
			query(2*node,s,mid,l,r,val);
		}
		else if(t[2*node].first<val)
		{
			int k=2*node;
			cout<<"going for Right= "<<val-t[k].first<<endl;
			return query(2*node+1,mid+1,e,l,r,val-t[k].first);
		}
		else
		{
			return 2*node;
		}
	}

}


int main()
{
	int n;
	
	cin>>n;
	int a[n];
	st s[n];
	t.assign(2*n+2,make_pair(0,0));
	maxn=2*n+2;
	int i,ans[n];
	for(i=0;i<n;i++)
	{	
		cin>>s[i].height;
	}
	for(i=0;i<n;i++)
	{
		cin>>s[i].infront;
	}
	sort(s,s+n,comp);
	build(1,0,n-1);
	ans[0]=s[0].infront;
	cout<<ans[0]<<endl;
//	cout<<"Before\n";
	update(1,0,n-1,ans[0],0);	cout<<"Before\n";

	for(i=1;i<n;i++)
	{
	//	cout<<"Start\n";
		int y=t[query(1,0,n-1,0,n-1,s[i].infront+1)].second;
		ans[i]=y;
		cout<<"y-----------------------------------="<<y<<endl;
			update(1,0,n-1,ans[i],0);
			cout<<"back\n";
	}
	cout<<endl<<endl;
//	for(i=0;i<n;i++)
//	{
//		cout<<ans[i]<<" ";
//	}
	vector<int> fans(n,0);
	for(i=0;i<n;i++)
	{
	//	cout<<ans[i]-1<<"  ";
		
		
		fans[ans[i]]=s[i].height;
	}
	for(i=0;i<n;i++)
	{
		cout<<fans[i]<<" ";
	}
	
	
	
}
