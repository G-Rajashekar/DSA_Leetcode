class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        
        vector<int>freeTime;
        
        int x=0;

        for (int i=0;i<n;i++){
            freeTime.push_back(startTime[i]-x);
            x=endTime[i];
        }

        freeTime.push_back(eventTime-x);

        int ans=0;
        int l=0;
        int sum=0;

        for (int r=0;r<freeTime.size();r++){
            sum+=freeTime[r];
            if (r-l+1>(k+1)) {
                sum-=freeTime[l];
                l++;
            }
            
            ans=max(ans,sum);
        }
        return ans;
    }
};