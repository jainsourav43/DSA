#include<bits/stdc++.h>
#define ll long  long 
using namespace std;
struct st
{
	int d,t,s;
};
bool comp(st s1,st s2)
{
	return s1.s>s2.s;
}
vector<pair<int,int> > v[100005];
int check=0;
void dfs(int ver,int dest,vector<bool> &visit,ll &an,int k,vector<int> &ans)
{
//	cout<<"intermediate= "<<ver<<endl;
	visit[ver]=true;
	if(ver==dest)
	{
		check=1;
		return ;
	}
	for(int i=0;i<v[ver].size();i++)
	{
		if(!visit[v[ver][i].first]&&check==0)
		{
			int check1=0;
			if(v[ver][i].second<=k)
			{
//			cout<<"pushing = "<<v[ver][i].second<<endl;
			ans.push_back(v[ver][i].second);
			check1=1;
			}
			dfs(v[ver][i].first,dest,visit,an,k,ans);
			if(check1&&check==0)
			{
//			cout<<"poping\n"<<ans[ans.size()-1];
			ans.pop_back();
			}
		}
		
	}
}
int main()
{
	long long t1,k;
	cin>>t1;
    while(t1--)
	{
		
		ll n;
		cin>>n;
		
		
		ll i,j;
		for(i=0;i<=n;i++)
		{
			v[i].clear();
		}
		for(i=0;i<n-1;i++)
		{
			int x,y,c;
			cin>>x>>y>>c;
			v[x].push_back(make_pair(y,c));
			v[y].push_back(make_pair(x,c));
		}
		ll m;
		cin>>m;
		for(i=0;i<m;i++)
		{
			ll x,y,k;
			cin>>x>>y>>k;
		//	vector<bool> visit(n+1,false);
			//visit[x]=true;
			ll an=0;
			
			for(j=0;j<v[x].size();j++)
			{
				check=0;
				vector<bool> visit(n+1,false);
				visit[x]=true;
				vector<int> ans;
				if(v[x][j].second<=k)
				ans.push_back(v[x][j].second);
			 	dfs(v[x][j].first,y,visit,an,k,ans);
			 	an=0;
			 	if(check==1)
			 	{
			 		if(ans.size()>=1)
			 		{
					 
			 		an=ans[0];
			 	}
			 		for(int u=1;u<ans.size();u++)
			 		{
			 			an=an^ans[u];					 	
					 }
					 cout<<an<<endl;
					 break;
				}
			}
		}
		
		
	}
}
