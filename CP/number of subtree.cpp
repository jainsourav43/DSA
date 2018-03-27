#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> g[1000000+10];
long long mod = 1e9 + 7,dp[100000+10];
long long tem;
 
long long dpsum(int n){
    tem=0;
 
    for(int i=1;i<=n;i++){//make i=1 and add equality
        tem = (tem + dp[i])%mod;
    }
    return tem;
}
 
void dfs(int n,int p=-1){
    dp[n]=1;
 
    for(int i=0;i<g[n].size();i++){
        if(g[n][i] != p){
            dfs(g[n][i],n);
 
            //increment dp[g[n][i]] by 1
            tem = dp[g[n][i]]+1;
            if(tem >= mod) tem -= mod;
 
            //use incremented dp[g[n][i]] and use % to calculate mod
            dp[n] = (dp[n] * tem)%mod;
            cout<<"dp = "<<dp[n]<<endl;
        }
    }
}
 
int main(){
    int t;
    scanf("%d",&t);
 
    int v,x,y;
    while(t--){
        scanf("%d",&v);
        for(int i=0;i<v-1;i++){
            scanf("%d %d", &x , &y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
 
        dfs(v);
        printf("%lld\n", dpsum(v));
 
        //clear the graph for next test case
        for(int i=0;i<v+1;i++) g[i].clear();
    }
    return 0;
}
