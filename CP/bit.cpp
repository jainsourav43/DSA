vector<vector <int> >v[100];
void func(int pos,int count,int k,int n,int c)
{
    int i;
    if(count<=k)
    {
        v[c].push_back(pos);
    }
    for(i=pos+1;i<=n;i++)
    {
     func(i,count+1,k,n,c+1);   
    }
    v[c].pop_back();
    
    
    
}


vector<vector<int> > Solution::combine(int n, int k) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int c=0;    
    int i;
    for(i=1;i<=n-k+1;i++)
    {
        func(i,0,k,c);
        c++;
    }
    return v;
    
}

