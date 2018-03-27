#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int c[51],m;  long long total[250+1][51];
long long calc(int sum,int coins)
    {
    
    
    if(sum<0)
        return 0;
    else if(sum==0)
        {
        return 1;
    }
    else if(coins<=0)
        {
      // cout<<"SUM= "<<sum<<endl;
return 0;
    }
    else if(total[sum][coins]!=-1)
        {
        return total[sum][coins];
    }
    else{
        total[sum][coins]=calc(sum,coins-1)+calc(sum-c[coins-1],coins);
        
            
            
}
    
     return total[sum][coins];       
}
    


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int sum;
    cin>>sum>>m;
    int i,j;
    for(i=0;i<m;i++)
        {
        cin>>c[i];
    }
    for(i=0;i<sum+1;i++)
        for(j=0;j<m+1;j++) total[i][j]=-1;
  
   // for(i=0;i<=sum;i++) total[i]=0;
    //total[0]=0;
    
 long long  totala=calc(sum,m);
   // for(i=1;i<=sum;i++)
    cout<<totala<<endl;
    
    
    return 0;
}

