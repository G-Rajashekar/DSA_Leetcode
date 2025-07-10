class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int>freq;

        freq.push_back(startTime[0]);

        for (int i=1;i<n;i++){
            freq.push_back(startTime[i]-endTime[i-1]);
        }

        freq.push_back(eventTime-endTime[n-1]);

        n=freq.size();
        vector<int>maxRightFree(n,0);
        vector<int>maxLeftFree(n,0);
        for (int i=n-2;i>=0;i--){
            maxRightFree[i]=max(maxRightFree[i+1],freq[i+1]);
        }

        for (int i=1;i<n;i++){
            maxLeftFree[i]=max(maxLeftFree[i-1],freq[i-1]);
        }

        int res=0;

        for (int i=1;i<n;i++){
            int duration=endTime[i-1]-startTime[i-1];

            if (duration<=max(maxLeftFree[i-1],maxRightFree[i])){
                res=max(res,freq[i-1]+duration+freq[i]);
            }
            else{
                res=max(res,freq[i-1]+freq[i]);
            }
        }
        return res;
    }
};