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
void updaterange(int node,int s,int e,int l,int r,int val)
{
	if(s>e||e<l|| s>r)
	{
		return;
	}
	 if(s==e)
	 {
	 	t[node]=val;
	 	return;
	 }
	 int mid=(s+e)/2;
	 
	 updaterange(2*node,s,mid,l,r,val);
	 updaterange(2*node+1,mid+1,e,l,r,val);
	 t[node]=t[2*node]+t[2*node+1];
}

int query(int node,int s,int e,int l,int r)
{
	if(s>e||r<s||l>e)
	{
		cout<<"\nr, s= "<<r<<" "<<s<<"  l,e = "<<l<<" "<<e<<endl;
		return 0;
	}
	if(l<=s&&e<=r)
	{
		cout<<"l= "<<l <<" r ="<<r<<endl;
		cout<<"t[node]= "<<t[node]<<endl;
		return t[node];
	}
	int mid=(s+e)/2;
	int left,right;
	left=query(2*node,s,mid,l,r);
	right=query(2*node+1,mid+1,e,l,r);
	return left+right;
}
int lazy[50];

int queryRange(int node,int s,int e,int l,int r)
{
	if(s>e||r<s||l>e)
	{
		cout<<"\nr, s= "<<r<<" "<<s<<"  l,e = "<<l<<" "<<e<<endl;
		return 0;
	}
	if(lazy[node]!=0)
	{
		t[node]=(e-s+1)*lazy[node];
//		t[node]=lazy[node];
		cout<<"\n\nvery very node ="<<node<<endl;
		if(s!=e)
		{
//			lazy[2*node]+=lazy[node];
//			lazy[2*node+1]+=lazy[node]; actual
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(l<=s&&e<=r)
	{
	//	cout<<"l= "<<l <<" r ="<<r<<endl;
	//	cout<<"t[node]= "<<t[node]<<endl;
		
		
		
		return t[node];
	}
	int mid=(s+e)/2;
	int left,right;
	left=queryRange(2*node,s,mid,l,r);
	right=queryRange(2*node+1,mid+1,e,l,r);
	return left+right;
}
void updateRange(int node,int s,int e,int l,int r,int val)
{
		if(lazy[node] != 0)
	    { 
	        // This node needs to be updated
	        t[node] += (e - s+ 1) * lazy[node];    // Update it
	        if(s != e)
	        {
	            lazy[node*2] += lazy[node];                  // Mark child as lazy
	            lazy[node*2+1] += lazy[node];                // Mark child as lazy
	        }
	        lazy[node] = 0;                                  // Reset it
	    }
		if(s>e||e<l||r<s)
		{
			return ;
		}
		
	if(s>=l&&e<=r )
	{
		t[node]+=(e-s+1)*val;
		cout<<"\n special s,e = "<<s<<" "<<e<<endl;
		cout<<"\n special node ="<<node<<endl;
		if(s!=e)
		{
			lazy[2*node]+=val;
			lazy[2*node+1]+=val;
		}
		return ;
	}
	int mid=(s+e)/2;
	updateRange(2*node,s,mid,l,r,val);
	updateRange(2*node+1,mid+1,e,l,r,val);
	t[node]=t[2*node]+t[2*node+1];
	
}
int main()
{
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	build(1,0,n-1);
	for(int i=1;i<2*n;i++)
	{
		cout<<t[i]<<" ";
	}
//	int ans=query(1,0,n-1,0,3);
//	cout<<"my ans="<<ans<<endl;
	updateRange(1,0,n-1,0,1,100);
	cout<<"t[8] ="<<t[8]<<endl;
int 	ans=queryRange(1,0,n-1,0,3);	cout<<"t[8] ="<<t[8]<<endl;

	cout<<"my ans="<<ans<<endl;
		for(int i=1;i<2*n;i++)
	{
		cout<<t[i]<<" ";
	}

}

