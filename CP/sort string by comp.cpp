#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
 
#define ll long long
 
using namespace std;
 
int n;
string s[100005];
int _t;
ll id[100005];
 
 
bool isitless(int a, int b)
{
	if (s[a].length() != s[b].length())
		return s[a].length() < s[b].length();
	if (s[a] != s[b])
		return s[a] < s[b];
	return a < b;
		
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> _t;
	for (int _i = 0; _i < _t; ++_i)
	{
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			cin >> s[i];
			id[i] = i;
		}
		sort(&id[1], &id[n + 1], isitless);
		ll ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			cout << s[id[i]] << " ";
			ans += id[i] * i;
		}
		cout << "\n" << ans << "\n";
	}
}
