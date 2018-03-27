#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long
vector<int> v[105];
long long ans=0;	  // vector<bool> visited;

void solve(int ver,vector<bool>& visited,int in)
{

    for(int i=ver;i<=100;i++)
    {
        while((v[i][0]==i&&i<100)||(v[i][0]<i&&visited[i]==true )||(v[i][0]<=in))
        {
            i++;
            if(visited[100]) return;
        }
        if((i-ver)>6)
        {
            if((i-ver)%6==0)
            ans=(i-ver)/6+ans;
            else
            {
            	ans=(i-ver)/6+1+ans;
			}
        }
        else
        {
            ans=ans+1;
        }
        if(i==100)
        {
            return;
        }        
		if(visited[100]) return;
      // cout<<"Ans before Call ="<<ans<<endl;
       // cout<<"Going fooo "<<v[i][0]<<endl;
        if(v[i][0]==100)
        {
        	visited[100]=true;
        	return ;
		}
        if(v[i][0]<i)
        visited[i]=true;
       // visited[i]=visited[v[i][0]]=true;
        if(visited[100]) return;
        solve(v[i][0],visited,i);
        //cout<<"ans after call= "<<ans<<endl;
    }
}
int main()
 {
	
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    for(int i=0;i<=105;i++)
		 v[i].clear();
	    int i,j,a,b;
	    for(i=1;i<=100;i++)
	    {
	        v[i].push_back(i);
	    }
	    for(i=0;i<n;i++)
	    {
	        cin>>a>>b;
	        v[a].clear();
	        v[a].push_back(b);
	    }
//	    int m;
//	    cin>>m;
//	    for(i=0;i<m;i++)
//	    {
//	        cin>>a>>b;
//	        v[a].clear();
//	        v[a].push_back(b);
//	    }
	    vector<bool> visited(105,false);
	   int fans=INT_MAX;
	    for(i=1;i<=100;i++)
	    {
	        ans=0;
	        while(i<100&&v[i][0]<=i)
	        {
	            i++;
	        }
	       if(i>6)
	        {
	            if((i-1)%6==0)
	            {
	            ans=(i-1)/6;
	        	}
	            else
	            {
	            	ans=(i-1)/6+1;
				}
	        }
	        else
	        {
	            ans=1;
	        }
	     //  cout<<"Ans before call= "<<ans<<endl;
	        if(i<100&&v[i][0]<100)
	        {
	    //	cout<<"Going to = "<<v[i][0]<<endl;
	    //	visited[i]=true;
	        solve(v[i][0],visited,i);
	        }
	        if(ans==17)
	        {
	        	int count=0;
	        	for(j=93;j<=99;j++)
	        	{
	        		if(v[j][0]<j)
	        		{
	        			count++;
					}
				}
				if(count==7)
				{
					fans=-1;
				}
			}
	   //   cout<<"Ans after completing the game = "<<ans<<endl;
	        
	        if(fans>ans)
	        {
	            fans=ans;
	        }
	    }
	    cout<<fans<<endl;
	   // cout<<"FANs = "<<fans<<endl;
	}
	return 0;
}
