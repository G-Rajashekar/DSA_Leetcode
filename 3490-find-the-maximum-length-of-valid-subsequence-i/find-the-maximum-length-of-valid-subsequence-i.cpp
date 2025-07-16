class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even=0;
        int odd=0;
        
        for (auto num:nums){
            if (num%2) odd++;
            else even++;
        }

        int alternate=1;
        int parity=nums[0]%2;

        for(int i=1;i<nums.size();i++){
            int curParity=nums[i]%2;
            if (curParity!=parity){
                alternate++;
                parity=curParity;
            }
        }

        return max({even,odd,alternate});
        
    } 
};