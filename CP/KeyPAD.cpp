#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long 
vector<int> next1[10];
void myfun(int pos,int n,int &sum)
{
    int i; 
    if(n==0)
    {
    	sum++;       
        return ;
    }
    else
    {
    	
        for(i=0;i<next1[pos].size();i++)
        {
            myfun(next1[pos][i],n-1,sum);
            
        }
    }
}
int main()
{
    
    
    next1[0]={0,8};
    next1[1]={1,2,4};
    next1[2]={1,2,3,5};
    next1[3]={2,3,6};
    next1[4]={1,4,7,5};
    next1[5]={2,4,5,6,8};
    next1[6]={3,5,6,9};
    next1[7]={4,7,8};
    next1[8]={0,5,7,8,9};
    next1[9]={6,8,9};
    int t;
    cin>>t;
  
    
    while(t--)
    {
        long long  int n,i;
        cin>>n;
    int count[10][n];
    for(i=0;i<=9;i++)
    count[i][0]=1;
    
	count[0][1]=2;
	count[1][1]=3;
	count[2][1]=4;
	count[3][1]=3;
	count[4][1]=4;
	count[5][1]=5;
	count[6][1]=4;
	count[7][1]=3;
	count[8][1]=5;
	count[9][1]=3;
       long long int sum=0;
       for(i=1;i<n;i++)
       {
         
	   }
		cout<<sum<<endl;
   
    }
    
	return 0;
}
