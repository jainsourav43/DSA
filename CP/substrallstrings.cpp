#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string.h>
using namespace std;
    int n;
string s1[11],login;
bool recur(int pos,int len,string my)
{
    len+=s1[pos].length();
    my=my+s1[pos];
    cout<<"my = "<<my.substr(0,len)<<endl;
    if(my.substr(0,len)==login)
    return 1;
    for(int i=0;i<n;i++)
    {
        recur(i,len,my);
    }
    len=len-s1[pos].length();
    return 0;
}



int main() {
    
    int t;
    cin>>t;
    while(t--)
    {

    cin>>n;
    
        for(int i=0;i<n;i++)
        {
            cin>>s1[i];
        }
        
        cin>>login;
        bool an;
        for(int i=0;i<n;i++)
        {
           // len=0;
           string my;
           cout<<"calling for = "<<s1[i]<<endl;
           an= recur(i,0,my);
            if(an)
            {
                an=1;
                break;
            }
        }
        if(an) cout<<"gotit\n";
        else
            cout<<"wrong\n";
    //    string s2,s3,s4;
      //  s4=s3-s2;
            
            
            
        
        
        
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

