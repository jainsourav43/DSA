#include <cmath>
#include <cstdio>
#include <vector>
#include<string.h>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    while(n--)
    {
        string s1,s2;
        cin>>s1;
        int len =s1.length();
        int i,j,cost=1;
        s2.push_back(s1.at(0));
        cout<<"s  ="<<s1.substr(1,2)<<endl;
        for(i=1;i<len;)
        {
            if((2*i<=len))
            {
            	cout<<"i,s1,s2 = "<<i<<"  "<<s1.substr(i,2*i)<<"  "<<s1.substr(0,i)<<endl;
            if(s1.substr(i,2*i)==s1.substr(0,i))
            {
                i=2*i;
            }
            else
           {
               cost++;
               i++;
           }
            }
           else
           {
               cost++;
               i++;
           }
        }
        cout<<cost<<endl;
    }
    return 0;
}

