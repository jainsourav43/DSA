#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ladderLength(string beginword, string endword, vector<string>& word) {
        int n=word.size(),i,j,k,mini=INT_MAX,count=0,len=word[0].length();
        vector<int  > v[n];  
        queue<pair<string ,int> > q;
        pair<string,int> p;
        vector<bool>vis(n+1,false);
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
			   		return p.second+1; 
				}
			   	q.push(make_pair(word[i],p.second+1));
			   	vis[i]=true;
			   }
	        }
	        
   	   }
        
        
        
        
        
        
        
        
        return 0;
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
cout<<s.ladderLength(b,e,word);
}
