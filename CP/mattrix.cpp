/*int *dp;
long long fact(int x)
{
    if(x==1 || x==2)
        return dp[x] = x;
    if(dp[x]!=-1)  
        return dp[x];
    return dp[x]=(x*fact(x-1))%1000000007;
}*/
long long fac(int x)
{
    return x==1 ? 1 : (x*fac(x-1))%1000000007;
}
long long pow1(long long a,long long b)
{
    if(b==1)
        return a;
    if(b%2==0)
    {
        long long ret = pow1(a,b/2);
        return (ret*ret)%1000000007;
    }
    else
    {
        long long ret = pow1(a,b/2);
        return (((ret*ret)%1000000007)*a)%1000000007;
    }
}

bool valid(vector<int> v,int part)
{
    for(int i=1;i<v.size();i++)
    {
        for(int j=0;j<part-1;j++)
        {
            if(v[i]<v[i-1])
                return false;
            i++;    
        }
    }
    return true;
}

int Solution::cntMatrix(vector<int> &A) {
   /* dp = new int[100000];
    for(int i=0;i<100000;i++)
        dp[i] = -1;*/
    int i=1,cnt=1,mn=INT_MAX;
    while(i<A.size())
    {
        while(i<A.size()  and A[i]>A[i-1])
            cnt++,i++;
        if(i==A.size())
            break;
        mn = min(cnt,mn);
        i++;
        cnt = 1;
    }
    mn = min(cnt,mn);
    long long ans = 1;
    for(int i=mn;i>1;i--)
    {
        if(mn%i==0 and A.size()%i==0)
        {
            if(!valid(A,i))
                continue;
            ans += pow1(fac(i),A.size()/i);
            ans %= 1000000007;
        }
    }
    return ans;
}

