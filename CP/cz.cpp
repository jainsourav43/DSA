   #include<bits/stdc++.h>
   using namespace std;
    int max(int a,int b,int c)
    {
        if(a>=b&&a>=c)
        {
            return a;
        }
        else if(b>=a&&b>=c)
        {
            return b;
        }
        return c;
    }
      int min1(int a,int b,int c)
    {
        if(a<=b&&a<=c)
        {
            return a;
        }
        else if(b<=a&&b<=c)
        {
            return b;
        }
        return c;
    }
  
    /* Function to get index of floor of x in
   arr[low..high] */
class Solution
{
public:int minimize(const vector<int> &a,const vector<int> &b,const vector<int> &c);
};
int Solution::minimize(const vector<int> &a, const vector<int> &b, const vector<int> &c) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
       int ans=INT_MAX,ma=INT_MIN,i,j,k,a1,a2,a3,b1,b2,b3,c1,d1,d2,d3,ans1,ans2,ans3,ans4;
    int n1=a.size(),n2=b.size(),n3=c.size(),mi=INT_MAX;
    for(i=0;i<n1;i++)
    {
        int p1=upper_bound(b.begin(),b.end(),a[i])-b.begin();
        int p2=upper_bound(c.begin(),c.end(),a[i])-c.begin();
       // cout<<"p1,p2= "<<p1<<" "<<p2<<endl;
        if(p1==n2)
        p1--;
        if(p2==n3)
        p2--;
        a1=a2=b1=b2=c1=INT_MAX;
        ans1=ans2=ans3=ans4=INT_MAX;
        a1=a[i];
        b1=b[p1];
        c1=c[p2];
        ans1=abs(max(a1,b1,c1)-min1(a1,b1,c1));
    	if(p1>0)
    	{
        a1=a[i];
        b1=b[p1-1];
        c1=c[p2];
    	ans2=abs(max(a1,b1,c1)-min1(a1,b1,c1));
		}
		if(p2>0)
		{
         a1=a[i];
        b1=b[p1];
        c1=c[p2-1];
    	ans3=abs(max(a1,b1,c1)-min1(a1,b1,c1));
		}
		
		if(p1>0&&p2>0)
		{
         a1=a[i];
        b1=b[p1-1];
        c1=c[p2-1];
    	ans4=abs(max(a1,b1,c1)-min1(a1,b1,c1));
		}
		mi=min(mi,ans1);
		mi=min(mi,ans2);
		mi=min(mi,ans3);
		mi=min(mi,ans4);

    }
    cout<<mi<<endl;
    return mi;
}
int main()
{
	Solution s;
	int n1,n2,n3;
	cin>>n1;
	int x;
	vector<int> a,b,c;
	while(n1--)
	{
		cin>>x;
		a.push_back(x);
	}
		cin>>n2;
	while(n2--)
	{
		cin>>x;
		b.push_back(x);
	}
		cin>>n3;
	while(n3--)
	{
		cin>>x;
		c.push_back(x);
	}
	s.minimize(a,b,c);
}
