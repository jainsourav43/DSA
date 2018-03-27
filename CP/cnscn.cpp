#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
vector<ll> graph[100000+10];
bool dfs(ll cur,vector<ll >&path,vector<bool> &visited,ll dest)
{
	ll i;
	bool check=false;
	for(i=0;i<graph[cur].size();i++)
	{
		if(graph[cur][i]==dest)
		{
			return true;
		}
		if(!visited[graph[cur][i]])
		{
			path.push_back(graph[cur][i]);
			visited[graph[cur][i]]=true;
	    	check=dfs(graph[cur][i],path,visited,dest);
			if(!check)
			{
			path.pop_back();
			visited[graph[cur][i]]=false;
			}	
			else
			{
				return true;
			}
		}
	}
	return false;

}
void findsum(ll cur,vector<ll>&s,vector<bool> &visited, ll &sum)
{
	ll i;
	for(i=0;i<graph[cur].size();i++)
	{
		if(!visited[graph[cur][i]])
		{
			sum=sum+s[graph[cur][i]];
			visited[graph[cur][i]]=true;
			findsum(graph[cur][i],s,visited,sum);
		}
	}
}
int main()
{
	ll n;
	cin>>n;
	vector<ll> s(n+5);
	ll i,j;
	for(i=1;i<=n;i++)
	{
		cin>>s[i];
		
	}
	for(i=0;i<n-1;i++)
	{
		ll a,b;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	ll u,v;
	ll a=0,b=0,c=0,d=0;
	ll q;
	cin>>q;
	vector<ll>path;
	for(i=0;i<q;i++)
	{
		vector<bool>visited(n+1,false);
		path.clear();
		cin>>u>>v;
		path.push_back(u);
		visited[u]=true;
		dfs(u,path,visited,v);
		path.push_back(v);
		visited[v]=true;
		ll suma=0,sumb=0;
		ll tempsumb=0,tempsuma=0;
		for(j=0;j<path.size()/2;j++)
		{
			tempsumb=0;tempsuma=0;
			suma+=s[path[j]];
			findsum(path[j],s,visited,tempsuma);
			suma+=tempsuma;
			sumb+=s[path[path.size()-j-1]];
			findsum(path[path.size()-j-1],s,visited,tempsumb);
			sumb+=tempsumb;	
		}
	//	cout<<"tmpa,tmpb= "<<tempsuma<<" "<<tempsumb<<endl;
		if(path.size()%2!=0)
		{
			tempsuma=0;
			suma+=s[path[path.size()/2]];
			findsum(path[j],s,visited,tempsuma);
			suma+=tempsuma;
		}
	//	cout<<"path\n";
//		for(j=0;j<path.size();j++)
//		{
//			cout<<path[j]<<" ";
//		}
	//	cout<<endl;
		if(suma>=sumb)
		{
			a++;
		}
		else
		{
			c++;
		}
		b+=suma;
		d+=sumb;
	//	cout<<"suma, sumb  ="<<suma<<"  "<<sumb<<endl;
		
	}
	cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	
}
