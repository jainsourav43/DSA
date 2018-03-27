
#include<bits/stdc++.h>
#include<vector>
using namespace std;

struct p1
{
    int num;
    int in;
};
int maxArr(vector<int> &a) {
    
    int i,j;
    
    int n=a.size();
    sort(a.begin(),a.end());
     p1 p[n];
    int dp[n];
    for(i=0;i<n;i++)
    {
        p[i].num=a[i];
        p[i].in=i;
         dp[i]=0;
    }
   
    for(i=1;i<n;i++)
    {
    	dp[i]=max(abs(a[i]-a[i-1])+abs(i-(i-1)),dp[i-1]);
    }
    for(i=0;i<n;i++) cout<<"dp[i] = "<<dp[i]<<" "; cout<<endl;
   // dp[n-1];
    return dp[n-1];
}
int main()
{
	int n;
	cin>>n;
	vector<int >a;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		a.push_back(t);
	}
	int ans=maxArr(a);
	cout<<ans<<endl;
}

