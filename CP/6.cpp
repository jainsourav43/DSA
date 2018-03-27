#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cassert>
using namespace std;
 
#define sz(a) int((a).size())
#define rep(i, s, n)  for(int i = s; i <= (n); ++i)
#define rev(i, n, s)  for(int i = (n); i >= s; --i)
#define fore(x, a) for(auto &&x : a)
typedef long long ll;
const int mod = 1000000007;
const int N = 100005;
 
char s[55][55];
bool v[55][55];
set<char> a;
int cur;
int n;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
 
void go(int x, int y) {
  a.insert(s[x][y]);
  v[x][y] = 1;
  cur++;
  rep(i, 0, 3) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx >= 0 && nx < n && ny >= 0 && ny < n && (s[nx][ny] != '.') && (!v[nx][ny])) {
      go(nx, ny);
    }
  }
}
 
int main() {
//#ifdef loc
//  if(!freopen((string(FOLDER) + "inp.txt").c_str(), "r", stdin)) {
//    assert(0);
//  }
//  freopen((string(FOLDER) + "out.txt").c_str(), "w", stdout);
//#endif
//  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while (t-- > 0) {
    cin >> n;
    rep(i, 0, n - 1) {
      cin >> s[i];
    }
    int res = 1;
    memset(v, 0, sizeof(v));
    rep(i, 0, n - 1) {
      rep(j, 0, n - 1) {
        if (s[i][j] != '.') {
          if (!v[i][j]) {
            a.clear();
            cur = 0;
            go(i, j);
            if (sz(a) > 2) res = 0;
            else if (sz(a) == 2) {
              if (a.find('?') == a.end()) res = 0;
              else if (a.find('G') != a.end()) res = 0;
            }
            else {
              if (a.find('?') != a.end()) {
                if (cur > 1) res = (res * 2LL) % mod;
                else res = (res * 3LL) % mod;
              }
              else if (a.find('G') != a.end()) {
                if (cur > 1) res = 0;
              }
            }
          }
        }
      }
    }
    cout << res << endl;
  }
  return 0;
} 
