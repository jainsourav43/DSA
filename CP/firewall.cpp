#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define maxn 300001
#define sigma 26
using namespace std;

int to[maxn][sigma],dp[maxn];
using namespace __gnu_pbds;
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
int calc(string &s)
{
	int len = s.length() + dp[0];
	int i;
	int cur = 0;
	int che=0;
	for( i = 0; i < s.length(); i++)
	{
		char c = s[i];
		cur = to[cur][c - 'a'];
		if(cur==0)
		{
			break;
		}
//		ans = min(ans, int(s.length()) + dp[cur] - 2*(i+1));
	}
	if(i<len)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
 
int main()
{
	ll n,i,j;
	cin>>n;
	string b[n+1],u[n+1],result[n+1],u1;
//	u1.begin();
	char c[n+1];
	ll l=0,m=0;
	string stri;
	for(i=0;i<maxn;i++) dp[i]=INF;
	for(i=0;i<n;i++)
	{
		cin>>c[i];
		if(c[i]=='+')
		{
			cin>>stri;
			add_str(stri);
			l++;
		}
		else
		{
			cin>>b[m++];
		}
	}
//	sort(b,b+m);
//	sort(u,u+l);
	ll r=0,ans=0;
	int temp;int che=0;
	set< string >se;
	for(i=0;i<m;i++)
	{
		temp=calc(b[i]);
		if(temp==-1)
		{
			che=1;
			break;
		}
		se.insert(se.end(),b[i].substr(0,temp+1));
	//	cout<<b[i].substr(0,temp+1);
	}
	if(se.size()==0|| che==1)
	cout<<-1<<endl;
	else
	{
	cout<<se.size()<<endl;
	typeof(se.begin()) it=se.begin();
	for(int i=0;it!=se.end();i++)
	{
		cout<<*it<<" \n";
		it++;
	}
	}
	
} 
