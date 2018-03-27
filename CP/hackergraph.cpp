#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<queue>
#include <algorithm>
using namespace std;
                vector<int> v[100001];

bool visit[100001];
int dist[100001],cost=0;
queue<int> q1;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int q;
    cin>>q;
    while(q--)
        {
        	
        int m,n,cl,cr;
        cost=0;
        cin>>n>>m>>cl>>cr;
 for(int i=1;i<=n;i++)
            v[i].clear();
        int i,j,u1,v1;
             for(i=0;i<m;i++)
            {
                cin>>u1>>v1;
                v[u1].push_back(v1);
                v[v1].push_back(u1);
                 
            }
           
            if(cl<cr)
                {
                cout<<n*cl<<endl;
                }

        else
            {
                 int max1=0,in;
                 
                 if(m==0){
                 	cout<<n*cl<<endl;
				 }
                 else
                 {
				 
				 
                 
                 
                for(i=1;i<=n;i++)
                {
                   visit[i]=false;
                   dist[i]=100000000;
                if(v[i].size()>max1)
                    {
                    //	cout<<"v["<<i<<"] ="<<v[i].size()<<endl;
                max1=v[i].size();
                in=i;
                }
                }
            cost=cost+cl;
            visit[in]=true;
            q1.push(in);
            visit[in]=true;
            dist[in]=0;
          //  cout<<"in= "<<in<<endl;
           // cout<<"in\n";
             while(!q1.empty())
                   {
                   int temp=q1.front();
                 // cout<<"temp= "<<temp<<endl;
                   q1.pop();
                   visit[temp]=true;
                   for(j=0;j<v[temp].size();j++)
                       {
                        if(visit[v[temp][j]]==false&&dist[v[temp][j]]>dist[temp]+1)
                            {//cout<<"temp1= "<<temp<<endl;
                            //	cout<<"dist["<<v[temp][j]<<"]= "<<dist[v[temp][j]]+1<<endl;
                            dist[v[temp][j]]=dist[temp]+1;
                            if(dist[v[temp][j]]*cr<cl)
                                cost=cost+dist[v[temp][j]]*cr;
                                else
                                {//cout<<"not\n";
                                    cost=cost+cl;
                                    dist[v[temp][j]]=0;
                                 }
                            q1.push(v[temp][j]);
                        }
                   }
                   
                    }
                    
                    
                    for(i=1;i<=n;i++)
                    {
                    	if(!visit[i])
                    	{
                    		cost+=cl;
						}
					}
                       
            cout<<cost<<endl;
            
            
            }   
        }
    }
    
    
    
    
    
    
    
    
    
    return 0;
}

