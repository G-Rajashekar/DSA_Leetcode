#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDiagonal = 0;
        int maxArea = 0;

        for (auto &rect : dimensions) {
            int l = rect[0], w = rect[1];
            double diag = sqrt((long long)l * l + (long long)w * w);
            int area = l * w;

            if (diag > maxDiagonal) {
                maxDiagonal = diag;
                maxArea = area;
            } 
            else if (diag==maxDiagonal){
                maxArea=max(area,maxArea);
            }
        }

        return maxArea;
    }
};
