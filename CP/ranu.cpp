#include<iostream>
using namespace std;
int a[1000001],t[2*1000001],n;
void build(int node,int s,int e)
{
	if(s==e)
	{
		t[node]=0;
		//cout<<"node = "<<node<<endl;
		//cout<<"t[node] = "<<t[node]<<endl;
	}
	else{
	int mid=(s+e)/2;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);
	t[node]=min(t[2*node],t[2*node+1]);
	}
}
void update(int node,int s,int e,int index,int value)
{
	if(s==e)
	{
		a[index]=value;
		t[node]=value;
		cout<<"node ="<<node<<endl;
		cout<<"welcome\n";
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
	 	t[node]+=val;
	 	return;
	 }
	 int mid=(s+e)/2;
	 updaterange(2*node,s,mid,l,r,val);
	 updaterange(2*node+1,mid+1,e,l,r,val);
	 t[node]=min(t[2*node],t[2*node+1]);
}

int query(int node,int s,int e,int l,int r,int x)
{
	if(s>e||r<s||l>e)
	{
	//	cout<<"\nr, s= "<<r<<" "<<s<<"  l,e = "<<l<<" "<<e<<endl;
		return 0;
	}
	if(s==e)
	{
		if(x<=t[node])
		return 1;
		else
		return 0;
	}
	if(l<=s&&e<=r&&x<=t[node])
	{
		//cout<<"l= "<<l <<" r ="<<r<<endl;
	//	cout<<"t[node]= "<<t[node]<<endl;
		return (e-s+1);
	}//cout<<"out\n";
	//cout<<"s,e = "<<s<<"  "<<e<<endl;
	int mid=(s+e)/2;
	int left,right;
	left=query(2*node,s,mid,l,r,x);
	right=query(2*node+1,mid+1,e,l,r,x);
	return left+right;
}
int lazy[50];

int queryRange(int node,int s,int e,int l,int r)
{
	if(s>e||r<s||l>e)
	{
		return 0;
	}
	if(lazy[node]!=0)
	{
		t[node]+=(e-s+1)*lazy[node];
		if(s!=e)
		{
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(l<=s&&e<=r)
	{
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
///		cout<<"\n special s,e = "<<s<<" "<<e<<endl;
//		cout<<"\n special node ="<<node<<endl;
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
int m;
int main()
{
	
	cin>>n;
	cin>>m;
	int l[m],r[m],i;
	for(i=0;i<m;i++)
	{
		cin>>l[i]>>r[i];
	}
	build(1,0,n-1);
	for(i=0;i<m;i++)
	{
		updaterange(1,0,n-1,l[i]-1,r[i]-1,1);
	}cout<<"\n";
//	for(i=1;i<2*n;i++) cout<<t[i]<<" ";
//	cout<<"\n";
	int q;
	cin>>q;
	int x[i],ans;
	int min1=1000001;
	for(i=0;i<q;i++)
	{
		cin>>x[i];
		if(min1>x[i])
		{
		ans=query(1,0,n-1,0,n-1,x[i]);
		cout<<ans<<endl;
		}
		else
		cout<<0<<endl;
		if(ans==0)
		{
			if(min1>x[i])
			{
				min1=x[i];
			}
		}
	//	cout<<ans<<endl;
	}
	
	

}
