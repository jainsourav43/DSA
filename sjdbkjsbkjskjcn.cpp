#include<bits/stdc++.h>
using namespace std;



class Solution
{
	public :vector<vector<int> > fourSum(vector<int> &a, int sum) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int > > ans;
    vector<int> current;
      int i,n=a.size(),j,k;
      int l,r;
    int count1=0;
     sort(a.begin(),a.end());
     for(i-0;i<n;i++) cout<<a[i]<<" ";
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
                
          l=j+1;r=n-1;
          while(l<=r)
          {
         cout<<a[i]<<" "<<a[j]<<"  "<<a[l]<<" " <<a[r]<<endl;
          if(a[i]+a[j]+a[l]+a[r]==sum)
          {
             
                    current.clear();
                    current.push_back(a[i]);
                    current.push_back(a[j]);
                    current.push_back(a[l]);
                    current.push_back(a[r]);
            //        sort(current.begin(),current.end());
                    ans.push_back(current);
                    l++;
          }
          else if(a[i]+a[j]+a[l]+a[r]<sum)
          {
              l++;
          }
          else
          {
              r--;
          }
          }
        //   while(j<n&&a[j]==a[j+1])
        //   {
        //       j++;
        //   }
        }
        // while(i<n&&a[i]==a[i+1])
        // i++;
    
    }
    
   
    
    
   
//     for (size_t i = 0; i < ans.size(); ++i)
// 	{
// 	    CompareVec comparator(ans[i]);
// 	    ans.erase(std::remove_if(ans.begin()+i+1, ans.end(), comparator), ans.end());
// 	}

    return ans;
    
    
    
    
    
    
}
};
int main()
{
	Solution s;
	vector<int > a;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
	int sum=0;
	cin>>sum;
	s.fourSum(a,sum);
}
