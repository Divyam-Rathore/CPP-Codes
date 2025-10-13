#include <vector>
using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;
    using ll = long long;

    // Matrix multiplication with modulo
    void matmul(vector<vector<ll>>& a, const vector<vector<ll>>& b) {
        int n = (int)a.size();
        int m = (int)a[0].size();
        int p = (int)b[0].size();

        vector<vector<ll>> c(n, vector<ll>(p, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < p; j++) {
                ll sum = 0;
                for (int k = 0; k < m; k++) {
                    sum += a[i][k] * b[k][j];
                }
                c[i][j] = sum % mod;
            }
        }
        a = move(c);
    }

    // Fast exponentiation of matrix x^y modulo mod
    vector<vector<ll>> pow_mod(vector<vector<ll>> x, int y) {
        int n = (int)x.size();
        vector<vector<ll>> res(n, vector<ll>(n, 0));
        for (int i = 0; i < n; i++) res[i][i] = 1;  // Identity matrix

        while (y > 0) {
            if (y & 1) matmul(res, x);
            y >>= 1;
            matmul(x, x);
        }
        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        // Transition matrix of size 2*m x 2*m
        vector<vector<ll>> a(2 * m, vector<ll>(2 * m, 0));
        vector<vector<ll>> dp(2 * m, vector<ll>(1, 1));  // Initial vector with all 1's

        // Construct adjacency matrix
        // First m rows correspond to increasing sequences,
        // next m rows correspond to decreasing sequences
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                a[i][j + m] = 1;     // From increasing to decreasing if next smaller
            }
            for (int j = i + 1; j < m; j++) {
                a[i + m][j] = 1;     // From decreasing to increasing if next bigger
            }
        }

        // Compute a^(n-1)
        a = pow_mod(a, n - 1);

        // Multiply by initial dp vector
        matmul(a, dp);

        ll ans = 0;
        for (int i = 0; i < 2 * m; i++) {
            ans += a[i][0];
            ans %= mod;
        }

        return (int)ans;
    }
};
