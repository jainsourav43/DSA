#include <bits/stdc++.h>

using namespace std;
vector<bool> visited;
bool check=false;
int x[140005],y[140005],post[140001];
int num=0;
void dfs1(int v,vector< int> street[])
{
	visited[v]=true;
	for(int i=0;i<street[v].size();i++)
	{
		if(visited[street[v][i]]==false)
		{
			dfs1(street[v][i],street);
		}
	}
	post[v]=num++;
}
void dfs2(map<int,bool> &vec,int v,vector< int> street[])
{
	//cout<<v<<endl;
	
	vec[v]=true;
	visited[v]=true;
	for(int i=0;i<street[v].size();i++)
	{
		if(visited[street[v][i]]==false)
		{
			//ans+=
			dfs2(vec,street[v][i],street);
		}
	}
	//post[v]=num++;
}
//bool dfs(int v,vector< int> street[],int source)
//{
////	cout<<v<<endl;
//    int i,j;
//    if(check==true&&source==v)
//    {
//        return true;
//    }
//    if(visited[v]==true)
//     return false;
//    
//    visited[v]=true;
//    check=true;
//    for(i=0;i<street[v].size();i++)
//    {
//        if(dfs(street[v][i],street,source))
//        {
//            return true;
//        }   
//    }
//    return false;
//}
int findnext(int n )
{
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==false)
		return i;
	}
	return -1;
}
int findnextmax(int n)
{
int max=INT_MIN;
for(int i=1;i<=n;i++)
{
	int index=-1;
	for(i=1;i<=n;i++)
	{
	
	if(visited[i]==false&&max<post[i])
	{
		//cout<<"max= "<<max<<endl;
		max=post[i];
		index=i;
	}
	}
	return index;
}
}
int findStreets(int n, vector< int > street[],int m) {
    
   long long  int ans=0,i,j;
   	visited.assign(n+1,false);

	while(1)
	{
		int v=findnext(n);
		if(v==-1)
		{
			break;
		}
		dfs1(v,street);
	}
//	for(i=1;i<=n;i++)
//	{
//		cout<<post[i]<<" ";
//	}
//	cout<<endl;
   	vector<int> copy[n+1];
   	for(i=0;i<m;i++)
   	{
   		copy[y[i]].push_back(x[i]);
	}
	visited.assign(n+1,false);
	while(1)
	{
		int v=findnextmax(n);
	//	cout<<"v= "<<v<<endl;
		if(v==-1)
		{
			break;
		}
		map<int,bool> vec;
		dfs2(vec,v,copy);
		if(vec.size()==1)
		{
			continue;
		}
		else
		{
			map<int,bool> :: iterator it=vec.begin();
			for(;it!=vec.end();it++)
			{
               	for(j=0;j<street[it->first].size();j++)
				{
				   	if(vec.find(street[it->first][j])!=vec.end())
				   	{
				   		ans++;
					}
				}			
			}
		}
	}
    return ans;
    
    
    // Complete this function
}
//1
//7 7
//7 2
//7 5
//7 2
//2 4
//4 2
//6 7
//4 6
int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int m;
        cin >> n >> m;
        int i;
        vector<int>street[n+1];  
        num=0;
        for(i=0;i<m;i++)
        {
            cin>>x[i]>>y[i];
          //  my[make_pair(x[i],y[i])]++;
            street[x[i]].push_back(y[i]);
        }
        int result = findStreets(n, street,m);
        cout<<result<<endl;
    }
    return 0;
}

