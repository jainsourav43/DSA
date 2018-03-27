#include<bits/stdc++.h>
#include<cstdlib>
#include<stdlib.h>


bool comp(int a,int b)
{
         string s1,s2,s3,s4;
         stringstream convert;
         convert<<a;
         s1=convert.str();
         convert<<b;
         s2=convert.str();
         s3=s1+s2;
         s4=s2+s1;
         return s3>s4;
}
string Solution::largestNumber(const vector<int> &a) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
int n=a.size();
vector<int> b;
int i;
for(i=0;i<n;i++)
{
    b.push_back(a[i]);
}
sort(b.begin(),b.end(),comp);
string s1;
for(int i=0;i<n;i++)
{
//cout<<b[i]<<" ";
  stringstream convert;
convert<<b[i];
s1+=convert.str();
    
}
return s1;
    
}

