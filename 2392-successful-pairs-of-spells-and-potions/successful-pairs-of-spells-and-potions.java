import java.util.*;

class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        int n = spells.length;
        int m = potions.length;
        int[] ans = new int[n];
        Arrays.sort(potions); // Sort potions once

        for (int i = 0; i < n; i++) {
            long minPotion = (success + spells[i] - 1) / spells[i]; // ceil(success / spell)
            int idx = binarySearch(potions, minPotion);
            ans[i] = m - idx; // remaining potions form successful pairs
        }

        return ans;
    }

    private int binarySearch(int[] potions, long target) {
        int l = 0, r = potions.length - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (potions[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
}
