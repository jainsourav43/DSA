#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
 
typedef long long ll;
 
int main() {
    ios_base::sync_with_stdio(false);
    
    int T;  cin>>T;
    while (T--) {
        int N, Q;   cin>>N>>Q;
        vector<int> nums(N);
        for (int i = 0; i < N; ++i)
            cin>>nums[i];
        
        vector<ll> left(N, -1);
        vector<ll> right(N, N);
        vector<ll> sums(N);
        
        for (int i = 0; i < N; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] <= nums[j]) {
                    left[i] = j;
                    break;
                }
            }       
            for (int j = i; j < N; ++j) {
                if (nums[i] < nums[j]) {
                    right[i] = j;
                    break;
                }
            }
        }
        
        vector<pair<int, int> > thingo(N);
        for (int i = 0; i < N; ++i)
            thingo[i] = {nums[i], i};
        sort(thingo.rbegin(), thingo.rend());
        
        for (int i = 0; i < N; ++i) {
            ll a = thingo[i].second - left[thingo[i].second] - 1;
            ll b = right[thingo[i].second] - thingo[i].second;
            sums[i] = b * (1 + a);
            if (i)
                sums[i] += sums[i-1];
        }
        
        while (Q--) {
            ll p;   cin>>p;
            int lo = 0;
            int hi = N-1;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (sums[mid] >= p)
                    hi = mid;
                else
                    lo = mid + 1;
            }
            cout<<thingo[hi].first<<endl;
        }
    }
    
    return 0;
} 
