class Solution {
public:
     #define ll long long
    long long minimumDifference(vector<int>& nums) {
        ll total=nums.size();
       ll n=total/3;
        priority_queue<ll>maxHeap;
        priority_queue<ll,vector<ll>,greater<ll>>minHeap;
        vector<ll>left(total);
        vector<ll>right(total);

        ll sum=0;
        for (int i=0;i<=2*n-1;i++){
            sum+=nums[i];
            maxHeap.push(nums[i]);

            if (maxHeap.size()>n){
                sum-=maxHeap.top();
                maxHeap.pop();
            }
            left[i]=sum;
        }

        sum=0;
        for (int i=total-1;i>=n;i--){
            sum+=nums[i];
            minHeap.push(nums[i]);

            if (minHeap.size()>n){
                sum-=minHeap.top();
                minHeap.pop();
            }
            right[i]=sum;
        }

        
        ll ans=LLONG_MAX;

        for (int i=n-1;i<=2*n-1;i++){
            ll diff=left[i]-right[i+1];

            ans=min(ans,diff);
        }
        return ans;
    }
};