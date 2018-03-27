#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
vector<pair <int,int> > v[1005];
vector<int> types[1005];
#define ll long long 
bool comp(pair <int,int> p1,pair<int,int> p2)
{
	return p1.first>p2.first;
}

void dfs(int ver,vector<bool> &visit,map<int,int> &ma,ll &cost,int k,int n,vector<bool> &visit1,bool flag)
{
    
   
    visit[ver]=true;
   // cout<<"AT =    "<<ver<<endl;
    int i;
    for(i=0;i<types[ver].size();i++)
    {
        ma[types[ver][i]]=1;
    }    //cout<<"SIZE of map= "<<ma.size()<<endl;

     if(ma.size()>=k&&visit[n]==true)
    return ;
    for(i=0;i<v[ver].size();i++)
    {
        if(!visit[v[ver][i].first])
        {
            cost=cost+v[ver][i].second;
            dfs(v[ver][i].first,visit,ma,cost,k,n,visit1,flag);
          //cost=cost-v[ver][i].second;
              if(ma.size()>=k&&visit[n]==true||(visit[n]==true&&flag==true))
    		  return ;
        }
    }
    
    
    
    
}
int main() {
    
    
   ll n,m,k;
    cin>>n>>m>>k;
    ll i,j;
    for(i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        for(j=0;j<t;j++)
        {
            int x;
            cin>>x;
            types[i].push_back(x);
        }
    }
    long long fans=INT_MAX;
    for(i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    for(i=1;i<=n;i++)
    {
    	sort(v[i].begin(),v[i].end(),comp);
	}
    for(i=0;i<v[1].size();i++)
    {
        for(j=i;j<v[1].size();j++)
        {
            vector<bool> visit1(n+1,false);
            map<int,int> ma;
            ll cost1=v[1][i].second;
             for(int i1=0;i1<types[1].size();i1++)
		    {
		        ma[types[1][i1]]=1;
		    }
          //    cout<<"Going For "<<v[1][j].first<<endl;
              //visit1[1]=true;
            dfs(v[1][i].first,visit1,ma,cost1,k,n,visit1,true);
            if(visit1[n]==false)
            {
             continue;   
            }
           ll  cost2=v[1][j].second;
            vector<bool> visit2(n+1,false);
         //   cout<<"Going For "<<v[1][j].first<<endl;
             //visit2[1]=true;
            dfs(v[1][j].first,visit2,ma,cost2,k,n,visit1,false);
           //cout<<"size= "<<ma.size()<<endl;
            //cout<<"visit1[n],visit2[n]= "<<visit1[n]<<" "<<visit2[n]<<endl;
            if(visit2[n]==true&&ma.size()==k)
            {
            //	cout<<"Cost ="<<max(cost1,cost2)<<endl;
                if(fans>max(cost1,cost2))
                {
                	
                    fans=max(cost1,cost2);
                }
            }
            visit1.clear();
            visit2.clear();
            ma.clear();
        }
    }
    
    
    cout<<fans<<endl;
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}

