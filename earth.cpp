#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct st
{
    int a;
    int b;
    int ind;
};
INT_MAX;
bool comp(st s1,st s2)
{
    return s1.a<s2.a;
}

int main()
{
    int n;
    cin>>n;
    int a[n],b[n],i;
    st s[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        s[i].a=a[i];
        s[i].ind=i;
    }
    for(i=0;i<n;i++)
    {
        cin>>b[i];
        s[i].b=b[i];
    }
    sort(s,s+n,comp);
//    for(i=0;i<n;i++)
//    {
//        cout<<s[i].a<<"  "<<s[i].b<<"  "<<s[i].ind<<endl;
//    }
    int count=0,output[n],k,j;
    for(i=0;i<n;)
    {
       for(j=i+1;j<n-1;j++)
       {
           if(a[i]==a[j])
           {
              count++;
           }
           else
           {
               int ma=INT_MIN;
             //  cout<<"Fi ,fj= "<<i<<"  "<<j<<endl;
               for(k=i;k<=j;k++)
               {
                   if(s[k].b>ma)
                   {
                       ma=s[k].b;
                   }
               }
               //cout<<"i,j= "<<i<<"  "<<j<<endl;
               for(k=i;k<=j;k++)
               {
                //cout<<ma<<" "<<s[k].ind<<endl;
               output[s[k].ind]=ma;
               
               }
               if(j==n-2)
               output[s[n-1].ind]=s[n-1].b;
               i=i+j+1;
           }
       }
      
    }
    
    for(i=0;i<n;i++)
    cout<<output[i]<<"  ";
    
    return 0;
}

