#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int a[26]={0},b[26]={0};
        int len=s.length(),i,j;
            if(len%2)
            {
            cout<<-1<<endl;
        }
        else
            {
        for(i=0;i<len/2;i++)
        {
            a[s.at(i)-'a']++;
        }
        for(j=len/2;j<len;j++)
        {
            b[s.at(j)-'a']++;
        }
            
         //   for(i=0;i<26;i++)
           //     cout<<"a,b = "<<a[i]<<"  "<<b[i]<<endl;
            int count1=0;
         for(i=0;i<26;i++)
         {
             if(b[i]>a[i])
             {
                 count1+=b[i]-a[i];
             }
         }
            
            cout<<count1<<endl;
        }
    }
    return 0;
}

