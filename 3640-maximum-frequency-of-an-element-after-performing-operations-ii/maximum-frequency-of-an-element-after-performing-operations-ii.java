class Solution {
    public int maxFrequency(int[] nums, int k, int numOperations) {
        int n = nums.length;
        Arrays.sort(nums);
        int ans = 0;
        Map<Integer, Integer> map = new HashMap<>(); //original frequency
        for(int x: nums) {
            map.put(x, map.getOrDefault(x, 0) + 1);
        }
//choose any of the exisiting number and try to make others equal to it
        for(int mid = 0, left = 0, right = 0; mid < n; mid++) {
            while(nums[mid] - k > nums[left]) left++;
            while(right < n && nums[mid] + k >= nums[right]) right++;
            int total = right - left;
            ans = Math.max(ans, Math.min(total, numOperations + map.get(nums[mid])));
        }
        
//choose any mid number which non - existing in the array and make others equal to it
        for(int left = 0, right = 0; right < n; left++) {
            int mid = (nums[left] + nums[right]) / 2;
            while(right < n && mid + k >= nums[right] && mid - k <= nums[left]) {
                right++;
                if(right < n)
                    mid = (nums[left] + nums[right]) / 2; 
            }
            ans = Math.max(ans, Math.min(right - left, numOperations));
            if(right == n) break;
        }
        return ans;
    }
}