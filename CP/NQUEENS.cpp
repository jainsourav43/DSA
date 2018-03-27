#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long
int mat[10][10];
vector< vector<int> > ans; 
bool check(int u,int v,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
      if(mat[u][i]==1&&i!=v)
      {
          return false;
      }
    }
    for(i=0;i<n;i++)
    {
        if(mat[i][v]==1&&i!=u)
        {
            return false;
        }
    }
    for(i=u-1,j=v-1;i>=0&&j>=0;i--,j--)
    {
        if(mat[i][j]==1)
        {
            return false;
        }
    }
    for(i=u+1,j=v-1;i<n&&j>=0;i++,j--)
    {
        if(mat[i][j]==1)
        {
            return false;
        }
    }
    return true;
}
void myfun(vector<int> cur,int u,int v,int n)
{
    int i;
   // cout<<"u,v="<<u<<" "<<v-1<<endl;
    //cout<<"check= "<<check(u,v-1,n)<<endl;
    if(!check(u,v-1,n))
    {
        return ;
    }
    if(v==n)
    {
    //	cout<<"Entering\n";
        ans.push_back(cur);
        return ;
    }
    for(i=0;i<n;i++)
    {
        mat[i][v]=1;
        cur.push_back(i+1);
        myfun(cur,i,v+1,n);
        cur.pop_back();
        mat[i][v]=0;
    }
    return ;
}



int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int i,j;
	    for(i=0;i<10;i++)
	    {
	        for(j=0;j<10;j++)
	        {
	         mat[i][j]=0;
	        }
	    }
	    ans.clear();
	    vector<int> cur;
	    for(i=0;i<n;i++)
	    {
	     for(int i1=0;i1<10;i1++)
	    {
	        for(j=0;j<10;j++)
	        {
	         mat[i1][j]=0;
	        }
	    }
	        cur.clear();
	        cur.push_back(i+1);
	        mat[i][0]=1;
	        myfun(cur,i,1,n);
	    }
	    if(ans.size()==0)
	    {
	        cout<<-1<<endl;
	    }
	    else
	    {
	        for(i=0;i<ans.size();i++)
	        {
	            cout<<"[";
	            for(j=0;j<ans[i].size();j++)
	            {
	                cout<<ans[i][j]<<" ";
	            }
	            cout<<"] ";
	        }
	    }
	}
	
	
	
	
	
	
	
	return 0;
}
