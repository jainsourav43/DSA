//#include<iostream>
//using namespace std;
//#include<bits/stdc++.h>
//#define ll long long
//int mat[10][10];
//vector< vector<int> > ans; 
//bool check(int u,int v,int n)
//{
//    int i,j;
//    for(i=0;i<n;i++)
//    {
//      if(mat[u][i]==1&&i!=v)
//      {
//          return false;
//      }
//    }
//    for(i=0;i<n;i++)
//    {
//        if(mat[i][v]==1&&i!=u)
//        {
//            return false;
//        }
//    }
//    for(i=u-1,j=v-1;i>=0&&j>=0;i--,j--)
//    {
//        if(mat[i][j]==1)
//        {
//            return false;
//        }
//    }
//    for(i=u+1,j=v-1;i<n&&j>=0;i++,j--)
//    {
//        if(mat[i][j]==1)
//        {
//            return false;
//        }
//    }
//    return true;
//}
//void myfun(vector<int> cur,int u,int v,int n)
//{
//    int i;
//   // cout<<"u,v="<<u<<" "<<v-1<<endl;
//    //cout<<"check= "<<check(u,v-1,n)<<endl;
//    if(!check(u,v-1,n))
//    {
//        return ;
//    }
//    if(v==n)
//    {
//    //	cout<<"Entering\n";
//        ans.push_back(cur);
//        return ;
//    }
//    for(i=0;i<n;i++)
//    {
//        mat[i][v]=1;
//        cur.push_back(i+1);
//        myfun(cur,i,v+1,n);
//        cur.pop_back();
//        mat[i][v]=0;
//    }
//    return ;
//}
//
//
//
//int main()
// {
//	//code
//	int t;
//	cin>>t;
//	while(t--)
//	{
//	    int n;
//	    cin>>n;
//	    int i,j;
//	    for(i=0;i<10;i++)
//	    {
//	        for(j=0;j<10;j++)
//	        {
//	         mat[i][j]=0;
//	        }
//	    }
//	    ans.clear();
//	    int k;
//	    vector<int> cur;
//	    for(i=0;i<n;i++)
//	    {
//	     for(int i1=0;i1<10;i1++)
//	    {
//	        for(j=0;j<10;j++)
//	        {
//	         mat[i1][j]=0;
//	        }
//	    }
//	        cur.clear();
//	        cur.push_back(i+1);
//	        mat[i][0]=1;
//	        myfun(cur,i,1,n);
//	    }
//	    string a;
//	    string arr[n+1];
//	    vector<string> an;
//	    vector<vector< string> >fans;
//	   int i1;
//	    if(ans.size()==0)
//	    {
//	        cout<<-1<<endl;
//	    }
//	    else
//	    {
//	        for(i=0;i<ans.size();i++)
//	        {
//	        	an.clear();	           	 int count=0;
//				
//	           for(j=0;j<ans[i].size();j++)
//	           {
//	             	cout<<ans[i][j]<<endl;
//	              	arr[ans[i][j]]="";
//	           	 	for(i1=0;i1<count;i1++)
//	           	 	arr[ans[i][j]]=arr[ans[i][j]]+'.';
//	           	 //	cout<<arr[an[i][j]]<<endl;
//	           	 	arr[ans[i][j]]=arr[ans[i][j]]+'Q';
//	           	 	
//	           	 	for(i1=count+1;i1<n;i1++)
//	           	 	{
//	           	 		arr[ans[i][j]]=arr[ans[i][j]]+'.';
//					}
//		//	 cout<<arr[ans]
//				cout<<arr[ans[i][j]]<<endl;
//				count++;
//			   }
//			   for(i1=1;i1<n+1;i1++)
//			   {
//			   	 an.push_back(arr[i1]);
//			   }
//			   fans.push_back(an);
//			   
//			   
//	        }
//	        cout<<endl<<endl;
//	        reverse(fans.begin(),fans.end());
//	        for(i=0;i<fans.size();i++)
//	        {
//	        	for(j=0;j<fans[i].size();j++)
//	        	{
//	        		cout<<fans[i][j]<<endl;
//				}
//				cout<<endl;
//			}
//	    }
//	}
//	
//	
//	
//	
//	
//	
//	
//	return 0;
//}


#include<iostream>
using namespace std;
#include<bits/stdc++.h>
vector<string> ans;
#define ll long long 

void myfun(string p,int i,int j,string  s,int n)
{
    if(i==n)
    {
      //  p[j]='\0';
        
        // cout<<"(";
        // cout<<p;
        // cout<<")";
        ans.push_back(p);
        return ;
    }
    p.push_back(s[i]);
    myfun(p,i+1,j+1,s,n);
    p.pop_back();
    if(p.size()==0)
    return ;
    p.push_back(' ');
    p.push_back(s[i]);
    myfun(p,i+1,j+2,s,n);
    p.pop_back();
    p.pop_back();
    
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	   string s;
	    cin>>s;
	    int n=s.length();
	    string p;
	   // p[0]=s[0];
	    
	    myfun(p,0,0,s,n);
	    sort(ans.begin(),ans.end());
	    n=ans.size();
	    for(int i=0;i<n;i++)
	    {
	        cout<<"(";
	        cout<<ans[i]<<")";
	    }
	    cout<<endl;
	}
	return 0;
}
