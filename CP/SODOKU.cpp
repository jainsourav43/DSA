#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
        int mat[9][9];
pair<int,int> nextpair(int u,int v)
{
    int i,j;
    pair <int,int> p={-1,-1};
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(mat[i][j]==0)
            {
                p.first=i;
                p.second=j;
                return p;
            }
        }
    }
    return p;
}
bool check(int u,int v)
{
    int i,j;
    for(i=0;i<9;i++)
    {
        
        if(i!=u&&mat[u][v]==mat[i][v])
        {
            return false;
        }
    }
    for(i=0;i<9;i++)
    {
        
        if(i!=v&&mat[u][v]==mat[u][i])
        {
            return false;
        }
    }
    int tempu=u,tempv=v;
   int si,sj,ei,ej; 
   while((u+1)%3!=0)
   u++;
   ei=u;
   while(tempu%3!=0)
   {
       tempu--;
   }
   si=tempu;
   while((v+1)%3!=0)
   v++;
   ej=v;
   while(tempv%3!=0)
   {
       tempv--;
   }
   sj=tempv;
  // cout<<"si,ei,sj,ej= "<<si<<" "<<ei<<" "<<sj<<" "<<ej<<endl;
   vector<bool> c(10,false);
    for(i=si;i<=ei;i++)
    {
        for(j=sj;j<=ej;j++)
        {
    //    	cout<<"m =  "<<mat[i][j]<<" c ="<<c[mat[i][j]]<<endl;
            if(c[mat[i][j]]&&mat[i][j]!=0)
            {
            	//cout<<"returnign  false\n";
                return false;
                
            }
            c[mat[i][j]]=true;
        }
    }
    return true;
}
bool myfun(int i,int j)
{
    pair<int,int> p;
  //  cout<<"mat["<<i<<"]["<<j<<"]"<<mat[i][j]<<endl; 
    if(!check(i,j))
    {
    //  cout<<"Going for next\n";
     return false   ;
    }
    p=nextpair(i,j);
    int u,v;
    u=p.first;v=p.second;
    //cout<<"u,u ="<<u<<" "<<v<<endl;
    if(u==-1)
    return true;
    for(i=1;i<=9;i++)
    {
        mat[u][v]=i;
        if(myfun(u,v))
        {
            return true;
        }
        mat[u][v]=0;
        
    }
    return 0;
}
int main() {


    int t;
    cin>>t;
    while(t--)
    {
        int i,j;
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                cin>>mat[i][j];
            }
        }
        int check=0,u,v;
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                if(mat[i][j]==0)
                {
                    u=i;
                    v=j;
                    check=1;
                    break;
                }
            }
            if(check==1)
            break;
        }
        
        for(i=1;i<=9;i++)
        {
            mat[u][v]=i;
        	bool c=myfun(u,v);
        //	cout<<"c ="<<c<<endl;
            if(c)
            {
                break;
            }
        }
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        
    }
    
    
    
	return 0;
}
