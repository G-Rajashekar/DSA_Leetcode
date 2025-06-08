class Solution {
public:
    void solve(int num, int n, vector<int>& res) {
        if (num > n)
            return;
        res.push_back(num);
        for (int i = 0; i <= 9; i++) {
            int newnum = num * 10 + i;
            solve(newnum, n, res);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i = 1; i <= 9; i++) {
            solve(i, n, res);
        }
        return res;
    }
};