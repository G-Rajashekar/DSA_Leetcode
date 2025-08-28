class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        unordered_map<int, priority_queue<int>> maxHeaps;
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> minHeaps; 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int diff = j - i;
                if (diff > 0) {
                    minHeaps[diff].push(grid[i][j]);
                } else {
                    maxHeaps[diff].push(grid[i][j]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int diff = j - i;
                if (diff > 0) {
                    grid[i][j] = minHeaps[diff].top();
                    minHeaps[diff].pop();
                } else {
                    grid[i][j] = maxHeaps[diff].top();
                    maxHeaps[diff].pop();
                }
            }
        }

        return grid;
    }
};
