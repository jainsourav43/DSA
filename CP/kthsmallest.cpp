#include<iostream>
using namespace std;
#include<bits/stdc++.h>
void perculateup(int j,int a[],int size)
{
    if(j>1&&a[j]>=a[j/2])
    {
        swap(a[j],a[j/2]);
        perculateup(j/2,a,size);
    }
    
}
void perculatedown(int j,int a[],int size)
{
 int k1=INT_MIN,k2=INT_MIN,in1,in2;
    if(size>=2*j&&a[j]<=a[2*j])
    {
        in1=2*j;
        k1=a[2*j];
    }
    if(size>=2*j+1&&a[j]<=a[2*j+1])
    {
        in2=2*j+1;
        k2=a[2*j+1];
    }
    if(k1>k2)
    {
        swap(a[j],a[2*j]);
        perculatedown(2*j,a,size);
    }
    else if(k1<k2)
    {
        swap(a[j],a[2*j+1]);
        perculatedown(2*j+1,a,size);
    }
    else if(k1==k2&&k1!=INT_MIN)
    {
    	swap(a[j],a[2*j+1]);
        perculatedown(2*j+1,a,size);
	}
    
}
void deleteit(int a[],int &size)
{
    a[1]=a[size];
    size--;
    perculatedown(1,a,size);
}
int getmin(int a[])
{
    return a[1];
}

void insert(int key,int a[],int &size)
{
    size++;
    a[size]=key;
   
    perculateup(size,a,size);
    
}


class Solution
{
	public :kthsmallest(const vector<int> &A, int k) ;
};
int Solution::kthsmallest(const vector<int> &A, int k) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int a[k+1];
    int size=0;
    int i=0,n=A.size();
    for(i=0;i<k;i++)
    {
        insert(A[i],a,size);
    }
//    for(int j=1;j<=k;j++)
//         {
//         	cout<<a[j]<<"  ";
//		 }cout<<endl;
     for(i=k;i<n;i++)
     {
     //	cout<<"max="<<getmin(a)<<endl;
         if(getmin(a)>=A[i])
         {
         deleteit(a,size);
         //cout<<"max2="<<getmin(a)<<endl;
        // cout<<"MyHeap\n";
        
         insert(A[i],a,size);
//          for(int j=1;j<=size;j++)
//         {
//         	cout<<a[j]<<"  ";
//		 }cout<<endl;
        // cout<<"max3="<<getmin(a)<<endl;
         }
     }
    return getmin(a);
    
}
int main()
{
	Solution s;
	vector<int >A;
	int n;
	cin>>n;
	int i;
	for(i=0;i<n;i++)
	{
	int x;
	cin>>x;
	A.push_back(x);
	}
	int k;
	cin>>k;
	
cout<<s.kthsmallest(A,k)<<endl;
}
