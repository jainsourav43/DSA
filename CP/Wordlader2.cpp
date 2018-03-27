#include<bits/stdc++.h>
using namespace std;
vector< vector< string > > ans;
class Solution {
public:
   
    void myfun(vector<string> prev,int n,int len,vector<string>&word , vector<bool>vis,string endword,int final)
    {
         int i,j,k,count=0;
         if(prev[prev.size()-1]==endword&&final==prev.size())
         {
           ans.push_back(prev);
             return;
         }
        queue<pair<string ,int> > q;
        pair<string,int> p;int check=0;
        q.push(make_pair(prev[prev.size()-1],1));
        while(!q.empty())
        {
        	p=q.front();
        	q.pop();
	        for(i=0;i<n;i++)
	        {
	        	count=0;
	        	if(vis[i])
	        	continue;
	           for(k=0;k<len;k++)
	           {
	           	if(word[i][k]!=p.first[k])
	           	{
	           		count++;
	           		if(count>1)
	           		break;
				   }
			   }
			   
			   if(count==1)
			   {
			   	int count1=0;
			   	for(k=0;k<len;k++)
	           {
	           	if(prev[prev.size()-1][k]!=word[i][k])
	           	{
	           		count1++;
	           		if(count1>1)
	           		break;
				   }
			   }
			   if(count1==1)
			   {
				prev.push_back(word[i]);
			   	q.push(make_pair(word[i],p.second+1));
			   	vis[i]=true;
			   	myfun(prev,n,len,word,vis,endword,final);
			   	prev.pop_back();
			   	if(word[i]==endword)
			   	{
			    check=1;
			   	break;
			   }
		 }
			   }
	        }
	        if(check) break;
   	   }
   	   
   	   
    }
  
    vector<vector<string>> findLadders(string beginword, string endword, vector<string>& word) {
         int n=word.size(),i,j,k,mini=INT_MAX,count=0,len=word[0].length();
         vector<bool> vis;
        vis.assign(n+1,false);
       queue<pair<string ,int> > q;
        pair<string,int> p;
        int final=-1;
        q.push(make_pair(beginword,1));
        while(!q.empty())
        {
        	p=q.front();
        	q.pop();
	        for(i=0;i<n;i++)
	        {
	        	count=0;
	        	if(vis[i])
	        	continue;
	           for(k=0;k<len;k++)
	           {
	           	if(word[i][k]!=p.first[k])
	           	{
	           		count++;
	           		if(count>1)
	           		break;
				   }
			   }
			   
			   if(count==1)
			   {
			   	if(word[i]==endword)
			   	{
				 final=p.second+1;
				 cout<<"Final ="<<final<<endl;
				 break;
				}
			   	q.push(make_pair(word[i],p.second+1));
			   	vis[i]=true;
			   }
	        }
	        if(final!=-1)
	        break;
	        
   	   }
       
     
       
       
       
       
       
       
       vis.clear();
       vis.assign(n+1,false);
	    vector<string> prev;
        ans.clear();
        
        prev.clear();
        prev.push_back(beginword);
        myfun(prev,n,len,word,vis,endword,final);
        return ans; 
    }
};
int main()
{
	string b,e;
	vector<string>word;
	Solution s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string temp;
		cin>>temp;
		word.push_back(temp);
	}
	cin>>b;
	cin>>e;
	vector<vector< string> > an;
	an=s.findLadders(b,e,word);
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}
