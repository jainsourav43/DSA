#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;
 
const int MAXN = 300001;
const int sigma = 26;
 
int to[MAXN][sigma];
int dp[MAXN];
int sz = 1;
 
void add_str(string s)
{
    int cur = 0;
    for(int i = 0; i < s.length(); i++)
    {
		char c = s[i];
		dp[cur] = min(int(s.length()), dp[cur]);
        if(!to[cur][c - 'a'])
        {
            to[cur][c - 'a'] = sz++;
        }
        cur = to[cur][c - 'a'];
    }
    dp[cur] = min(int(s.length()), dp[cur]);
}
 
const int INF = 1000000000;
 
int calc(string &s)
{
	int ans = s.length() + dp[0];
	int cur = 0;
	for(int i = 0; i < s.length(); i++)
	{
		char c = s[i];
		cur = to[cur][c - 'a'];
		if(cur == 0) break;
		ans = min(ans, int(s.length()) + dp[cur] - 2*(i+1));
	}
	return ans;
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(int i = 0; i < MAXN; i++) dp[i] = INF;
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		string s; cin >> s;
		add_str(s);
	}
	//cerr<<"DP 0 = "<<dp[0]<<'\n';
	int q; cin >> q;
	while(q--)
	{
		string s; cin >> s;
		cout << calc(s) << '\n';
	}
}
 
