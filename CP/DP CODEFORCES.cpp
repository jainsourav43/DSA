#include<bits/stdc++.h>
#define maxn 200001
using namespace std;
struct ti
{
	int maxa=INT_MAX,minb=INT_MIN,a,b;
};
ti t[maxn];
long long int a[200001],b[200001],n;
void build(int node,int s,int e)
{
	if(s==e)
	{
	//	cout<<"s="<<s<<"  b[s]= "<<b[s]<<endl;
		t[node].maxa=a[s];
		t[node].minb=b[s];
	//	cout<<"node = "<<node<<endl;
	//	cout<<"t[node] = "<<t[node].minb<<endl;
		
	}
	else{
	int mid=(s+e)/2;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);
	t[node].maxa=max(t[2*node].maxa,t[2*node+1].maxa);
	t[node].minb=min(t[2*node].minb,t[2*node+1].minb);
	}
}
long long ans=0;
void visit(int node,int s,int e)
{
	cout<<"s,e= "<<s<<"  "<<e<<endl;
		if(s>e)
		return ;
		if(node>=2*n+2)
		{
			return;
		}
		if(t[node].maxa==t[node].minb&&t[node].minb!=INT_MIN)
		{
		//	cout<<"NONDE= "<<node<<endl;
			ans=ans+1;
		}
			int mid=(s+e)/2;
		visit(2*node,s,mid);
		visit(2*node+1,mid+1,e);	
}
int main()
{
	cin>>n;
	long long i,j;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(j=0;j<n;j++)
	{
		cin>>b[j];
	}
	build(1,0,n-1);
	visit(1,0,n-1);
cout<<ans<<endl;	
//	cout<<"Ans = "<<ans<<endl;
}
