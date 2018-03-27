#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

double ans=INT_MIN;
void dfs(vector < vector<double> > &a,int count,long long int cur,int pos ,int f,int n,int m)
{
	
	
	cout<<"cur,count ,pos="<<cur<<" "<<count<<"  "<<pos<<endl;
	
    if(pos==f&&count==m)
    {
        if(cur>ans)
        {
            ans=cur;
        }
        return ;
        
        
    }
    else if(count>=m)
    return ;
    int i;
    for(i=0;i<n;i++)
    {
        if(i==pos)
        continue;
        cur=(cur*(int )a[pos][i])%mod;
        count++;
        dfs(a,count,cur,i,f,n,m);
        count--;
        cur=cur/a[pos][i];
    }
    
    
    
    
}
double currencies(int n, int x, int s, int f, int m, vector < vector<double> > a) {
    // Complete this function
    
  /*  vector<vector < int >> a;
    
    
    for(int i=0;i<n;i++)
    {
        vector<int > c;
        for(j=0;j<n;j++)
        {
            c.push_back((int)A[i])
        }
    }*/
    int cur=x;
    ans=INT_MIN;
    dfs(a,0,cur,s,f,n,m);
    return ans;
        
}

int main() {
    int n;
    cin >> n;
    int x;
    int s;
    int f;
    int m;
    cin >> x >> s >> f >> m;
    vector< vector<double> > A(n,vector<double>(n));
    for(int A_i = 0;A_i < n;A_i++){
       for(int A_j = 0;A_j < n;A_j++){
          cin >> A[A_i][A_j];
       }
        
        
        
    }
            cout<<currencies(n,x,s,f,m,A)<<endl;

    return 0;
}

