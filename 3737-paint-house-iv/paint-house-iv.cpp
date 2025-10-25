typedef long long int ll;

class Solution {
public:
    long long minCost(int n, vector<vector<int>>& cost) {
        int half = n / 2;
        vector<vector<vector<ll>>> dp(half + 1, vector<vector<ll>>(3, vector<ll>(3, LLONG_MAX)));

        // Base case: first and last house
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                dp[0][i][j] = cost[0][i] + cost[n - 1][j];
            }
        }

        // DP transitions
        for (int i = 1; i < half; i++) {
            for (int j = 0; j < 3; j++) {      // left side color
                for (int k = 0; k < 3; k++) {  // right side color
                    if (j == k) continue;
                    ll mini = LLONG_MAX;

                    for (int j1 = 0; j1 < 3; j1++) {
                        for (int k1 = 0; k1 < 3; k1++) {
                            if (j1 != j && k1 != k && j1 != k1)
                                mini = min(mini, dp[i - 1][j1][k1]);
                        }
                    }

                    dp[i][j][k] = cost[i][j] + cost[n - 1 - i][k] + mini;
                }
            }
        }

        // Final answer
        ll ans = LLONG_MAX;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i != j)
                    ans = min(ans, dp[half - 1][i][j]);
            }
        }

        return ans;
    }
};
