class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        
        for (int i=1;i<n;i++){
            int req=n-i;

            if (to_string(i).find('0')==string::npos && to_string(req).find('0')==string::npos) return {i,req};
        }

        return {-1,-1};
    }
};