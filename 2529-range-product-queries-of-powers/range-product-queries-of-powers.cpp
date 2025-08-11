class Solution {
public:
    const int mod = 1e9+7;

    long long modPow(long long base, long long exp) {
         if (exp==0) return 1;
         long long half=modPow(base,exp/2);
         long long res=(half*half)%mod;

         if (exp%2) res=(res*base)%mod;
         return res;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        for (int i = 0; i < 31; i++) {
            if (n & (1 << i)) powers.push_back(i);
        }

        int s = powers.size();
        vector<int> prefix(s);
        prefix[0] = powers[0];
        for (int i = 1; i < s; i++) {
            prefix[i] = powers[i] + prefix[i-1];
        }

        vector<int> res;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long exponent = prefix[r] - (l == 0 ? 0 : prefix[l-1]);
            res.push_back(modPow(2, exponent));
        }
        return res;
    }
};
