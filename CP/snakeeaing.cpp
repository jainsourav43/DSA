#include <bits/stdc++.h>
using namespace std;
#define FORE(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORIT(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define X first
#define Y second
#define ll long long
#define mp make_pair
#define pb push_back
#define all(a) a.begin(),a.end()
#define sqr(x) (x)*(x)
#define endl '\n'
 
template <typename G> inline void read(G &x)
{
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do{x = x*10 + c - '0';} while(isdigit(c = getchar()));
}
 
template <typename G> inline void write(G x)
{
    if (x > 9) write(x/10);
    putchar(x%10 + '0');
}
 
template <class T> inline T min(T a,T b,T c){ return min(a,min(b,c)); }
template <class T> inline T min(T a,T b,T c,T d) { return min(a,min(b,c,d)); }
template <class T> inline T max(T a,T b,T c){ return max(a,max(b,c)); }
template <class T> inline T max(T a,T b,T c,T d) { return max(a,max(b,c,d)); }
 
 
 
const int MAXN = 1e5 * 5;
const int base = 1e9 + 7;
const int N = 5000;
 
 
int t,n,q;
int a[MAXN];
ll s[MAXN];
 
int query(int x)
{
    int ri = lower_bound(a+1,a+n+1,x) - a - 1;
    //if (ri == 0) return n;
    int le = 1;
    int ans = ri+1;
    int xx = ri;
    while(le <= ri)
    {
        int mid = (le + ri)>>1;
        ll ss = 1ll*(xx-mid+1)*x - (s[mid] - s[xx+1]);
        if (ss > mid - 1) le = mid + 1;
        else
        {
            ri = mid - 1;
            ans = mid;
        }
    }
    return n - ans + 1;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("snakeeat.inp", "r", stdin);
    freopen("snakeeat.out", "w", stdout);
    #endif
    read(t);
    while(t--)
    {
        read(n); read(q);
        FORE(i,1,n) read(a[i]);
        sort(a+1,a+n+1);
        s[n+1] = 0;
        FORD(i,n,1)
        s[i] = s[i+1] + a[i];
        //cout<< s[1] <<endl;
        FORE(i,1,q)
        {
            int k;
            read(k);
            write(query(k));
            putchar(endl);
        }
    }
    return 0;
}
