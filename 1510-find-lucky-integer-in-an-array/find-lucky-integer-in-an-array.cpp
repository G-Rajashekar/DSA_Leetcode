class Solution {
public:
    int findLucky(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int ans=-1;
        int val=arr[0];
        int freq=1;

        for (int i=1;i<arr.size();i++){
            if (arr[i]==val) freq++;
            else{
                if (freq==val) ans=val;
                freq=1;
                val=arr[i];
            }
        }
        if (freq==val) ans=val;
        return ans;
    }
};