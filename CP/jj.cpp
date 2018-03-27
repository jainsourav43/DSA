#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
int a[200002],size=0;
void perculateup(int j)
{
    if(j>1&&a[j]<a[j/2])
    {
        swap(a[j],a[j/2]);
        perculateup(j/2);
    }
    
}
void perculatedown(int j)
{
 int k1=INT_MAX,k2=INT_MAX,in1,in2;
    if(size>=2*j&&a[j]>a[2*j])
    {
        in1=2*j;
        k1=a[2*j];
    }
    if(size>=2*j+1&&a[j]>a[2*j+1])
    {
        in2=2*j+1;
        k2=a[2*j+1];
    }
    if(k1<k2)
    {
        swap(a[j],a[2*j]);
        perculatedown(2*j);
    }
    else if(k1>k2)
    {
        swap(a[j],a[2*j+1]);
        perculatedown(2*j+1);
    }
}
void deleteme(int key,int j)
{
    
    if(a[j]==key)
    {
        a[j]=a[size];
        size--;
        perculatedown(j);
    }
    else
    {
        int k1=INT_MIN,k2=INT_MIN;
      if(size>=2*j&&key>a[2*j])
       {
       		
        	k1=a[2*j];  
       }
       if(size>=2*j+1&&key>a[2*j+1])
       {
           k2=a[2*j+1];
       }
       if(k1>k2)
       {
       	deleteme(key,2*j);
	   }
	   else if(k2>k1)
	   {
	   	deleteme(key,2*j+1);
	   }
 
        
    }

}
void deleteit()
{
    a[1]=a[size];
    size--;
    perculatedown(1);
}
int getmin()
{
    return a[1];
}

void insert(int key)
{
    size++;
    a[size]=key;
   
    perculateup(size);
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    
    int q,i;
    cin>>q;
    for(i=0;i<q;i++)
    {
        int q1,v;
        cin>>q1;
        if(q1==1)
        {
            cin>>v;
            insert(v);
        }
        else if(q1==2)
        {
            cin>>v;
            deleteme(v,1);
        }
        else
        {
         //   cout<<"Hii\n";
            cout<<getmin()<<endl;
            
         }
    }
    return 0;
}

