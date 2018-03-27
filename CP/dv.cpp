#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int to[60][26];
int sz=1;
void  add_str(string s)
{
    int cur = 0;
    for(int i = 0; i < s.length(); i++)
    {
		char c = s[i];
//	dp[cur] = min(int(s.length()), dp[cur]);
        if(!to[cur][c - 'a'])
        {
            to[cur][c - 'a'] = sz++;
        }
        cur = to[cur][c - 'a'];
    }
  //  dp[cur] = min(int(s.length()), dp[cur]);
}
const int INF = 1000000000;
bool calc(string &s)
{
	int len = s.length() ;
	int i;
	int cur = 0;
	int che=0;
	for( i = 0; i < s.length(); i++)
	{
		char c = s[i];
		if(to[cur][c-'a']==0)
		return false;
		cur = to[cur][c - 'a'];
		
//		ans = min(ans, int(s.length()) + dp[cur] - 2*(i+1));
	}
	return true;
}
 
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    int i;
    string s[n+1];
    for(i=0;i<n;i++)
    {
        cin>>s[i];
    }
    int j,k;
    for(i=0;i<n;i++)
    {
    add_str(s[i]);
    for(j=0;j<60;j++);
    {
    	for(k=1;k<26;k++)
    	{
    		cout<<to[j][k]<<" ";
		}
		cout<<endl;
	}
    }
    if(i==n)
    {
        cout<<"GOOD SET\n";
    }
    return 0;
}

