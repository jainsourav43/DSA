#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n,x;    int count1=0;

int recur(int pos,int sum)
    {
    	sum=sum-pow(pos,n);	cout<<"sum = "<<sum<<endl;
    if(sum<0)
        return 0;
    else if(sum==0)
    {    

    	count1++;
	}
        else
        {
        for(int j=pos+1;sum>=pow(j,n);j++)
            {
            
             recur(j,sum);
             }
                         sum+=pos*pos;

          }
    
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin>>x>>n;
    for(int i=1;x>=pow(i,n);i++)
        {
        	cout<<"in";
         recur(i,x);
         
       
    }
    cout<<count1<<endl;
    
    
    
    
    return 0;
}

