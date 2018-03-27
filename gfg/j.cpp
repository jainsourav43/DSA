#include <bits/stdc++.h>
#include<map>
map<string,bool>v;
map<string,int>ma;
using namespace std;
int fastexpo(int a,int p,int m)
{
  int ans=1;
    while(p)
    {
        if(p&1)
        {
            ans=(ans*a)%m;
        }
        a=(a*a)%m;
        p>>=1;
    }
    return ans;
}
int getnumber(string s,int b,int m)
{
 int len=s.length(),sum=0;
    int a,i,count=0;
    for(i=len-1;i>=0;i--)
    {
           a=s.at(i)-'0';
           sum=(sum+(a*fastexpo(b,count,m))%m)%m;
             count++;
    }
    return sum;
}
int getMagicNumber(string s, int k, int b, int m){
    // Complete this function
    int len =s.length(),i,j,in=0,sum=0;
    string temp; 
    for(i=0;i<len;i++)
    {
     if(s.at(i)=='0')
         {continue;}
        else
            {
            in=i;
            break;
            }
            
    }
    for(i=in;i<len-k+1;i++)
    {
        temp=s.substr(i,k);
        if(v[temp]==false)
         {  
         int te=getnumber(temp,b,m);
            ma[temp]=te;
            sum=sum+te;
            v[temp]=true;
        }
        else
        {
            sum+=ma[temp];
        }
    }
    return sum;
    
}

int main() {
    string s;
    cin >> s;
    int k;
    int b;
    int m;
    cin >> k >> b >> m;
    int result = getMagicNumber(s, k, b, m);
    cout << result << endl;
    return 0;
}

