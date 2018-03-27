#include<bits/stdc++.h>

#define x first
#define y second
#define y0 hi1
#define y1 hi2
#define ll long long
#define mp make_pair
#define pb push_back
#define sqr(a) (a)*(a)
#define ld long double
#define all(a) (a).begin(), (a).end()

using namespace std;

const int md = 1e9 + 7;

vector<int> getpos(string s, string t){
    s = t + "#" + s;
    int n = s.length();
    int m = t.length();

    int p[n];
    p[0] = 0;
    for(int i = 1; i < n; i++){
        int j = p[i - 1];
        while(j > 0 && s[i] != s[j]){
            j = p[j - 1];
        }
        if(s[i] == s[j])j++;
        p[i] = j;
    }

    vector<int> ans;
    for(int i = m + m; i < n; i++){
        if(p[i] == m){
            ans.pb(i - m);
        }
    }

    return ans;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--){
        string s, t;
        cin >> s >> t;
        int n = s.length();
        int m = t.length();

        vector<int> pos = getpos(s, t);
        bool a[n + 1];
        memset(a, 0, sizeof(a));
        for(int i = 0; i < pos.size(); i++){
            a[pos[i]] = true;
        }

        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for(int i = 1; i <= n; i++){
            if(a[i]){
                dp[i] = (dp[i] + dp[i - m]) % md;
            }
            dp[i] = (dp[i] + dp[i - 1]) % md;
        }

        cout << (dp[n] - 1 + md) % md << "\n";
    }
}
