class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>mp;

        for (auto c:s){
            mp[c]++;
        }

        int max_odd=INT_MIN;
        int min_even=INT_MAX;

        for (auto it:mp){
            if (it.second%2==1)
                 max_odd=max(max_odd,it.second);
            else
                  min_even=min(min_even,it.second);

        }

        if (max_odd==INT_MIN) max_odd=0;
        if (min_even==INT_MAX) min_even=0;
        return max_odd-min_even;
    }
};