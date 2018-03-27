#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,q;
		cin>>n>>q;
		ll ans;
		vector< vector< ll > > a,b;
		ll cyclecost[n];
		ll i,j;
		memset(cyclecost,0,sizeof(cyclecost));
		
		vector<ll> cur,cur1;
		for(i=0;i<n;i++)
		{
			
			ll num;
			cin>>num;
			for(j=0;j<num;j++)
			{
				ll temp;
				cin>>temp;
				cur1.push_back(0);
				cur.push_back(temp);
				cyclecost[i]+=temp;
				
			}
			a.push_back(cur);
			b.push_back(cur1);
			cur1.clear();
			cur.clear();
		}
		for(i=0;i<n;i++)
		{
			b[i][0]=0;
			for(j=1;j<a[i].size();j++)
			{	
				b[i][j]+=b[i][j-1]+a[i][j-1];
			}
		}
		vector< pair<pair <ll,ll> ,ll > > v;
		ll outer[n],inner[n];
		for(i=0;i<n;i++)
		{
			ll c1,c2,w;
			cin>>c1>>c2>>w;
		    v.push_back(make_pair(make_pair(c1,c2),w));
		}
		for(i=0;i<n;i++)
		{
			outer[i]=v[i].first.first;
			inner[i]=v[(i-1+n)%n].first.second;
		}
		ll cost[n+1];
		ll total=0;
		
		
		
		
	
		for(i=0;i<n;i++)
		{
			//sum=0;
//			for(j=outer[i]-1;j!=inner[i]-1;)
//			{
//				sum=sum+a[i][j];
//				j=(j+1)%n;
//			}
			ll temp=inner[i];
			inner[i]=min(inner[i],outer[i]);
			outer[i]=max(outer[i],temp);
			cost[i]=b[i][outer[i]-1]-b[i][inner[i]-1];
			cost[i]=min(cyclecost[i]-cost[i],cost[i]);
			total+=cost[i];
		}
		ll left[n];
		left[0]=0;
		left[1]=v[0].second;
		for(i=0;i<n;i++)
		{
			total+=v[i].second;
		}
		for(i=2;i<n;i++)
		{
			left[i]=left[i-1]+v[i-1].second+cost[i-1];
		}
		
//		for(i=0;i<n;i++)
//		{
//			cout<<"outer,inner = " <<outer[i]<<" "<<inner[i]<<endl;
//			cout<<"cost = "<<cost[i]<<endl; 
//			cout<<"left = "<<left[i]<<endl;
//			
//		}
//		for(i=0;i<n;i++)
//		{
//			cout<<"b for "<<i<<endl;
//			for(j=0;j<a[i].size();j++)
//			{	
//				cout<<b[i][j]<<" ";
//			}
//			cout<<endl;
//		}
//		cout<<"Total= "<<total<<endl;
		ll ans1,ans2;
		
		for(i=0;i<q;i++)
		{
			ll v1,c1,v2,c2;
			cin>>v1>>c1>>v2>>c2;
//			ll temp=c1;
//			c1=min(c1,c2);
//			c2=max(temp,c2);
			if(c1>c2)
			{
				swap(c1,c2);
			}
			if(c1==1)
			ans1=left[c2-1]-left[c1-1];
			else
			ans1=left[c2-1]-left[c1-1]-cost[c1-1];
		//	cout<<"ans1 = "<<ans1<<endl;
			ans2=total-ans1-cost[c1-1]-cost[c2-1];
		//	cout<<"ans2 = "<<ans2<<endl;
			ans1=ans1+min(cyclecost[c1-1]-abs(b[c1-1][outer[c1-1]-1]-b[c1-1][v1-1]),abs(b[c1-1][outer[c1-1]-1]-b[c1-1][v1-1]));
		//	cout<<"ans1 = "<<ans1<<endl;
			ans1=ans1+min(cyclecost[c2-1]-abs(b[c2-1][inner[c2-1]-1]-b[c2-1][v2-1]),abs(b[c2-1][inner[c2-1]-1]-b[c2-1][v2-1]));
		//	cout<<"ans1 = "<<ans1<<endl;
			ans2=ans2+min(cyclecost[c1-1]-abs(b[c1-1][inner[c1-1]-1]-b[c1-1][v1-1]),abs(b[c1-1][inner[c1-1]-1]-b[c1-1][v1-1]));
		//	cout<<"ans2 = "<<ans2<<endl;
			ans2=ans2+min(cyclecost[c2-1]-abs(b[c2-1][outer[c2-1]-1]-b[c2-1][v2-1]),abs(b[c2-1][outer[c2-1]-1]-b[c2-1][v2-1]));
		//	cout<<"ans2 = "<<ans2<<endl;
			ans=min(ans1,ans2);
		//	cout<<"ans= ";
			cout<<ans<<endl;
			
					
		}
		
		
	}
	
} 
