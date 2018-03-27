#include<bits/stdc++.h>
using namespace std;
class Solution
{
	public:vector<int> grayCode(int n);
};
vector<int> current;
int convert(vector<int> &a,int n)
{
   int num=0,c=0,i;
   for(i=n-1;i>=0;i--)
   {
       num=num+a[i]*pow(2,c);
       c++;
   }
 //  cout<<"num= "<<num<<endl;
   return num;
}

bool valid(vector<int> &a, vector<int> &b,int n)
{
    int count=0,i=0;
    cout<<"Testing\n";
    cout<<convert(a,n)<<" "<<convert(b,n)<<endl;
    for(i=0;i<n;i++)
    {
        if(a[i]!=b[i])
        {
            count++;
        }
    }
    if(count>1)
    return false;
    return true;
}

void myfun(vector<int> a,int &pos,vector<int> &prev,int n)
{
    int i;
    if(valid(a,prev,n))
    {
    prev=a;
    current.push_back(convert(a,n));
    }
    else
    {
    	pos--;
    	return ;
	}
    for(i=pos-1;i>=0;i--)
    {
        a[i]=1;
        myfun(a,i,prev,n);
        a[i]=0;
    }
}
vector<int> Solution::grayCode(int n) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> a;
    int i;
    
    for(i=0;i<n;i++)
    {
        a.push_back(0);
    }
    current.clear();
    vector<int>prev;
    prev=a;
    myfun(a,n,prev,n);
    
    return current;
    
    
}
int main()
{
	vector<int> ans;
	int n;
	cin>>n;
	Solution s;
	ans=s.grayCode(n);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<endl;
	}
	
}


