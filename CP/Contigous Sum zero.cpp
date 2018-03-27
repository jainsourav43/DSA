vector<int> Solution::lszero(vector<int> &a) {
    
    unordered_map<int,int>m;
    int temp,i1,i2,maxi=0;
    vector<int>ans;
    int i=0,n=a.size();
    int sum[n];
    sum[0]=a[0];
    m[sum[0]]=0;
    if(sum[0]==0)
    {
      maxi=1;
      i1=0;
      i2=0;
    }
    for(i=1;i<n;i++)
    {
      sum[i]=sum[i-1]+a[i];
      if(sum[i]==0)
      {
           temp=i+1;
          if(maxi<temp){
         maxi=temp;
          i1=0;
          i2=i;
          }
          
      }
       if(a[i]==0)
      {
          temp=1;
          if(maxi<temp)
          {
              maxi=temp;
              i1=i;i2=i;
          }
      }
       if(m.find(sum[i])==m.end())
      {
      m[sum[i]]=i;
      }
      else
      {
          temp=i-(m[sum[i]]);
          if(temp>maxi){ 
              i1=m[sum[i]]+1;
              i2=i;
              maxi=temp;
          }
      }
    }
    if(maxi>=1)
    for(i=i1;i<=i2;i++)
    {
        ans.push_back(a[i]);
    }
    return ans;
}

