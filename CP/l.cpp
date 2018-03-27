#include <cmath>
#include <cstdio>
#include <vector>
#include<string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#include<typeinfo>
#include<bits/stdc++.h>
#include<set>
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    while(n--)
    {
        char s1[100001],s2;
        cin>>s1;
        int len =strlen(s1);
        char *p=s1;
        int i,j,cost=1;
        for(i=1;i<len;)
        {
            if((2*i<=len))
            {
            	int j=2*i;
            if(strcmp((p+i-p+j,(p+0-p+i)))==0)
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

