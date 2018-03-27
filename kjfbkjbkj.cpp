#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    bool myfun1(string s1,string s2,string s3,int i,int j,int len1,int len2)
    {
        
        if(i==len1&&j==len2)
        {
        	cout<<"I,j,= "<<i<<"  "<<j<<endl;
        	cout<<"IF 1\n";
            return true;
        }
        else if(i==len1)
        {
			cout<<"I,j,= "<<i<<"  "<<j<<endl;
        	cout<<"IF 2\n";
        	while(j<len2&&s2[j]==s3[i+j])
        	{
        		j++;
			}
        	if(j==len2)
        	{
        		return true;
			}
            return false;
        }
        else if(j==len2)
        {
        	while(i<len1&&s1[i]==s3[i+j])
        	{
        		i++;
			}
			if(i==len1)
			{
				return true;
			}
			return false;
		}
        cout<<"s1,s2,s3= "<<s1[i]<<"  "<<s2[j]<<"  "<<s3[i+j]<<endl;
         if(s1[i]==s3[i+j]&&s2[j]!=s3[i+j])
        {cout<<"I,j,= "<<i<<"  "<<j<<endl;
			cout<<"IF 3\n";
           return  myfun1(s1,s2,s3,i+1,j,len1,len2);
        }
        else if(s2[j]==s3[i+j]&&s1[i]!=s3[i+j])
        {cout<<"I,j,= "<<i<<"  "<<j<<endl;
           cout<<"IF 4\n";
           return myfun1(s1,s2,s3,i,j+1,len1,len2); 
        
        }
        else if(s2[j]==s3[i+j]&&s1[i]==s3[i+j])
        {
        	cout<<"Spec\n";
        	cout<<"I,j,= "<<i<<"  "<<j<<endl;
           if(!myfun1(s1,s2,s3,i+1,j,len1,len2))
           {cout<<"I,j,= "<<i<<"  "<<j<<endl;
           		cout<<"IF 5\n";
               return myfun1(s1,s2,s3,i,j+1,len1,len2) ;
            }
            else
            {cout<<"I,j,= "<<i<<"  "<<j<<endl;
             cout<<"IF 6\n";
             return true;   
            }   
        }
        else
        {
        	return false;
		}
    }
    
    
    
    
    
    
    
        bool myfun(string s1,string s2,string s3,int i,int j,int len1,int len2,vector<vector< int> > &dp)
    {
            if(dp[i][j]!=-1)
                return dp[i][j];
        
        if(i==len1&&j==len2)
        {
        	//cout<<"I,j,= "<<i<<"  "<<j<<endl;
        	//cout<<"IF 1\n";
            return dp[i][j]=true;
        }
        else if(i==len1)
        {
			//cout<<"I,j,= "<<i<<"  "<<j<<endl;
        	//cout<<"IF 2\n";
        	while(j<len2&&s2[j]==s3[i+j])
        	{
        		j++;
			}
        	if(j==len2)
        	{
        		return dp[i][j]=true;
			}
            return dp[i][j]=false;
        }
        else if(j==len2)
        {
        	while(i<len1&&s1[i]==s3[i+j])
        	{
        		i++;
			}
			if(i==len1)
			{
				return dp[i][j]=true;
			}
			return dp[i][j]=false;
		}
     //   cout<<"s1,s2,s3= "<<s1[i]<<"  "<<s2[j]<<"  "<<s3[i+j]<<endl;
         if(s1[i]==s3[i+j]&&s2[j]!=s3[i+j])
        {
             
             //cout<<"I,j,= "<<i<<"  "<<j<<endl;
			 //cout<<"IF 3\n";
           return dp[i][j]= myfun(s1,s2,s3,i+1,j,len1,len2,dp);
        }
        else if(s2[j]==s3[i+j]&&s1[i]!=s3[i+j])
        {
            //cout<<"I,j,= "<<i<<"  "<<j<<endl;
           //cout<<"IF 4\n";
           return dp[i][j]= myfun(s1,s2,s3,i,j+1,len1,len2,dp); 
        
        }
        else if(s2[j]==s3[i+j]&&s1[i]==s3[i+j])
        {
        	//cout<<"Spec\n";
        	//cout<<"I,j,= "<<i<<"  "<<j<<endl;
           if(!myfun(s1,s2,s3,i+1,j,len1,len2,dp))
           {
               //cout<<"I,j,= "<<i<<"  "<<j<<endl;
           		//cout<<"IF 5\n";
               return dp[i][j] = myfun(s1,s2,s3,i,j+1,len1,len2,dp);
            }
            else
            {
            //cout<<"I,j,= "<<i<<"  "<<j<<endl;
             //cout<<"IF 6\n";
            return dp[i][j]=true;  
            }   
        }
        else
        {
        	return dp[i][j]=false;
		}
    }
    
    
    
    bool isInterleave(string s1, string s2, string s3) {
        
        int n=s1.length(),m=s2.length(),l=s3.length();
        
        if(n+m!=l)
        {
            return false;
        }
     //   return myfun(s1,s2,s3,0,0,n,m,dp);
    //  
        
        
        
    }
};
int main()
{
	string s1,s2,s3;
	cin>>s1>>s2>>s3;
	int n=s1.length(),m=s2.length();
	Solution s;
	    vector< vector< int> > dp;
        vector<int> curr;
        int i,j;
        
        for(i=0;i<=n;i++)
        {
            curr.clear();
            for(j=0;j<=m;j++)
            {
                curr.push_back(-1);
            }
            dp.push_back(curr);
        }
	cout<< s.myfun(s1,s2,s3,0,0,n,m,dp);
	
}
