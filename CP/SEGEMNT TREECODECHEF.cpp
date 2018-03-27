#include<iostream>
using namespace std;
int a[1000001],t[1000001];
void build(int node,int s,int e)
{
	if(s==e)
	{
		t[node]=a[s];
		cout<<"node = "<<node<<endl;
		cout<<"t[node] = "<<t[node]<<endl;
	}
	else{
	int mid=(s+e)/2;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);
	t[node]=t[2*node]+t[2*node+1];
	}
}
void update(int node,int s,int e,int index,int value)
{
	if(s==e)
	{
		a[index]=value;
		t[node]=value;
		//cout<<"node ="<<node<<endl;
		//cout<<"welcome\n";
	}
	else
	{
	    int mid =(s+e)/2;
		if(s<=index&&index<=mid)
		{
			update(node*2,s,mid,index,value);
			
		}
		else
		{
			update(node*2+1,mid+1,e,index,value);
		}
		t[node]=t[2*node]+t[2*node+1];
	}
}
long long query(long long  node,long long s,long long e,long long l,long long r)
{
	if(s>e||l>e||r<s)
	{
		return 0;
	}
	if(l<=s&&e<=r)
	{
		return t[node];
	}
	long long mid=(s+e)/2;
	long long left=query(2*node,s,mid,l,r);
	long long right=query(2*node+1,mid+1,e,l,r);
	return left+right;
}
int main()
{
	long long n;
	cin>>n;
	long long i,j;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	long long q;
	cin>>q;
	for(i=0;i<q;i++)
	{
		int type;
		cin>>type;
		if(type==1)
		{
			long long x,y;
			cin>>x>>y;
			update(1,0,n-1,x-1,y);
		}
		else
		{
			long long x;
			int flag=0;
			cin>>x;
			long long l=0,h=n-1;
			while(l<=h)
			{
				long long mid=(l+h)/2;
				long long  ans=query(1,0,n-1,mid,h);
				if(ans==x)
				{
					flag=1;
					break;
				}
				else if(ans>x)
				{
					l=mid+1;
				}
				else
				{
					h=mid-1;
				}
			}
			if(flag==1)
			{
				cout<<"YES\n";
			}
			else
			{
				cout<<"NO\n";
			}
		}
	}
	
	
	
	
}
