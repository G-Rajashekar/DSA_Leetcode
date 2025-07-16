class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even=0;
        int odd=0;
        int alternate=1;
        int parity=nums[0]%2;

        for(int i=0;i<nums.size();i++){
           if (nums[i]%2) odd++;
           else even++;

           if (i>=1){
                int curParity=nums[i]%2;
                if (curParity!=parity){
                alternate++;
                parity=curParity;
              }
           }
        }

        return max({even,odd,alternate});
        
    } 
};