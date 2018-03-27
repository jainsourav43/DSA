

#include<bits/stdc++.h>
using namespace std;
class Solution
{
	public :int  removeDuplicates(vector<int> &a);
};
int Solution::removeDuplicates(vector<int> &a) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i,n=a.size();
       vector<int> :: iterator it1=a.end(),it2=it1,it3,it4=a.end();
       it4--;
    it1--;
    it2--;
    it2--;
    int count1=0;
    for(i=0;i<n-1;i++)
    {
    	
        if(*it1==*it2&&count1==1)
        {
         it3=it2;
         swap(*it1,*it4);
		it4--;	
         a.pop_back();
         it2--;
         it1=it3;
        }
        else if(*it1==*it2)
        {
        	count1++;
        	it1--;
        	it2--;
		}
        else
		{
        it1--;
        it2--;
        count1=0;
        }
    }
    sort(a.begin(),a.end());
//    cout<<endl;
//for(int i=0;i<a.size();i++)
//cout<<a[i]<<endl;
//cout<<a.size()<<" ";
    return a.size();
    
    
    
}
int main()
{
	Solution s;
	vector<int> a;
	int n;
	cin>>n;
	int i=0;
	for(i=0;i<n;i++)
	{
int x;
cin>>x;	
	a.push_back(x);
}
s.removeDuplicates(a);
//	s.removeDulplicates(a);
}
