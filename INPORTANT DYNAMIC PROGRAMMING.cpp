class Solution {
    public:
    
    vector<vector<int> > dp;

    int rec(int start, int stables, string str, int K) {
        int N = str.size();
        if(start == N) {
            if(stables == K)
                    return 0;
            return INT_MAX;
        }

        if(stables == K)
                return INT_MAX;

        if(dp[start][stables] != -1)
                return dp[start][stables];

        int W = 0;
        int B = 0;
        int ans = INT_MAX;

        for(int i = start; i < N; ++i) {
            W += str[i] == 'W';
            B += str[i] == 'B';
            if (W * B > ans) break;
            int Temp = rec(i + 1, stables + 1, str, K);
            if(Temp != INT_MAX) {
                ans = min(ans, Temp + (W * B));
            }
        }
        
        return dp[start][stables] =  ans;
    }

    int arrange(string str, int K) {
        int N = str.size();
        dp.clear();
        dp.resize(N, vector<int>(K, -1));

        int ans = rec(0, 0, str, K);
        return ans == INT_MAX ? -1 : ans;
    }
};


