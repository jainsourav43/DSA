#include<iostream>
#include<queue>
#include<bits/stdc++.h>
//#include<pairs>
#include<vector>
using namespace std;
int visit1[20];
vector < pair<int,int> > graph[11];
int sum1[1048576],count1=0;
//void visit(int v,int n,queue<int> q)
//{
//	visit1[v]=1;
////	cout<<"v= "<<v<<" ";
//		q.push(v);
//		if(q.size()==n)
//		{
//			for(int i=0;i<n;i++)
//			{
//				int temp=q.front();
//				cout<<q.front()<<" ";
//				q.pop();
//			//	q.push(temp);
//			}
//					cout<<endl;
//				//	for(int j=1;j<=n;j++) visit1[j]=0;
//				
//				
//		}
//	
//	for(int i=1;i<=n;i++)
//	{
//		if(graph[v][i]&&!visit1[i])
//		{
//				visit(i,n,q);
//				visit1[i]=0;
//				
//			
//		}
//	}
//			
//
//	
//	
//	
//}


void visit(int v,int n,queue<int> q,int sum)
{
		visit1[v]=1;
		q.push(v);
		if(q.size()==n)
		{
			sum1[count1++]=sum;
			for(int i=0;i<n;i++)
			{
			cout<<q.front()<<" ";
				q.pop();
			}
					cout<<endl;
					
	    }
	for(auto it =graph[v].begin();it!=graph[v].end();it++)
	{
		if(!visit1[it->first])
		{
				sum=sum+it->second;
				visit(it->first,n,q,sum);
				visit1[it->first]=0;
				sum=sum-it->second;
		}
	}	
}
//void dfs(int v,int n)
//{
//	visit1[v]=1;
//	for(int i=1;i<=n;i++)
//	{
//		if(graph[v][i]&&!visit1[i])
//		{
//			dfs(i,n);
//		}
//	}
//}

int main()
{
	int m,n;
	cin>>n>>m;
	queue<int> q;
	int x,y,z,j;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y>>z;
	//	graph[x][y]=z;
	//	graph[y][x]=z;
	  graph[y].push_back(make_pair(x,z));	
	  graph[x].push_back(make_pair(y,z));	
		
	}
	for(int i=1;i<=n;i++)
	{
		
		for(j=1;j<=n;j++)
		{
			visit1[j]=0;
		}
		visit(i,n,q,0);
	}
	int ans=*min_element(sum1,sum1+count1)	;
	cout<<ans<<endl;
}
