vector<int> Solution::twoSum(const vector<int> &a, int sum) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i,n=a.size(),index2=INT_MAX,index1=INT_MAX;
    unordered_map<int,int>m;
    for(i=n-1;i>=0;i--)
    {
        if(m.find(sum-a[i])==m.end())
        {
            m[a[i]]=i;
        }
        else
        {
            if(m[sum-a[i]]<index2)
            {
            index2=m[sum-a[i]];
            index1=i;
            }
            else if(m[sum-a[i]]==index2)
            {
                if(index1>i)
                {
                    index2=m[sum-a[i]];
                    index1=i;
                }
            }
            m[a[i]]=i;
            
        }
    }
    vector<int>ans;
    if(index1!=INT_MAX)
    {
        ans.push_back(index1+1);
        ans.push_back(index2+1);
    }
    
    return ans;
    

